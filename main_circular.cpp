/*                                                                            */
/*                                                        :::      ::::::::   */
/* ************************************************************************** */
/*   main_circular.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:17:44 by julnolle          #+#    #+#             */
/*   Updated: 2021/01/15 11:53:16 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_circular.hpp"
#include <list>
#include <vector>

bool single_digit (const int& value) { return (value<10); }

struct is_odd {
	bool operator() (const int& value) { return (value%2)==1; }
};

bool is_higher (const int& value1, const int& value2) { return (value2 > value1); }

struct is_lower {
	bool operator() (const int& value1, const int& value2) { return (value2 < value1); }
};

bool same_as (int first, int second){ return ( int(first)==int(second) ); }


template<typename T>
void displaylist(T first, T last)
{
	while (first != last)
	{
		std::cout << *first << ' ';
		++first;
	}
	std::cout << std::endl;
}

template<typename T>
void displaylist(std::list<T> lst)
{
	typename std::list<T>::iterator it = lst.begin();
	while (it != lst.end())
	{
		std::cout << *it << ' ';
		++it;
	}
	std::cout << std::endl;
}

int main(void)
{
	ft::list<int> lst1;
	std::list<int> lst;

	std::cout << "---- empty ? ----" << std::endl;
	std::cout << std::boolalpha << "empty: " << lst1.empty() << std::endl;
	
	std::cout << "---- push_back ----" << std::endl;
	lst1.push_back(1);
	lst1.push_back(2);
	lst1.push_back(3);
	lst1.push_back(4);
	lst1.displaylist();

	std::cout << "---- empty ? ----" << std::endl;
	std::cout << std::boolalpha << "empty: " << lst1.empty() << std::endl;

	std::cout << "---- push_front ----" << std::endl;
	lst1.push_front(5);
	lst1.push_front(6);
	lst1.displaylist();
	std::cout << "---- pop_front & pop_back ----" << std::endl;
	lst1.pop_front();
	lst1.pop_back();
	lst1.displaylist();
	std::cout << "---- front & back ----" << std::endl;
	std::cout << lst1.front() << std::endl;
	std::cout << lst1.back() << std::endl;
	
	std::cout << "---- assign vector(41, 42, 43, 44, 45) ----" << std::endl;
	std::vector<int> v;
	for (int i = 41; i < 46; ++i) { v.push_back(i); }
	lst1.assign(v.begin(), v.end());
	lst1.displaylist();
	
	// std::cout << "---- assign(3, 42) ----" << std::endl;
	// lst1.assign(3, 43);
	// lst1.displaylist();

	std::cout << "---- erase 41 - 43 - 45 by position ----" << std::endl;
	ft::list<int>::iterator it1 = lst1.begin();
	lst1.displaylist();
	++it1;
	lst1.erase(it1);
	lst1.displaylist();
	it1 = lst1.begin();
	lst1.erase(++it1);
	lst1.displaylist();
	it1 = lst1.begin();
	lst1.erase(++it1);
	lst1.displaylist();

	std::cout << "---- erase range [42 ; 44] ----" << std::endl;
	lst1.assign(v.begin(), v.end());
	lst1.displaylist();
	it1 = lst1.begin();
	ft::list<int>::iterator it2(++it1);
	it2 += 3;
	lst1.erase(it1, it2);
	lst1.displaylist();

	// lst.assign(v.begin(), v.end());
	// std::list<int>::iterator it = lst.begin();
	// for (int i = 0; i < 5; ++i)
	// {
	// 	std::cout << *it++ << ' ';
	// }
	// std::cout << std::endl;
	// lst.erase(it);

	std::cout << "---- insert 42 at 2nd position ----" << std::endl;
	it1 = lst1.begin();
	lst1.insert(++it1, 42);
	lst1.displaylist();

	std::cout << "---- insert 3 x 43 at 3rd position ----" << std::endl;
	it1 = lst1.begin();
	++it1;
	lst1.insert(++it1, 3, 43);
	lst1.displaylist();

	return (0);
}
