/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:00:45 by anttorre          #+#    #+#             */
/*   Updated: 2024/06/10 15:59:39 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed areaABC;
	Fixed areaPAB;
	Fixed areaPAC;
	Fixed areaPBC;

	areaABC = Fixed(0.5f) * ((b.getX() - a.getX()) * (c.getY() - a.getY()) - (b.getY() - a.getY()) * (c.getX() - a.getX()));
	areaPAB = Fixed(0.5f) * ((b.getX() - point.getX()) * (a.getY() - point.getY()) - (b.getY() - point.getY()) * (a.getX() - point.getX()));
	areaPBC = Fixed(0.5f) * ((c.getX() - point.getX()) * (b.getY() - point.getY()) - (c.getY() - point.getY()) * (b.getX() - point.getX()));
	areaPAC = Fixed(0.5f) * ((a.getX() - point.getX()) * (c.getY() - point.getY()) - (a.getY() - point.getY()) * (c.getX() - point.getX()));
	if ( Point::abs(areaABC) == (Point::abs(areaPAB) + Point::abs(areaPAC) + Point::abs(areaPBC)))
		return (true);	
	return (false);
}