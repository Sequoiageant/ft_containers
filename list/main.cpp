/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:26:07 by julnolle          #+#    #+#             */
/*   Updated: 2021/01/28 16:55:23 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"
#include <list>
#include <vector>

#define NS ft

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
void displaylist(ft::list<T>& lst)
{
	typename ft::list<T>::iterator it = lst.begin();
	while (it != lst.end())
	{
		std::cout << *it << ' ';
		++it;
	}
	std::cout << std::endl;
}

template<typename T>
void displaylist(const ft::list<T>& lst)
{
	typename ft::list<T>::const_iterator it = lst.begin();
	while (it != lst.end())
	{
		std::cout << *it << ' ';
		++it;
	}
	std::cout << std::endl;
}

template<typename T>
void displaylist(std::list<T>& lst)
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
	NS::list<int> lst1;
	std::list<int> lst;

	std::vector<int> v;
	for (int i = 41; i < 46; ++i) { v.push_back(i); }
	
	NS::list<int> lst2;
	for (int i = 1; i < 5; ++i) { lst2.push_back(i); }

	std::cout << "---- empty ? ----" << std::endl;
	std::cout << std::boolalpha << "empty: " << lst1.empty() << std::endl;
	
	std::cout << "---- push_back ----" << std::endl;
	lst1.push_back(1);
	lst1.push_back(2);
	lst1.push_back(3);
	lst1.push_back(4);
	displaylist(lst1);

	std::cout << "---- empty ? ----" << std::endl;
	std::cout << std::boolalpha << "empty: " << lst1.empty() << std::endl;

	std::cout << "---- push_front ----" << std::endl;
	lst1.push_front(5);
	lst1.push_front(6);
	displaylist(lst1);
	std::cout << "---- pop_front & pop_back ----" << std::endl;
	lst1.pop_front();
	lst1.pop_back();
	displaylist(lst1);
	std::cout << "---- front & back ----" << std::endl;
	std::cout << "front: " << lst1.front() << std::endl;
	std::cout << "back : " << lst1.back() << std::endl;
	
	std::cout << "---- assign 3 x 42 ----" << std::endl;
	lst1.assign(3, 42);
	displaylist(lst1);

	std::cout << "---- assign vector(41, 42, 43, 44, 45) ----" << std::endl;
	lst1.assign(v.begin(), v.end());
	displaylist(lst1);	

	std::cout << "---- erase 41 - 43 - 45 by position ----" << std::endl;
	NS::list<int>::iterator it1 = lst1.begin();
	displaylist(lst1);
	lst1.erase(it1);
	displaylist(lst1);
	it1 = lst1.begin();
	lst1.erase(++it1);
	displaylist(lst1);
	it1 = lst1.begin();
	++it1;
	lst1.erase(++it1);
	displaylist(lst1);

	std::cout << "---- erase range [42 ; 44] ----" << std::endl;
	lst1.assign(v.begin(), v.end());
	displaylist(lst1);
	it1 = lst1.begin();
	NS::list<int>::iterator it1bis(++it1);
	it1bis++;
	it1bis++;
	it1bis++;
	lst1.erase(it1, it1bis);
	displaylist(lst1);

	std::cout << "---- insert 42 at 2nd position ----" << std::endl;
	it1 = lst1.begin();
	lst1.insert(++it1, 42);
	displaylist(lst1);

	std::cout << "---- insert 3 x 43 at 3rd position ----" << std::endl;
	it1 = lst1.begin();
	++it1;
	lst1.insert(++it1, 3, 43);
	displaylist(lst1);

	std::cout << "---- insert vector(5, 5, 5, 5) at 2nd position ----" << std::endl;
	v.assign(5, 5);
	it1 = lst1.begin();
	lst1.insert(++it1, v.begin(), v.end());
	displaylist(lst1);
	std::cout << "lst1 size: " << lst1.size() << std::endl;
	
	std::cout << "---- Resize to 15 with '1' ----" << std::endl;
	lst1.resize(15, 1);
	displaylist(lst1);
	std::cout << std::boolalpha << "size: " << lst1.size() << std::endl;

	std::cout << "---- Resize to 8 ----" << std::endl;
	lst1.resize(8, 5);
	displaylist(lst1);
	std::cout << std::boolalpha << "size: " << lst1.size() << std::endl;

	std::cout << "---- Splice lst2 into lst1 at 2nd position ----" << std::endl;
	it1 = lst1.begin();
	lst1.splice(++it1, lst2);
	displaylist(lst1);
	std::cout << "lst2 size: " << lst2.size() << std::endl;
	std::cout << std::boolalpha << "lst2 empty: " << lst2.empty() << std::endl;

	std::cout << "---- Splice 2nd elem of lst2 into lst1 at 2nd position ----" << std::endl;
	for (int i = 1; i < 5; ++i) { lst2.push_back(i); }
	it1 = lst1.begin();
	NS::list<int>::iterator it2 = lst2.begin();
	std::cout << "lst2 before splice: "; displaylist(lst2);
	lst1.splice(++it1, lst2, ++it2);
	displaylist(lst1);
	std::cout << "lst2 after splice: "; displaylist(lst2);

	std::cout << "---- Splice part of lst2 into lst1 at 2nd position ----" << std::endl;
	lst2.clear();
	for (int i = 1; i < 5; ++i) { lst2.push_back(i); }
	it1 = lst1.begin();
	it2 = lst2.begin();
	NS::list<int>::iterator it2end = lst2.end();
	std::cout << "lst2 before splice: "; displaylist(lst2);
	lst1.splice(++it1, lst2, ++it2, --it2end);
	displaylist(lst1);
	std::cout << "lst2 after splice: "; displaylist(lst2);

	std::cout << "---- Remove first(41), last(43) and 5 in lst1 ----" << std::endl;
	lst1.remove(41);
	lst1.remove(5);
	lst1.remove(43);
	displaylist(lst1);

	std::cout << "---- Remove if element < 10 in lst1 ----" << std::endl;
	lst1.remove_if(single_digit);
	displaylist(lst1);

	std::cout << "---- Unique : removes all consecutive doublon ----" << std::endl;
	lst1.clear();
	lst1.push_back(1);
	lst1.push_back(1);
	lst1.push_back(2);
	lst1.push_back(3);
	lst1.push_back(3);
	lst1.push_back(3);
	lst1.push_back(4);
	lst1.push_back(5);
	lst1.push_back(5);
	lst1.push_back(5);
	displaylist(lst1);
	lst1.unique();
	displaylist(lst1);

	std::cout << "---- Sort() ----" << std::endl;
	lst1.clear();
	lst1.push_back(9);
	lst1.push_back(1);
	lst1.push_back(5);
	lst1.push_back(7);
	lst1.push_back(3);
	displaylist(lst1);
	lst1.sort();
	displaylist(lst1);

	std::cout << "---- Merge lst1 with lst2 ----" << std::endl;
	lst2.clear();
	for (int i = 2; i < 11; i+=2) { lst2.push_back(i); }
	lst2.push_back(42);
	std::cout << "lst1: "; displaylist(lst1);
	std::cout << "lst2: "; displaylist(lst2);
	lst1.merge(lst2);
	std::cout << "lst1: "; displaylist(lst1);

	std::cout << "---- Reverse lst1 ----" << std::endl;
	displaylist(lst1);
	lst1.reverse();
	displaylist(lst1);

	std::cout << "---- Display lst1 with reverse iterator ----" << std::endl;
	
	NS::list<int>::reverse_iterator rit = lst1.rbegin();
	while(rit != lst1.rend()) {
		std::cout << *rit << ' ';
		++rit;
	}
	std::cout << std::endl;

	std::cout << "---- Swap lst1 with lst2 ----" << std::endl;
	std::cout << "lst1: "; displaylist(lst1);

	for (int i = 2; i < 11; i+=2) { lst2.push_back(i); }
	std::cout << "lst2: "; displaylist(lst2);
	
	lst1.swap(lst2);
	// lst2.push_back(100);
	std::cout << "lst1: "; displaylist(lst1);
	std::cout << "lst2: "; displaylist(lst2);

	std::cout << "---- Operator= 'lst2 = lst1' ----" << std::endl;
	lst2 = lst1;
	std::cout << "lst2: "; displaylist(lst2);

	std::cout << "---- Copy constructor: lst3(lst1) ----" << std::endl;
	NS::list<int> lst3(lst1);
	std::cout << "lst3: "; displaylist(lst3);

	std::cout << "---- Range constructor: lst4(v.begin, v.end) ----" << std::endl;
	const NS::list<int> lst4(v.begin(), v.end());
	std::cout << "v   : ";
	for (unsigned int i = 0; i < v.size(); ++i)
	{
		std::cout << v[i] << ' ';
	}
	std::cout << std::endl;
	std::cout << "lst4: "; displaylist(lst4);

	std::cout << "---- Clear() ----" << std::endl;
	lst1.clear();
	std::cout << std::boolalpha << "lst1 empty: " << lst1.empty() << std::endl;

	std::cout << "---- iterator ----" << std::endl;
	ft::list<int> lst5(5,5);
	ft::list<int>::iterator it5 = lst5.begin();
	std::cout << "lst5: "; displaylist(lst5);

	std::cout << "---- splice ----" << std::endl;
	std::cout << "lst2: "; displaylist(lst2);
	std::cout << "lst5: "; displaylist(lst5);
	
	std::cout << "---- splice lst2 into lst5 at 2nd pos ----" << std::endl;
	lst5.splice(++lst5.begin(), lst2);
	std::cout << "lst5: "; displaylist(lst5);

	std::cout << "---- splice lst6 (2nd pos) into lst5 before the end ----" << std::endl;
	NS::list<int> lst6(lst3);
	std::cout << "lst6: "; displaylist(lst6);
	lst5.splice(--lst5.end(), lst6, ++lst6.begin());
	std::cout << "lst5: "; displaylist(lst5);

	return (0);
}
