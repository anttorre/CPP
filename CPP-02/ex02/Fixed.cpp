/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:18:29 by anttorre          #+#    #+#             */
/*   Updated: 2024/06/07 17:21:31 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
Fixed::Fixed()
{
	this->_value = 0;
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	this->_value = other._value;
	//std::cout << "Copy constructor called." << std::endl;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	//std::cout << "Copy assignment operator called." << std::endl;
	if (this != &other)
	{
		this->_value = other._value;
	}
	return *this;
}

Fixed::Fixed(const int integer)
{
	this->_value = integer * Fixed::pow(2, this->_bits);
	//std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float floating)
{
	this->_value = roundf(floating * Fixed::pow(2, this->_bits));
	//std::cout << "Float constructor called\n";
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

/* Comparison operators */
bool	Fixed::operator>(Fixed const &n)
{
	return this->getRawBits() > n.getRawBits();
}

bool	Fixed::operator<(Fixed const &n)
{
	return this->getRawBits() < n.getRawBits();
}

bool	Fixed::operator>=(Fixed const &n)
{
	return this->getRawBits() >= n.getRawBits();
}

bool	Fixed::operator<=(Fixed const &n)
{
	return this->getRawBits() <= n.getRawBits();
}

bool	Fixed::operator==(Fixed const &n)
{
	return this->getRawBits() == n.getRawBits();
}

bool	Fixed::operator!=(Fixed const &n)
{
	return this->getRawBits() != n.getRawBits();
}

/* Arithmetic operators */
Fixed Fixed::operator+(Fixed const &n) const
{
	return Fixed(this->toFloat() + n.toFloat());
}

Fixed Fixed::operator-(Fixed const &n) const
{
	return Fixed(this->toFloat() - n.toFloat());
}

Fixed Fixed::operator*(Fixed const &n) const
{
	return Fixed(this->toFloat() * n.toFloat());
}

Fixed Fixed::operator/(Fixed const &n) const
{
	return Fixed(this->toFloat() / n.toFloat());
}

/*postfix*/
Fixed	Fixed::operator++(int)
{
	Fixed tmpValue(this->toFloat());
	this->_value++;
	return tmpValue;
}

Fixed&	Fixed::operator++(void)
{
	++this->_value;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed tmpValue(this->toFloat());
	this->_value--;
	return tmpValue;
}

Fixed&	Fixed::operator--(void)
{
	--this->_value;
	return *this;
}

Fixed& Fixed::min( Fixed &a, Fixed &b ) {
    if ( a.getRawBits() < b.getRawBits() )
        return a;
    return b;
}

const Fixed& Fixed::min( const Fixed &a, const Fixed &b ) {
    if ( a.getRawBits() < b.getRawBits() )
        return a;
    return b;
}

Fixed& Fixed::max( Fixed &a, Fixed &b ) {
    if ( a.getRawBits() > b.getRawBits() )
        return a;
    return b;
}

const Fixed& Fixed::max( const Fixed &a, const Fixed &b ) {
    if ( a.getRawBits() > b.getRawBits() )
        return a;
    return b;
}