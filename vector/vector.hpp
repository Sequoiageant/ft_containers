/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 11:07:21 by julnolle          #+#    #+#             */
/*   Updated: 2021/01/28 17:04:11 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <string>
# include <iostream>
# include <cstddef>
# include <exception>
# include <sstream>
# include <cstring>
# include "integral_traits.hpp"
# include "functional.hpp"

namespace ft
{

template<typename T>
	class Vector_iterator
	{

	public:
		typedef	size_t								size_type;

		typedef Vector_iterator<T>					iterator;
		typedef ptrdiff_t							difference_type;
		typedef std::bidirectional_iterator_tag		iterator_category;
		typedef T									value_type;
		typedef T*									pointer;
		typedef T&									reference;


		Vector_iterator(void) : p(NULL) {}
		Vector_iterator(pointer x) : p(x) {}
		Vector_iterator(const iterator& copy) : p(copy.p) {}
		iterator& operator=(const iterator& rhs) { this->p = rhs.p; return *this;}
		iterator& operator++() { ++p; return *this;}
		iterator& operator+=(difference_type n) { p += n; return *this; }
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
		pointer operator->() const { return p; }
		~Vector_iterator(void) {}

		const pointer& base() const { return p; }

	private:
		value_type *p;
	};

// Non-member function overloads
// ==================================	
template<typename T>
	bool operator==(const Vector_iterator<T>& lhs, const Vector_iterator<T>& rhs)
	{ 
		return lhs.base() == rhs.base();
	}
template<typename T>
	bool operator!=(const Vector_iterator<T>& lhs, const Vector_iterator<T>& rhs)
	{ 
		return lhs.base() != rhs.base();
	}
template<typename T>
	bool operator<(const Vector_iterator<T>& lhs, const Vector_iterator<T>& rhs)
	{ 
		return lhs.base() < rhs.base();
	}
template<typename T>
	bool operator>(const Vector_iterator<T>& lhs, const Vector_iterator<T>& rhs)
	{ 
		return lhs.base() > rhs.base();
	}
template<typename T>
	bool operator<=(const Vector_iterator<T>& lhs, const Vector_iterator<T>& rhs)
	{ 
		return lhs.base() <= rhs.base();
	}
template<typename T>
	bool operator>=(const Vector_iterator<T>& lhs, const Vector_iterator<T>& rhs)
	{ 
		return lhs.base() >= rhs.base();
	}
template<typename T>
	typename Vector_iterator<T>::difference_type operator-(const Vector_iterator<T>& lhs, const Vector_iterator<T>& rhs)
	{
		return lhs.base() - rhs.base();
	}
template<typename T>
	Vector_iterator<T> operator+(typename Vector_iterator<T>::difference_type n , const Vector_iterator<T>& rhs)
	{
		return rhs.base() + n;
	}

// ==================================	
// Non-member function overloads END

template<typename T>
	class Vector_const_iterator
	{

	public:
		typedef	size_t								size_type;
		typedef Vector_const_iterator<T>			const_iterator;
		typedef Vector_iterator<T>					iterator;

		typedef ptrdiff_t							difference_type;
		typedef std::bidirectional_iterator_tag		iterator_category;
		typedef	T									value_type;
		typedef const T*							pointer;
		typedef const T&							reference;

		Vector_const_iterator(void) : p(NULL) {}
		Vector_const_iterator(value_type *x) : p(x) {}
		Vector_const_iterator(const const_iterator& copy) : p(copy.p) {}
		Vector_const_iterator(const iterator& copy) : p(copy.p) {}
		const_iterator& operator=(const iterator& rhs) { this->p = rhs.p; return *this;}
		const_iterator& operator=(const const_iterator& rhs) { this->p = rhs.p; return *this;}
		const_iterator& operator++() {++p; return *this;}
		const_iterator& operator+=(difference_type n) { p += n; return *this; }
		const_iterator operator++(int) {const_iterator tmp(*this); operator++(); return tmp;}
		const_iterator operator+(difference_type n) { return const_iterator(p + n); }
		const_iterator operator-(difference_type n) { return const_iterator(p - n); }
		reference operator[](difference_type n) { return p[n]; }
		const_iterator& operator--() {--p; return *this;}
		const_iterator& operator-=(difference_type n) { p -= n; return *this; }
		const_iterator operator--(int) {const_iterator tmp(*this); operator--(); return tmp;}
		bool operator==(const const_iterator& rhs) const {return p==rhs.p;}
		bool operator!=(const const_iterator& rhs) const {return p!=rhs.p;}
		reference operator*() const {return *p;}
		pointer operator->() const {return p;}
		~Vector_const_iterator(void) {}

		const pointer& base() const { return p; }

	private:
		const value_type *p;
	};

// Non-member const_iterator function overloads
// ==================================	
template<typename T>
	bool operator==(const Vector_const_iterator<T>& lhs, const Vector_const_iterator<T>& rhs)
	{ 
		return lhs.base() == rhs.base();
	}
template<typename T>
	bool operator!=(const Vector_const_iterator<T>& lhs, const Vector_const_iterator<T>& rhs)
	{ 
		return lhs.base() != rhs.base();
	}
template<typename T>
	bool operator<(const Vector_const_iterator<T>& lhs, const Vector_const_iterator<T>& rhs)
	{ 
		return lhs.base() < rhs.base();
	}
template<typename T>
	bool operator>(const Vector_const_iterator<T>& lhs, const Vector_const_iterator<T>& rhs)
	{ 
		return lhs.base() > rhs.base();
	}
template<typename T>
	bool operator<=(const Vector_const_iterator<T>& lhs, const Vector_const_iterator<T>& rhs)
	{ 
		return lhs.base() <= rhs.base();
	}
template<typename T>
	bool operator>=(const Vector_const_iterator<T>& lhs, const Vector_const_iterator<T>& rhs)
	{ 
		return lhs.base() >= rhs.base();
	}
template<typename T>
	typename Vector_const_iterator<T>::difference_type operator-(const Vector_const_iterator<T>& lhs, const Vector_const_iterator<T>& rhs)
	{
		return lhs.base() - rhs.base();
	}
template<typename T>
	Vector_const_iterator<T> operator+(typename Vector_iterator<T>::difference_type n , const Vector_const_iterator<T>& rhs)
	{
		return rhs.base() + n;
	}


// ==================================	
// Non-member function overloads END

template <typename T>
	class vector {

	public:
		typedef Vector_iterator<T>						iterator;
		typedef Vector_const_iterator<T>				const_iterator;
		typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;
		typedef std::reverse_iterator<iterator>			reverse_iterator;
		typedef	size_t									size_type;
		typedef T										value_type;
		typedef T*										pointer;
		typedef const T*								const_pointer;
		typedef T&										reference;
		typedef const T&								const_reference;


		explicit vector () : _capacity(0), _size(0), _array(NULL)
		{
			// buffer(static_cast<T*>(::operator new(sizeof(T) * capacity)))
			// std::cout << "FT VECTOR" << std::endl;
			return;
		}

		explicit vector (size_type n, const value_type& val = value_type()) : _capacity(n), _size(n), _array(static_cast<T*>(::operator new(sizeof(T) * _capacity)))
		{
			for (size_type i = 0; i < n; ++i)
			{
				new (static_cast<void*>(this->_array + i)) value_type(val);
				// this->_array[i] = val;
			}
		}

	template <class InputIterator>
		vector (InputIterator first, typename ft::enable_if< !ft::is_integral< InputIterator >::value, InputIterator >::type last)
		: _capacity(last - first), _size(_capacity), _array(static_cast<T*>(::operator new(sizeof(T) * _capacity)))
		{
			size_type i = 0;
			while (first != last)
			{
				new (static_cast<void*>(this->_array + i)) value_type(*first);
				++first;
				++i;
			}
		}

		vector(vector const & copy)
		: _capacity(copy._capacity), _size(copy._size), _array(static_cast<T*>(::operator new(sizeof(T) * _capacity)))
		{
			for (size_type i = 0; i < this->_size; ++i)
			{
				new (static_cast<void*>(this->_array + i)) value_type(copy._array[i]);
			}
		}

		~vector()
		{
			this->clear();
			delete this->_array;
		}

		vector& operator=(vector const & rhs)
		{
			// std::cout << "ASSIGNATION" << std::endl;
			this->assign(rhs.begin(), rhs.end());

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
			// return size_type(&this->_array[this->_size] - this->_array);
			return this->_size;
		}

		size_type max_size() const
		{
			std::allocator<value_type> a;
			return a.max_size();
		}

		void resize (size_type n, value_type val = value_type())
		{
			if (n > this->capacity())
			{
				T* tmp = reallocate_tab(n, val);
				this->clear();
				delete this->_array;
				this->_array = tmp;
				this->_size = n;
			}
			else if (n > this->_size)
			{
				while (this->_size < n)
				{
					new (static_cast<void*>(this->_array + this->_size)) value_type(val);
					++this->_size;
				}
			}
			else
			{
				while (this->_size > n)
				{
					this->_array[this->_size].~value_type();
					--this->_size;
				}
			}
		}

		size_type capacity() const
		{
			return this->_capacity;
		}
		bool empty() const
		{
			return this->begin() == this->end();
		}

		void reserve (size_type n)
		{
			// std::cout << "RESERVE" << std::endl;
			if ( n > this->max_size())
				throw std::length_error("cannot reserve THAT size !");
			if (n > this->capacity())
			{
				this->_capacity = n;
				T *tmp = static_cast<T*>(::operator new(sizeof(T) * n));
				for (size_type i = 0; i < this->size(); ++i)
				{
					new (static_cast<void*>(tmp + i)) value_type(this->_array[i]);
				}
				this->destroy_array();
				delete (this->_array);
				this->_array = tmp;
			}
		}

		reference operator[] (size_type n)
		{
			return this->_array[n];
		}

		const_reference operator[] (size_type n) const
		{
			return this->_array[n];
		}

		reference at (size_type n)
		{
			this->range_check(n);
			return this->_array[n];
		}

		const_reference at (size_type n) const
		{
			this->range_check(n);
			return this->_array[n];
		}

		reference front()
		{
			return *this->_array;
		}

		const_reference front() const
		{
			return *this->_array;
		}

		reference back()
		{
			return this->_array[this->_size - 1];
		}

		const_reference back() const
		{
			return this->_array[this->_size - 1];
		}

	template <class InputIterator>
		void assign (InputIterator first, typename ft::enable_if< !ft::is_integral< InputIterator >::value, InputIterator >::type last) // NEEDS enable_if
		{
			size_type range = static_cast<size_type>(last - first);
			if (range > this->capacity())
			{
				this->destroy_array();
				delete this->_array;
				this->_array = static_cast<T*>(::operator new(sizeof(value_type) * range));
				this->_capacity = range;
			}
			else
			{
				for (size_type i = 0; i < this->_size; ++i)
				{
					this->_array[i].~T();
				}
			}
			for (size_type i = 0; i < range; ++i)
			{
				new (static_cast<void*>(this->_array + i)) T(*first);
				++first;
			}
			this->_size = range;
		}

		void assign (size_type n, const value_type& val)
		{
			if (n > this->capacity())
			{
				this->clear();
				delete this->_array;
				this->_array = static_cast<T*>(::operator new(sizeof(T) * n));
				this->_capacity = n;
			}
			for (size_type i = 0; i < n; ++i)
			{
				this->_array[i] = val;
				// new (static_cast<void*>(this->_array + i)) T(val);
			}
			for (size_type i = n; i < this->_size; ++i)
			{
				this->_array[i].~T();
			}
			this->_size = n;
		}

		void push_back (const value_type& val)
		{
			resize(this->size() + 1, val);
		}

		void pop_back()
		{
			resize(this->size() - 1);
			// this->back().~T();
			// --this->_size;
		}

		iterator insert (iterator position, const value_type& val)
		{
			this->insert (position, 1, val);
			return (position);
		}

		void insert (iterator position, size_type n, const value_type& val)
		{
			size_type pos = position - this->begin();

			this->resize(this->_size + n);
			iterator end = this->end() - 1;
			while (end != (begin() + pos))
			{
				*end = *(end - n);
				--end;
			}
			for (size_type i = 0; i < n; ++i)
			{
				*(begin() + pos + i) = val;
			}
		}

	template <class InputIterator>
		void insert (iterator position, InputIterator first, typename ft::enable_if< !ft::is_integral< InputIterator >::value, InputIterator >::type last) // NEEDS enable_if
		{
			size_type pos = position - this->begin();
			size_type n = last - first;

			this->resize(this->_size + n);
			iterator end = this->end() - 1;
			while (end != (begin() + pos))
			{
				*end = *(end - n);
				--end;
			}
			for (size_type i = 0; i < n; ++i)
			{
				*(begin() + pos + i) = *first;
				++first;
			}
		}

		iterator erase (iterator position)
		{
			while (position + 1 != this->end())
			{
				*position = *(position + 1);
				++position;
			}
			this->pop_back();
			return (position);
		}

		iterator erase (iterator first, iterator last)
		{
			size_type range = static_cast<size_type>(last - first);

			while (first != last && last != this->end())
			{
				*first = *last;
				++first;
				++last;
			}
			this->_size -= range;
			return (first);
		}

		void swap (vector& x)
		{
			// pointer tmp;
			// tmp = this->_array;
			// this->_array = x._array;
			// x._array = tmp;
			this->swap_values(this->_array, x._array);
			this->swap_values(this->_size, x._size);
			this->swap_values(this->_capacity, x._capacity);
		}

		void clear()
		{
			this->destroy_array();
			this->_size = 0;
		}


	private:
		size_type	_capacity;
		size_type	_size;
		T*			_array;

		void new_array(size_type n, const value_type& val = value_type())
		{
			this->_capacity = n;
			this->_size = n;
			this->_array =static_cast<T*>(::operator new(sizeof(T) * this->_capacity));

			for (size_type i = 0; i < n; ++i)
			{
				new (static_cast<void*>(this->_array + i)) value_type(val);
			}
		}

		template <class Value>
		void	swap_values(Value& a, Value& b)
		{
			Value tmp;

			tmp = a;
			a = b;
			b = tmp;
		}

		void	destroy_array()
		{
			for (size_type i = 0; i < this->_size; ++i)
			{
				this->_array[i].~value_type();
			}
		}

		void	range_check(size_type n) const
		{
			if (n >= this->size())
			{
				// std::stringstream	ss;
				// ss << "vector::range_check: n (which is " << n << ") >= this->size() (which is " << this->size() << ")";
				throw std::out_of_range("vector");
				// throw std::out_of_range(ss.str());
			}
		}

		T* reallocate_tab(size_type n, T val = value_type())
		{
			// std::cout << "REALLOCATION" << std::endl;
			T* tab = NULL;
			if (n > this->capacity() * 2)
				this->_capacity = n;
			else if (n > this->capacity())
				this->_capacity *= 2;

			tab = static_cast<T*>(::operator new(sizeof(T) * this->_capacity));

			for (size_type i = 0; i < n; ++i)
			{
				if (i < this->size())
					new (static_cast<void*>(tab + i)) value_type(this->_array[i]);
				else
					new (static_cast<void*>(tab + i)) value_type(val);
			}
			return tab;
		}
	};

// Non-member function overloads
// ==================================	

template <class T>
	std::ostream & operator<<(std::ostream & o, vector<T> const & rhs);

template <class T>
	bool operator== (const vector<T>& lhs, const vector<T>& rhs)
	{
		typename vector<T>::const_iterator first1 = lhs.begin();
		typename vector<T>::const_iterator first2 = rhs.begin();
		typename vector<T>::const_iterator end1 = lhs.end();

		while (first1 != end1)
		{
			if (*first1 != *first2)
				return (false);
			first1++;
			first2++;
		}
		return (lhs.size() == rhs.size());
	}


template <class T>
	bool operator!= (const vector<T>& lhs, const vector<T>& rhs)
	{
		return !(lhs == rhs);
	}

template <class T>
	bool operator<  (const vector<T>& lhs, const vector<T>& rhs)
	{
		typename vector<T>::const_iterator first1 = lhs.begin();
		typename vector<T>::const_iterator first2 = rhs.begin();
		typename vector<T>::const_iterator end1 = lhs.end();

		while (first1 != end1)
		{
			if (*first1 < *first2)
				return (true);
			++first1;
			++first2;
		}
		return (first1 == end1);
	}

template <class T>
	bool operator<= (const vector<T>& lhs, const vector<T>& rhs)
	{
		return !(rhs < lhs);
	}

template <class T>
	bool operator>  (const vector<T>& lhs, const vector<T>& rhs)
	{
		return (rhs < lhs);
	}

template <class T>
	bool operator>= (const vector<T>& lhs, const vector<T>& rhs)
	{
		return !(lhs < rhs);
	}

  template <class T>
	void swap (vector<T>& x, vector<T>& y)
	{
		x.swap(y);
	}

}
// Non-member function overloads END
// ==================================

#endif // VECTOR_HPP
