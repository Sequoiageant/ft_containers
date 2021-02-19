/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 10:29:50 by julnolle          #+#    #+#             */
/*   Updated: 2021/02/19 15:43:19 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MAP_HPP
# define MAP_HPP

# include <string>
# include <iostream>
# include <cstddef>
# include <exception>
# include <sstream>
# include <cstring>
# include "integral_traits.hpp"
# include "functional.hpp"
# include "Map_iterator.hpp"

// # define LEFT	-1
// # define RIGHT	1
// # define THIS	0

namespace ft {

template<typename Key, typename T, typename Compare = std::less<Key> >
class map {

public:

	typedef Key										key_type;
	typedef T										mapped_type;
	// typedef Tree_node<key_type, mapped_type>		node_type;
	typedef std::pair<const Key, T>					value_type;
	typedef Tree_node<value_type>					node_type;
	typedef Compare									key_compare;
	typedef Map_iterator<value_type>				iterator;
	typedef Map_iterator<const value_type>			const_iterator;
	typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;
	typedef std::reverse_iterator<iterator>			reverse_iterator;
	typedef	size_t									size_type;
	typedef	ptrdiff_t								difference_type;

	class value_compare
	{	// in C++98, it is required to inherit binary_function<value_type,value_type,bool>
		friend class map;
		
		protected:
			Compare comp;
	 		 value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
		public:
			bool operator() (const value_type& x, const value_type& y) const
			{
				return comp(x.first, y.first);
			}
	};
	

	explicit map (const key_compare& comp = key_compare())
	: _root(NULL), _size(0), _comp(comp)
	{
		this->_sentinel = new node_type();
		// this->_sentinel->parent = NULL;
		// this->_sentinel->left = this->_sentinel;
		// this->_sentinel->right = this->_sentinel;
	}

	template <class InputIterator>
	map (InputIterator first, InputIterator last, const key_compare& comp = key_compare())
	: _root(NULL), _size(0), _comp(comp)
	{
		this->insert(first, last);
	}

	map (const map& x)
	{
		this->_comp = x._comp;
		this->insert(x.begin(), x.end());
	}

	map& operator=(map const & x)
	{
		this->clear();
		this->_comp = x._comp;
		this->insert(x.begin(), x.end());

		return *this;
	}
	~map ()
	{
		this->clear();
		delete this->_sentinel;
	}

	iterator begin() { return iterator(LeftMost(this->_root), this->_sentinel); }
	const_iterator begin() const { return const_iterator(LeftMost(this->_root), this->_sentinel); }

	iterator end() { return iterator(this->_sentinel, this->_sentinel); }
	const_iterator end() const { return const_iterator(this->_sentinel, this->_sentinel); }
	
	reverse_iterator rbegin(void) { return reverse_iterator(this->end()); }
	const_reverse_iterator rbegin(void) const { return const_reverse_iterator(this->end()); }

	reverse_iterator rend(void) { return reverse_iterator(this->begin()); }
	const_reverse_iterator rend(void) const { return const_reverse_iterator(this->begin()); }

	bool empty() const
	{
		return (this->_root == NULL);
	}

	size_type size() const
	{
		return (this->_size);
	}

	size_type max_size() const
	{
		std::allocator<node_type> a;
		return a.max_size();
	}

	mapped_type& operator[] (const key_type& k)
	{
		return (*((this->insert(std::make_pair(k,mapped_type()))).first)).second;
	}

	std::pair<iterator,bool> insert (const value_type& val)
	{
		if (this->_root == NULL)
		{
			this->_root = this->new_node(val);
			this->_sentinel->left = this->_root;
			this->_sentinel->right = this->_root;
			++this->_size;
			return (std::make_pair(iterator(this->_root, this->_sentinel), true));
		}
		return this->insertRecurse(this->_root, val);
	}

	iterator insert (iterator position, const value_type& val)
	{
		node_type* node = position.base();

		if (this->_comp(val.first, node->value.first) && node->left == this->_sentinel)
		{
			std::cerr << "- Insert It I -" << std::endl;
			node_type *n = this->new_node(val);
			n->parent = node;
			node->left = n;
			++this->_size;
			return iterator(n, this->_sentinel);
		}
		else if (this->_comp(node->value.first, val.first) && node->right == this->_sentinel)
		{
			std::cerr << "- Insert It II -" << std::endl;
			node_type *n = this->new_node(val);
			n->parent = node;
			node->right = n;
			++this->_size;			
			return iterator(n, this->_sentinel);
		}
		std::cerr << "- Insert It III -" << std::endl;
		return this->insert(val).first;
	}

	template <class InputIterator>
	void insert (InputIterator first, InputIterator last)
	{
		while (first != last)
		{
			this->insert(*first);
			++first;
		}
	}

	void erase (iterator position)
	{
		this->eraseRecurse(this->_root, position->first);
	}

	size_type erase (const key_type& k)
	{
		return this->eraseRecurse(this->_root, k);
	}

	void erase (iterator first, iterator last)
	{
		while (first != last)
		{
			this->erase(first++);
		}
	}

	void swap (map& x)
	{
		this->swap_values(this->_root, x._root);
		this->swap_values(this->_sentinel, x._sentinel); //works with sentinel as pointer (or a node_base ?)
		this->swap_values(this->_size, x._size);
		this->swap_values(this->_comp, x._comp);
	}

	void clear ()
	{
		deleteRecurse(this->_root);
		this->_size = 0;
	}

	key_compare key_comp() const
	{
		return this->_comp;
	}

	value_compare value_comp() const
	{
		return value_compare(this->_comp);
	}

	iterator find (const key_type& k)
	{
		if (this->_root == NULL)
			return (this->end());
		return iterator(this->findRecurse(this->_root, k), this->_sentinel);
	}

	const_iterator find (const key_type& k) const
	{
		if (this->_root == NULL)
			return (this->end());
		return const_iterator(this->findRecurse(this->_root, k), this->_sentinel);
	}

	size_type count (const key_type& k) const
	{
		if (this->findRecurse(this->_root, k) != this->_sentinel)
			return 1;
		return 0;
	}

	iterator lower_bound (const key_type& k)
	{
		iterator it = this->begin();
		while (it != this->end() && _comp(it->first, k))
		{
			++it;
		}
		return it;
	}

	const_iterator lower_bound (const key_type& k) const
	{
		const_iterator it = this->begin();
		while (it != this->end() && _comp(it->first, k))
		{
			++it;
		}
		return it;
	}

	iterator upper_bound (const key_type& k)
	{
		iterator it = this->begin();
		while (it != this->end() && !_comp(k, it->first))
		{
			++it;
		}
		return it;
	}

	const_iterator upper_bound (const key_type& k) const
	{
		const_iterator it = this->begin();
		while (it != this->end() && !_comp(k, it->first))
		{
			++it;
		}
		return it;
	}

	std::pair<iterator,iterator>				equal_range (const key_type& k)
	{
		return std::make_pair(this->lower_bound(k), this->upper_bound(k));
	}

	std::pair<const_iterator,const_iterator>	equal_range (const key_type& k) const
	{
		return std::make_pair(this->lower_bound(k), this->upper_bound(k));
	}





// DISPLAY FUNCTION FOR DEBUG
/////////////////////////////	
	void displayMap()
	{
		this->printInorder (this->_root);
	}

	void printInorder(node_type *node)
	{
		if (node == NULL || node == this->_sentinel)
			return ;
		printInorder(node->left);
		// std::cout << "this->root: " << this->_root->value.first << std::endl;
		// if (node->side == 'h')
		// 	std::cout << "map[" << node->value.first << "] = " << node->value.second << " (HEAD)" << std::endl;
		// else
		// 	std::cout << "map[" << node->value.first << "] = " << node->value.second << " (" << node->side << ")" << std::endl;
		// std::cout << "map[" << node->value.first << "] = " << node->value.second << std::endl;
		if (node->left == this->_sentinel && node->right == this->_sentinel)
			std::cout << node->value.first << ": L= sentinel, R= sentinel" << std::endl;
		else if (node->left == this->_sentinel)
			std::cout << node->value.first << ": L= sentinel, R= " << node->right->value.first << std::endl;
		else if (node->right == this->_sentinel)
			std::cout << node->value.first << ": L= " << node->left->value.first << ", R= sentinel" << std::endl;
		else
			std::cout << node->value.first << ": L= " << node->left->value.first << ", R= " << node->right->value.first << std::endl;
		printInorder(node->right);
	}
//////////////////////////////////////// DISPLAY FUNCTION FOR DEBUG
	
private:
	node_type	*_sentinel;
	node_type	*_root;
	size_type	_size;
	key_compare	_comp;

	node_type* new_node(const value_type& val)
	{
		node_type *n = new node_type(val); // for typename Pair

		n->left = this->_sentinel;
		n->right = this->_sentinel;
		n->parent = this->_sentinel;
		this->_sentinel->left = this->_root;
		this->_sentinel->right = RightMost(this->_root);
		return n;
	}

	void delete_node(node_type*& node, node_type* substitute = NULL) // substitute is a copy of chils or min, not a ref
	{
		if (substitute)
			substitute->parent = node->parent;
		delete node;
		node = substitute;
		--this->_size;
	}

	template <class Value>
	void	swap_values(Value& a, Value& b)
	{
		Value tmp;

		tmp = a;
		a = b;
		b = tmp;
	}

	node_type* RightMost(node_type* node)
	{
		if (node)
		{
			while (node->right != this->_sentinel)
			{
				node = node->right;
			}
		}
		return node;
	}

	node_type* LeftMost(node_type* node)
	{
		if (node)
		{
			while (node->left != this->_sentinel)
			{
				node = node->left;
				// std::cerr << "first: " << node->value.first << std::endl;
			}
		}
		return node;
	}
	
	node_type* searchRightest(node_type* node, node_type* &parent = NULL)
	{
		while (node->right != this->_sentinel)
		{
			if (parent) //&& parent != this->_sentinel
				parent = node;
			node = node->right;
		}
		return node;
	}

	node_type* findRecurse(node_type *node, const key_type& k) const
	{
		// std::cerr << "FIND" << std::endl;
		if (node != this->_sentinel)
		{
			// std::cerr << "key: " << node->key << std::endl;
			if (this->_comp(k, node->value.first))
				return findRecurse(node->left, k);
			else if (this->_comp(node->value.first, k))
				return findRecurse(node->right, k);
		}
		return (node);
	}

	std::pair<iterator,bool> insertRecurse(node_type *node, const value_type& val)
	{	
		if (!_comp(val.first, node->value.first) && !_comp(node->value.first, val.first))
		{
			std::cerr << "EGALE" << std::endl;
			return std::make_pair(iterator(node, this->_sentinel), false);
		}

		if (this->_comp(val.first, node->value.first)) {
			if (node->left != this->_sentinel) {
				return insertRecurse(node->left, val);
			}
			else
			{
				node_type *n = this->new_node(val); // for typename Pair
				n->side = 'L'; // FOR DEBUG
				n->parent = node;
				node->left = n;
				++this->_size;
				return (std::make_pair(iterator(n, this->_sentinel), true));
			}
		} 
		else {
			if (node->right != this->_sentinel) {
				return insertRecurse(node->right, val);
			}
			else
			{
				node_type *n = this->new_node(val); // for typename Pair
				n->side = 'R'; // FOR DEBUG
				n->parent = node;
				node->right = n;
				++this->_size;
				return (std::make_pair(iterator(n, this->_sentinel), true));
			}
		}
	}

	int eraseRecurse(node_type*& node, const key_type& k)
	{
		if (node == NULL || node == this->_sentinel)
			return 0;
		if (node->value.first == k)
		{
			// if (node->left == this->_sentinel && node->right == this->_sentinel)
			// {
			// 	// std::cerr << "--> I <--" << std::endl;
			// 	this->delete_node(node, node->left); // node->left is this->_sentinel
			// 	return 1;
			// }
			if (node->right == this->_sentinel)
			{
				// std::cerr << "--> II <--" << std::endl;
				this->delete_node(node, node->left);
				return 1;
			}
			else if (node->left == this->_sentinel)
			{
				// std::cerr << "--> III <--" << std::endl;
				this->delete_node(node, node->right);
				this->_sentinel->right = RightMost(this->_root);
				return 1;
			}
			else
			{
				// std::cerr << "--> IV <--" << std::endl;
				node_type *last_parent = node;
				node_type* min = searchRightest(node->left, last_parent);				
				if (node == this->_root)
				{
					min->side = 'h'; // FOR DEBUG
					this->_sentinel->left = min;
				}
				if (last_parent != node)
				{
					last_parent->right = min->right;
					min->left = node->left;
				}
				min->right = node->right;
				node->right->parent = min;
				node->left->parent = min;
				
				this->delete_node(node, min);
				return 1;
			}
		}
		else if (this->_comp(k, node->value.first))
			eraseRecurse(node->left, k);
		else
			eraseRecurse(node->right, k);
		return 0;
	}

	void deleteRecurse(node_type *&node)
	{
		if (node && node != this->_sentinel)
		{
			deleteRecurse(node->left);
			deleteRecurse(node->right);

			delete node;
			node = NULL;
		}
	}
};

template< class Key, class T, class Compare>
bool operator==(const map<Key,T,Compare>& lhs, const map<Key,T,Compare>& rhs)
{
	typename map<Key, T, Compare>::const_iterator it1 = lhs.begin();
	typename map<Key, T, Compare>::const_iterator it2 = rhs.begin();

	if (lhs.size() != rhs.size())
		return false;

	while (it1 != lhs.end())
	{
		if (*it1 != *it2)
			return false;
		++it1;
		++it2;
	}
	return true;
}

template< class Key, class T, class Compare>
bool operator!=(const map<Key,T,Compare>& lhs, const map<Key,T,Compare>& rhs)
{
	return !(lhs == rhs);
}

template< class Key, class T, class Compare>
bool operator<(const map<Key,T,Compare>& lhs, const map<Key,T,Compare>& rhs)
{
		typename map<Key,T,Compare>::const_iterator end1 = lhs.end();
		typename map<Key,T,Compare>::const_iterator end2 = rhs.end();
		typename map<Key,T,Compare>::const_iterator first1 = lhs.begin();
		typename map<Key,T,Compare>::const_iterator first2 = rhs.begin();

		while (first1 != end1 && first2 != end2)
		{
			if (*first1 < *first2 )
				return true;
			++first1;
			++first2;
			if (first1 == end1 && first2 != end2)
				return true;
		}
		return false;
}

template< class Key, class T, class Compare>
bool operator<=(const map<Key,T,Compare>& lhs, const map<Key,T,Compare>& rhs)
{
	return !(rhs < lhs);
}

template< class Key, class T, class Compare>
bool operator>(const map<Key,T,Compare>& lhs, const map<Key,T,Compare>& rhs)
{
	return (rhs < lhs);
}

template< class Key, class T, class Compare>
bool operator>=(const map<Key,T,Compare>& lhs, const map<Key,T,Compare>& rhs)
{
	return !(lhs < rhs);
}

template< class Key, class T, class Compare>
void swap (map<Key,T,Compare>& x, map<Key,T,Compare>& y)
{
	x.swap(y);
}


} // ft

#endif // MAP_HPP