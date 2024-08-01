/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:49:30 by anttorre          #+#    #+#             */
/*   Updated: 2024/05/29 14:18:01 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie (std::string name)
{
    this->name = name;
}

Zombie::Zombie ()
{}

Zombie::~Zombie()
{
    std::cout << "Destroying " << this->name << " Zombie." << std::endl;
}

std::string Zombie::getName()
{
    return this->name;
}

void    Zombie::announce(void)
{
    std::cout << this->getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}