/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:47:11 by anttorre          #+#    #+#             */
/*   Updated: 2024/06/13 16:48:36 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"



DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	std::cout << "DiamondTrap param constructor called\n";
	_name = name;
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called\n";
}

DiamondTrap::DiamondTrap(DiamondTrap &other)
{
	std::cout << "DiamondTrap copy constructor called\n";
	*this = other;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap &other)
{
	std::cout << "DiamondTrap operator asignment called\n";
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name " << _name << ", ClapTrap name: " << (ClapTrap::_name += "_clap_name") << std::endl;
}