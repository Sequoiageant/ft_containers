/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 11:01:52 by julnolle          #+#    #+#             */
/*   Updated: 2021/02/03 19:57:44 by julnolle         ###   ########.fr       */
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

int main(void)
{
	typedef std::pair<char, int>	pair;

	ft::map<char, int> map;

	map.insert(pair('a', 2));
	map.insert(pair('b', 3));
	map.insert(pair('d', 5));
	map.insert(pair('e', 12));
	map.insert(pair('c', 42));
	map.insert(pair('Z', 6));
	map.insert(pair('D', 7));
	map.insert(pair('E', 8));

	map.displayMap();


	return 0;
}