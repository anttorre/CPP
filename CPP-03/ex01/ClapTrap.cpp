/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:36:01 by anttorre          #+#    #+#             */
/*   Updated: 2024/06/12 16:22:20 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap default constructor called.\n";
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap default param constructor called\n";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	this->_name = name;
}

ClapTrap::ClapTrap(ClapTrap &other)
{
	std::cout << "ClapTrap Copy constructor called\n";
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called\n";
}

ClapTrap& ClapTrap::operator=(ClapTrap &other)
{
	std::cout << "ClapTrap Operator Asignment Called\n";
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

const std::string& ClapTrap::getName() const
{
	return this->_name;
}

int ClapTrap::getHitPoints() const
{
	return this->_hitPoints;
}

int	ClapTrap::getEnergyPoints() const
{
	return this->_energyPoints;
}

int	ClapTrap::getAttackDamage() const
{
	return this->_attackDamage;
}

void ClapTrap::attack(const std::string &target)
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
	std::cout << "ClapTrap " << this->_name << " attacks " << target <<", causing " << this->_attackDamage << " points of damage!\n";
	this->_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "What is dead may never die\n"; 
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " took " << amount << " points of damage!\n";
	this->_hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
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
	std::cout << "ClapTrap " << this->_name << " healed " << amount << " points itself!\n";
	this->_hitPoints += amount;
	this->_energyPoints -= 1;
}