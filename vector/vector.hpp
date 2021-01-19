/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 11:07:21 by julnolle          #+#    #+#             */
/*   Updated: 2021/01/19 17:08:26 by julnolle         ###   ########.fr       */
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


		iterator(void) : p(NULL) {}
		iterator(value_type *x) : p(x) {}
		iterator(const iterator& copy) : p(copy.p) {}
		iterator& operator++() { ++p; return *this;}
		iterator& operator+=(difference_type inc) { p += inc; return *this; }
		iterator operator++(int) {iterator tmp(*this); operator++(); return tmp;}
		iterator& operator--() {--p;return *this;}
		iterator& operator-=(difference_type inc) { p -= inc; return *this; }
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

	const_iterator(void) : p(NULL) {}
	const_iterator(value_type *x) : p(x) {}
	const_iterator(const const_iterator& copy) : p(copy.p) {}
	const_iterator& operator++() {++p; return *this;}
	const_iterator& operator+=(difference_type inc) { p += inc; return *this; }
	const_iterator operator++(int) {const_iterator tmp(*this); operator++(); return tmp;}
	const_iterator& operator--() {--p; return *this;}
	const_iterator& operator-=(difference_type inc) { p -= inc; return *this; }
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


	explicit vector () : _array(new T[0]), _size(0), _capacity(0)
	{
		return;
	}

	explicit vector (size_type n, const value_type& val = value_type()) : _array(new T[n]), _size(n), _capacity(n)
	{
		for (size_type i = 0; i < n; ++i)
		{
			this->_array[i] = val;
		}
	}

	template <class InputIterator>
	vector (InputIterator first, InputIterator last) :  _array(NULL), _size(0), _capacity(0)
	{
		InputIterator it = first;
		while (it != last)
		{
			this->_size++;
			this->_capacity++;
			++it;
		}
		this->_array = new T[this->_capacity];

		for (size_type i = 0; i < this->_size; ++i)
		{
			this->_array[i] = *first;
			++first;
		}
	}

	vector(vector const & copy)
	: _array(new T[copy._capacity]), _size(copy._size), _capacity(copy._capacity)
	{
		for (size_type i = 0; i < this->_size; ++i)
		{
			this->_array[i] = copy[i];
		}
	}

	~vector()
	{
		this->clear();
	}

	vector& operator=(vector const & rhs)
	{
		this->clear();
		this->_size = rhs._size;
		this->_capacity = rhs._capacity;
		this->_array = new T[this->_capacity];
		for (size_type i = 0; i < this->_size; ++i)
		{
			this->_array[i] = rhs[i];
		}
		return *this;
	}

	iterator begin() { return iterator(this->_array); }
	const_iterator begin() const { return const_iterator(this->_array); }

	iterator end() { return iterator(&this->_array[this->_size]); }
	const_iterator end() const { return const_iterator(&this->_array[this->_size]); }

	reverse_iterator rbegin(void) { return reverse_iterator(this->end()); }
	const_reverse_iterator rbegin(void) const { return const_reverse_iterator(this->end()); }
	
	reverse_iterator rend(void) { return reverse_iterator(this->begin()); }
	const_reverse_iterator rend(void) const { return const_reverse_iterator(this->begin()); }

	size_type size() const
	{
		return size_type(&this->_array[this->_size] - this->_array);
		// return this->_size;
	}
	size_type max_size() const
	{
		std::allocator<value_type> a;
		return a.max_size();
	}
	void resize (size_type n, value_type val = value_type());
	size_type capacity() const;
	bool empty() const;
	void reserve (size_type n);

	reference operator[] (size_type n)
	{
		return this->_array[n];
	}

	const_reference operator[] (size_type n) const
	{
		return this->_array[n];
	}

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

	void clear()
	{
		delete [] this->_array;
	}

	void displayVec() const {
		for (size_type i = 0; i < this->_size; ++i)
		{
			std::cout << this->_array[i] << ' ';
		}
		std::cout << std::endl;
	}

private:
	T*			_array;
	size_type	_size;
	size_type	_capacity;

};

// Non-member function overloads
// ==================================	

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
// Non-member function overloads END
// ==================================

#endif // VECTOR_HPP
