/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:55:38 by anttorre          #+#    #+#             */
/*   Updated: 2024/06/12 16:22:09 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor called.\n";
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap default param constructor called\n";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_name = name;
}

ScavTrap::ScavTrap(ScavTrap &other)
{
	std::cout << "ScavTrap copy constructor called\n";
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called\n";
}

ScavTrap& ScavTrap::operator=(ScavTrap &other)
{
	std::cout << "ScavTrap Operator Asignment Called\n";
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "No health left\n";
		return ;
	}	
	if (this->_energyPoints <= 0)
	{
		std::cout << "No energy points left\n";
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " attacks " << target <<", causing " << this->_attackDamage << " points of damage!\n";
	this->_energyPoints--;
}

void	ScavTrap::guardGate()
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "No health left\n";
		return ;
	}	
	std::cout << "ScavTrap in Gate Keeper Mode\n";
}

