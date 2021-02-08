/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 10:55:32 by julnolle          #+#    #+#             */
/*   Updated: 2021/02/08 19:43:21 by julnolle         ###   ########.fr       */
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
		typedef T*									pointer;
		typedef T&									reference;
		typedef Tree_node<value_type>				node_type;
		typedef Map_iterator<value_type>			iterator;
		typedef std::bidirectional_iterator_tag		iterator_category;
		typedef ptrdiff_t							difference_type;
		


		Map_iterator(void) : p(NULL) {}
		Map_iterator(node_type *x) : p(x) {}
		Map_iterator(const iterator& copy) : p(copy.p) {}
		iterator& operator=(const iterator& rhs) { this->p = rhs.p; return *this;}
		// iterator& operator++()
		// {
		// 	if (p->right != NULL) {
		// // find the leftmost child of the right node
		// 		p = p->right;
		// 		while (p->left != NULL)
		// 		{
		// 			p = p->left;
		// 		}
		// 	}
		// 	else {
		//  // go upwards along right branches...  stop after the first left
		// 		while (p->parent != NULL && p->parent->right == p) 
		// 		{
		// 			p = p->parent;
		// 		}
		// 		p = p->parent;
		// 	}
		// 	return *this;
		// }
		iterator& operator++()
		{
			std::cerr << "OPERATOR++" << std::endl;
			if (p->right != NULL) {
				p = p->right;
				while (p->left != NULL)
					p = p->left;
			}
			else {
				std::cerr << "AVANT" << std::endl;
				node_type* tmp = p->parent;
				while (p == tmp->right) {
				std::cerr << "APRES" << std::endl;
					p = tmp;
					tmp = tmp->parent;
				}
				if (p->right != tmp)
					p = tmp;
			}
			return *this;
		}
		iterator& operator+=(difference_type n) {p += n; return *this; }
		iterator operator++(int) {iterator tmp(*this); operator++(); return tmp;}
		iterator& operator--() {--p;return *this;}
		iterator& operator-=(difference_type n) { p -= n; return *this; }
		iterator operator--(int) {iterator tmp(*this); operator--(); return tmp;}
		iterator operator+(difference_type n) { return iterator(p + n); }
		iterator operator-(difference_type n) { return iterator(p - n); }
		reference operator[](difference_type n) { return p[n]; }
		bool operator==(const iterator& rhs) const { return p==rhs.p; }
		bool operator!=(const iterator& rhs) const { return p!=rhs.p; }
		bool operator<(const iterator& rhs) const { return p < rhs.p; }
		reference operator*() const { return *p; }
		value_type* operator->() const { return &(p->value); }
		~Map_iterator(void) {}

		const pointer& base() const { return p; }

	private:
		node_type *p;
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