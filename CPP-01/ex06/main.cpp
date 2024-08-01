/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:49:43 by anttorre          #+#    #+#             */
/*   Updated: 2024/06/04 17:04:50 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, const char **argv)
{
	if (argc > 2 || argc == 1) 
	{
		std::cout << "Wrong number of arguments.\n";
		return (1);
	}
	Harl harl;
	harl.complain(argv[1]);
	return (0);
}
