/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 11:07:21 by julnolle          #+#    #+#             */
/*   Updated: 2021/01/21 19:36:52 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <string>
# include <iostream>
# include <cstddef>
# include <exception>
# include <sstream>

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

		pointer& base() const { return p; }

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


		explicit vector () : _array(new T[0]), _size(0), _capacity(0)
		{
			// std::cout << "FT VECTOR" << std::endl;
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
			this->allocate_array();

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
			this->allocate_array();
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
			// std::cout << "SIZE: " << this->size() << std::endl;
			if (n > this->capacity())
			{
				T* tmp = reallocte_tab(n, val);
				this->clear();
				this->_array = tmp;
				this->_size = n;
			}
			else if (n > this->_size)
			{
				while (this->_size < n)
				{
					// std::cout << "RESIZE II" << std::endl;
					this->_array[this->_size] = val;
					++this->_size;
				}
			}
			else
			{
				while (this->_size > n)
				{
					this->_array[this->_size].~T();
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
			T *tmp = NULL;
			if (n > this->capacity())
			{
				this->_capacity = n;
				try
				{
					tmp = new T[this->capacity()];
				}
				catch (std::bad_alloc& ba)
				{
					std::cerr << "bad_alloc caught: " << ba.what() << '\n';
				}
				for (size_type i = 0; i < this->size(); ++i)
				{
					tmp[i] = (*this)[i];
				}
				this->clear();
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
		void assign (InputIterator first, InputIterator last)
		{
			size_type range = last - first;

			if (range > this->capacity())
			{
				T* tmp = new T[range];
				this->clear();
				this->_array = tmp;
				this->_capacity = range;
			}
			for (size_type i = 0; i < range; ++i)
			{
				this->_array[i] = *first;
				++first;
			}
			for (size_type i = range; i < this->_size; ++i)
			{
				first->~T();
				++first;
			}
			this->_size = range;
		}

		void assign (size_type n, const value_type& val) // NEEDS enable_if
		{
			if (n > this->capacity())
			{
				T* tmp = new T[n];
				this->clear();
				this->_array = tmp;
				this->_capacity = n;
			}
			for (size_type i = 0; i < n; ++i)
			{
				this->_array[i] = val;
			}
			for (size_type i = n; i < this->_size; ++i)
			{
				this->_array[i].~T();
			}
			this->_size = n;
		}

		void push_back (const value_type& val)
		{
			resize (this->size() + 1);
			this->_array[this->_size - 1] = val;

		}
		void pop_back()
		{
			this->back().~T();
			--this->_size;
		}

/*		iterator insert (iterator position, const value_type& val)
		{
			T* tmp = 

			resize (this->size() + 1); // reallocates if this->size + 1 > capacity


		}*/

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


	private:
		T*			_array;
		size_type	_size;
		size_type	_capacity;

		void	allocate_array()
		{
			try
			{
				this->_array = new T[this->_capacity];
			}
			catch (std::bad_alloc& ba)
			{
				std::cerr << "bad_alloc caught: " << ba.what() << '\n';
			}	
		}
		void	range_check(size_type n) const
		{
			if (n >= this->size())
			{
				std::stringstream	ss;
				ss << "vector::range_check: n (which is " << n << ") >= this->size() (which is " << this->size() << ")";
				throw std::out_of_range(ss.str());
			}
		}

		// T* new_empty_tab(size_type n, T val = value_type())
		// {
		// 	tab = new T[n];
		// }

		T* reallocte_tab(size_type n, T val = value_type())
		{
			// std::cout << "REALLOCATION" << std::endl;
			T* tab = NULL;
			if (n > this->capacity() * 2)
				this->_capacity = n;
			else if (n > this->capacity())
				this->_capacity *= 2;
			
			try
			{
				tab = new T[this->capacity()];
			}
			catch (std::bad_alloc& ba)
			{
				std::cerr << "bad_alloc caught: " << ba.what() << '\n';
			}

			for (size_type i = 0; i < n; ++i)
			{
				if (i < this->size())
					tab[i] = (*this)[i];
				else// if (i < n)
					tab[i] = val;
				// else
				// 	tab[i] = value_type();
			}
			return tab;
		}
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
