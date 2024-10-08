/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 13:08:28 by anttorre          #+#    #+#             */
/*   Updated: 2024/08/19 14:24:19 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static std::string trim(const std::string& str) {
	if (str.empty()) {
        return str;
    }
    std::string::size_type start = 0;
    while (start < str.length() && std::isspace(str[start])) {
        ++start;
    }
    if (start == str.length()) {
        return "";
    }
    std::string::size_type end = str.length() - 1;
    while (end > start && std::isspace(str[end])) {
        --end;
    }
    return str.substr(start, end - start + 1);
}

RPN::RPN()
{
}

RPN::RPN(std::string s)
{
	if (s.empty())
		throw EmptyString();
	std::string str = trim(s);
	size_t i = 0;
	size_t next;
	std::string n1;
	while (i != std::string::npos)
	{
		next = str.find(" ", i);
		n1 = str.substr(i, next - i);
		if (!check_values(n1))
			throw WrongArguments();
		else if (isdigit(n1[0]))
		{
			this->_data.push(atoi(n1.c_str()));
		}
		else if (n1 == "-" || n1 == "+" || n1 == "/" || n1 == "*")
			calculate(n1);
		if (next == std::string::npos)
			break;
		i = next + 1;
	}
	if (this->_data.size() >= 2)
		throw NotEnoughTokens();
	std::cout << this->_data.top() << std::endl;
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

void	RPN::calculate(std::string s)
{
	(void)s;
	if (this->_data.size() < 2)
	{
		throw NotEnoughNumbers();
	}
	else
	{
		int n1 = this->_data.top();
		this->_data.pop();
		int n2 = this->_data.top();
		this->_data.pop();
		if (s == "-")
		{
			this->_data.push(n2 - n1);
		}
		else if (s == "+")
		{
			this->_data.push(n2 + n1);
		}
		else if (s == "*")
		{
			this->_data.push(n2 * n1);
		}
		else if (s == "/")
		{
			this->_data.push(n2 / n1);
		}
	}
}

bool RPN::check_values(std::string s)
{
	for (size_t i = 0; i < s.length(); i++)
	{
		if (s[i] == '-' || s[i] == '+' || s[i] == '*' || s[i] == '/')
		{
			if (s[i + 1] != ' ' && s[i + 1] != '\0')
				throw WrongArguments();
			break;
		}
		if (s[i] < '0' || s[i] > '9' || isdigit(s[i + 1]))
			return false;
		else if (!isdigit(s[i]) && s[i] != '-' && s[i] != '+' && s[i] != '*' && s[i] != '/')
			return false;
	}
	return true;
}

const char *RPN::EmptyString::what() const throw()
{
	return "Empty string.";
}

const char *RPN::WrongArguments::what() const throw()
{
	return "Wrong arguments given.";
}

const char *RPN::NotEnoughNumbers::what() const throw()
{
	return "Stack size with less than 2 numbers.";
}

const char *RPN::NotEnoughTokens::what() const throw()
{
	return "Not enough token to process.";
}