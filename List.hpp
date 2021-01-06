/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 11:07:21 by julnolle          #+#    #+#             */
/*   Updated: 2021/01/06 18:05:43 by julnolle         ###   ########.fr       */
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
	class List
	{

	private:

		typedef struct		s_list
		{
			T				value;
			struct s_list	*prev;
			struct s_list	*next;
		}					t_list;

	/*Attributs*/
		t_list				*_list;
		unsigned int		_size;

		void				ft_swap(T& val1, T& val2) {
			T tmp;
			tmp = val1;
			val1 = val2;
			val2 = tmp;
		}


	public:
		List(void);
		List(unsigned int size, const T &val);

		// template<typename InputIterator>
		// List(InputIterator first, InputIterator last);

		List(const List<T> & copy);
		~List(void);

		List<T> & operator=(List<T> const & rhs);

	// iterator begin();
	// const_iterator begin() const;
	// iterator end();
	// const_iterator end() const;
	// reverse_iterator rbegin();
	// const_reverse_iterator rbegin() const;
	// reverse_iterator rend();
	// const_reverse_iterator rend() const;

		// t_list* getList(void) const;

		bool empty() const;
		unsigned int size() const;
		unsigned int max_size() const;
		T& front();
		const T& front() const;
		T& back();
		const T& back() const;

		// template<typename InputIterator>
		// void assign (InputIterator first, InputIterator last);
		// void assign (unsigned int n, const T& val);

		void push_front (const T& val);
		void pop_front();
		void push_back (const T& val);
		void pop_back();
		
		// iterator insert (iterator position, const T& val);
		// void insert (iterator position, size_type n, const T& val);
		// template <class InputIterator>
		// void insert (iterator position, InputIterator first, InputIterator last);
		// iterator erase (iterator position);
		// iterator erase (iterator first, iterator last);

		void swap (List& x);
		void resize (size_t n, T val);
		void clear();
		
		// void splice (iterator position, list& x);
		// void splice (iterator position, list& x, iterator i);
		// void splice (iterator position, list& x, iterator first, iterator last);

		void remove (const T& val);

		template <class Predicate>
		void remove_if (Predicate pred);

		void unique();
		template <class BinaryPredicate>
		void unique (BinaryPredicate binary_pred);
		
		void sort();
		
		template <class Compare>
		void sort (Compare comp);
		
		void reverse();

		void displayList() const;
		void displayReverse() const;

	};

template<typename T>
	std::ostream & operator<<(std::ostream & o, List<T> const & rhs);
}

#include "List.ipp"

#endif // LIST_HPP