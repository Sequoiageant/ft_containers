/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_traits.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 10:55:18 by julnolle          #+#    #+#             */
/*   Updated: 2021/01/27 11:51:23 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
// #include <type_traits>
#include "integral_traits.hpp"

template <typename T>
void test(T& value)
{
	if (ft::is_integral<T>::value)
		std::cout << value << " is an integral" << std::endl;
	else
		std::cout << value << " is NOT an integral" << std::endl;
}

int main() 
{
	// std::cout << std::boolalpha << ft::is_integral<int>::value << std::endl;
	// std::cout << std::boolalpha << ft::is_integral<float>::value << std::endl;
	// std::cout << std::boolalpha << ft::is_integral<char>::value << std::endl;

	int *i = NULL;
	// int i = 42;
	char c = 'x';
	test(i);
	test(c);

}