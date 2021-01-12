/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 11:07:21 by julnolle          #+#    #+#             */
/*   Updated: 2021/01/04 17:18:31 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "List.hpp"
#include <iostream>

template<typename T>
ft::List<T>::List(void) : _list(new t_list), _size(0)
{
	return;
}

template<typename T>
ft::List<T>::List(unsigned int size, const T &val) : _list(NULL), _size(0)
{
	for (unsigned int i = 0; i < size; ++i)
	{
		this->push_back(val);
	}
}

template<typename T>
template<typename InputIterator>
ft::List<T>::List(InputIterator first, InputIterator last) : _list(NULL), _size(0)
{
	while(first != last)
	{
		this->push_back(*first);
		++first;
	}
}

template<typename T>
ft::List<T>::List(List<T> const & copy) : _list(NULL), _size(0)
{
	t_list *tmp = copy._list;
	while (tmp)
	{
		this->push_back(tmp->value);
		tmp = tmp->next;
	}
}

template<typename T>
ft::List<T>::~List(void)
{
	this->clear();
}

template<typename T>
ft::List<T>& ft::List<T>::operator=(List<T> const & rhs)
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
bool ft::List<T>::empty() const
{
	return (this->_size == 0);
}

template<typename T>
unsigned int ft::List<T>::size() const
{
	return this->_size;
}

template<typename T>
unsigned int ft::List<T>::max_size() const
{
	return this->_size;
}

template<typename T>
T& ft::List<T>::front()
{
	return this->_list->value;
}

template<typename T>
const T& ft::List<T>::front() const
{
	return this->_list->value;
}

template<typename T>
T& ft::List<T>::back()
{
	t_list *cpy = this->_list;

	while (cpy->next)
	{
		cpy = cpy->next;
	}
	return cpy->value;
}

template<typename T>
const T& ft::List<T>::back() const
{
	t_list *cpy = this->_list;

	while (cpy->next)
	{
		cpy = cpy->next;
	}
	return cpy->value;
}

template<typename T>
template<typename InputIterator>
void ft::List<T>::assign (InputIterator first, InputIterator last)
{
	this->clear();
	while(first != last)
	{
		this->push_back(*first);
		++first;
	}
}

template<typename T>
void ft::List<T>::assign (unsigned int n, const T& val)
{
	this->clear();
	for (unsigned int i = 0; i < n; ++i)
	{
		this->push_back(val);
	}
}

template<typename T>
void ft::List<T>::push_front (const T& val)
{
	t_list *newElem;

	newElem = new t_list;

	newElem->value = val;
	newElem->prev = NULL;
	newElem->next = this->_list;
	this->_list = newElem;
	this->_size++;
}

template<typename T>
void ft::List<T>::pop_front()
{
	t_list *tmp;

	tmp = this->_list->next;
	delete this->_list;
	this->_list = tmp;
	this->_size--;
}

template<typename T>
void ft::List<T>::push_back(const T& val)
{
	t_list *newElem;
	t_list *copy;

	newElem = new t_list;

	newElem->prev = NULL;
	newElem->next = NULL;
	newElem->value = val;

	if (this->_size == 0)
		this->_list = newElem;
	else
	{
		copy = this->_list;
		while(copy->next)
		{
			copy = copy->next;
		}
		newElem->prev = copy;
		copy->next = newElem;
	}
	this->_size++;
}

/*void push_back(const value_type &val)
{
	node *insert = new node(val);
	insert->previous = this->tail->previous;
	insert->next = this->tail;
	this->tail->previous->next = insert;
	this->tail->previous = insert;
	this->total++;
}*/

template<typename T>
void ft::List<T>::pop_back()
{
	t_list *cpy = this->_list;
	while (cpy->next->next)
	{
		cpy = cpy->next;
	}
	delete cpy->next;
	cpy->next = NULL;
	this->_size--;
}


