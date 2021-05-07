/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integral_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 10:49:03 by julnolle          #+#    #+#             */
/*   Updated: 2021/05/07 10:46:18 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTEGRAL_TRAITS_HPP
# define INTEGRAL_TRAITS_HPP

# include <string>
# include <iostream>

namespace ft
{
	template <typename T> 
	struct is_integral 
	{ static const bool value = false; };

	template <> 
	struct is_integral<bool> 
	{ static const bool value = true; };
	
	template <> 
	struct is_integral<char> 
	{ static const bool value = true; };
		
	template <> 
	struct is_integral<wchar_t> 
	{ static const bool value = true; };
	
	template <> 
	struct is_integral<signed char> 
	{ static const bool value = true; };
	
	template <> 
	struct is_integral<short int> 
	{ static const bool value = true; };
	
	template <> 
	struct is_integral<int> 
	{ static const bool value = true; };
	
	template <> 
	struct is_integral<long int> 
	{ static const bool value = true; };
	
	template <> 
	struct is_integral<long long int> 
	{ static const bool value = true; };
	
	template <> 
	struct is_integral<unsigned char> 
	{ static const bool value = true; };
	
	template <> 
	struct is_integral<unsigned short int> 
	{ static const bool value = true; };
	
	template <> 
	struct is_integral<unsigned int> 
	{ static const bool value = true; };
	
	template <> 
	struct is_integral<unsigned long int> 
	{ static const bool value = true; };

	template <> 
	struct is_integral<unsigned long long int> 
	{ static const bool value = true; };

} // ft

#endif // INTEGRAL_TRAITS_HPP
