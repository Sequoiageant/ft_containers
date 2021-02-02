/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 10:29:50 by julnolle          #+#    #+#             */
/*   Updated: 2021/02/02 18:27:50 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft {

#ifndef MAP_HPP
# define MAP_HPP

# include <string>
# include <iostream>
# include <cstddef>
# include <exception>
# include <sstream>
# include <cstring>
# include "integral_traits.hpp"
# include "functional.hpp"
# include "Map_iterator.hpp"

template<typename Key, typename T>
	struct Node {
		T	data;
		Key	key;
		struct Node* left;
		struct Node* right;

		Node(T val)
		{
			data = val;
			left = NULL;
			right = NULL;
		}
	};

template<typename Key, typename T, typename Compare = std::less<Key> >
class map {

public:

	typedef Key										key_type;
	typedef T										mapped_type;
	typedef std::pair<const Key, T>					value_type;
	typedef Compare									key_compare;
	typedef Map_iterator<T*>						iterator;
	typedef Map_iterator<const T*>					const_iterator;
	typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;
	typedef std::reverse_iterator<iterator>			reverse_iterator;
	typedef	size_t									size_type;
	typedef	ptrdiff_t								difference_type;

	class value_compare
	{	// in C++98, it is required to inherit binary_function<value_type,value_type,bool>
		friend class map;
		
		protected:
			Compare comp;
	 		 value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
		public:
			bool operator() (const value_type& x, const value_type& y) const
			{
				return comp(x.first, y.first);
			}
	};
	

	explicit map (const key_compare& comp = key_compare());

	template <class InputIterator>
	map (InputIterator first, InputIterator last, const key_compare& comp = key_compare());

	map (const map& x);

	map& operator=(map const & x);
	~map ();

/*	iterator begin() { return iterator(this->_array); }
	const_iterator begin() const { return const_iterator(this->_array); }

	iterator end() { return iterator(&this->_array[this->_size]); }
	const_iterator end() const { return const_iterator(&this->_array[this->_size]); }

	reverse_iterator rbegin(void) { return reverse_iterator(this->end()); }
	const_reverse_iterator rbegin(void) const { return const_reverse_iterator(this->end()); }

	reverse_iterator rend(void) { return reverse_iterator(this->begin()); }
	const_reverse_iterator rend(void) const { return const_reverse_iterator(this->begin()); }
*/
	bool empty() const;
	size_type size() const;
	size_type max_size() const;
	mapped_type& operator[] (const key_type& k);

	std::pair<iterator,bool> insert (const value_type& val);
	iterator insert (iterator position, const value_type& val);
	template <class InputIterator>
	void insert (InputIterator first, InputIterator last);

	void erase (iterator position);
	size_type erase (const key_type& k);
	void erase (iterator first, iterator last);

	void swap (map& x);
	void clear ();

	key_compare key_comp() const;

	value_compare value_comp() const;

	iterator find (const key_type& k);
	const_iterator find (const key_type& k) const;
	size_type count (const key_type& k) const;
	iterator lower_bound (const key_type& k);
	const_iterator lower_bound (const key_type& k) const;
	iterator upper_bound (const key_type& k);
	const_iterator upper_bound (const key_type& k) const;

	pair<const_iterator,const_iterator>	equal_range (const key_type& k) const;
	pair<iterator,iterator>				equal_range (const key_type& k);


private:
	Node *node;
};

std::ostream & operator<<(std::ostream & o, map const & rhs);

#endif // MAP_HPP


} // ft