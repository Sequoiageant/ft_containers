/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 11:07:21 by julnolle          #+#    #+#             */
/*   Updated: 2021/01/12 11:38:31 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include <string>
# include <iostream>
# include <iterator>


namespace ft
{

template<typename T>
	struct				t_list
	{
		T				value;
		struct t_list	*prev;
		struct t_list	*next;
	};

template<typename T>
	class List
	{

	public:
		typedef	t_list<T>	t_list;
		typedef	size_t		size_type;

		class iterator;

		List(void);
		List(unsigned int size, const T &val);

		template<typename InputIterator>
		List(InputIterator first, InputIterator last);

		List(const List<T> & copy);
		~List(void);

		List<T> & operator=(List<T> const & rhs);


		iterator begin(void) { return iterator(this->_list); }
	// const_iterator begin() const;
		iterator end(void) { return iterator(this->back_ptr()); }
	// const_iterator end() const;
	// reverse_iterator rbegin();
	// const_reverse_iterator rbegin() const;
	// reverse_iterator rend();
	// const_reverse_iterator rend() const;

		bool empty() const;
		unsigned int size() const;
		unsigned int max_size() const;
		T& front();
		const T& front() const;
		T& back();
		const T& back() const;

		template<typename InputIterator>
		void assign (InputIterator first, InputIterator last);
		void assign (unsigned int n, const T& val);

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

		void swap (List& x);
		void resize (size_type n, T val);
		void clear();

		void splice (iterator position, List<T>& x);
		void splice (iterator position, List<T>& x, iterator i);
		void splice (iterator position, List<T>& x, iterator first, iterator last);

		void remove (const T& val);

		template <class Predicate>
		void remove_if (Predicate pred);

		void unique();
		template <class BinaryPredicate>
		void unique (BinaryPredicate binary_pred);


		void merge (List& x);
		template <class Compare>
		void merge (List& x, Compare comp);

		void sort();

		template <class Compare>
		void sort (Compare comp);

		void reverse();

		void displayList();
		void displayReverse() const;

	private:

	/*Attributs*/
		t_list				*_list;
		unsigned int		_size;

		void	swap_values(T& val1, T& val2) {
			T tmp;
			tmp = val1;
			val1 = val2;
			val2 = tmp;
		}

		void	unlink_node(t_list *node)
		{
			if (node->prev)
				node->prev->next = node->next;
			else
				this->_list = this->_list->next;
			
			if (node->next)
				node->next->prev = node->prev;
			this->_size--;
		}

/*		void	unlink_node(t_list *node)
		{
			if (node->next == NULL)
				node->prev->next = NULL;
			else if (node->prev == NULL)
			{
				node->next->prev = NULL;
				this->_list = this->_list->next;
			}
			if (node->next)
			{
				node->prev->next = node->next;
				node->next->prev = node->prev;
			}
			this->_size--;
		}*/

		void	delete_node(t_list *node)
		{
			this->unlink_node(node);
			delete node;
		}

		void	insert_node(t_list *node, t_list *newElem)
		{
			if (node->prev == NULL)
				this->_list = newElem;
			else
				node->prev->next = newElem;

			newElem->prev = node->prev;
			node->prev = newElem;
			newElem->next = node;
			this->_size++;
		}

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

		t_list *front_ptr()
		{
			return this->_list;
		}

		t_list *back_ptr()
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
	class List<T>::iterator : public std::iterator<std::bidirectional_iterator_tag, T> {

	private:
		t_list *p;

	public:
		iterator(void) {}
		iterator(t_list *x) : p(x) {}
		iterator(const iterator& copy) : p(copy.p) {}
		iterator& operator++() {p = p->next;return *this;}
		iterator& operator+=(size_type inc) {
			for (size_type i = 0; i < inc; ++i) { p = p->next; }return *this;}
		iterator operator++(int) {iterator tmp(*this); operator++(); return tmp;}
		iterator& operator--() {p = p->prev;return *this;}
		iterator& operator-=(size_type inc) {
			for (size_type i = 0; i < inc; ++i) { p = p->prev; }return *this;}
		iterator operator--(int) {iterator tmp(*this); operator--(); return tmp;}
		bool operator==(const iterator& rhs) const {return p==rhs.p;}
		bool operator!=(const iterator& rhs) const {return p!=rhs.p;}
		T& operator*() const {return p->value;}
		T* operator->() const {return &p->value;}
		~iterator(void) {}
	};


template<typename T>
	std::ostream & operator<<(std::ostream & o, List<T> const & rhs);
}

#include "List.ipp"

#endif // LIST_HPP