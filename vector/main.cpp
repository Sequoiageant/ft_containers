/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 16:07:36 by julnolle          #+#    #+#             */
/*   Updated: 2021/01/19 12:44:11 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>

#define NS std

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

int main(void)
{
	std::vector<int> v(9, 5);
	std::cout << "v capacity: " << std::endl;
	std::vector<int> v2(v.begin(), v.end());
	std::cout << "v2 capacity: " << v2.capacity() << std::endl;


	std::cout << "v capacity: " << std::endl;
	size_t capacity = 0;
	std::cout << v.capacity() << ' ';
	for (int i = 0; i < 100000; ++i)
	{
		v.push_back(1);
		if (capacity != v.capacity())
		{
			capacity = v.capacity();
			std::cout << capacity << ' ';
		}

	}
	return 0;
}