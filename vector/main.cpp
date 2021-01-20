/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 16:07:36 by julnolle          #+#    #+#             */
/*   Updated: 2021/01/20 16:35:15 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
// #include "../list/list.hpp"
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

int main(void)
{
	std::cout << "---- std Vector v = (1,2,3,4) ----" << std::endl;
	std::vector<int> v;
	for (int i = 1; i < 5; ++i)	{ v.push_back(i); }
	std::cout << "v: "; displayVec(v);

	std::cout << std::endl << "==== Default Constructor ====" << std::endl;
	
	NS::vector<int> v1;
	std::cout << "v1: "; displayVec(v1);
	
	std::cout << "---- Constructor by range (v.begin(), v.end()) ----" << std::endl;

	const NS::vector<int> v2(v.begin(), v.end());
	std::cout << "v2: "; displayVec(v2);

	std::cout << "---- Constructor by copy v3(v2) ----" << std::endl;
	NS::vector<int> v3(v2);
	std::cout << "v3: "; displayVec(v3);

	std::cout << "---- Assignation of v1 = v2 ----" << std::endl;
	v1 = v2;
	std::cout << "v1: "; displayVec(v1);

	std::cout << std::endl << "==== ITERATORS ====" << std::endl;
	std::cout << "- Inc / Decrementations -------" << std::endl;
	NS::vector<int>::iterator it1 = v1.begin();
	std::cout << "v1: "; displayVec(v1);
	std::cout << "it1: " << *it1 << std::endl;
	++it1;
	std::cout << "++it1: " << *it1 << std::endl;
	it1 += 2;
	std::cout << "it1 += 2: " << *it1 << std::endl;
	it1--;
	std::cout << "it1--: " << *it1 << std::endl;
	--it1;
	std::cout << "--it1: " << *it1 << std::endl;
	it1++;
	std::cout << "it1++: " << *it1 << std::endl;
	it1 -= 2;
	std::cout << "it1 -= 2: " << *it1 << std::endl;
	
	std::cout << "- Binary Operations -------" << std::endl;
	NS::vector<int>::iterator it1bis = v1.begin();
	it1bis += 2;
	std::cout << "it1 - it1bis: " << it1 - it1bis << std::endl;
	std::cout << "it1bis - it1: " << it1bis - it1 << std::endl;
	std::cout << "it1 + 3: " << *(it1 + 3) << std::endl;
	std::cout << "it1: " << *it1 << std::endl;
	it1bis = it1 + 3;
	std::cout << "it1bis = it1 + 3: " << *it1bis << std::endl;
	std::cout << std::boolalpha << "it1bis < it1 : " << (it1bis < it1) << std::endl;
	std::cout << std::boolalpha << "it1bis > it1 : " << (it1bis > it1) << std::endl;
	it1bis -= 3;
	std::cout << "it1bis: " << *it1bis << std::endl;
	std::cout << std::boolalpha << "it1bis == it1 : " << (it1bis == it1) << std::endl;
	std::cout << "it1[0]: " << it1[0] << std::endl;
	std::cout << "it1[2]: " << it1[2] << std::endl;


	std::cout << std::endl << "==== v1 size ====" << std::endl;
	std::cout << "v1 size: " << v1.size() << std::endl;	

	std::cout << std::endl << "==== vector max size ====" << std::endl;
	std::cout << "std::vector: " << v.max_size() << std::endl;
	std::cout << "ft::vector: " << v1.max_size() << std::endl;
	
	std::cout << std::endl << "==== operator [] & at() ====" << std::endl;
	std::cout << "- Non const -------" << std::endl;
	std::cout << "v1[2]   : " << v1[2] << std::endl;
	std::cout << "v1.at(2): " << v1.at(2) << std::endl;
	try {
		std::cout << "v1.at(5): " << v1.at(5) << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	std::cout << "v1.at(2)++: " << v1.at(2)++ << std::endl;
	std::cout << "v1: "; displayVec(v1);
	std::cout << "--v1.at(2): " << --v1.at(2) << std::endl;
	std::cout << "v1: "; displayVec(v1);
	std::cout << "----  const -------" << std::endl;
	std::cout << "v2[2]   : " << v2[2] << std::endl;
	std::cout << "v2.at(2): " << v2.at(2) << std::endl;
	

	std::cout << std::endl << "==== front() back() ====" << std::endl;
	std::cout << "- Non const -------" << std::endl;
	std::cout << "v1.front(): " << v1.front() << std::endl;	
	std::cout << "v1.back()++: " << v1.back()++ << std::endl;
	std::cout << "v1.back(): " << v1.back() << std::endl;
	std::cout << "v1: "; displayVec(v1);

	std::cout << "----  const -------" << std::endl;
	std::cout << "v2.front(): " << v2.front() << std::endl;	
	std::cout << "v2.back(): " << v2.back() << std::endl;

	std::cout << std::endl << "==== resize() ====" << std::endl;
	std::cout << "-- resize(3) -------" << std::endl;
	v1.resize(3);
	std::cout << "v1: "; displayVec(v1);	
	std::cout << "v1 size: " << v1.size() << std::endl;	
	// std::cout << "it end: " << *v1.end() << std::endl;	
	std::cout << "v1 capacity: " << v1.capacity() << std::endl;	
	std::cout << "-- resize(3) -------" << std::endl;
	v1.resize(3);
	std::cout << "v1: "; displayVec(v1);	
	std::cout << "v1 size: " << v1.size() << std::endl;	
	std::cout << "v1 capacity: " << v1.capacity() << std::endl;	
	std::cout << "-- resize(4) -------" << std::endl;
	v1.resize(4);
	std::cout << "v1: "; displayVec(v1);	
	std::cout << "v1 size: " << v1.size() << std::endl;	
	std::cout << "v1 capacity: " << v1.capacity() << std::endl;	
	std::cout << "-- resize(6, 42) -------" << std::endl;
	v1.resize(6, 42);
	std::cout << "v1: "; displayVec(v1);	
	std::cout << "v1 size: " << v1.size() << std::endl;	
	std::cout << "v1 capacity: " << v1.capacity() << std::endl;	
	std::cout << "-- resize(17, 50) -------" << std::endl;
	v1.resize(17, 50);
	std::cout << "v1: "; displayVec(v1);	
	std::cout << "v1 size: " << v1.size() << std::endl;	
	std::cout << "v1 capacity: " << v1.capacity() << std::endl;	

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