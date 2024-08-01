/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:08:32 by anttorre          #+#    #+#             */
/*   Updated: 2024/07/19 16:13:50 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename T>
class Array
{
	private:
		T               *_arr;
		unsigned int    _size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		Array &operator=(const Array &other);
		~Array();

		unsigned int size(void) const;
		T &operator[](unsigned int i);
		
		class OutOfBoundsException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
};

#include "Array.tpp"