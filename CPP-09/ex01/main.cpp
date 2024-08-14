/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 13:35:57 by anttorre          #+#    #+#             */
/*   Updated: 2024/08/14 13:40:42 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, const char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./program <\"string\">" << std::endl;
		return 1;
	}
	try
	{
		RPN rpn(argv[1]);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}