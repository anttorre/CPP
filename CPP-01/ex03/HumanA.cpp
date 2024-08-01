/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:31:37 by anttorre          #+#    #+#             */
/*   Updated: 2024/05/31 14:04:30 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : weapon(weapon)
{
	this->name = name;
	std::cout << "HumanA " << name << " created." << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "HumanA " << name << " deleted." << std::endl;
}

void	HumanA::attack(void)
{
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}

void	HumanA::setWeapon(Weapon weapon)
{
	this->weapon = weapon;
}