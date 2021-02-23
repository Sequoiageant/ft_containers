/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 11:01:52 by julnolle          #+#    #+#             */
/*   Updated: 2021/02/23 18:24:38 by julnolle         ###   ########.fr       */
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

	
	std::cout << "===== EMPTY MAP =====" << std::endl;
	NS::map<char, int> map;
	// NS::map<char, int>::iterator itf = map.begin();
	// std::cout << "begin(): " << itf->first << std::endl;

	std::cout << std::boolalpha << "empty: " << map.empty() << std::endl;
	std::cout << "size: " << map.size() << std::endl;

	std::cout << "===== INSERT =====" << std::endl;
	std::pair<NS::map<char,int>::iterator,bool> insert_pair; // for insert return

	map.insert(pair('a', 2));
	map.insert(pair('e', 12));
	map.insert(pair('c', 42));
	map.insert(pair('b', 3));
	map.insert(pair('d', 5));
	map.insert(pair('g', 10));
	map.insert(pair('f', 5));
	map.insert(pair('Z', 6));
	map.insert(pair('D', 7));
	insert_pair = map.insert(pair('E', 8));
	// map.insert(pair('h', 4));
	// map['H'] = 21;
	// map['H'] = 28;
	displayMap(map);
	std::cout << "size: " << map.size() << std::endl;
	std::cout << "last insert it: " << insert_pair.first->first << std::endl;

	std::cout << "--- Insert already-in values ---" << std::endl;
	map.insert(pair('a', 2));
	insert_pair = map.insert(pair('Z', 6));
	
	displayMap(map);
	std::cout << "size: " << map.size() << std::endl;
	std::cout << "last insert try: " << insert_pair.first->first << std::endl;
	
	std::cout << "---- Insert at position ----" << std::endl;
	map.erase('b'); // Erase b to insert it at same position after
	
	NS::map<char, int>::iterator it = map.begin();
	NS::map<char, int>::iterator ite = map.end();
	++it;
	++it;
	++it;
	++it;
	map.insert(it, pair('b', 4));
	displayMap(map);


	std::cout << std::endl << "===== COPY CONSTRUCTOR map2(map) =====" << std::endl;
	NS::map<char, int> map2(map);
	std::cout << "map2:" << std::endl; displayMap(map2);

	std::cout << std::endl << "===== ASSIGNATION map3 = map; =====" << std::endl;
	NS::map<char, int> map3;
	map3 = map;
	std::cout << "map3:" << std::endl; displayMap(map3);


	std::cout << std::endl << "===== ERASE =====" << std::endl;

	std::cout << "--- Erase the Root ---" << std::endl;
	std::cout << "erase('a') first time: " << map.erase('a') << std::endl;
	displayMap(map);

	std::cout << "--- Try Erase 2nd time ---" << std::endl;
	std::cout << "erase('a') second try: " << map.erase('a') << std::endl;

	std::cout << "--- Erase the leaf 'E' ---" << std::endl;
	map.erase('E');
	displayMap(map);

	std::cout << "--- Erase a node with L & R: 'e' ---" << std::endl;
	map.erase('e');
	displayMapReverse(map);
	std::cout << "size: " << map.size() << std::endl;

	std::cout << "--- Erase begin() ---" << std::endl;
	it = map.begin();
	std::cout << "begin(): " << it->first << std::endl;
	map.erase(it);
	displayMap(map);

	std::cout << "--- Erase Range ---" << std::endl;
	it = map.begin();
	map.erase(++it, ite);
	displayMap(map);
	std::cout << "size: " << map.size() << std::endl;


	std::cout << std::endl << "===== [ ] =====" << std::endl;
	map['a'] = 5;
	map['F'] = 3;
	map['d'] = 4;
	map['d'] = 1;
	displayMap(map);
	std::cout << "--- map['a'] = 42 ---" << std::endl;
	map['a'] = 42;
	std::cout << "map['a']: " << map['a'] << std::endl;
	std::cout << "--- map['g'] ---" << std::endl;
	std::cout << "map['g']: " << map['g'] << std::endl;
	displayMap(map);


	std::cout << std::endl << "===== ITERATOR =====" << std::endl;
	displayMap(map2);
	NS::map<char, int>::iterator it2 = map2.begin();

	std::cout << "--- operator++ et operator-- ---" << std::endl;
	std::cout << "(++it2)->first: " << (++it2)->first << std::endl;
	std::cout << "(++it2)->first: " << (++it2)->first << std::endl;
	std::cout << "(it2++)->first: " << (it2++)->first << std::endl;
	std::cout << "it2->first: " << it2->first << std::endl;
	std::cout << "(--it2)->first: " << (--it2)->first << std::endl;
	std::cout << "(it2--)->first: " << (it2--)->first << std::endl;
	std::cout << "it2->first: " << it2->first << std::endl;

	std::cout << std::endl << "--- iterator comparison-- ---" << std::endl;
	it2 = map2.begin();
	NS::map<char, int>::iterator it2bis = map2.begin();
	std::cout << "(it2 == it2bis): " << (it2 == it2bis) << std::endl;
	std::cout << "(++it2 == it2bis): " << (++it2 == it2bis) << std::endl;
	std::cout << "(it2 != it2bis): " << (it2 != it2bis) << std::endl;

	std::cout << std::endl << "--- const iterator-- ---" << std::endl;
	NS::map<char, int>::const_iterator it2c = map2.begin();
	
	std::cout << "(++it2c)->first: " << (++it2c)->first << std::endl;
	std::cout << "(--it2c)->first: " << (--it2c)->first << std::endl;

	std::cout << std::endl << "===== REVERSE ITERATOR =====" << std::endl;
	NS::map<char, int>::reverse_iterator itr = map2.rbegin();
	NS::map<char, int>::reverse_iterator itre = map2.rend();
	while(itr != itre) {
		std::cout << itr->first << ": " << itr->second << std::endl;
		++itr;
	}

	std::cout << std::endl << "===== FIND =====" << std::endl;
	NS::map<char, int>::iterator find;
	NS::map<char, int>::iterator findx;
	find = map2.find('b');
	findx = map2.find('x');
	std::cout << "map2:" << std::endl; displayMap(map2);
	std::cout << "find('b'): " << find->first << std::endl;
	if (findx->first)
		std::cout << "find('x'): " << findx->first << std::endl;
	else
		std::cout << "find('x'): " << "\n" << std::endl;
	std::cout << "count('b'): " << map2.count('b') << std::endl;
	std::cout << "count('x'): " << map2.count('x') << std::endl;
	
	std::cout << std::endl << "===== SWAP =====" << std::endl;

	NS::map<char, int> map4;

	map4.insert(pair('x', 100));
	map4.insert(pair('y', 200));
	std::cout << "map2" << std::endl; displayMap(map2);
	std::cout << "map4" << std::endl; displayMap(map4);

	std::cout << "---> SWAP <---" << std::endl;
	map4.swap(map2);
	std::cout << "map2" << std::endl; displayMap(map2);
	std::cout << "map4" << std::endl; displayMap(map4);

	std::cout << std::endl << "===== MAX SIZE =====" << std::endl;
	NS::map<char,int> map5;
	std::cout << "max size: " << map5.max_size() << std::endl;


	std::cout << std::endl << "===== BOUND COMPARISON =====" << std::endl;

	if (map3.lower_bound('i')->first)
		std::cout << "lower_bound('i'): " << map3.lower_bound('i')->first << std::endl;
	else
		std::cout << "lower_bound('i'): " << "\n" << std::endl;

	std::cout << "lower_bound('C'): " << map3.lower_bound('C')->first << std::endl;
	std::cout << "lower_bound('b'): " << map3.lower_bound('b')->first << std::endl;
	if (map3.lower_bound('i')->first)
		std::cout << "upper_bound('i'): " << map3.upper_bound('i')->first << std::endl;
	else
		std::cout << "upper_bound('i'): " << "\n" << std::endl;
	std::cout << "upper_bound('C'): "  << map3.upper_bound('C')->first << std::endl;
	std::cout << "upper_bound('b'): "  << map3.upper_bound('b')->first << std::endl;

	std::cout << std::endl << "===== EQUAL RANGE =====" << std::endl;

	std::pair<NS::map<char,int>::iterator, NS::map<char,int>::iterator> range;
	range = map3.equal_range('a');
	std::cout << range.first->first << std::endl;
	std::cout << range.second->first << std::endl;
	range = map3.equal_range('x');
	if (range.first->first)
		std::cout << range.first->first << std::endl;
	else
		std::cout << "\n" << std::endl;

	if (range.second->first)
		std::cout << range.second->first << std::endl;
	else
		std::cout << "\n" << std::endl;

	std::cout << std::endl << "=== COMPARISION ===" << std::endl;
	std::cout << "map3: " << std::endl;	displayMap(map3);
	std::cout << "map4: " << std::endl;	displayMap(map4);
	std::cout << std::boolalpha << "map4 == map3: " << (map4 == map3) << std::endl;
	std::cout << std::boolalpha << "map4 != map3: " << (map4 != map3) << std::endl;

	std::cout << "---> map3.erase('Z')" << std::endl; map3.erase('Z');
	std::cout << std::boolalpha << "map4 < map3: " << (map4 < map3) << std::endl;
	std::cout << std::boolalpha << "map4 > map3: " << (map4 > map3) << std::endl;
	std::cout << std::boolalpha << "map4 >= map3: " << (map4 >= map3) << std::endl;
	std::cout << std::boolalpha << "map4 <= map3: " << (map4 <= map3) << std::endl;
	
	
	std::cout << std::endl << "=== KEY_COMP - VALUE_COMP ===" << std::endl;

	NS::map<char,int>::iterator it4 = map4.begin();
	NS::map<char,int>::iterator it4bis = it4++;
	
	std::map<char,int>::key_compare mycomp = map4.key_comp();
	std::cout << std::boolalpha << mycomp(it4->first, it4bis->first) << std::endl;
	std::cout << std::boolalpha << mycomp(it4bis->first, it4->first) << std::endl;
	std::cout << std::boolalpha << map4.value_comp() (*it4, *it4bis) << std::endl;
	std::cout << std::boolalpha << map4.value_comp() (*it4bis, *it4) << std::endl;

	std::cout << std::endl << "===== CLEAR =====" << std::endl;
	std::cout << std::boolalpha << "map empty: " << map.empty() << std::endl;
	std::cout << "---> clear()" << std::endl;
	map.clear();
	std::cout << std::boolalpha << "empty: " << map.empty() << std::endl;

	return 0;
}