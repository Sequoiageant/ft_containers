/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 10:29:50 by julnolle          #+#    #+#             */
/*   Updated: 2021/02/15 18:23:45 by julnolle         ###   ########.fr       */
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

# define LEFT	-1
# define RIGHT	1
# define THIS	0

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

/*	class value_compare
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
	};*/
	

	explicit map (const key_compare& comp = key_compare()) : _root(NULL), _size(0), _comp(comp)
	{
		this->_head.parent = NULL;
		this->_head.left = &this->_head;
		this->_head.right = &this->_head;
	}

	template <class InputIterator>
	map (InputIterator first, InputIterator last, const key_compare& comp = key_compare());

	map (const map& x);

	map& operator=(map const & x);
	~map () {}

	iterator begin() { return iterator(LeftMost(this->_root), &this->_head); }
	const_iterator begin() const { return const_iterator(LeftMost(this->_root), &this->_head); }

	iterator end() { return iterator(&this->_head, &this->_head); }
	const_iterator end() const { return const_iterator(&this->_head, &this->_head); }
	
/*	reverse_iterator rbegin(void) { return reverse_iterator(this->end()); }
	const_reverse_iterator rbegin(void) const { return const_reverse_iterator(this->end()); }

	reverse_iterator rend(void) { return reverse_iterator(this->begin()); }
	const_reverse_iterator rend(void) const { return const_reverse_iterator(this->begin()); }
*/
	bool empty() const
	{
		return (this->_root == NULL);
	}

	size_type size() const
	{
		return (this->_size);
	}

	size_type max_size() const;
	mapped_type& operator[] (const key_type& k);

	// std::pair<iterator,bool> insert (const value_type& val);
	iterator insert (iterator position, const value_type& val);
	template <class InputIterator>
	void insert (InputIterator first, InputIterator last);

	void erase (iterator position);
	// size_type erase (const key_type& k);
	void erase (iterator first, iterator last);

	void swap (map& x);
	void clear ()
	{
		deleteRecurse(this->_root);
		this->_size = 0;
	}

	key_compare key_comp() const;

	// value_compare value_comp() const;

	// iterator find (const key_type& k);
	const_iterator find (const key_type& k) const;
	size_type count (const key_type& k) const;
	iterator lower_bound (const key_type& k);
	const_iterator lower_bound (const key_type& k) const;
	iterator upper_bound (const key_type& k);
	const_iterator upper_bound (const key_type& k) const;

	std::pair<const_iterator,const_iterator>	equal_range (const key_type& k) const;
	std::pair<iterator,iterator>				equal_range (const key_type& k);

	void displayMap()
	{
		printInorder (this->_root);
	}

	void printInorder(node_type *node)
	{
		if (node == NULL || node == &this->_head)
			return ;
		printInorder(node->left);
		// std::cout << "this->root: " << this->_root->value.first << std::endl;
		if (node->side == 'h')
			std::cout << "map[" << node->value.first << "] = " << node->value.second << " (HEAD)" << std::endl;
		else
			std::cout << "map[" << node->value.first << "] = " << node->value.second << " (" << node->side << ")" << std::endl;
		printInorder(node->right);
	}

	void insert (const value_type& val)
	{
		node_type *n = new node_type(val); // for typename Pair
		n->left = &this->_head;
		n->right = &this->_head;
		n->parent = &this->_head;
		this->_head.left = this->_root;
		this->_head.right = LeftMost(this->_root);

		// node_type *n = new node_type(val.first, val.second);

		if (this->_root == NULL)
		{
			n->parent = &this->_head;
			this->_root = n;
			++this->_size;
			return ;
		}
		insertRecurse(this->_root, n);
		++this->_size;
	}

	void insertRecurse(node_type *node, node_type *n)
	{	
  		// Descente récursive dans l'arbre jusqu'à atteindre une feuille
		if (node != NULL && this->_comp(n->value.first, node->value.first)) {
			if (node->left != NULL && node->left != &this->_head) {
				insertRecurse(node->left, n);
				return;
			}
			else
			{
				n->side = 'L';
				n->parent = node;
				n->left = node->left;
				node->left = n;
			}
		} 
		else if (node != NULL) {
			if (node->right != NULL && node->right != &this->_head) {
				insertRecurse(node->right, n);
				return;
			}
			else
			{
				n->side = 'R';
				n->parent = node;
				n->right = node->right;
				node->right = n;
			}
		}
	}

	void deleteRecurse(node_type *&node)
	{
		if (node != &this->_head)
		{
			if (node->left)
				deleteRecurse(node->left);
			if (node->right)
				deleteRecurse(node->right);
		// std::cout << "Deleting: " << node->key << std::endl;
			delete node;
			node = NULL;
		}
	}

	bool find (const key_type& k)
	{
		if (this->_root == NULL)
			return (false);
		return findRecurse(this->_root, k);
	}

	bool findRecurse(node_type *node, const key_type& k)
	{
		// std::cerr << "FIND" << std::endl;
		if (node)
		{
			// std::cerr << "key: " << node->key << std::endl;
			if (this->_comp(k, node->value.first))
				return findRecurse(node->left, k);
			else if (this->_comp(node->value.first, k))
				return findRecurse(node->right, k);
			else
				return (true);
		}
		return (false);
	}

	void erase (const key_type& k)
	{
		if (this->_root == NULL || this->_root == &this->_head)
			return ;
		eraseRecurse(this->_root, k);
	}
	
	node_type* RightMost(node_type* node)
	{
		// node_type *cpy = node;
		if (node)
		{
			while (node->right != &this->_head)
			{
				node = node->right;
			}
		}
		return node;
	}

	node_type* LeftMost(node_type* node)
	{
		// node_type *cpy = node;
		if (node)
		{
			while (node->left != &this->_head && node->left != NULL)
			{
				node = node->left;
				// std::cerr << "first: " << node->value.first << std::endl;
			}
		}
		return node;
	}
	
	node_type* searchRightest(node_type* node, node_type* &parent = NULL)
	{
		// node_type *cpy = node;
		while (node->right != &this->_head)
		{
			if (parent)
				parent = node;
			node = node->right;
		}
		return node;
	}

	node_type* searchLeftest(node_type* node, node_type* &parent = NULL)
	{
		// node_type *cpy = node;
		while (node->left)
		{
			if (parent)
				parent = node;
			node = node->left;
		}
		return node;
	}

	void eraseRecurse(node_type*& node, const key_type& k)
	{
		if (node == NULL || node == &this->_head)
			return;
		if (node->value.first == k)
		{
			if (node->left == &this->_head && node->right == &this->_head)
			{
				std::cerr << "--> I <--" << std::endl;
				// delete node;
				// node = NULL;
				// --this->_size;
				this->delete_node(node);
				return ;
			}
			else if (node->left == NULL || node == &this->_head)
			{
				std::cerr << "--> II <--" << std::endl;
				// node_type *child = node->right;
				// child->parent = node->parent;
				// delete node;
				// node = child;
				// --this->_size;
				this->delete_node(node, node->right);
				return ;
			}
			else if (node->right == NULL || node == &this->_head)
			{
				std::cerr << "--> III <--" << std::endl;
				// node_type *child = node->left;
				// child->parent = node->parent;
				// delete node;
				// node = child;
				// --this->_size;
				this->delete_node(node, node->left);
				return ;
			}
			else
			{
				std::cerr << "ICI" << std::endl;
				node_type *last_parent = node;
				node_type* min = searchRightest(node->left, last_parent);				
				if (node == this->_root) // FOR DEBUG
					min->side = 'h';	//
				
/*				if (min == last_parent->left)
					last_parent->left = min->left;
				else
					last_parent->right = min->left;
*/				
				if (last_parent != node)
				{
					last_parent->right = min->right;
					min->left = node->left;
				}
				min->right = node->right;
				node->right->parent = min;
				node->left->parent = min;
				
				this->delete_node(node, min);
				return ;
			}
		}
		else if (k < node->value.first)
			eraseRecurse(node->left, k);
		else
			eraseRecurse(node->right, k);
	}

private:
	node_type	_head;
	node_type	*_root;
	size_type	_size;
	key_compare	_comp;

	void delete_node(node_type*& node, node_type* substitute = NULL) // substitute is a copy of chils or min, not a ref
	{
		if (substitute)
			substitute->parent = node->parent;
		delete node;
		node = substitute;
		--this->_size;
	}
};

// std::ostream & operator<<(std::ostream & o, map const & rhs);

#endif // MAP_HPP


} // ft