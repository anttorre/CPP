/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:35:59 by anttorre          #+#    #+#             */
/*   Updated: 2024/06/12 14:29:02 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class ClapTrap
{
	private:
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
			
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap &other);
		~ClapTrap();
		ClapTrap& operator=(ClapTrap& other);

		/*Getters*/
		const std::string&	getName() const;
		int				getHitPoints() const;
		int				getEnergyPoints() const;
		int				getAttackDamage() const;
		
		/*Functions*/
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};
