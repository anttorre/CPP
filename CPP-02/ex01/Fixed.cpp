/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:18:29 by anttorre          #+#    #+#             */
/*   Updated: 2024/06/06 17:16:31 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
Fixed::Fixed()
{
	this->_value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	this->_value = other._value;
	std::cout << "Copy constructor called." << std::endl;
}

Fixed::Fixed(const int integer)
{
	this->_value = integer * Fixed::pow(2, this->_bits);
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float floating)
{
	this->_value = roundf(floating * Fixed::pow(2, this->_bits));
	std::cout << "Float constructor called\n";
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called." << std::endl;
	if (this != &other)
	{
		this->_value = other._value;
	}
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	return this->_value;
}

void    Fixed::setRawBits(const int raw)
{
	this->_value = raw;
}

float	Fixed::toFloat(void) const
{
	return (this->_value / Fixed::pow(2, this->_bits));
}

int		Fixed::toInt(void) const
{
	return (this->_value / Fixed::pow(2, this->_bits));
}

float Fixed::pow(float base, int exp)
{
	float newFloat;

	newFloat = base;
	if (exp == 0)
		return(1);
	while (--exp)
		newFloat *= base;
	return (newFloat);
}

std::ostream &operator<<(std::ostream &out, Fixed const &i)
{
	out << i.toFloat();
	return (out);
}