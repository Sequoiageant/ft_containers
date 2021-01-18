/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 11:07:21 by julnolle          #+#    #+#             */
/*   Updated: 2021/01/04 17:18:31 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"
#include "functional.hpp"

template<typename T>
ft::list<T>::list(void) : _list(new List_node)
{
	return;
}

template<typename T>
ft::list<T>::list(size_t size, const T &val) : _list(new List_node)
{
	for (size_t i = 0; i < size; ++i)
	{
		this->push_back(val);
	}
}

template<typename T>
template<typename InputIterator>
ft::list<T>::list(InputIterator first, InputIterator last) : _list(new List_node)
{
	this->insert (this->begin(), first, last);
}

template<typename T>
ft::list<T>::list(list<T> const & copy) : _list(new List_node)
{
	this->insert (this->begin(), copy.begin(), copy.end());
}

template<typename T>
ft::list<T>::~list(void)
{
	this->clear();
	delete this->_list;
}

template<typename T>
ft::list<T>& ft::list<T>::operator=(list<T> const & rhs)
{
	this->clear();
	this->insert (this->begin(), rhs.begin(), rhs.end());

	return (*this);
}

template<typename T>
bool ft::list<T>::empty() const
{
	return (this->_list == this->_list->next);
}

template<typename T>
size_t ft::list<T>::size() const
{
	size_t size = 0;

	const_iterator first = this->begin();
	while(first != this->end()) {
		++first;
		++size;
	}
	return size;
}

template<typename T>
size_t ft::list<T>::max_size() const
{
	std::allocator<List_node> a;
	return a.max_size();
}

template<typename T>
T& ft::list<T>::front()
{
	return this->_list->next->value;
}

template<typename T>
const T& ft::list<T>::front() const
{
	return this->_list->next->value;
}

template<typename T>
T& ft::list<T>::back()
{
	return this->_list->prev->value;
}

template<typename T>
const T& ft::list<T>::back() const
{
	return this->_list->prev->value;
}

template<typename T>
template<typename InputIterator>
void ft::list<T>::assign (InputIterator first, InputIterator last)
{
	this->clear();
	while(first != last)
	{
		this->push_back(*first);
		++first;
	}
}

template<typename T>
void ft::list<T>::assign (size_t n, const T& val)
{
	this->clear();
	for (size_t i = 0; i < n; ++i)
	{
		this->push_back(val);
	}
}

template<typename T>
void ft::list<T>::push_front (const T& val)
{
	this->insert(this->begin(), val);
}

template<typename T>
void ft::list<T>::pop_front()
{
	this->delete_node(this->_list->next);
}

template<typename T>
void ft::list<T>::push_back(const T& val)
{
	this->insert(this->end(), val);
}

template<typename T>
void ft::list<T>::pop_back()
{
	this->delete_node(this->_list->prev);
}


template<typename T>
typename ft::list<T>::iterator ft::list<T>::insert (iterator position, const T& val)
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

template<typename T>
void ft::list<T>::insert (iterator position, int n, const T& val)
{
	iterator it = this->begin();
	List_node *tmp = this->_list->next;

	while (it != position)
	{
		tmp = tmp->next;
		++it;
	}
	for (int i = 0; i < n; ++i)
	{
		this->insert_node(tmp, new_node(val));
	}
}

template<typename T>
template <class InputIterator>
void ft::list<T>::insert (iterator position, InputIterator first, InputIterator last)
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

template<typename T>
typename ft::list<T>::iterator ft::list<T>::erase (ft::list<T>::iterator position)
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

template<typename T>
typename ft::list<T>::iterator ft::list<T>::erase (iterator first, iterator last)
{
	while (first != last)
	{
		first = this->erase(first);
	}
	return last;
}

template<typename T>
void ft::list<T>::swap (list& x)
{
	List_node *tmp;

	tmp = this->_list;
	this->_list = x._list;
	x._list = tmp; 
}

template<typename T>
void ft::list<T>::resize (size_t n, T val)
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

template<typename T>
void ft::list<T>::clear()
{
	List_node *tmp;

	while (this->_list->next != this->_list)
	{
		tmp = this->_list->next->next;
		this->delete_node(this->_list->next);
		this->_list->next = tmp;
	}
}

template<typename T>
void ft::list<T>::splice (iterator position, list<T>& x)
{
	if (!x.empty())
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

template<typename T>
void ft::list<T>::splice (iterator position, list<T>& x, iterator i)
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

template<typename T>
void ft::list<T>::splice (iterator position, list<T>& x, iterator first, iterator last)
{
	if (first != last)
	{

		iterator it = this->begin();
		List_node *tmp = this->_list->next;
		List_node *tmpx = x._list->next;

		while (it != position)
		{
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

template<typename T>
void ft::list<T>::remove (const T& val)
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

template<typename T>
template <class Predicate>
void ft::list<T>::remove_if (Predicate pred)
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

template<typename T>
void ft::list<T>::unique ()
{
	this->unique(equal_to<T>);
}

template<typename T>
template <class BinaryPredicate>
void ft::list<T>::unique (BinaryPredicate binary_pred)
{
	iterator first = this->begin();
	iterator last = this->end();
	iterator next;

	while (first != last)
	{
		next = first;
		++next;
		if (binary_pred(*first, *next))
			this->erase(first);
		first = next;
	}
}

template<typename T>
void ft::list<T>::merge (list& x)
{
	this->merge(x, less<T>);
}

template<typename T>
template <class Compare>
void ft::list<T>::merge (list& x, Compare comp)
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

template<typename T>
void ft::list<T>::sort()
{
	this->sort(less<T>);
}

template<typename T>
template <class Compare>
void ft::list<T>::sort (Compare comp)
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

/*template<typename T>
void ft::list<T>::reverse()
{
	// Do nothing if the list has length 0 or 1.
	if (this->_list->next != this->_list
		&& this->_list->next->next != this->_list)
	{		
		iterator first = this->begin();
		iterator last = this->end();

		List_node *cpy = this->_list;
		List_node *tmp;
	// int i = 1;
		while (first != last)
		{
		// std::cerr << "REVERSE " << i++ << std::endl;
			tmp = cpy->next;
		// this->swap(cpy->next, cpy->prev);
			cpy->next = cpy->prev;
			cpy->prev = tmp;
			cpy = tmp;
			++first;
		}
		tmp = cpy->next;
	// this->swap(cpy->next, cpy->prev);
		cpy->next = cpy->prev;
		cpy->prev = tmp;
		cpy = tmp;
	}
}
*/
template<typename T>
void ft::list<T>::reverse()
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

// =========================================================
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
// =========================================================
