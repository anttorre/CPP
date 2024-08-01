/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:51:11 by anttorre          #+#    #+#             */
/*   Updated: 2024/07/30 13:00:34 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
}

Span::Span(unsigned int n)
{
	this->_maxSize = n;
}

Span::Span(const Span &other) : _vec(other._vec), _maxSize(other._maxSize)
{
}

Span::~Span()
{
}

Span& Span::operator=(Span &other)
{
	if (this != &other)
	{
		this->_maxSize = other._maxSize;
		this->_vec = other._vec;
	}
	return *this;
}

void Span::addNumber(int n)
{
	if (this->_vec.size() >= this->_maxSize)
		throw MaxSizeReached();
	this->_vec.push_back(n);
}

void Span::addNumber(std::vector<int>::iterator b, std::vector<int>::iterator e)
{
	if (this->_vec.size() + std::distance(b, e) > this->_maxSize)
		throw MaxSizeReached();
	this->_vec.insert(this->_vec.end(), b, e);
}

unsigned int Span::getSize() const
{
	return this->_vec.size();
}

int Span::getNumber(int n)
{
	if (this->_vec.size() == 0)
		throw EmptyOrOneElement();
	if (n >= (int)this->_vec.size() || n < 0)
		throw IndexNotFound();
	if (this->_vec[n])
		return this->_vec[n];
	return -1;
}

int Span::shortestSpan()
{
	if (this->_vec.size() <= 1)
		throw Span::EmptyOrOneElement();
	int min = INT_MAX;
	std::sort(this->_vec.begin(), this->_vec.end());
	for (std::vector<int>::iterator i = this->_vec.begin(); i < this->_vec.end() - 1; i++)
	{
		std::vector<int>::iterator next = i + 1;
		while (next < this->_vec.end())
		{
			if (*next - *i < min)
				min = *next - *i;
			next++;
		}
	}
	return min;
}

int Span::longestSpan()
{
	if (this->_vec.size() <= 1)
		throw Span::EmptyOrOneElement();
	int max = INT_MIN;
	std::sort(this->_vec.begin(), this->_vec.end());
	for (std::vector<int>::iterator i = this->_vec.begin(); i < this->_vec.end() - 1; i++)
	{
		std::vector<int>::iterator next = i + 1;
		while (next < this->_vec.end())
		{
			if (*next - *i > max)
				max = *next - *i;
			next++;
		}
	}
	return max;
}

const char * Span::MaxSizeReached::what() const throw()
{
	return "Max size limit reached.";
}

const char * Span::IndexNotFound::what() const throw()
{
	return "Index out of bounds.";
}

const char * Span::EmptyOrOneElement::what() const throw()
{
	return "Empty span or one element.";
}