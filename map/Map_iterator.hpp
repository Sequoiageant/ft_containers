/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 10:55:32 by julnolle          #+#    #+#             */
/*   Updated: 2021/02/02 11:15:58 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft {

template<typename T>
	class Map_iterator
	{

	public:
		typedef	size_t								size_type;

		typedef Map_iterator<T>						iterator;
		typedef ptrdiff_t							difference_type;
		typedef std::bidirectional_iterator_tag		iterator_category;
		typedef T									pointer;
		typedef T&									reference;


		Map_iterator(void) : p(NULL) {}
		Map_iterator(pointer x) : p(x) {}
		Map_iterator(const iterator& copy) : p(copy.p) {}
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
		~Map_iterator(void) {}

		const pointer& base() const { return p; }

	private:
		pointer p;
	};

// Non-member function overloads
// ==================================	
template<typename T>
	bool operator==(const Map_iterator<T>& lhs, const Map_iterator<T>& rhs)
	{ 
		return lhs.base() == rhs.base();
	}
template<typename T>
	bool operator!=(const Map_iterator<T>& lhs, const Map_iterator<T>& rhs)
	{ 
		return lhs.base() != rhs.base();
	}
template<typename T>
	bool operator<(const Map_iterator<T>& lhs, const Map_iterator<T>& rhs)
	{ 
		return lhs.base() < rhs.base();
	}
template<typename T>
	bool operator>(const Map_iterator<T>& lhs, const Map_iterator<T>& rhs)
	{ 
		return lhs.base() > rhs.base();
	}
template<typename T>
	bool operator<=(const Map_iterator<T>& lhs, const Map_iterator<T>& rhs)
	{ 
		return lhs.base() <= rhs.base();
	}
template<typename T>
	bool operator>=(const Map_iterator<T>& lhs, const Map_iterator<T>& rhs)
	{ 
		return lhs.base() >= rhs.base();
	}
template<typename T>
	typename Map_iterator<T>::difference_type operator-(const Map_iterator<T>& lhs, const Map_iterator<T>& rhs)
	{
		return lhs.base() - rhs.base();
	}
template<typename T>
	Map_iterator<T> operator+(typename Map_iterator<T>::difference_type n , const Map_iterator<T>& rhs)
	{
		return rhs.base() + n;
	}

} // ft