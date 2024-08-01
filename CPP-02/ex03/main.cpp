/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:54:55 by anttorre          #+#    #+#             */
/*   Updated: 2024/06/10 16:00:29 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main( void ) {
    
    Point a(0, 0);
    Point b(4, 0);
    Point c(2, 4);
    Point point(2, 2);

    if (bsp(a, b, c, point)) {
        std::cout << "Test 1: El punto está dentro del triángulo." << std::endl;
    } else {
        std::cout << "Test 1: El punto está fuera del triángulo." << std::endl;
    }

	Point d(0, 0);
    Point e(4, 0);
    Point f(2, 4);
    Point point2(5, 5);

    if (bsp(a, b, c, point2)) {
        std::cout << "Test 2: El punto está dentro del triángulo." << std::endl;
    } else {
        std::cout << "Test 2: El punto está fuera del triángulo." << std::endl;
    }
	return 0;
}