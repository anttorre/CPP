/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:18:17 by anttorre          #+#    #+#             */
/*   Updated: 2024/06/12 17:25:08 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap default constructor called.\n";
}

FragTrap::FragTrap(std::string name)
{
	std::cout << "FragTrap default param constructor called\n";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	this->_name = name;
}

FragTrap::FragTrap(FragTrap &other)
{
	std::cout << "FragTrap copy constructor called\n";
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called\n";
}

FragTrap& FragTrap::operator=(FragTrap &other)
{
	std::cout << "FragTrap Operator Asignment Called\n";
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

void FragTrap::attack(const std::string &target)
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
	std::cout << "FragTrap " << this->_name << " attacks " << target <<", causing " << this->_attackDamage << " points of damage!\n";
	this->_energyPoints--;
}

void	FragTrap::highFiveGuys()
{
	std::cout << "Let's GO!. High Five Bro :)\n";
}