/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 11:01:52 by julnolle          #+#    #+#             */
/*   Updated: 2021/02/08 19:26:09 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"
// #include "Fixed.hpp"
#include <vector>
#include <list>
#include <map>

#ifndef STD
# define NS ft
#else
# define NS std
#endif

template<typename Key, typename Val>
void displayMap(ft::map<Key, Val> &map)
{
	typename ft::map<Key, Val>::iterator it = map.begin();

	while(it != map.end()) {
		std::cout << it->first << ": " << it->second << std::endl;
		++it;
	}
	std::cout << std::endl;
}

template<typename Key, typename Val>
void displayMap(std::map<Key, Val> &map)
{
	typename std::map<Key, Val>::iterator it = map.begin();

	while(it != map.end()) {
		std::cout << it->first << ": " << it->second << std::endl;
		++it;
	}
	std::cout << std::endl;
}

int main(void)
{
	typedef std::pair<char, int>	pair;

	ft::map<char, int> map;

	std::cout << std::boolalpha << "empty: " << map.empty() << std::endl;

	map.insert(pair('a', 2));
	map.insert(pair('e', 12));
	map.insert(pair('c', 42));
	map.insert(pair('b', 3));
	map.insert(pair('d', 5));
	map.insert(pair('g', 5));
	map.insert(pair('f', 5));
	map.insert(pair('Z', 6));
	map.insert(pair('D', 7));
	map.insert(pair('E', 8));

	map.displayMap();
	displayMap(map);
	std::cout << "size: " << map.size() << std::endl;
	std::cout << std::boolalpha << "empty: " << map.empty() << std::endl;
	std::cout << std::boolalpha << "find('b'): " << map.find('b') << std::endl;

	// std::cout << "CLEAR" << std::endl;
	map.erase('c');
	map.erase('b');
	map.erase('d');
	map.erase('e');
	// map.erase('b');
	map.displayMap();
	displayMap(map);
	std::cout << "size: " << map.size() << std::endl;

	// ft::map<char, int>::iterator it = map.begin();
	// std::cout << "it: " << it->first << std::endl;
	// ++it;
	// std::cout << "it: " << it->first << std::endl;
	// ++it;
	// std::cout << "it: " << it->first << std::endl;


	std::cout << "===== CLEAR =====" << std::endl;
	map.clear();
	std::cout << std::boolalpha << "empty: " << map.empty() << std::endl;


	std::cout << std::endl << "===== REAL MAP =====" << std::endl;


	std::map<char, int> map2;

	std::cout << std::boolalpha << "empty: " << map2.empty() << std::endl;

	map2.insert(pair('a', 2));
	map2.insert(pair('e', 12));
	map2.insert(pair('c', 42));
	map2.insert(pair('b', 3));
	map2.insert(pair('d', 5));
	map2.insert(pair('g', 5));
	map2.insert(pair('f', 5));
	map2.insert(pair('Z', 6));
	map2.insert(pair('D', 7));
	map2.insert(pair('E', 8));

	displayMap(map2);
	std::cout << "size: " << map2.size() << std::endl;
	std::cout << std::boolalpha << "empty: " << map2.empty() << std::endl;
	// std::cout << std::boolalpha << "find('b'): " << map2.find('b') << std::endl;

	map2.erase('c');
	map2.erase('b');
	map2.erase('d');
	map2.erase('e');
	std::cout << "size: " << map2.size() << std::endl;

	displayMap(map2);


	std::cout << "===== CLEAR =====" << std::endl;
	map2.clear();
	std::cout << std::boolalpha << "empty: " << map2.empty() << std::endl;

	return 0;
}