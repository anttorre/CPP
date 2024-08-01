/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:26:20 by anttorre          #+#    #+#             */
/*   Updated: 2024/07/10 12:53:05 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter& other)
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter& other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

bool isround(float n){
    int i = static_cast<int>(n);
    if(n == i)
        return true;
    return false;
}

int	get_type(std::string s)
{
	char *endptr;
	if (s == "nan" || s == "-inf" || s == "+inf")
		return PLD;
	if(s == "nanf" || s == "+inff" || s == "-inff")
        return PLF;
    if(s == "inf")
        return INT;
    if(s.length() == 1 && std::isalpha(s[0]) && std::isprint(s[0]))
        return CHAR;
    strtol(s.c_str(), &endptr, 10);
    if (endptr[0] == '\0')
        return INT;
    strtod(s.c_str(), &endptr);
    if (endptr[0] == 'F' || endptr[0] == 'f')
        return FLOAT;
    else if(endptr[0] == '\0')
	{
        return DOUBLE;
	}
	return -1;
}

void ScalarConverter::convert(const std::string str){
    int i;
    char c;
    float f;
    double d;

    switch (get_type(str))
    {
		case CHAR:
			c = str[0];
			std::cout << "char: '" << c << "'\n";
			std::cout << "int: " << static_cast<int>(c) << "\n";
			std::cout << "float: " << static_cast<float>(c) << ".0f\n";
			std::cout << "double: " << static_cast<double>(c) << ".0\n";
			break;
		
		case INT:
			i = atoi(str.c_str());
			std::cout << "char: ";
			if(isprint(static_cast<char>(i)))
				std::cout << "'" << static_cast<char>(i) << "'\n";
			else
				std::cout << "Non displayable\n";
			if(atol(str.c_str()) > INT_MAX || atol(str.c_str()) < INT_MIN){
				std::cout << "int: value overflow\n";
				std::cout << "float: value overflow\n";
				std::cout << "double: value overflow\n";
				break;
			}
			std::cout << "int: " << i << "\n";
			std::cout << "float: " << static_cast<float>(i) << ".0f\n";
			std::cout << "double: " << static_cast<double>(i) << ".0\n";
			break;
			
		case FLOAT:
			f = atof(str.c_str());
			std::cout << "char: ";
			if(isround(f) && isprint(static_cast<char>(f)))
				std::cout << "'" << static_cast<char>(f) << "'\n";
			else
				std::cout << "Non displayable\n";
			if(atol(str.c_str()) > INT_MAX || atol(str.c_str()) < INT_MIN){
				std::cout << "int: value overflow\n";
				std::cout << "float: value overflow\n";
				std::cout << "double: value overflow\n";
				break;
			}
			std::cout << "int: " << static_cast<int>(f) << "\n";
			std::cout << "float: " << f;
			if(isround(f))
				std::cout << ".0f\n";
			else
				std::cout << "f\n";
			std::cout << "double: " << static_cast<double>(f);
		if(isround(f))
				std::cout << ".0\n";
			else
				std::cout << "\n";
			break;
			
		case DOUBLE:
			d = atof(str.c_str());
			std::cout << "char: ";
			if(isround(d) && isprint(static_cast<char>(d)))
				std::cout << "'" << static_cast<char>(d) << "'\n";
			else
				std::cout << "Non displayable\n";
			if(atol(str.c_str()) > INT_MAX || atol(str.c_str()) < INT_MIN){
				std::cout << "int: value overflow\n";
				std::cout << "float: value overflow\n";
				std::cout << "double: value overflow\n";
				break;
			}
			std::cout << "int: " << static_cast<int>(d) << "\n";
			std::cout << "float: " << static_cast<float>(d);
			if(isround(d))
				std::cout << ".0f\n";
			else
				std::cout << "f\n";
			std::cout << "double: " << d;
		if(isround(d))
				std::cout << ".0\n";
			else
				std::cout << "\n";
			break;
		
		case PLF:
			std::cout << "char: impossible\n";
			std::cout << "int: impossible\n";
			std::cout << "float: " << str << "\n";
			std::cout << "double: " << str.substr(0, str.length() - 1) << "\n";
			break;

		case PLD:
			std::cout << "char: impossible\n";
			std::cout << "int: impossible\n";
			std::cout << "float: " << str << "f\n";
			std::cout << "double: " << str << "\n";
			break;
		
		default:
			std::cout << "Error, no conversion possible\n";
			break;
	}
}