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

// template<typename T>
// template<typename InputIterator>
// ft::List<T>::List(InputIterator first, InputIterator last) : _list(NULL), _size(0)
// {
// 	while(first != last)
// 	{
// 		this->push_back(*first);
// 		++first;
// 	}
// }

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


// template<typename T>
// typename ft::List<T>::iterator ft::List<T>::insert (iterator position, const T& val)
// {
// 	t_list *tmp = this->_list;

// 	if (*position < this->_size)
// 	{
// 		for (unsigned int i = 0; i < *position; ++i)
// 		{
// 			tmp = tmp->next;
// 		}
// 		this->insert_node(val);
// 	}
// }

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

template<typename T>
void ft::List<T>::displayList() const
{
	t_list *cpy = this->_list;
	while (cpy)
	{
		std::cout << cpy->value << " ";
		cpy = cpy->next;
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

// std::ostream & operator<<(std::ostream & o, List<T> const & rhs)
// {
// 	t_list *cpy;

// 	cpy = rhs.getList();
// 	while (cpy->next != NULL)
// 	{
// 		o << cpy->value << " ";
// 		cpy = cpy->next;
// 	}
// 	o << std::endl;
// 	return o;
// }

