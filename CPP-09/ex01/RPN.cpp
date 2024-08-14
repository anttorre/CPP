/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 13:08:28 by anttorre          #+#    #+#             */
/*   Updated: 2024/08/14 16:44:22 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(std::string s)
{
	if (s.empty())
		throw EmptyString();
	size_t i = s.find(" ");
	size_t next;
	std::string n1 = s.substr(0, i);
	double n2 = atof(n1.c_str());
	std::cout << n2 << std::endl;
	this->_data.push(atof(n1.c_str()));
	std::cout << n1 << std::endl;
	while (i != std::string::npos)
	{
		next = s.find(" ", i + 1);
		n1 = s.substr(i + 1, next - (i + 1));
		i = next;
				
	}

}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN::~RPN()
{
}

RPN& RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		this->_data = other._data;
	}
	return *this;
}

const char *RPN::EmptyString::what() const throw()
{
	return "Empty string.";
}

const char *RPN::WrongNumber::what() const throw()
{
	return "Wrong number given.";
}