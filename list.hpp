/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 11:07:21 by julnolle          #+#    #+#             */
/*   Updated: 2021/01/18 14:48:54 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include <string>
# include <iostream>
# include <iterator>
# include <cstddef>


namespace ft
{

/*struct			List_node_base
	{
		struct	List_node_base	*prev;
		struct	List_node_base	*next;
	};

struct			List_node_header //: public List_node_base
	{
		List_node_header();
		size_t 	*size;
	};*/

template<typename T>
	struct		List_node //: public List_node_base
	{
		List_node(){
			this->value = T();
			this->prev = this->next = this;
		};

		List_node(const T& val){	
			this->value = val;
			this->prev = this->next = this;
		};

		void	reverse() {
			List_node *tmp;

			tmp = this->next;
			this->next = this->prev;
			prev = tmp;
		}

		void unhook() {
			this->prev->next = this->next;
			this->next->prev = this->prev;
		}

		struct	List_node	*prev;
		struct	List_node	*next;
		T					value;
	};

template<typename T>
	class iterator
	{

	public:
		typedef	size_t								size_type;
		typedef	List_node<T>						List_node;

		typedef ptrdiff_t							difference_type;
		typedef std::bidirectional_iterator_tag		iterator_category;
		typedef T									value_type;
		typedef T*									pointer;
		typedef T&									reference;


		iterator(void) {}
		iterator(List_node *x) : p(x) {}
		iterator(const iterator& copy) : p(copy.p) {}
		iterator& operator++() {p = p->next;return *this;}
		iterator& operator+=(size_type inc) {
			for (size_type i = 0; i < inc; ++i) { p = p->next; } return *this;
		}
		iterator operator++(int) {iterator tmp(*this); operator++(); return tmp;}
		iterator& operator--() {p = p->prev;return *this;}
		iterator& operator-=(size_type inc) {
			for (size_type i = 0; i < inc; ++i) { p = p->prev; } return *this;
		}
		iterator operator--(int) {iterator tmp(*this); operator--(); return tmp;}
		bool operator==(const iterator& rhs) const {return p==rhs.p;}
		bool operator!=(const iterator& rhs) const {return p!=rhs.p;}
		value_type& operator*() const {return p->value;}
		value_type* operator->() const {return &(p->value);}
		~iterator(void) {}

	private:
		List_node *p;
};

template<typename T>
	class const_iterator
	{

	public:
		typedef	size_t								size_type;
		typedef	List_node<T>						List_node;

		typedef ptrdiff_t							difference_type;
		typedef std::bidirectional_iterator_tag		iterator_category;
		typedef	T									value_type;
		typedef const T*							pointer;
		typedef const T&							reference;

		const_iterator(void) {}
		const_iterator(List_node *x) : p(x) {}
		const_iterator(const const_iterator& copy) : p(copy.p) {}
		const_iterator& operator++() {p = p->next;return *this;}
		const_iterator& operator+=(size_type inc) {
			for (size_type i = 0; i < inc; ++i) { p = p->next; } return *this;
		}
		const_iterator operator++(int) {const_iterator tmp(*this); operator++(); return tmp;}
		const_iterator& operator--() {p = p->prev;return *this;}
		const_iterator& operator-=(size_type inc) {
			for (size_type i = 0; i < inc; ++i) { p = p->prev; } return *this;
		}
		const_iterator operator--(int) {const_iterator tmp(*this); operator--(); return tmp;}
		bool operator==(const const_iterator& rhs) const {return p==rhs.p;}
		bool operator!=(const const_iterator& rhs) const {return p!=rhs.p;}
		const value_type& operator*() const {return p->value;}
		const value_type* operator->() const {return &(p->value);}
		~const_iterator(void) {}

	private:
		const List_node *p;
};

