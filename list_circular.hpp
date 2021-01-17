/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_circular.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 11:07:21 by julnolle          #+#    #+#             */
/*   Updated: 2021/01/17 13:25:40 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LIST_CIRCULAR_HPP
# define LIST_CIRCULAR_HPP

# include <string>
# include <iostream>
# include <iterator>
# include <memory>
# include <cstddef>


namespace ft
{

struct			List_node_base
	{
		struct	List_node_base	*prev;
		struct	List_node_base	*next;
	};

struct			List_node_header //: public List_node_base
	{
		size_t 	*size;
	};

template<typename T>
	struct		List_node //: public List_node_base
	{
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


/*template<typename T>
	class reverse_iterator : public iterator<T>
	{

	public:
		typedef	size_t			size_type;
		typedef	List_node<T>		List_node;
		typedef	iterator<T>		iterator;


		reverse_iterator(void) {}
		reverse_iterator(List_node *x) : iterator(x) {}
		reverse_iterator(const reverse_iterator& copy) : iterator(copy) {}
		reverse_iterator& operator++() {this->p = this->p->prev;return *this;}
		reverse_iterator& operator+=(size_type inc) {
			for (size_type i = 0; i < inc; ++i) { this->p = this->p->prev; } return *this;
		}
		reverse_iterator operator++(int) {reverse_iterator tmp(*this); operator++(); return tmp;}
		reverse_iterator& operator--() {this->p = this->p->next;return *this;}
		reverse_iterator& operator-=(size_type inc) {
			for (size_type i = 0; i < inc; ++i) { this->p = this->p->next; } return *this;
		}
		reverse_iterator operator--(int) {reverse_iterator tmp(*this); operator--(); return tmp;}
		T& operator*() const {return this->p->value;}
		~reverse_iterator(void) {}
};
*/
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

/*template<typename T>
	class const_reverse_iterator : public const_iterator<T>
	{

	public:
		typedef	size_t				size_type;
		typedef	List_node<T>			List_node;
		typedef	const_iterator<T>	const_iterator;


		const_reverse_iterator(void) {}
		const_reverse_iterator(List_node *x) : const_iterator(x) {}
		const_reverse_iterator(const const_reverse_iterator& copy) : const_iterator(copy) {}
		const_reverse_iterator& operator++() {this->p = this->p->prev;return *this;}
		const_reverse_iterator& operator+=(size_type inc) {
			for (size_type i = 0; i < inc; ++i) { this->p = this->p->prev; } return *this;
		}
		const_reverse_iterator operator++(int) {const_reverse_iterator tmp(*this); operator++(); return tmp;}
		const_reverse_iterator& operator--() {this->p = this->p->next;return *this;}
		const_reverse_iterator& operator-=(size_type inc) {
			for (size_type i = 0; i < inc; ++i) { this->p = this->p->next; } return *this;
		}
		const_reverse_iterator operator--(int) {const_reverse_iterator tmp(*this); operator--(); return tmp;}
		~const_reverse_iterator(void) {}
};*/

template<typename T>
	class list
	{

	public:
		// class iterator;
		// class const_iterator;
		// class reverse_iterator;
		// class const_reverse_iterator;
		
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


		iterator begin(void) { /*std::cerr << "begin" << std::endl;*/ return iterator(this->_list->next); }
		const_iterator begin() const { /*std::cerr << "begin const" << std::endl;*/ return const_iterator(this->_list->next); }
		
		iterator end(void) { return iterator(this->_list); }
		const_iterator end() const { return const_iterator(this->_list); }
		
		reverse_iterator rbegin(void) {/*std::cerr << this->_list->prev->value << std::endl;*/ return reverse_iterator(end()); }
		const_reverse_iterator rbegin(void) const {/*std::cerr << "rbegin const" << std::endl;*/ return const_reverse_iterator(end()); } //this->_list->prev
		
		reverse_iterator rend(void) { return reverse_iterator(begin()); }
		const_reverse_iterator rend(void) const { return const_reverse_iterator(begin()); } //this->_list

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
		// size_type		_size;

		void init_list()
		{
			this->_list = new List_node;
			this->_list->value = T();
			this->_list->prev = this->_list;
			this->_list->next = this->_list;
		}		

		void reset_list()
		{
			this->clear();
			this->init_list();
		}

		void	swap_values(T& val1, T& val2) {
			T tmp;
			tmp = val1;
			val1 = val2;
			val2 = tmp;
		}

		void	swap(List_node *next, List_node *prev) {
			List_node *tmp;

			tmp = next;
			next = prev;
			prev = tmp;
		}

		void	unlink_node(List_node *node)
		{
			node->prev->next = node->next;
			node->next->prev = node->prev;
			// this->_size--;
		}

		void	delete_node(List_node *node)
		{
			if (node == this->_list)
				return;

			this->unlink_node(node);
			delete node;
		}

		void	insert_node(List_node *node, List_node *newElem)
		{
			node->prev->next = newElem;
			newElem->prev = node->prev;
			node->prev = newElem;
			newElem->next = node;
			// this->_size++;
		}

		// void	insert_end(List_node *newElem)
		// {
		// 	if (this->_list)
		// 	{
		// 		List_node *copy = this->_list;
		// 		while(copy->next)
		// 		{
		// 			copy = copy->next;
		// 		}
		// 		newElem->prev = copy;
		// 		copy->next = newElem;
		// 	}
		// 	else
		// 		this->_list = newElem;
		//	// this->_size++;
		// }

/*		void	append_end(List_node *x)
		{
			if (this->_list)
			{
				List_node *copy = this->_list;
				while(copy->next)
				{
					copy = copy->next;
				}
				x->prev = copy;
				copy->next = x;
			}
			else
				this->_list = x;
		}*/

		List_node *new_node(const T& val)
		{
			List_node *newElem = new List_node;
			newElem->value = val;
			newElem->prev = NULL;
			newElem->next = NULL;
			return (newElem);
		}

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
		}*/

		// List_node *front_ptr() const
		// {
		// 	return this->_list;
		// }

		List_node *last_ptr() const
		{
			List_node *cpy = this->_list;

			while (cpy->next)
			{
				cpy = cpy->next;
			}
			return cpy;
		}

		List_node *back_ptr() const
		{
			List_node *cpy = this->_list;

			while (cpy)
			{
				cpy = cpy->next;
			}
			return cpy;
		}
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

#include "list_circular.ipp"

#endif // LIST_CIRCULAR_HPP