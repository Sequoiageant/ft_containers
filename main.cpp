/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:17:44 by julnolle          #+#    #+#             */
/*   Updated: 2021/01/05 17:58:50 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "List.hpp"
#include <list>

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
