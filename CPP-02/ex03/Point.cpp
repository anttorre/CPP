/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:25:11 by anttorre          #+#    #+#             */
/*   Updated: 2024/06/10 15:56:21 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::Point(const Fixed &x, const Fixed &y) : _x(x), _y(y)
{
}

Point::Point(const Point& other) : _x(other._x), _y(other._y)
{
}

Point::~Point()
{
}

Point& Point::operator=(const Point &other)
{
	if (this != &other)
	{
		(Fixed) this->_x = other._x;
		(Fixed) this->_y = other._y;
	}
	return (*this);
}

/* Getters */
const Fixed Point::getX() const
{
	return (this->_x);
}

const Fixed Point::getY() const
{
	return (this->_y);
}

Fixed& Point::abs(Fixed &n)
{
	if (n < 0)
        n =  n * -1;
    return n;
}