template<typename T>
typename ft::List<T>::iterator ft::List<T>::insert (iterator position, const T& val)
{
	t_list *tmp = this->_list;
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
void ft::List<T>::insert (iterator position, int n, const T& val)
{
	iterator it = this->begin();
	t_list *tmp = this->_list;

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
void ft::List<T>::insert (iterator position, InputIterator first, InputIterator last)
{
	iterator it = this->begin();
	t_list *tmp = this->_list;

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
typename ft::List<T>::iterator ft::List<T>::erase (ft::List<T>::iterator position)
{
	t_list	*tmp = this->_list;
	iterator it = this->begin();
	iterator ret(position);
	
	if (ret++ == NULL)
		ret = this->end();

	while (it != position)
	{
		tmp = tmp->next;
		++it;
	}
	this->delete_node(tmp);
	return ret;
}

template<typename T>
typename ft::List<T>::iterator ft::List<T>::erase (iterator first, iterator last)
{
	while (first != last)
	{
		first = this->erase(first);
	}
	return last;
}

template<typename T>
void ft::List<T>::swap (List& x)
{
	List tmp;

	tmp = *this;
	*this = x;
	x = tmp; 
}

template<typename T>
void ft::List<T>::resize (size_t n, T val)
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
void ft::List<T>::clear()
{
	t_list *tmp;

	while (this->_size > 0)
	{
		tmp = this->_list->next;
		delete this->_list;
		this->_list = tmp;
		this->_size--;
	}
	this->_list = NULL;
}

template<typename T>
void ft::List<T>::splice (iterator position, List<T>& x)
{
	if (!x.empty())
	{
		iterator it = this->begin();
		t_list *tmp = this->_list;
		t_list *tmpx = x._list;
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
	// if (!x.empty())
	// 	this->insert(position, x.begin(), x.end());
	// x.clear();
}

template<typename T>
void ft::List<T>::splice (iterator position, List<T>& x, iterator i)
{
	iterator j = i;
	++j;
	if (position == i || position == j)
		return;

	iterator it = this->begin();
	t_list *tmp = this->_list;
	t_list *tmpx = x._list;

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


	// this->insert(position, *i);
	// x.erase(i);
	// std::cerr << "x size: " << x._size << std::endl;
}

template<typename T>
void ft::List<T>::splice (iterator position, List<T>& x, iterator first, iterator last)
{
	if (first != last)
	{

		iterator it = this->begin();
		t_list *tmp = this->_list;
		t_list *tmpx = x._list;

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
		// this->insert(position, first, last);
		// x.erase(first, last);
	}
}

template<typename T>
void ft::List<T>::remove (const T& val)
{
	t_list *tmp = this->_list;
	t_list *tmp2 = tmp->next;
	unsigned int i = this->_size;

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
void ft::List<T>::remove_if (Predicate pred)
{
	t_list *tmp = this->_list;
	unsigned int i = this->_size;

	while (i > 0)
	{
		if (pred(tmp->value))
			this->delete_node(tmp);
		tmp = tmp->next;
		i--;
	}
}

template<typename T>
void ft::List<T>::unique ()
{
	t_list *tmp = this->_list;
	t_list *tmp2 = tmp->next;
	unsigned int i = this->_size;

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
void ft::List<T>::unique (BinaryPredicate binary_pred)
{
	t_list *tmp = this->_list;
	t_list *tmp2 = tmp->next;
	unsigned int i = this->_size;

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
void ft::List<T>::merge (List& x)
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
			// if (first2 != last2)
			// {
			// 	iterator next = first2;
			// 	this->splice(last1, x, next++, last2);
			// 	first2 = next;
			// }
		}
	}
}

/*
template<typename T>
void ft::List<T>::merge (List& x)
{
	t_list *tmp = this->_list;
	t_list *tmp2 = x._list;

	if (&x == this)
		return;

	this->sort();
	while (tmp)
	{
		if (tmp->value < tmp2->value)
			this->insert_node(tmp, tmp2);
			tmp = tmp->next;
			tmp2 = tmp2->next;
	}
	while(tmp2)
	{
		this->push_back(tmp2->value);
	}
	x.clear();
}
template<typename T>
template <class Compare>
void ft::List<T>::merge (List& x, Compare comp)
{

}*/


template<typename T>
void ft::List<T>::sort()
{
	t_list *tmp;
	unsigned int i = this->_size;

	while (i > 0)
	{
		tmp = this->_list;
		while (tmp->next)
		{
			if (tmp->value > tmp->next->value)
				this->swap_values(tmp->value, tmp->next->value);
			tmp = tmp->next;
		}
		i--;
	}
}
template<typename T>
template <class Compare>
void ft::List<T>::sort (Compare comp)
{
	t_list *tmp;
	unsigned int i = this->_size;

	while (i > 0)
	{
		tmp = this->_list;
		while (tmp->next)
		{
			if (comp(tmp->value, tmp->next->value))
				this->swap_values(tmp->value, tmp->next->value);
			tmp = tmp->next;
		}
		i--;
	}
}

template<typename T>
void ft::List<T>::reverse()
{
	t_list *tmp = this->_list;
	t_list *tmp2 = this->_list;
	unsigned int i = this->_size;

	while (tmp2->next)
	{
		tmp2 = tmp2->next;
	}
	while (i > this->_size / 2)
	{
		this->swap_values(tmp->value, tmp2->value);
		tmp = tmp->next;
		tmp2 = tmp2->prev;
		i--;
	}
}

// template<typename T>
// void ft::List<T>::displayList() const
// {
// 	t_list *cpy = this->_list;
// 	while (cpy)
// 	{
// 		std::cout << cpy->value << " ";
// 		cpy = cpy->next;
// 	}
// 	std::cout << std::endl;
// }

template<typename T>
void ft::List<T>::displayList()
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
void ft::List<T>::displayReverse() const
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

/*template<typename T>
std::ostream & operator<<(std::ostream & o, typename ft::List<T> const & rhs)
{
	typename ft::List<T>::iterator it = rhs.begin();
	typename ft::List<T>::iterator ite = rhs.end();

	while (it != ite)
	{
		o << *it << " ";
		++it;
	}
	o << std::endl;
	return o;
}*/

