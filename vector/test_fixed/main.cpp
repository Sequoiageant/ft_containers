/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 17:29:38 by julnolle          #+#    #+#             */
/*   Updated: 2021/01/22 10:06:25 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "vector.hpp"
#include <vector>

#ifndef STD
# define NS ft
#else
# define NS std
#endif

template<typename T>
void displayVec(std::vector<T>& v)
{
	typename std::vector<T>::iterator it = v.begin();
	while (it != v.end())
	{
		std::cout << *it << ' ';
		++it;
	}
	std::cout << std::endl;
}

template<typename T>
void displayVec(const std::vector<T>& v)
{
	typename std::vector<T>::const_iterator it = v.begin();
	while (it != v.end())
	{
		std::cout << *it << ' ';
		++it;
	}
	std::cout << std::endl;
}

template<typename T>
void displayVec(ft::vector<T>& v)
{
	typename ft::vector<T>::iterator it = v.begin();
	while (it != v.end())
	{
		std::cout << *it << ' ';
		++it;
	}
	std::cout << std::endl;
}

template<typename T>
void displayVec(const ft::vector<T>& v)
{
	typename ft::vector<T>::const_iterator it = v.begin();
	while (it != v.end())
	{
		std::cout << *it << ' ';
		++it;
	}
	std::cout << std::endl;
}

int main( void ) {

	Fixed		a;
	Fixed		b;
	Fixed		c;

	std::cout << "==== Vector v = (a,b,c) ====" << std::endl;
	NS::vector<Fixed> v(3, Fixed(8));

	std::cout << "==== assign(1, Fixed(42)) ====" << std::endl;
	v.assign(1, Fixed(42));
	std::cout << "v: "; displayVec(v);
	std::cout << "==== push_back(Fixed(43)) ====" << std::endl;
	v.push_back(Fixed(43));
	std::cout << "v: "; displayVec(v);

	return 0;
}
