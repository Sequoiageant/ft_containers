/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 16:07:36 by julnolle          #+#    #+#             */
/*   Updated: 2021/01/19 22:03:30 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
// #include "../list/list.hpp"
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

int main(void)
{
	std::cout << "---- std Vector v = (1,2,3,4) ----" << std::endl;
	std::vector<int> v;
	for (int i = 1; i < 5; ++i)	{ v.push_back(i); }
	std::cout << "v: "; displayVec(v);

	std::cout << "---- Default Constructor ----" << std::endl;
	
	ft::vector<int> v1;
	std::cout << "v1: "; v1.displayVec();
	
	std::cout << "---- Constructor by range (v.begin(), v.end()) ----" << std::endl;

	ft::vector<int> v2(v.begin(), v.end());
	std::cout << "v2: "; v2.displayVec();

	std::cout << "---- Constructor by copy v3(v2) ----" << std::endl;
	ft::vector<int> v3(v2);
	std::cout << "v3: "; v3.displayVec();

	std::cout << "---- Assignation of v1 = v2 ----" << std::endl;
	v1 = v2;
	std::cout << "v1: "; v1.displayVec();

	std::cout << "---- Iterators ----" << std::endl;
	ft::vector<int>::iterator it1 = v1.begin();
	std::cout << "it1: " << *it1 << std::endl;
	it1 += 2;
	std::cout << "++it1: " << *it1 << std::endl;
	std::cout << "*it1--: " << *it1-- << std::endl;
	std::cout << "*it1: " << *it1 << std::endl;
	std::cout << "v1: "; displayVec(v1);

	std::cout << "---- v1 size ----" << std::endl;
	std::cout << "v1 size: " << v1.size() << std::endl;

	std::cout << "---- vector max size ----" << std::endl;
	std::cout << "std::vector: " << v.max_size() << std::endl;
	std::cout << "ft::vector: " << v1.max_size() << std::endl;
	
	std::cout << "---- operator [] ----" << std::endl;
	std::cout << "v1[2]: " << v1[2] << std::endl;
	try {
		std::cout << "v1.at(5): " << v1.at(5) << std::endl;
		// std::cout << "v[1]: " << v.at(5) << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}


/*	std::cout << "---- std Iterators ----" << std::endl;
	// v.push_back(5);
	std::vector<int>::iterator it = v.begin();
	std::cout << "it: " << *it << std::endl;
	it++;
	std::cout << "++it: " << *it << std::endl;
	std::cout << "v: "; displayVec(v);
	std::cout << "v size: " << v.size() << std::endl;
	std::cout << "v capacity: " << v.capacity() << std::endl;
	*/

	return 0;
}