/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:59:12 by anttorre          #+#    #+#             */
/*   Updated: 2024/07/19 13:27:04 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Templates.hpp"

/*
int main(void)
{
	int a = 6;
	int b = 6;
	std::cout << "MIN" <<std::endl;
	std::cout << min<int>(a, b) << std::endl;
	std::cout << "VALUES BEFORE SWAP" <<std::endl;
	std::cout << "a: " << a <<std::endl;
	std::cout << "b: " << b<<std::endl;
	swap<int>(a, b);
	std::cout << "VALUES AFTER SWAP" <<std::endl;
	std::cout << "a: " << a <<std::endl;
	std::cout << "b: " << b <<std::endl;
}
*/

int main( void ) {
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}