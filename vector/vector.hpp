/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 11:07:21 by julnolle          #+#    #+#             */
/*   Updated: 2021/01/18 16:23:19 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <string>
# include <iostream>

namespace ft
{

template<typename T>
	class iterator
	{

	public:
		typedef	size_t								size_type;

		typedef ptrdiff_t							difference_type;
		typedef std::bidirectional_iterator_tag		iterator_category;
		typedef T									value_type;
		typedef T*									pointer;
		typedef T&									reference;


		iterator(void) {}
		iterator(value_type *x) : p(x) {}
		iterator(const iterator& copy) : p(copy.p) {}
		iterator& operator++() {++p; return *this;}
		iterator& operator+=(size_type inc) {
			for (size_type i = 0; i < inc; ++i) { ++p; } return *this;
		}
		iterator operator++(int) {iterator tmp(*this); operator++(); return tmp;}
		iterator& operator--() {--p;return *this;}
		iterator& operator-=(size_type inc) {
			for (size_type i = 0; i < inc; ++i) { --p; } return *this;
		}
		iterator operator--(int) {iterator tmp(*this); operator--(); return tmp;}
		bool operator==(const iterator& rhs) const {return p==rhs.p;}
		bool operator!=(const iterator& rhs) const {return p!=rhs.p;}
		value_type& operator*() const {return *p;}
		value_type* operator->() const {return p;}
		~iterator(void) {}

	private:
		value_type *p;
};

template<typename T>
	class const_iterator
	{

	public:
		typedef	size_t								size_type;
		typedef ptrdiff_t							difference_type;
		typedef std::bidirectional_iterator_tag		iterator_category;
		typedef	T									value_type;
		typedef const T*							pointer;
		typedef const T&							reference;

		const_iterator(void) {}
		const_iterator(value_type *x) : p(x) {}
		const_iterator(const const_iterator& copy) : p(copy.p) {}
		const_iterator& operator++() {++p; return *this;}
		const_iterator& operator+=(size_type inc) {
			for (size_type i = 0; i < inc; ++i) { ++p; } return *this;
		}
		const_iterator operator++(int) {const_iterator tmp(*this); operator++(); return tmp;}
		const_iterator& operator--() {--p; return *this;}
		const_iterator& operator-=(size_type inc) {
			for (size_type i = 0; i < inc; ++i) { --p; } return *this;
		}
		const_iterator operator--(int) {const_iterator tmp(*this); operator--(); return tmp;}
		bool operator==(const const_iterator& rhs) const {return p==rhs.p;}
		bool operator!=(const const_iterator& rhs) const {return p!=rhs.p;}
		const value_type& operator*() const {return *p;}
		const value_type* operator->() const {return p;}
		~const_iterator(void) {}

	private:
		const value_type *p;
};	

template <typename T>
	class vector {

	public:
		typedef iterator<T>								iterator;
		typedef const_iterator<T>						const_iterator;
		typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;
		typedef std::reverse_iterator<iterator>			reverse_iterator;
		typedef	size_t									size_type;
		typedef T										value_type;
		typedef T*										pointer;
		typedef const T*								const_pointer;
		typedef T&										reference;
		typedef const T&								const_reference;

		explicit vector ();

		explicit vector (size_type n, const value_type& val = value_type());

	template <class InputIterator>
		vector (InputIterator first, InputIterator last);
		
		vector(vector const & copy);
		~vector(void);
		vector& operator=(vector const & rhs);

		iterator begin();
		const_iterator begin() const;
		iterator end();
		const_iterator end() const;
		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;
		reverse_iterator rend();
		const_reverse_iterator rend() const;
		size_type size() const;
		size_type max_size() const;
		void resize (size_type n, value_type val = value_type());
		size_type capacity() const;
		bool empty() const;
		void reserve (size_type n);
		reference operator[] (size_type n);
		const_reference operator[] (size_type n) const;
		reference at (size_type n);
		const_reference at (size_type n) const;
		reference front();
		const_reference front() const;
		reference back();
		const_reference back() const;

	template <class InputIterator>
		void assign (InputIterator first, InputIterator last);

		void assign (size_type n, const value_type& val);

		void push_back (const value_type& val);
		void pop_back();

		iterator insert (iterator position, const value_type& val);

		void insert (iterator position, size_type n, const value_type& val);

	template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last);

		iterator erase (iterator position);
		iterator erase (iterator first, iterator last);

		void swap (vector& x);

		void clear();

	private:
		T* data;

	};

template <class T>
	std::ostream & operator<<(std::ostream & o, vector<T> const & rhs);

template <class T>
	bool operator== (const vector<T>& lhs, const vector<T>& rhs);

template <class T>
	bool operator!= (const vector<T>& lhs, const vector<T>& rhs);

template <class T>
	bool operator<  (const vector<T>& lhs, const vector<T>& rhs);

template <class T>
	bool operator<= (const vector<T>& lhs, const vector<T>& rhs);

template <class T>
	bool operator>  (const vector<T>& lhs, const vector<T>& rhs);

template <class T>
	bool operator>= (const vector<T>& lhs, const vector<T>& rhs);

  template <class T>
	void swap (vector<T>& x, vector<T>& y);
}

#endif // VECTOR_HPP
