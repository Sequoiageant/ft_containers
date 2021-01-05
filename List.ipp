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
	t_list *tmp;

	while (this->_list)
	{
		tmp = this->_list->next;
		// delete this->_list->value;
		delete this->_list;
		this->_list = tmp;
	}
}

template<typename T>
ft::List<T>& ft::List<T>::operator=(List<T> const & rhs)
{
	t_list *tmp;

	while (this->_list)
	{
		tmp = this->_list->next;
		// delete this->_list->value;
		delete this->_list;
		this->_list = tmp;
	}

	this->_size = 0;
	tmp = rhs._list;
	while (tmp)
	{
		this->push_back(tmp->value);
		tmp = tmp->next;
	}
	return (*this);
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

// template<typename T>
// template<typename InputIterator>
// void assign (InputIterator first, InputIterator last)
// {
// 	while(first != last)
// 	{
// 		this->push_back(*first);
// 		++first;
// 	}
// }

template<typename T>
void ft::List<T>::push_front (const T& val)
{
	t_list *newElem;

	newElem = new t_list;

	newElem->value = val;
	newElem->before = NULL;
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

	newElem->before = NULL;
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
		newElem->before = copy;
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
// void ft::List<T>::swap (List& x)
// {
// 	List tmp(x);
// 	List cpy(*this);

// 	if (x._size <= this->_size)
// 	{

// 		for (unsigned int i = 0; i < x._size; ++i)
// 		{
// 			this->_list->value = tmp._list->value
// 			this->_list = this->_list->next;
// 			tmp._list = tmp._list->next;
// 		}
// 	}
// 	if (x._size > this->_size)
// 	{
// 		while (tmp._list->next)
// 		{
// 			this->push_back(tmp._list->value);
// 		}
// 	}
// }

template<typename T>
void ft::List<T>::resize (size_t n, T val)
{
	t_list *cpy = this->_list;

	if (n < this->_size)
	{
		for (size_t i = 0; i < n; ++i)
		{
			cpy = cpy->next;
		}
		while (this->_size > n)
		{
			this->pop_back();
		}
	}
	else
	{
		while (cpy->next)
		{
			cpy = cpy->next;
		}
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

	while (this->_list)
	{
		tmp = this->_list->next;
		// delete this->_list->value;
		delete this->_list;
		this->_list = tmp;
	}
	this->_size = 0;
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
	t_list *tmp = cpy;
	while (tmp)
	{
		std::cout << tmp->value << " ";
		tmp = tmp->before;
	}
	std::cout << std::endl;
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

