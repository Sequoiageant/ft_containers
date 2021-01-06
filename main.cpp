/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:17:44 by julnolle          #+#    #+#             */
/*   Updated: 2021/01/06 18:07:17 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "List.hpp"
#include <list>

bool single_digit (const int& value) { return (value<10); }

struct is_odd {
  bool operator() (const int& value) { return (value%2)==1; }
};

bool is_higher (const int& value1, const int& value2) { return (value2 > value1); }

struct is_lower {
  bool operator() (const int& value1, const int& value2) { return (value2 < value1); }
};

int main(void)
{
	ft::List<int> lst(5, 3);
	lst.push_back(5);
	std::cout << "lst: "; lst.displayList();
	std::cout << "front: " << lst.front() << std::endl;
	std::cout << "back: " << lst.back() << std::endl;
	std::cout << "size: " << lst.size() << std::endl;
	std::cout << std::boolalpha << "empty: " << lst.empty() << std::endl;

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

	// lst6.remove(4);
	// lst6.remove(1);
	// lst6.remove_if(single_digit);
	lst6.remove_if(is_odd());
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
	lst8.push_back(3);
	lst8.push_back(28);
	lst8.push_back(1);
	// lst8.sort();
	// lst8.sort(is_higher);
	lst8.sort(is_lower());
	std::cout << "lst8: "; lst8.displayList();
	std::cout << "lst8 size: " << lst8.size() << std::endl;

	// lst8.unique();
	// std::cout << "lst8: "; lst8.displayList();
	// std::cout << "lst8 size: " << lst8.size() << std::endl;

	// std::list<int> lst4(5, 1);
	// lst4.pop_back();
	// lst4.pop_back();
	// lst4.pop_back();
	// lst4.pop_back();
	// // lst4.pop_back();
	// lst4.pop_front();
	// // lst4.pop_front();

	return (0);
}
