/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:36:03 by anttorre          #+#    #+#             */
/*   Updated: 2024/06/12 14:29:19 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap trap("Wakanda");

	trap.attack("Virus");
	trap.takeDamage(8);
	trap.beRepaired(2);
	for (int i = 0; i < 10; i++)
		trap.attack("Pepe");
	trap.takeDamage(6);
	trap.takeDamage(6);
	trap.beRepaired(3);
}