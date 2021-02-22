/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 11:58:57 by julnolle          #+#    #+#             */
/*   Updated: 2021/02/22 15:24:59 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include <iostream>
# include <deque>


namespace ft {

template <class T, class Container = std::deque<T> >
	class stack {

	public:
		typedef typename Container::value_type		value_type;
		typedef typename Container::size_type		size_type;
		typedef Container							container_type;


		explicit stack (const container_type& ctnr = container_type()) : _container(ctnr)
		{
			// std::cout << "CONSTRUCTOR" << std::endl;
		}

/*		stack (const stack& copy) : _container(copy._container) {
			std::cout << " CPY CONSTRUCTOR" << std::endl;

		}

		stack& operator=(stack const & rhs)
		{
			std::cout << "ASSI" << std::endl;
			this->_container = rhs._container;
			return *this;
		}
		~stack(void) {}
*/

		bool empty() const
		{
			return this->_container.empty();
		}	

		size_type size() const
		{
			return this->_container.size();
		}
		value_type& top()
		{
			return this->_container.back();
		}

		const value_type& top() const
		{
			return this->_container.back();
		}

		void push (const value_type& val)
		{
			this->_container.push_back(val);
		}

		void pop()
		{
			this->_container.pop_back();
		}

	template<typename T2, typename Cont>
	friend bool operator==(const stack<T2, Cont>&, const stack<T2, Cont>&);

	template<typename T2, typename Cont>
	friend bool operator<(const stack<T2, Cont>&, const stack<T2, Cont>&);


	protected:
		container_type _container;

	};

template <class T, class Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs._container == rhs._container);	
	}

template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return !(lhs == rhs);	
	}

template <class T, class Container>
	bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs._container < rhs._container);	
	}

template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return !(rhs < lhs);	
	}

template <class T, class Container>
	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (rhs < lhs);	
	}

template <class T, class Container>
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return !(lhs < rhs);	
	}

} // ft

#endif // STACK_HPP
