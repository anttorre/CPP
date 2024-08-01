/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:51:07 by anttorre          #+#    #+#             */
/*   Updated: 2024/07/30 14:06:17 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

class Span
{
	private:
		std::vector<int> _vec;
		unsigned int _maxSize;
		Span();
	public:
		Span(unsigned int n);
		Span(const Span &other);
		~Span();
		Span& operator=(Span &other);
		void addNumber(int n);
		void addNumber(std::vector<int>::iterator b, std::vector<int>::iterator e);
		int shortestSpan();
		int longestSpan();
		unsigned int getSize() const;
		int getNumber(int n);
		class MaxSizeReached : public std::exception
		{
			public:
				const char * what() const throw();
		};
		class IndexNotFound : public std::exception
		{
			public:
				const char * what() const throw();
		};
		class EmptyOrOneElement : public std::exception
		{
			public:
				const char * what() const throw();
		};
};
