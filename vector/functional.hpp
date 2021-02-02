/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functional.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 12:44:55 by julnolle          #+#    #+#             */
/*   Updated: 2021/01/28 15:22:13 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONAL_HPP
# define FUNCTIONAL_HPP

namespace ft {

template<typename T>
	bool	equal_to(const T& val1, const T& val2)
	{
		return (val1 == val2);
	}

template<typename T>
	bool	less(const T& val1, const T& val2)
	{
		return (val1 < val2);
	}

// enable_if
template<bool Cond, class T = void>
	struct enable_if {};

template<class T>
	struct enable_if<true, T> { typedef T type; };

} // ft

#endif // FUNCTIONAL_HPP
