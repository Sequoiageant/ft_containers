/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:40:37 by julnolle          #+#    #+#             */
/*   Updated: 2021/02/22 15:40:58 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.hpp"
#include <queue>

#ifndef STD
# define NS ft
#else
# define NS std
#endif


int main(void)
{
	std::cout << "=== EMPTY QUEUE ===" << std::endl;
	NS::queue<int> qu;
	std::cout << std::boolalpha << "empty: " << qu.empty() << std::endl;
	std::cout << "size: " << qu.size() << std::endl;
	
	std::cout << "=== PUSH ===" << std::endl;
	qu.push(5);
	qu.push(10);
	qu.push(15);
	qu.push(4);
	qu.push(3);
	std::cout << std::boolalpha << "empty: " << qu.empty() << std::endl;
	std::cout << "size: " << qu.size() << std::endl;
	std::cout << "front: " << qu.front() << std::endl;
	std::cout << "back: " << qu.back() << std::endl;
	
	std::cout << "=== POP ===" << std::endl;
	qu.pop();
	std::cout << "size: " << qu.size() << std::endl;
	std::cout << "front: " << qu.front() << std::endl;
	std::cout << "back: " << qu.back() << std::endl;

	std::cout << "=== COPY CONSTRUCTOR ===" << std::endl;
	const NS::queue<int> qu2(qu);
	std::cout << "qu2 size: " << qu2.size() << std::endl;
	std::cout << "qu2 front: " << qu2.front() << std::endl;
	std::cout << "qu2 back: " << qu2.back() << std::endl;

	std::cout << "=== ASSIGNATION ===" << std::endl;
	NS::queue<int> qu3;
	qu3 = qu2;
	std::cout << "qu3 size: " << qu3.size() << std::endl;
	std::cout << "qu3 front: " << qu3.front() << std::endl;
	std::cout << "qu3 back: " << qu3.back() << std::endl;

	std::cout << "=== COMPARISION ===" << std::endl;
	std::cout << std::boolalpha << "qu == qu3: " << (qu == qu3) << std::endl;
	std::cout << "--> qu3.pop()" << std::endl;
	qu3.pop();
	std::cout << std::boolalpha << "qu != qu3: " << (qu != qu3) << std::endl;
	std::cout << std::boolalpha << "qu < qu3: " << (qu < qu3) << std::endl;
	std::cout << std::boolalpha << "qu > qu3: " << (qu > qu3) << std::endl;
	std::cout << std::boolalpha << "qu >= qu3: " << (qu >= qu3) << std::endl;
	std::cout << std::boolalpha << "qu <= qu3: " << (qu <= qu3) << std::endl;
	

	return 0;
}