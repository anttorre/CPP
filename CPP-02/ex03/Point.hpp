/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:25:13 by anttorre          #+#    #+#             */
/*   Updated: 2024/06/10 15:55:40 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Fixed.hpp"

class Point
{
	private:
		const Fixed _x;
		const Fixed _y;

	public:
		Point();
		Point(const Fixed &x, const Fixed &y);
		Point(const Point& other);
		~Point();
		Point& operator=(const Point &other);
		
		/* Getters */
		const Fixed getX() const;
		const Fixed getY() const;

		/* Functions */
		static Fixed& abs(Fixed &n);
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
