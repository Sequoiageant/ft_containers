/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 11:07:21 by julnolle          #+#    #+#             */
/*   Updated: 2021/05/07 10:31:25 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include <string>
# include <iostream>
# include <iterator>
# include <cstddef>
# include "integral_traits.hpp"
# include "functional.hpp"


namespace ft
{

template<typename T>
	struct		List_node
	{
		List_node(){
			this->value = T();
			this->prev = this->next = this;
		};

		List_node(const T& val){	
			this->value = val;
			this->prev = this->next = this;
		};

		void	reverse() {
			List_node *tmp;

			tmp = this->next;
			this->next = this->prev;
			prev = tmp;
		}

		void unhook() {
			this->prev->next = this->next;
			this->next->prev = this->prev;
		}

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
		List_node*	get_node() const { return p;}
		~iterator(void) {}

private:
		List_node *p;
};

template<typename T>
	class const_iterator
	{

public:
		typedef	size_t								size_type;
		typedef	List_node<T>						List_node;

		typedef ptrdiff_t							difference_type;
		typedef iterator<T>							iterator;
		typedef std::bidirectional_iterator_tag		iterator_category;
		typedef	T									value_type;
		typedef const T*							pointer;
		typedef const T&							reference;

		const_iterator(void) {}
		const_iterator(const List_node *x) : p(x) {}
		const_iterator(const const_iterator& copy) : p(copy.p) {}
		const_iterator(const iterator& copy) : p(copy.p) {}
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
		const List_node* get_node() const { return p;}
		~const_iterator(void) {}

private:
		const List_node *p;
};

template<typename T>
class list
{

public:
	typedef	List_node<T>							List_node;
	typedef	T										value_type;
	typedef iterator<T>								iterator;
	typedef const_iterator<T>						const_iterator;
	typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;
	typedef std::reverse_iterator<iterator>			reverse_iterator;
	typedef	size_t									size_type;

	
	list(void) : _list(new List_node)
	{
		return;
	}

	list(size_type size, const T &val) : _list(new List_node)
	{
		for (size_type i = 0; i < size; ++i)
		{
			this->push_back(val);
		}
	}

	template<typename InputIterator>
	list(InputIterator first, typename ft::enable_if< !ft::is_integral< InputIterator >::value, InputIterator >::type last) : _list(new List_node)
	{
		this->insert (this->begin(), first, last);
	}

	list(list<T> const & copy) : _list(new List_node)
	{
		this->insert (this->begin(), copy.begin(), copy.end());
	}

	~list(void)
	{
		this->clear();
		delete this->_list;
	}

	list& operator=(list<T> const & rhs)
	{
		this->clear();
		this->insert (this->begin(), rhs.begin(), rhs.end());

		return (*this);
	}


	iterator begin(void) { return iterator(this->_list->next); }
	const_iterator begin() const { return const_iterator(this->_list->next); }
	
	iterator end(void) { return iterator(this->_list); }
	const_iterator end() const { return const_iterator(this->_list); }
	
	reverse_iterator rbegin(void) { return reverse_iterator(this->end()); }
	const_reverse_iterator rbegin(void) const { return const_reverse_iterator(this->end()); } //this->_list->prev
	
	reverse_iterator rend(void) { return reverse_iterator(this->begin()); }
	const_reverse_iterator rend(void) const { return const_reverse_iterator(this->begin()); } //this->_list

		
bool empty() const
{
	return (this->_list == this->_list->next);
}

size_type size() const
{
	size_type size = 0;

	const_iterator first = this->begin();
	while(first != this->end()) {
		++first;
		++size;
	}
	return size;
}

size_type max_size() const
{
	std::allocator<List_node> a;
	return a.max_size();
}

T& front()
{
	return this->_list->next->value;
}

const T& front() const
{
	return this->_list->next->value;
}

T& back()
{
	return this->_list->prev->value;
}

const T& back() const
{
	return this->_list->prev->value;
}

template<typename InputIterator>
void assign (InputIterator first, typename ft::enable_if< !ft::is_integral< InputIterator >::value, InputIterator >::type last)
{
	this->clear();
	while(first != last)
	{
		this->push_back(*first);
		++first;
	}
}

void assign (size_type n, const T& val)
{
	this->clear();
	for (size_type i = 0; i < n; ++i)
	{
		this->push_back(val);
	}
}

void push_front (const T& val)
{
	this->insert(this->begin(), val);
}

void pop_front()
{
	this->delete_node(this->_list->next);
}

void push_back(const T& val)
{
	this->insert(this->end(), val);
}

void pop_back()
{
	this->delete_node(this->_list->prev);
}


iterator insert (iterator position, const T& val)
{
	List_node *tmp = this->_list->next;
	iterator it(this->begin());

	while (it != position)
	{
		tmp = tmp->next;
		++it;
	}
	this->insert_node(tmp, new_node(val));
	return --it;
}

void insert (iterator position, size_type n, const T& val)
{
	iterator it = this->begin();
	List_node *tmp = this->_list->next;

	while (it != position)
	{
		tmp = tmp->next;
		++it;
	}
	for (size_type i = 0; i < n; ++i)
	{
		this->insert_node(tmp, new_node(val));
	}
}

template <class InputIterator>
void insert (iterator position, InputIterator first, typename ft::enable_if< !ft::is_integral< InputIterator >::value, InputIterator >::type last)
{
	iterator it = this->begin();
	List_node *tmp = this->_list->next;

	while (it != position)
	{
		tmp = tmp->next;
		++it;
	}
	while (first != last)
	{
		this->insert_node(tmp, new_node(*first));
		++first;
	}
}

iterator erase (iterator position)
{
	List_node	*tmp = this->_list->next;
	iterator it = this->begin();
	iterator ret(position);
	++ret;

	while (it != position)
	{
		tmp = tmp->next;
		++it;
	}
	this->delete_node(tmp);
	return ret;
}

iterator erase (iterator first, iterator last)
{
	while (first != last)
	{
		first = this->erase(first);
	}
	return last;
}

void swap (list& x)
{
	List_node *tmp;

	tmp = this->_list;
	this->_list = x._list;
	x._list = tmp; 
}

void resize (size_type n, T val)
{
	iterator i = this->begin();

	if (n < this->size())
	{
		while (n-- > 0)
			++i;
		erase(i, this->end());
	}
	else
		insert(this->end(), n - this->size(), val);
}

void clear()
{
	List_node *tmp;

	while (this->_list->next != this->_list)
	{
		tmp = this->_list->next->next;
		this->delete_node(this->_list->next);
		this->_list->next = tmp;
	}
}

void splice (iterator position, list<T>& x)
{
	if (!x.empty() && &x != this)
	{
		iterator it = this->begin();
		List_node *tmp = this->_list->next;
		List_node *tmpx = x._list->next;
		iterator last = x.end();

		while (it != position)
		{
			tmp = tmp->next;
			++it;
		}
		it = x.begin();
		iterator next = it;
		List_node *tmpx2;
		while (it != last)
		{
			tmpx2 = tmpx->next;
			++next;
			tmpx->unhook();
			this->insert_node(tmp, tmpx);
			tmpx = tmpx2;
			it = next;
		}
	}
}

void splice (iterator position, list<T>& x, iterator i)
{
	iterator j = i;
	++j;
	if (position == i || position == j)
		return;

	iterator it = this->begin();
	List_node *tmp = this->_list->next;
	List_node *tmpx = x._list->next;

	while (it != position)
	{
		tmp = tmp->next;
		++it;
	}
	it = x.begin();
	while (it != i)
	{
		tmpx = tmpx->next;
		++it;
	}
	tmpx->unhook();
	this->insert_node(tmp, tmpx);
}

void splice (iterator position, list<T>& x, iterator first, iterator last)
{
	if (first != last)
	{
		iterator it = this->begin();
		List_node *tmp = this->_list->next;
		List_node *tmpx = x._list->next;

		while (it != position)
		{
			if (it == first)
				return;
			tmp = tmp->next;
			++it;
		}
		it = x.begin();
		while(it != first) {
			tmpx = tmpx->next;
			++it;
		}
		iterator next = it;
		List_node *tmpx2;
		while (it != last)
		{
			tmpx2 = tmpx->next;
			++next;
			tmpx->unhook();
			this->insert_node(tmp, tmpx);
			tmpx = tmpx2;
			it = next;
		}
	}
}

void remove (const T& val)
{
	iterator first = this->begin();
	iterator last = this->end();
	iterator next;

	while (first != last)
	{
		next = first;
		++next;
		if (*first == val)
			this->erase(first);
		first = next;
	}
}

template <class Predicate>
void remove_if (Predicate pred)
{
	iterator first = this->begin();
	iterator last = this->end();
	iterator next;

	while (first != last)
	{
		next = first;
		++next;
		if (pred(*first))
			this->erase(first);
		first = next;
	}
}

void unique ()
{
	this->unique(equal_to<T>);
}

template <class BinaryPredicate>
void unique (BinaryPredicate binary_pred)
{
	iterator first = this->begin();
	iterator last = this->end();
	iterator next;

	while (first != last)
	{
		next = first;
		++next;
		if (binary_pred(*first, *next))
			this->erase(next);
		else
			++first;
	}
}

void merge (list& x)
{
	this->merge(x, less<T>);
}

template <class Compare>
void merge (list& x, Compare comp)
{
	if (&x != this)
	{
		iterator first1 = this->begin();
		iterator last1 = this->end();
		iterator first2 = x.begin();
		iterator last2 = x.end();

		while (first1 != last1 && first2 != last2)
		{
			if (comp(*first2, *first1))
			{
				iterator next = first2;
				this->splice(first1, x, next++);
				first2 = next;
			}
			else
				++first1;
		}
		if (first2 != last2)
			this->splice(last1, x, first2, last2);
	}
}

void sort()
{
	this->sort(less<T>);
}

template <class Compare>
void sort (Compare comp)
{
	// Do nothing if the list has length 0 or 1.
	if (this->_list->next != this->_list
		&& this->_list->next->next != this->_list)
	{
		iterator first1 = this->begin();
		iterator last = this->end();
		iterator first2;
		iterator min;

		while (first1 != last)
		{
			first2 = min = first1;
			first2++;
			while (first2 != last)
			{
				if (comp(*first2, *min))
					min = first2;
				++first2;
			}
			this->splice(first1, *this, min);
			if (min == first1)
				++first1;
		}
	}
}

void reverse()
{
	// Do nothing if the list has length 0 or 1.
	if (this->_list->next != this->_list
		&& this->_list->next->next != this->_list)
	{	
		List_node *tmp = this->_list->prev;
		while (tmp != this->_list)
		{
			tmp->reverse();
			tmp = tmp->next;
		}
		tmp->reverse();
	}
}

		void displaylist();
		void displayReverse() const;

	private:

		/*Attributs*/
		List_node		*_list;

		/*Member functions*/
		List_node *new_node(const T& val)
		{
			return (new List_node(val));
		}

		void	insert_node(List_node *node, List_node *newElem)
		{
			node->prev->next = newElem;
			newElem->prev = node->prev;
			node->prev = newElem;
			newElem->next = node;
		}

		void	delete_node(List_node *node)
		{
			if (node == this->_list)
				return;

			node->unhook();
			delete node;
		}

	};


// Non-member function overloads
// ==================================

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
// Non-member function overloads END
// ==================================

/*// =========================================================
// Only for debug

template<typename T>
void ft::list<T>::displaylist()
{
	iterator it = this->begin();
	while (it != this->end())
	{
		std::cout << *it << ' ';
		++it;
	}
	std::cout << std::endl;
}

template<typename T>
void ft::list<T>::displayReverse() const
{
	List_node *cpy = this->_list;
	while (cpy->next)
	{
		cpy = cpy->next;
	}
	while (cpy)
	{
		std::cout << cpy->value << " ";
		cpy = cpy->prev;
	}
}
// =========================================================*/
#endif // LIST_HPP