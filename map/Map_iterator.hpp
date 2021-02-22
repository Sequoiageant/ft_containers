/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 10:55:32 by julnolle          #+#    #+#             */
/*   Updated: 2021/02/19 16:40:22 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft {

// template<typename KeyType, typename ValueType>
// 	struct Tree_node {
// 		KeyType				key;
// 		ValueType			value;
// 		struct Tree_node* 	left;
// 		struct Tree_node* 	right;
// 		char			side; // left 'l', right 'r', root : 'h' ==> FOR DEBUG

// 		Tree_node()
// 		: key(KeyType()), value(ValueType()), left(NULL), right(NULL), side('h')
// 		{}

// 		Tree_node(KeyType key, ValueType val)
// 		: key(key), value(val), left(NULL), right(NULL), side('h')
// 		{}
// 	};

template<typename T> //T is a pair<Key, Val>
	struct Tree_node {
		T					value;
		struct Tree_node* 	parent;
		struct Tree_node* 	left;
		struct Tree_node* 	right;
		char				side; // left 'l', right 'r', root : 'h' ==> FOR DEBUG

		Tree_node()
		: value(T()), parent(NULL), left(NULL), right(NULL), side('h')
		{}

		Tree_node(const T& val)
		: value(val), parent(NULL), left(NULL), right(NULL), side('h')
		{}
	};


template<typename T> //T is a pair<Key, Val>
	class Map_iterator
	{

	public:
		typedef T									value_type;
		typedef value_type*							pointer;
		typedef value_type&							reference;
		typedef Tree_node<value_type>				node_type;
		typedef Map_iterator<value_type>			iterator;
		typedef std::bidirectional_iterator_tag		iterator_category;
		typedef ptrdiff_t							difference_type;
		


		Map_iterator(void) : p(NULL), sentinel(NULL) {}
		Map_iterator(node_type* x, node_type* sentinel) : p(x), sentinel(sentinel) {}
		Map_iterator(const iterator& copy) : p(copy.p), sentinel(copy.sentinel) {}
		~Map_iterator(void) {}

		iterator& operator=(const iterator& rhs)
		{
			this->p = rhs.p;
			this->sentinel = rhs.sentinel;
			return *this;
		}

		iterator& operator++()
		{
			if (p->right != sentinel)
			{ // find the leftmost child of the right node
				p = p->right;
				while (p->left != sentinel)
				{
					p = p->left;
				}
			}
			else
			{ // go upwards along right branches...  stop after the first left
				while (p->parent != sentinel && p->parent->right == p) 
				{
					p = p->parent;
				}
				if (p->right != p)
					p = p->parent;
			}
			return *this;
		}

		iterator operator++(int) { iterator tmp(*this);	operator++(); return tmp; }
		
		iterator& operator--()
		{
			if (p->left != sentinel)
			{ // find the rightmost child of the left node
				p = p->left;
				while (p->right != sentinel)
				{
					p = p->right;
				}
			}
			else
			{ // go upwards along left branches...  stop after the first right
				while (p->parent != sentinel && p->parent->left == p) 
				{
					p = p->parent;
				}
				p = p->parent;
			}
			return *this;
		}

		iterator operator--(int) {iterator tmp(*this); operator--(); return tmp;}

		bool operator==(const iterator& rhs) const { return p==rhs.p; }
		bool operator!=(const iterator& rhs) const { return p!=rhs.p; }

		reference operator*() const { return p->value; }
		value_type* operator->() const { return &(p->value); }

		node_type* base() const { return p; }
		node_type* get_sent() const { return sentinel; }

	private:
		node_type *p;
		node_type *sentinel;
	};

template<typename T> //T is a pair<Key, Val>
	class Map_const_iterator
	{

	public:
		typedef T									value_type;
		typedef const value_type*					pointer;
		typedef const value_type&					reference;
		typedef Tree_node<value_type>				node_type;
		typedef Map_iterator<value_type>			iterator;
		typedef Map_const_iterator<value_type>		const_iterator;
		typedef std::bidirectional_iterator_tag		iterator_category;
		typedef ptrdiff_t							difference_type;
		


		Map_const_iterator(void) : p(NULL), sentinel(NULL) {}
		Map_const_iterator(node_type* x, node_type* sentinel) : p(x), sentinel(sentinel) {}
		Map_const_iterator(const const_iterator& copy) : p(copy.p), sentinel(copy.sentinel) {}
		Map_const_iterator(const iterator& copy) : p(copy.base()), sentinel(copy.get_sent()) {}
		~Map_const_iterator(void) {}

		const_iterator& operator=(const const_iterator& rhs)
		{
			this->p = rhs.p;
			this->sentinel = rhs.sentinel;
			return *this;
		}

		const_iterator& operator++()
		{
			if (p->right != sentinel)
			{ // find the leftmost child of the right node
				p = p->right;
				while (p->left != sentinel)
				{
					p = p->left;
				}
			}
			else
			{ // go upwards along right branches...  stop after the first left
				while (p->parent != sentinel && p->parent->right == p) 
				{
					p = p->parent;
				}
				if (p->right != p)
					p = p->parent;
			}
			return *this;
		}

		const_iterator operator++(int) { const_iterator tmp(*this);	operator++(); return tmp; }
		
		const_iterator& operator--()
		{
			if (p->left != sentinel)
			{ // find the rightmost child of the left node
				p = p->left;
				while (p->right != sentinel)
				{
					p = p->right;
				}
			}
			else
			{ // go upwards along left branches...  stop after the first right
				while (p->parent != sentinel && p->parent->left == p) 
				{
					p = p->parent;
				}
				p = p->parent;
			}
			return *this;
		}

		const_iterator operator--(int) {const_iterator tmp(*this); operator--(); return tmp;}

		bool operator==(const const_iterator& rhs) const { return p==rhs.p; }
		bool operator!=(const const_iterator& rhs) const { return p!=rhs.p; }

		reference operator*() const { return p->value; }
		pointer operator->() const { return &(p->value); }

		// node_type* base() const { return p; }
		// node_type* sent() const { return sentinel; }

	private:
		const node_type *p;
		const node_type *sentinel;
	};


// Non-member function overloads
// ==================================	
// template<typename T>
// 	bool operator==(const Map_iterator<T>& lhs, const Map_iterator<T>& rhs)
// 	{ 
// 		return lhs.base() == rhs.base();
// 	}
// template<typename T>
// 	bool operator!=(const Map_iterator<T>& lhs, const Map_iterator<T>& rhs)
// 	{ 
// 		return lhs.base() != rhs.base();
// 	}
// template<typename T>
// 	bool operator<(const Map_iterator<T>& lhs, const Map_iterator<T>& rhs)
// 	{ 
// 		return lhs.base() < rhs.base();
// 	}
// template<typename T>
// 	bool operator>(const Map_iterator<T>& lhs, const Map_iterator<T>& rhs)
// 	{ 
// 		return lhs.base() > rhs.base();
// 	}
// template<typename T>
// 	bool operator<=(const Map_iterator<T>& lhs, const Map_iterator<T>& rhs)
// 	{ 
// 		return lhs.base() <= rhs.base();
// 	}
// template<typename T>
// 	bool operator>=(const Map_iterator<T>& lhs, const Map_iterator<T>& rhs)
// 	{ 
// 		return lhs.base() >= rhs.base();
// 	}
// template<typename T>
// 	typename Map_iterator<T>::difference_type operator-(const Map_iterator<T>& lhs, const Map_iterator<T>& rhs)
// 	{
// 		return lhs.base() - rhs.base();
// 	}
// template<typename T>
// 	Map_iterator<T> operator+(typename Map_iterator<T>::difference_type n , const Map_iterator<T>& rhs)
// 	{
// 		return rhs.base() + n;
// 	}

} // ft