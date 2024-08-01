/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:04:56 by anttorre          #+#    #+#             */
/*   Updated: 2024/05/31 14:23:12 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB()
{}

HumanB::HumanB(std::string name)
{
	this->name = name;
	std::cout << "HumanB " << name << " created." << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "HumanB " << name << " deleted." << std::endl;
}

void	HumanB::attack(void)
{
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}