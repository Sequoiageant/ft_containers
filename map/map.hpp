/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 10:29:50 by julnolle          #+#    #+#             */
/*   Updated: 2021/02/04 18:39:00 by julnolle         ###   ########.fr       */
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

/*template<typename Pair>
	struct Node {
		Pair			value;
		struct Node* 	left;
		struct Node* 	right;

		Node()
		: value(Pair()), left(NULL), right(NULL)
		{}

		Node(Pair val)
		: value(val), left(NULL), right(NULL)
		{}
	};
*/
template<typename KeyType, typename ValueType>
	struct Node {
		KeyType			key;
		ValueType		value;
		struct Node* 	left;
		struct Node* 	right;
		int				color; // left 0, right 1

		Node()
		: key(KeyType()), value(ValueType()), left(NULL), right(NULL), color(-1)
		{}

		Node(KeyType key, ValueType val)
		: key(key), value(val), left(NULL), right(NULL), color(-1)
		{}
	};

template<typename Key, typename T, typename Compare = std::less<Key> >
class map {

public:

	typedef Key										key_type;
	typedef T										mapped_type;
	typedef Node<key_type, mapped_type>				node_type;
	typedef std::pair<const Key, T>					value_type;
	// typedef Node<value_type>						node_type;
	typedef Compare									key_compare;
	typedef Map_iterator<T*>						iterator;
	typedef Map_iterator<const T*>					const_iterator;
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
	

	explicit map (const key_compare& comp = key_compare()) : _root(NULL), _size(0), _comp(comp)
	{(void)comp;}

	template <class InputIterator>
	map (InputIterator first, InputIterator last, const key_compare& comp = key_compare());

	map (const map& x);

	map& operator=(map const & x);
	~map () {}

/*	iterator begin() { return iterator(this->_array); }
	const_iterator begin() const { return const_iterator(this->_array); }

	iterator end() { return iterator(&this->_array[this->_size]); }
	const_iterator end() const { return const_iterator(&this->_array[this->_size]); }

	reverse_iterator rbegin(void) { return reverse_iterator(this->end()); }
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
		this->_root = NULL;
	}

	key_compare key_comp() const;

	value_compare value_comp() const;

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
		if (node == NULL)
			return ;
		printInorder(node->left);
		if (node->color == 0)
			std::cout << "map[" << node->key << "] = " << node->value << " (left)" << std::endl;
		else if (node->color == 1)
			std::cout << "map[" << node->key << "] = " << node->value << " (right)" << std::endl;
		else
			std::cout << "map[" << node->key << "] = " << node->value << std::endl;
		printInorder(node->right);
	}

	void insert (const value_type& val)
	{
		node_type *n = new node_type(val.first, val.second);

		if (this->_root == NULL)
		{
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
		if (node != NULL && this->_comp(n->key, node->key)) {
			if (node->left != NULL) {
				insertRecurse(node->left, n);
				return;
			}
			else
			{
				n->color = 0;
				node->left = n;
			}
		} 
		else if (node != NULL) {
			if (node->right != NULL) {
				insertRecurse(node->right, n);
				return;
			}
			else
			{
				n->color = 1;
				node->right = n;
			}
		}
	}

	void deleteRecurse(node_type *node)
	{	
		if (node->left)
			deleteRecurse(node->left);
		if (node->right)
			deleteRecurse(node->right);
		// std::cout << "Deleting: " << node->key << std::endl;
		delete node;
		node = NULL;
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
			if (this->_comp(k, node->key))
				return findRecurse(node->left, k);
			else if (this->_comp(node->key, k))
				return findRecurse(node->right, k);
			else
				return (true);
		}
		return (false);
	}

	void erase (const key_type& k)
	{
		if (this->_root == NULL)
			return ;
		eraseRecurse(this->_root, k);
	}

	void eraseRecurse(node_type *node, const key_type& k)
	{
		if (node)
		{
			if (k < node->key)
			{
				if (node->left && k == node->left->key)
					this->delete_node(node, LEFT);
				else
					return eraseRecurse(node->left, k);
			}
			else if (k > node->key)
			{
				if (node->right && k == node->right->key)
					this->delete_node(node, RIGHT);
				else
					return eraseRecurse(node->right, k);
			}
			else
				this->delete_node(node, THIS);
		}
	}


private:
	node_type	*_root;
	size_type	_size;
	key_compare	_comp;

	void delete_node(node_type* node, int pos)
	{
		(void)node;
		(void)pos;
		return;
	}
};

// std::ostream & operator<<(std::ostream & o, map const & rhs);

#endif // MAP_HPP


} // ft