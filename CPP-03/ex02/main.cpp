/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:36:03 by anttorre          #+#    #+#             */
/*   Updated: 2024/06/12 17:26:33 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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

	std::cout << std::endl;
	
	ScavTrap trap2("Pepa");
	trap2.guardGate();
	trap2.attack(trap.getName());
	trap2.takeDamage(25);
	trap2.beRepaired(25);
	for (int i = 0; i < 50; i++)
		trap2.attack(trap.getName());
	trap2.takeDamage(90);
	trap2.takeDamage(10);
	trap2.beRepaired(3);

	std::cout << std::endl;

	FragTrap trap3("Bellum");
	trap3.attack(trap.getName());
	trap3.highFiveGuys();
	trap3.takeDamage(25);
	trap3.beRepaired(25);
	for (int i = 0; i < 100; i++)
		trap3.attack(trap.getName());
	trap3.takeDamage(90);
	trap3.takeDamage(10);
	trap3.beRepaired(3);
	
	std::cout << std::endl;
}