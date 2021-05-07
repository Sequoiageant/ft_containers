/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:35:39 by julnolle          #+#    #+#             */
/*   Updated: 2021/05/07 10:43:15 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP
# define QUEUE_HPP

# include <iostream>
# include <deque>


namespace ft {

template <class T, class Container = std::deque<T> >
	class queue {

	public:
		typedef typename Container::value_type		value_type;
		typedef typename Container::size_type		size_type;
		typedef Container							container_type;


		explicit queue (const container_type& ctnr = container_type()) : _container(ctnr)
		{
			// std::cout << "CONSTRUCTOR" << std::endl;
		}

		~queue(void) {}

		bool empty() const
		{
			return this->_container.empty();
		}	

		size_type size() const
		{
			return this->_container.size();
		}
		value_type& front()
		{
			return this->_container.front();
		}

		const value_type& front() const
		{
			return this->_container.front();
		}

		value_type& back()
		{
			return this->_container.back();
		}

		const value_type& back() const
		{
			return this->_container.back();
		}

		void push (const value_type& val)
		{
			this->_container.push_back(val);
		}

		void pop()
		{
			this->_container.pop_front();
		}

	template<typename T2, typename Cont>
	friend bool operator==(const queue<T2, Cont>&, const queue<T2, Cont>&);

	template<typename T2, typename Cont>
	friend bool operator<(const queue<T2, Cont>&, const queue<T2, Cont>&);


	protected:
		container_type _container;

	};

template <class T, class Container>
	bool operator== (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{
		return (lhs._container == rhs._container);	
	}

template <class T, class Container>
	bool operator!= (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{
		return !(lhs == rhs);	
	}

template <class T, class Container>
	bool operator<  (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{
		return (lhs._container < rhs._container);	
	}

template <class T, class Container>
	bool operator<= (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{
		return !(rhs < lhs);	
	}

template <class T, class Container>
	bool operator>  (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{
		return (rhs < lhs);	
	}

template <class T, class Container>
	bool operator>= (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{
		return !(lhs < rhs);	
	}

} // ft

#endif // QUEUE_HPP