template<typename T>
	class list
	{

	public:
		typedef	List_node<T>							List_node;
		typedef iterator<T>								iterator;
		typedef const_iterator<T>						const_iterator;
		typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;
		typedef std::reverse_iterator<iterator>			reverse_iterator;
		typedef	size_t									size_type;

		list(void);
		list(size_type size, const T &val);

		template<typename InputIterator>
		list(InputIterator first, InputIterator last);

		list(const list<T> & copy);
		~list(void);

		list<T> & operator=(list<T> const & rhs);


		iterator begin(void) { return iterator(this->_list->next); }
		const_iterator begin() const { return const_iterator(this->_list->next); }
		
		iterator end(void) { return iterator(this->_list); }
		const_iterator end() const { return const_iterator(this->_list); }
		
		reverse_iterator rbegin(void) { return reverse_iterator(this->end()); }
		const_reverse_iterator rbegin(void) const { return const_reverse_iterator(this->end()); } //this->_list->prev
		
		reverse_iterator rend(void) { return reverse_iterator(this->begin()); }
		const_reverse_iterator rend(void) const { return const_reverse_iterator(this->begin()); } //this->_list

		bool empty() const;
		size_type size() const;
		size_type max_size() const;
		T& front();
		const T& front() const;
		T& back();
		const T& back() const;

		template<typename InputIterator>
		void assign (InputIterator first, InputIterator last);
		void assign (size_type n, const T& val);

		void push_front (const T& val);
		void pop_front();
		void push_back (const T& val);
		void pop_back();

		iterator insert (iterator position, const T& val);
		void insert (iterator position, int n, const T& val);
		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last);
		iterator erase (iterator position);
		iterator erase (iterator first, iterator last);

		void swap (list& x);
		void resize (size_type n, T val);
		void clear();

		void splice (iterator position, list<T>& x);
		void splice (iterator position, list<T>& x, iterator i);
		void splice (iterator position, list<T>& x, iterator first, iterator last);

		void remove (const T& val);

		template <class Predicate>
		void remove_if (Predicate pred);

		void unique();
		template <class BinaryPredicate>
		void unique (BinaryPredicate binary_pred);


		void merge (list& x);
		template <class Compare>
		void merge (list& x, Compare comp);

		void sort();

		template <class Compare>
		void sort (Compare comp);

		void reverse();

		void displaylist();
		void displayReverse() const;

	private:

		/*Attributs*/
		List_node		*_list;

		/*Member functions*/
		List_node *new_node(const T& val)
		{
			return (new List_node(val));
		}

		void	insert_node(List_node *node, List_node *newElem)
		{
			node->prev->next = newElem;
			newElem->prev = node->prev;
			node->prev = newElem;
			newElem->next = node;
		}

		void	delete_node(List_node *node)
		{
			if (node == this->_list)
				return;

			node->unhook();
			delete node;
		}

/*		void	unlink_node(List_node *node)
		{
			node->prev->next = node->next;
			node->next->prev = node->prev;
		}*/

/*		List_node	*find_node(iterator position)
		{
			List_node *node = this->_list;
			iterator it(this->begin());

			while (it != position)
			{
				node = node->next;
				++it;
			}
			return (node);
		}
*/

	};

template<typename T>
	std::ostream & operator<<(std::ostream & o, list<T> const & rhs);

template<typename T>
	bool operator== (const list<T>& lhs, const list<T>& rhs)
	{
		typename list<T>::const_iterator end1 = lhs.end();
		typename list<T>::const_iterator end2 = rhs.end();
		typename list<T>::const_iterator first1 = lhs.begin();
		typename list<T>::const_iterator first2 = rhs.begin();

		while (first1 != end1 && first2 != end2 && *first1 == *first2)
		{
			++first1;
			++first2;
		}
		return (first1 == end1 && first2 == end2);
	}

template<typename T>
	bool operator!= (const list<T>& lhs, const list<T>& rhs)
	{
		return !(lhs == rhs);
	}

template<typename T>
	bool operator<  (const list<T>& lhs, const list<T>& rhs)
	{
		typename list<T>::const_iterator end1 = lhs.end();
		typename list<T>::const_iterator end2 = rhs.end();
		typename list<T>::const_iterator first1 = lhs.begin();
		typename list<T>::const_iterator first2 = rhs.begin();

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

template<typename T>
bool operator<= (const list<T>& lhs, const list<T>& rhs)
{
	return !(rhs < lhs);
}

template<typename T>
bool operator>  (const list<T>& lhs, const list<T>& rhs)
{
	return (rhs < lhs);
}

template<typename T>
bool operator>= (const list<T>& lhs, const list<T>& rhs)
{
	return !(lhs < rhs);
}

template<typename T>
void swap (list<T>& x, list<T>& y)
{
	x.swap(y);
}


}

#include "list.ipp"

#endif // LIST_HPP