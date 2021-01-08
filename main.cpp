/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:17:44 by julnolle          #+#    #+#             */
/*   Updated: 2021/01/08 15:47:09 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "List.hpp"
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

int main(void)
{
/*	ft::List<int> lst(5, 3);
	lst.push_back(5);
	std::cout << "lst: "; lst.displayList();
	std::cout << "front: " << lst.front() << std::endl;
	std::cout << "back: " << lst.back() << std::endl;
	std::cout << "size: " << lst.size() << std::endl;
	std::cout << std::boolalpha << "lst empty: " << lst.empty() << std::endl;

	ft::List<int> lst2;
	std::cout << std::boolalpha << "lst2 empty: " << lst2.empty() << std::endl;

	lst2 = lst;
	std::cout << "lst2: "; lst2.displayList();

	ft::List<int> lst3(lst);
	std::cout << "lst3: "; lst3.displayList();
	std::cout << "lst3 rev: "; lst3.displayReverse();

	lst.push_front(2);
	std::cout << "lst: "; lst.displayList();
	lst.pop_front();
	std::cout << "lst: "; lst.displayList();
	lst.pop_back();
	std::cout << "lst: "; lst.displayList();
	std::cout << "lst size: " << lst.size() << std::endl;
	lst.resize(3, 2);
	std::cout << "lst: "; lst.displayList();
	std::cout << "lst size: " << lst.size() << std::endl;

	lst.resize(6, 4);
	std::cout << "lst: "; lst.displayList();
	std::cout << "lst size: " << lst.size() << std::endl;
	
	lst.clear();
	std::cout << "lst: "; lst.displayList();
	std::cout << "lst size: " << lst.size() << std::endl;

	ft::List<int> lst4(3, 4);
	ft::List<int> lst5(6, 3);
	std::cout << "lst4: "; lst4.displayList();
	std::cout << "lst5: "; lst5.displayList();
	lst4.swap(lst5);
	std::cout << "lst4: "; lst4.displayList();
	std::cout << "lst5: "; lst5.displayList();
	std::cout << "lst4 size: " << lst4.size() << std::endl;
	std::cout << "lst5 size: " << lst5.size() << std::endl;

	ft::List<int> lst6;
	lst6.push_back(1);
	lst6.push_back(1);
	lst6.push_back(42);
	lst6.push_back(2);
	lst6.push_back(3);
	lst6.push_back(39);
	lst6.push_back(4);
	lst6.push_back(1);
	lst6.push_back(5);
	lst6.push_back(10);
	lst6.push_back(1);

	std::cout << "lst6: "; lst6.displayList();
	std::cout << "lst6 size: " << lst6.size() << std::endl;

	lst6.remove(4);
	lst6.remove(1);
	// lst6.remove_if(single_digit);
	// lst6.remove_if(is_odd());
	std::cout << "lst6: "; lst6.displayList();
	std::cout << "lst6 size: " << lst6.size() << std::endl;

	ft::List<int> lst7;
	lst7.push_back(1);
	lst7.push_back(2);
	lst7.push_back(3);
	lst7.push_back(4);
	lst7.push_back(5);
	lst7.push_back(6);
	lst7.reverse();
	std::cout << "lst7: "; lst7.displayList();
	std::cout << "lst7 size: " << lst7.size() << std::endl;

	ft::List<int> lst8;
	lst8.push_back(42);
	lst8.push_back(3);
	lst8.push_back(12);
	lst8.push_back(3);
	lst8.push_back(100);
	lst8.push_back(100);
	lst8.push_back(42);
	lst8.push_back(3);
	lst8.push_back(28);
	lst8.push_back(1);
	lst8.sort();
	// lst8.sort(is_higher);
	// lst8.sort(is_lower());
	std::cout << "lst8: "; lst8.displayList();
	std::cout << "lst8 size: " << lst8.size() << std::endl;

	lst8.unique(same_as);
	std::cout << "lst8: "; lst8.displayList();
	std::cout << "lst8 size: " << lst8.size() << std::endl;

	ft::List<int> lst9(6, 3);
	lst9.unique();
	std::cout << "lst9: "; lst9.displayList();
	std::cout << "lst9 size: " << lst9.size() << std::endl;

*/	/*
	ft::List<int> first, second;
	first.push_back(42);
	first.push_back(3);
	first.push_back(12);
	first.push_back(3);
	first.push_back(43);

	second.push_back(42);
	second.push_back(3);
	second.push_back(12);
	second.push_back(3);
	second.push_back(43);
	second.push_back(5);
	second.push_back(6);
	first.sort();
 	second.sort();
	first.merge(second);
	std::cout << "my   contains: "; first.displayList();

	std::list<int> test1, test2;
	test1.push_back(42);
	test1.push_back(3);
	test1.push_back(12);
	test1.push_back(3);
	test1.push_back(43);

	test2.push_back(42);
	test2.push_back(3);
	test2.push_back(12);
	test2.push_back(3);
	test2.push_back(43);
	test2.push_back(5);
	test2.push_back(6);
 	// test1.sort();
 	// test2.sort();
	test1.merge(test2);
	std::cout << "real contains:";
	for (std::list<int>::iterator it=test1.begin(); it!=test1.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
*/
/*
	ft::List<char> lst10;

	lst10.push_back('d');
	lst10.push_back('c');
	lst10.push_back('b');
	lst10.push_back('a');
	lst10.sort();
	std::cout << "lst10: "; lst10.displayList();
	std::cout << "lst10 size: " << lst10.size() << std::endl;

	ft::List<std::string> lst11;

	lst11.push_back("efg");
	lst11.push_back("cde");
	lst11.push_back("bcd");
	lst11.push_back("abc");
	lst11.sort();
	std::cout << "lst11: "; lst11.displayList();
	std::cout << "lst11 size: " << lst11.size() << std::endl;
*/

	ft::List<int> lst12;
	lst12.push_back(1);
	lst12.push_back(3);
	lst12.push_back(5);
	lst12.push_back(7);
	lst12.push_back(9);
	std::cout << "lst12: "; lst12.displayList();

	ft::List<int> lst13(lst12);


	
	std::list<int> lst;
	lst.push_back(1);
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(7);
	lst.push_back(9);
	std::cout << "lst size: " << lst.size() << std::endl;

	std::vector<int> v;
	v.push_back(11);
	// v.push_back(13);
	// v.push_back(15);
	v.push_back(17);
	// v.push_back(19);
	// v.push_back(21);
	// std::vector<int>::iterator vit = v.begin();
	// std::vector<int>::iterator vite = v.end();


	

	std::list<int>::iterator itL = lst.begin();
	std::list<int>::iterator iteL = lst.end();
	itL++;
	lst.insert(itL, 3, 12);
	itL = lst.begin();
	while (itL != iteL)
	{
		std::cout << *itL << ' ';
		++itL;
	}
	std::cout << std::endl;
	std::cout << "lst size: " << lst.size() << std::endl;

	const int a = 8;
	unsigned int b = 12;
	lst12.assign(a,b);
	ft::List<int>::iterator it = lst12.begin();
	ft::List<int>::iterator ite = lst12.end();
	while (it != ite)
	{
		std::cout << *it << ' ';
		++it;
	}
	std::cout << std::endl;
	std::cout << "lst12 size: " << lst12.size() << std::endl;

	ft::List<int>::iterator it13 = lst13.begin();
	ft::List<int>::iterator ite13 = lst13.end();
	it13++;
	// it13++; //ATTENTION SI ON INC TROP L'it => SEGFAULT
	lst13.insert(it13, 3, 12);
	// ft::List<int>::iterator itInserted = lst13.insert(it13, 12);
	it13 = lst13.begin();
	while (it13 != ite13)
	{
		std::cout << *it13 << ' ';
		++it13;
	}
	std::cout << std::endl;
	std::cout << "lst13 size: " << lst13.size() << std::endl;
	// std::cout << "itInserted: " << *itInserted << std::endl;

	return (0);
}
