/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:02:23 by anttorre          #+#    #+#             */
/*   Updated: 2024/08/19 16:55:16 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const char **argv)
{
	int i = 0;
	this->_len = 0;
	while (argv[++i] != NULL)
	{
		if (argv[i][0] == '\0')
			throw EmptyString();
		for (size_t j = 0; j < strlen(argv[i]); j++)
		{
			if (argv[i][j] == '-')
				throw NegativeValue();
			if (!isdigit(argv[i][j]))
			{
				std::cout << "At index: " << i << " value: " << argv[i] << "." << std::endl;
				throw NotADigit();
			}
		}
		if (atol(argv[i]) < INT_MIN || atol(argv[i]) > INT_MAX)
			throw IntOverflow();
		this->_list.push_back(atol(argv[i]));
		this->_vector.push_back(atol(argv[i]));
		this->_len++;
	}
}

void PmergeMe::printNumbers()
{
	for(std::list<int>::iterator it = this->_list.begin(); it != this->_list.end(); it++)
	{
		std::list<int>::iterator it2 = it;
		if (++it2 == this->_list.end())
			std::cout << *it << std::endl;
		else
			std::cout << *it << " ";
	}
}

int	PmergeMe::getLen() const
{
	return this->_len;
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}

PmergeMe::~PmergeMe()
{
}

PmergeMe& PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		this->_list = other._list;
		this->_vector = other._vector;
	}
	return *this;
}

const char *PmergeMe::EmptyString::what() const throw()
{
	return "Empty string.";
}

const char *PmergeMe::NotADigit::what() const throw()
{
	return "The string contains letters instead of digits.";
}

const char *PmergeMe::IntOverflow::what() const throw()
{
	return "Integer Overflow.";
}

const char *PmergeMe::NegativeValue::what() const throw()
{
	return "Negative Values are forbidden.";
}