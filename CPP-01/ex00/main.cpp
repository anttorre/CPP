/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:37:00 by anttorre          #+#    #+#             */
/*   Updated: 2024/05/29 13:58:12 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie* z1 = new Zombie("Anttorre");
    z1->announce();
    Zombie* z2 = newZombie("marciano");
    z2->announce();
    randomChump("Pepa");
    delete(z1);
    delete(z2);
}