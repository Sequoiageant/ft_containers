/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:17:44 by julnolle          #+#    #+#             */
/*   Updated: 2021/01/11 18:12:30 by julnolle         ###   ########.fr       */
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

	// ft::List<int> lst13(lst12);


	
/*	std::list<int> lst;
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
	std::cout << "lst size: " << lst.size() << std::endl;*/

/*	const int a = 8;
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
	std::cout << "lst12 size: " << lst12.size() << std::endl;*/


	// it12++; //ATTENTION SI ON INC TROP L'it => SEGFAULT
	// lst12.insert(it12, 3, 12);
	ft::List<int>::iterator it12 = lst12.begin();
	ft::List<int>::iterator ite12 = lst12.end();
	while (it12 != ite12)
	{
		std::cout << *it12 << ' ';
		++it12;
	}
	std::cout << std::endl;
	std::cout << "lst12 size: " << lst12.size() << std::endl;
	
	ft::List<int>::iterator it13 = lst12.begin();
	it13++;
	it13++;
	ft::List<int>::iterator itInserted = lst12.insert(it13, 88);

	it12 = lst12.begin();
	ite12 = lst12.end();
	while (it12 != ite12)
	{
		std::cout << *it12 << ' ';
		++it12;
	}
	std::cout << std::endl;
	std::cout << "lst12 size: " << lst12.size() << std::endl;
	std::cout << "itInserted: " << *itInserted << std::endl;

	
	ft::List<int> lst15(lst12);
	ft::List<int>::iterator it15 = lst15.begin();
	it15++;

	ft::List<int> lst16(it15, ++it15);
	ft::List<int>::iterator it16 = lst16.begin();
	ft::List<int>::iterator ite16 = lst16.end();
	while (it16 != ite16)
	{
		std::cout << *it16 << ' ';
		++it16;
	}
	std::cout << std::endl;

	it12 = lst12.begin();
	ite12 = lst12.end();


	lst12.erase(++it12);
	it12 = lst12.begin();
	while (it12 != ite12)
	{
		std::cout << *it12 << ' ';
		++it12;
	}
	std::cout << std::endl;

	it12 = lst12.begin();
	++it12;
	lst12.insert(it12, 3, 12);

	it12 = lst12.begin();
	while (it12 != ite12)
	{
		std::cout << *it12 << ' ';
		++it12;
	}
	std::cout << std::endl;

	it12 = lst12.begin();
	++it12;

	std::vector<int> v;
	v.push_back(42);
	v.push_back(43);
	v.push_back(44);
	lst12.insert(it12, v.begin(), v.end());

	it12 = lst12.begin();
	while (it12 != lst12.end())
	{
		std::cout << *it12 << ' ';
		++it12;
	}
	std::cout << std::endl;
	
	it12 = lst12.begin();
	ft::List<int>::iterator it12end = it12;
	++it12end;
	++it12end;
	++it12end;
	++it12end;
	lst12.erase(++it12, it12end);
	
	it12 = lst12.begin();
	while (it12 != lst12.end())
	{
		std::cout << *it12 << ' ';
		++it12;
	}
	std::cout << std::endl;

	ft::List<int>lst14;
	lst14.push_back(1);
	lst14.push_back(2);
	lst14.push_back(3);

	ft::List<int>::iterator it14 = lst14.begin();
	while (it14 != lst14.end())
	{
		std::cout << *it14 << ' ';
		++it14;
	}
	std::cout << std::endl;

	it12 = lst12.begin();
	lst12.splice(++it12, lst14);
	it12 = lst12.begin();
	while (it12 != lst12.end())
	{
		std::cout << *it12 << ' ';
		++it12;
	}
	std::cout << std::endl;

	return (0);
}
