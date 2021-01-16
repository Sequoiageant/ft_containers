/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_circular.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 11:07:21 by julnolle          #+#    #+#             */
/*   Updated: 2021/01/16 19:22:08 by julnolle         ###   ########.fr       */
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

struct				t_base
	{
		struct t_base	*prev;
		struct t_base	*next;
	};

template<typename T>
	struct				t_list // : t_base
	{
		struct t_list	*prev;
		struct t_list	*next;
		T				value;
	};

template<typename T>
	class iterator
	{

	public:
		typedef	size_t								size_type;
		typedef	t_list<T>							t_list;

		typedef ptrdiff_t							difference_type;
		typedef std::bidirectional_iterator_tag		iterator_category;
		typedef T									value_type;
		typedef T*									pointer;
		typedef T&									reference;


		iterator(void) {}
		iterator(t_list *x) : p(x) {}
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

	protected:
		t_list *p;
};


/*template<typename T>
	class reverse_iterator : public iterator<T>
	{

	public:
		typedef	size_t			size_type;
		typedef	t_list<T>		t_list;
		typedef	iterator<T>		iterator;


		reverse_iterator(void) {}
		reverse_iterator(t_list *x) : iterator(x) {}
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
		typedef	t_list<T>							t_list;

		typedef ptrdiff_t							difference_type;
		typedef std::bidirectional_iterator_tag		iterator_category;
		typedef	T									value_type;
		typedef const T*							pointer;
		typedef const T&							reference;

		const_iterator(void) {}
		const_iterator(t_list *x) : p(x) {}
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

	protected:
		const t_list *p;
};

/*template<typename T>
	class const_reverse_iterator : public const_iterator<T>
	{

	public:
		typedef	size_t				size_type;
		typedef	t_list<T>			t_list;
		typedef	const_iterator<T>	const_iterator;


		const_reverse_iterator(void) {}
		const_reverse_iterator(t_list *x) : const_iterator(x) {}
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
		
		typedef	t_list<T>								t_list;
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
		
		reverse_iterator rbegin(void) {/*std::cerr << this->_list->prev->value << std::endl;*/ return reverse_iterator(this->_list); }
		const_reverse_iterator rbegin(void) const {/*std::cerr << "rbegin const" << std::endl;*/ return const_reverse_iterator(this->_list); } //this->_list->prev
		
		reverse_iterator rend(void) { return reverse_iterator(this->_list->next); }
		const_reverse_iterator rend(void) const { return const_reverse_iterator(this->_list->next); } //this->_list

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
		t_list			*_list;
		size_type		_size;

		void init_list()
		{
			this->_list = new t_list;
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

		void	swap(t_list *next, t_list *prev) {
			t_list *tmp;

			tmp = next;
			next = prev;
			prev = tmp;
		}

		void	unlink_node(t_list *node)
		{
			node->prev->next = node->next;
			node->next->prev = node->prev;
			this->_size--;
		}

		void	delete_node(t_list *node)
		{
			if (node == this->_list)
				return;

			this->unlink_node(node);
			delete node;
		}

		void	insert_node(t_list *node, t_list *newElem)
		{
			node->prev->next = newElem;
			newElem->prev = node->prev;
			node->prev = newElem;
			newElem->next = node;
			this->_size++;
		}

		// void	insert_end(t_list *newElem)
		// {
		// 	if (this->_list)
		// 	{
		// 		t_list *copy = this->_list;
		// 		while(copy->next)
		// 		{
		// 			copy = copy->next;
		// 		}
		// 		newElem->prev = copy;
		// 		copy->next = newElem;
		// 	}
		// 	else
		// 		this->_list = newElem;
		// 	this->_size++;
		// }

/*		void	append_end(t_list *x)
		{
			if (this->_list)
			{
				t_list *copy = this->_list;
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

		t_list *new_node(const T& val)
		{
			t_list *newElem = new t_list;
			newElem->value = val;
			newElem->prev = NULL;
			newElem->next = NULL;
			return (newElem);
		}

/*		t_list	*find_node(iterator position)
		{
			t_list *node = this->_list;
			iterator it(this->begin());

			while (it != position)
			{
				node = node->next;
				++it;
			}
			return (node);
		}*/

		// t_list *front_ptr() const
		// {
		// 	return this->_list;
		// }

		t_list *last_ptr() const
		{
			t_list *cpy = this->_list;

			while (cpy->next)
			{
				cpy = cpy->next;
			}
			return cpy;
		}

		t_list *back_ptr() const
		{
			t_list *cpy = this->_list;

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