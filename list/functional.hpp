/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functional.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 12:44:55 by julnolle          #+#    #+#             */
/*   Updated: 2021/01/16 12:59:58 by julnolle         ###   ########.fr       */
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

} // ft

#endif // FUNCTIONAL_HPP
