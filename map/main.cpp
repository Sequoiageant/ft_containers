/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 11:01:52 by julnolle          #+#    #+#             */
/*   Updated: 2021/02/19 16:38:33 by julnolle         ###   ########.fr       */
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
template<typename Key, typename Val>
void displayMapReverse(ft::map<Key, Val> &map)
{
	typename ft::map<Key, Val>::iterator it = --map.end();

	while(it != map.begin()) {
		std::cout << it->first << ": " << it->second << std::endl;
		--it;
	}
	std::cout << it->first << ": " << it->second << std::endl;
}
template<typename Key, typename Val>
void displayMapReverse(std::map<Key, Val> &map)
{
	typename std::map<Key, Val>::iterator it = --map.end();

	while(it != map.begin()) {
		std::cout << it->first << ": " << it->second << std::endl;
		--it;
	}
	std::cout << it->first << ": " << it->second << std::endl;
}

int main(void)
{
	typedef std::pair<char, int>	pair;

	
	ft::map<char, int> map;

	std::cout << std::boolalpha << "empty: " << map.empty() << std::endl;

	std::cout << "===== INSERT =====" << std::endl;

	map.insert(pair('a', 2));
	map.insert(pair('e', 12));
	map.insert(pair('c', 42));
	map.insert(pair('b', 3));
	map.insert(pair('d', 5));
	map.insert(pair('g', 10));
	map.insert(pair('f', 5));
	map.insert(pair('Z', 6));
	map.insert(pair('D', 7));
	map.insert(pair('E', 8));
	// map.insert(pair('h', 4));
	// map['H'] = 21;
	// map['H'] = 28;

	// displayMap(map);
	map.displayMap();
	
	// std::cout << std::endl << "===== ITERATOR =====" << std::endl;
	// std::cout << "------ reverse ------" << std::endl;
	// displayMapReverse(map);
	// ft::map<char, int>::iterator it = map.begin();
	// ++it;
	// ++it;
	// --it;
	// std::cout << "IT: " << it->first << std::endl;

	std::cout << "size: " << map.size() << std::endl;
	std::cout << std::boolalpha << "empty: " << map.empty() << std::endl;
	// std::cout << std::boolalpha << "find('b'): " << map.find('b') << std::endl;
	ft::map<char, int>::iterator find;
	find = map.find('b');
	std::cout << "find('b'): " << find->first << std::endl;
	std::cout << "count('x'): " << map.count('x') << std::endl;

	std::cout << std::endl << "===== ERASE =====" << std::endl;
	// std::cout << "erase('a') first time: " << map.erase('a') << std::endl;
	// std::cout << "erase('a') second try: " << map.erase('a') << std::endl;
	// map.insert(pair('a', 2));
	// map.erase('D');
	// map.erase('E');
	// map.erase('Z');
	// map.erase('e');
	map.erase('b');
	// map.erase('c');
	// map.insert(pair('U', 8));
	// map.displayMap();
	displayMap(map);
	displayMapReverse(map);
	std::cout << "size: " << map.size() << std::endl;
	
	std::cout << std::endl << "===== ITERATOR =====" << std::endl;
	
	ft::map<char, int>::iterator it = map.begin();
	ft::map<char, int>::iterator ite = map.end();
	++it;
	++it;
	++it;
	++it;
	--ite;
	// std::cout << "IT to erase: " << it->first << "," << it->second << std::endl;
	// map.erase(it);
	// map.erase(it, ite);
	map.insert(ite, pair('h', 4));
	map.insert(it, pair('b', 4));
	displayMap(map);
	// map.displayMap();
	// while(it != ite) {
	// 	std::cout << it->first << ": " << it->second << std::endl;
	// 	++it;
	// }

	// std::cout << std::endl << "===== REVERSE ITERATOR =====" << std::endl;
	// ft::map<char, int>::reverse_iterator itr = map.rbegin();
	// ft::map<char, int>::reverse_iterator itre = map.rend();
	// while(itr != itre) {
	// 	std::cout << itr->first << ": " << itr->second << std::endl;
	// 	++itr;
	// }
	
	std::cout << std::endl << "===== SWAP =====" << std::endl;

	ft::map<char, int> map3;

	map3.insert(pair('x', 100));
	map3.insert(pair('y', 200));
	displayMap(map3);

	// map3.swap(map);
	// map.displayMap();
	displayMap(map3);
	displayMap(map);

	ft::map<char, int>::const_iterator itc(it);
	while (itc != map.end())
	{
		std::cout << itc->first << std::endl;
		++itc;
	}
	std::cout << std::endl << "===== BOUND COMPARISON =====" << std::endl;

	std::cout << "lower_bound('i'): " << map.lower_bound('i')->first << std::endl;
	std::cout << "upper_bound('i'): "  << map.upper_bound('i')->first << std::endl;

	// ++it;
	// for (int i = 0; i < 30; ++i)
	// {
	// 	std::cout << "IT: " << it->first << ": " << it->second << std::endl;
	// 	++it;
	// }
	// for (int i = 0; i < 10; ++i)
	// {
	// 	std::cout << "IT: " << ite->first << ": " << ite->second << std::endl;
	// 	++ite;
	// }

	// --ite;
	// std::cout << "ite: " << ite->first << std::endl;
	// while(it != ite) {
	// std::cout << it->first << ": " << it->second << std::endl;
	// ++it;
	// }
	// std::cout << "it: " << it->first << std::endl;
	// ++it;
	// std::cout << "it: " << it->first << std::endl;
	// ++it;
	// std::cout << "it: " << it->first << std::endl;

	std::cout << std::endl << "===== CLEAR =====" << std::endl;
	map.clear();
	std::cout << std::boolalpha << "empty: " << map.empty() << std::endl;


/*
	std::cout << std::endl << "===== REAL MAP =====" << std::endl;


	std::map<char, int> map2;

	std::cout << std::boolalpha << "empty: " << map2.empty() << std::endl;

	map2.insert(pair('a', 2));
	map2.insert(pair('a', 5));
	map2.insert(pair('e', 12));
	map2.insert(pair('c', 42));
	map2.insert(pair('b', 3));
	map2.insert(pair('d', 5));
	map2.insert(pair('g', 10));
	map2.insert(pair('f', 5));
	map2.insert(pair('Z', 6));
	map2.insert(pair('D', 7));
	map2.insert(pair('E', 8));
	map2['H'] = 21;
	map2['H'] = 28;


	// displayMap(map2);
	// std::cout << "------ reverse ------" << std::endl;
	// displayMapReverse(map2);
	std::cout << "size: " << map2.size() << std::endl;
	std::cout << std::boolalpha << "empty: " << map2.empty() << std::endl;
	// std::cout << std::boolalpha << "find('b'): " << map2.find('b') << std::endl;

	// map2.erase('a');
	// map2.erase('b');
	// map2.erase('d');
	// map2.erase('e');
	std::cout << "size: " << map2.size() << std::endl;

	// displayMap(map2);
	std::map<char, int>::iterator it2 = map2.begin();
	// std::map<char, int>::iterator it2e = map2.end();
	// --it2e;
	// while(it2 != it2e) {
	// 	std::cout << it2->first << ": " << it2->second << std::endl;
	// 	++it2;
	// }
	for (int i = 0; i < 30; ++i)
	{
		std::cout << "IT: " << it2->first << ": " << it2->second << std::endl;
		--it2;
	}
	// for (int i = 0; i < 30; ++i)
	// {
	// 	std::cout << "IT: " << it2e->first << ": " << it2e->second << std::endl;
	// 	--it2e;
	// }

	std::cout << std::endl << "===== BOUND COMPARISON =====" << std::endl;
	std::cout << "lower_bound('i'): " << map2.lower_bound('i')->first << std::endl;
	std::cout << "upper_bound('i'): "  << map2.upper_bound('i')->first << std::endl;


	std::cout << "===== CLEAR =====" << std::endl;
	map2.clear();
	std::cout << std::boolalpha << "empty: " << map2.empty() << std::endl;
*/
	return 0;
}