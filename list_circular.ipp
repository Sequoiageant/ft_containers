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

#include "list_circular.hpp"
#include <iostream>

template<typename T>
ft::list<T>::list(void) : _list(NULL), _size(0)
{
	this->init_list();
	return;
}

template<typename T>
ft::list<T>::list(size_t size, const T &val) : _list(NULL), _size(0)
{
	for (size_t i = 0; i < size; ++i)
	{
		this->push_back(val);
	}
}

template<typename T>
template<typename InputIterator>
ft::list<T>::list(InputIterator first, InputIterator last) : _list(NULL), _size(0)
{
	while(first != last)
	{
		this->push_back(*first);
		++first;
	}
}

template<typename T>
ft::list<T>::list(list<T> const & copy) : _list(NULL), _size(0)
{
	t_list *tmp = copy._list;
	while (tmp)
	{
		this->push_back(tmp->value);
		tmp = tmp->next;
	}
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
	t_list *tmp;

	this->clear();
	tmp = rhs._list;
	while (tmp)
	{
		this->push_back(tmp->value);
		tmp = tmp->next;
	}
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
	return this->_size;
}

template<typename T>
size_t ft::list<T>::max_size() const
{
	std::allocator<t_list> a;
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
	t_list *tmp = this->_list->next;
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
	t_list *tmp = this->_list->next;

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
	t_list *tmp = this->_list->next;

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
	t_list	*tmp = this->_list->next;
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
	list tmp;

	tmp = *this;
	*this = x;
	x = tmp; 
}

template<typename T>
void ft::list<T>::resize (size_t n, T val)
{
	if (n < this->_size)
	{
		while (this->_size > n)
		{
			this->pop_back();
		}
	}
	else
	{
		while (this->_size < n)
		{
			this->push_back(val);
		}		
	}
}

template<typename T>
void ft::list<T>::clear()
{
	while (this->_size > 0)
	{
		this->pop_back();
	}
}

template<typename T>
void ft::list<T>::splice (iterator position, list<T>& x)
{
	if (!x.empty())
	{
		iterator it = this->begin();
		t_list *tmp = this->_list->next;
		t_list *tmpx = x._list->next;
		iterator last = x.end();

		while (it != position)
		{
			tmp = tmp->next;
			++it;
		}
		it = x.begin();
		iterator next = it;
		t_list *tmpx2;
		while (it != last)
		{
			tmpx2 = tmpx->next;
			++next;
			x.unlink_node(tmpx);
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
	t_list *tmp = this->_list->next;
	t_list *tmpx = x._list->next;

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
	x.unlink_node(tmpx);
	this->insert_node(tmp, tmpx);
}

template<typename T>
void ft::list<T>::splice (iterator position, list<T>& x, iterator first, iterator last)
{
	if (first != last)
	{

		iterator it = this->begin();
		t_list *tmp = this->_list->next;
		t_list *tmpx = x._list->next;

		while (it != position)
		{
			tmp = tmp->next;
			++it;
		}
		iterator next = first;
		t_list *tmpx2;
		while (first != last)
		{
			tmpx2 = tmpx->next;
			++next;
			x.unlink_node(tmpx);
			this->insert_node(tmp, tmpx);
			tmpx = tmpx2;
			first = next;
		}
	}
}

template<typename T>
void ft::list<T>::remove (const T& val)
{
	t_list *tmp = this->_list->next;
	t_list *tmp2 = tmp->next;
	size_t i = this->_size;

	while (i > 1)
	{
		if (tmp->value == val)
			this->delete_node(tmp);
		tmp = tmp2;
		tmp2 = tmp2->next;
		i--;
	}
}

template<typename T>
template <class Predicate>
void ft::list<T>::remove_if (Predicate pred)
{
	t_list *tmp = this->_list->next;
	size_t i = this->_size;

	while (i > 0)
	{
		if (pred(tmp->value))
			this->delete_node(tmp);
		tmp = tmp->next;
		i--;
	}
}

template<typename T>
void ft::list<T>::unique ()
{
	t_list *tmp = this->_list->next;
	t_list *tmp2 = tmp->next;
	size_t i = this->_size;

	while (i > 1)
	{
		if (tmp->value == tmp2->value)
			this->delete_node(tmp);
		tmp = tmp2;
		tmp2 = tmp2->next;
		i--;
	}
}

template<typename T>
template <class BinaryPredicate>
void ft::list<T>::unique (BinaryPredicate binary_pred)
{
	t_list *tmp = this->_list->next;
	t_list *tmp2 = tmp->next;
	size_t i = this->_size;

	while (i > 1)
	{
		if (binary_pred(tmp->value, tmp2->value))
			this->delete_node(tmp);
		tmp = tmp2;
		tmp2 = tmp2->next;
		i--;
	}
}

template<typename T>
void ft::list<T>::merge (list& x)
{
	if (&x != this)
	{
		iterator first1 = this->begin();
		iterator last1 = this->end();
		iterator first2 = x.begin();
		iterator last2 = x.end();

		while (first1 != last1 && first2 != last2)
		{
			if (*first2 < *first1)
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
	if (this->_list == NULL || this->_size == 1)
		return;
	
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
			if (*first2 < *min)
				min = first2;
			++first2;
		}
		this->splice(first1, *this, min);
		if (min == first1)
			++first1;
	}
}

template<typename T>
template <class Compare>
void ft::list<T>::sort (Compare comp)
{
	if (this->_list == NULL || this->_size == 1)
		return;
	
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

template<typename T>
void ft::list<T>::reverse()
{
	if (this->_list->next == this->_list)
		return;
	
	iterator first = this->begin();
	iterator last = this->end();

	t_list *cpy = this->_list;
	t_list *tmp;

	while (first != last)
	{
		tmp = cpy->next;
		cpy->next = cpy->prev;
		cpy->prev = tmp;
		cpy = tmp;
		++first;
	}
	tmp = cpy->next;
	cpy->next = cpy->prev;
	cpy->prev = tmp;
	cpy = tmp;
}

/*template<typename T>
void ft::list<T>::reverse()
{
	if (this->_list->next == NULL)
		return;

	t_list *cpy = this->_list;
	t_list *tmp;

	while (cpy->next)
		cpy = cpy->next;

	this->_list = cpy;
	while (cpy)
	{
		tmp = cpy->prev;
		cpy->prev = cpy->next;
		cpy->next = tmp;
		cpy = tmp;
	}
}
*/
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
	t_list *cpy = this->_list;
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


/*template<typename T>
bool ft::operator== (const ft::list<T>& lhs, const ft::list<T>& rhs)
{
	typename ft::list<T>::const_iterator end1 = lhs.end();
	typename ft::list<T>::const_iterator end2 = rhs.end();
	typename ft::list<T>::const_iterator first1 = lhs.end();
	typename ft::list<T>::const_iterator first2 = rhs.end();

	while (first1 != end1 && first2 != end2 && *first1 == *first2)
	{
		++first1;
		++first2;
	}
	return (first1 == end1 && first2 == end2);
}*/



/*template<typename T>
std::ostream & operator<<(std::ostream & o, typename ft::list<T> const & rhs)
{
	typename ft::list<T>::iterator it = rhs.begin();
	typename ft::list<T>::iterator ite = rhs.end();

	while (it != ite)
	{
		o << *it << " ";
		++it;
	}
	o << std::endl;
	return o;
}*/

