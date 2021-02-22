/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 11:58:49 by julnolle          #+#    #+#             */
/*   Updated: 2021/02/22 15:12:57 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.hpp"
#include <stack>

#ifndef STD
# define NS ft
#else
# define NS std
#endif


int main(void)
{
	std::cout << "=== EMPTY STACK ===" << std::endl;
	NS::stack<int> st;
	std::cout << std::boolalpha << "empty: " << st.empty() << std::endl;
	std::cout << "size: " << st.size() << std::endl;
	
	std::cout << "=== PUSH ===" << std::endl;
	st.push(5);
	st.push(10);
	st.push(15);
	st.push(4);
	st.push(3);
	std::cout << std::boolalpha << "empty: " << st.empty() << std::endl;
	std::cout << "size: " << st.size() << std::endl;
	std::cout << "top: " << st.top() << std::endl;
	
	std::cout << "=== POP ===" << std::endl;
	st.pop();
	std::cout << "size: " << st.size() << std::endl;
	std::cout << "top: " << st.top() << std::endl;

	std::cout << "=== COPY CONSTRUCTOR ===" << std::endl;
	const NS::stack<int> st2(st);
	std::cout << "st2 size: " << st2.size() << std::endl;
	std::cout << "st2 top: " << st2.top() << std::endl;

	std::cout << "=== ASSIGNATION ===" << std::endl;
	NS::stack<int> st3;
	st3 = st2;
	std::cout << "st3 size: " << st3.size() << std::endl;
	std::cout << "st3 top: " << st3.top() << std::endl;

	std::cout << "=== COMPARISION ===" << std::endl;
	std::cout << std::boolalpha << "st == st3: " << (st == st3) << std::endl;
	std::cout << "--> st3.pop()" << std::endl;
	st3.pop();
	std::cout << std::boolalpha << "st != st3: " << (st != st3) << std::endl;
	std::cout << std::boolalpha << "st < st3: " << (st < st3) << std::endl;
	std::cout << std::boolalpha << "st > st3: " << (st > st3) << std::endl;
	std::cout << std::boolalpha << "st >= st3: " << (st >= st3) << std::endl;
	std::cout << std::boolalpha << "st <= st3: " << (st <= st3) << std::endl;
	

	return 0;
}