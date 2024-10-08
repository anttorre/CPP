/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:02:23 by anttorre          #+#    #+#             */
/*   Updated: 2024/08/21 15:30:00 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const char **argv)
{
	int i = 0;
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
	}
	if (check_duplicates(this->_list.begin(), this->_list.end()))
		throw DuplicatedNumbers();
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

bool PmergeMe::check_duplicates(std::list<int>::iterator begin, std::list<int>::iterator end)
{
	for (std::list<int>::iterator it = begin; it != end; it++)
	{
		std::list<int>::iterator next = it;
		++next;
		for (std::list<int>::iterator it2 = next; it2 != end; it2++)
		{
			if (*it == *it2)
				return true;
		}
	}
	return false;
}

int	PmergeMe::getLen() const
{
	return this->_list.size();
}

std::list<int>& PmergeMe::getList()
{
	return this->_list;
}

std::vector<int>& PmergeMe::getVector()
{
	return this->_vector;
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

const char *PmergeMe::DuplicatedNumbers::what() const throw()
{
	return "Duplicated numbers given.";
}