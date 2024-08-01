/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 11:57:09 by anttorre          #+#    #+#             */
/*   Updated: 2024/05/31 14:27:22 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HumanB_HPP
# define HumanB_HPP
# include "Weapon.hpp"
# include <iostream>

class HumanB
{
  private:
	std::string	name;
	Weapon	*weapon;

  public:
	HumanB();
	HumanB(std::string name);
	~HumanB();
	void	attack(void);
	void	setWeapon(Weapon &weapon);
};

#endif
