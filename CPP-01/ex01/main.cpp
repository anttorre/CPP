/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:37:00 by anttorre          #+#    #+#             */
/*   Updated: 2024/05/29 17:09:16 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int N = 5;
    Zombie* z1 = zombieHorde(N, "Anttorre");
    for (int i = 0; i < N; i++)
    {
        z1[i].announce();
    }
    delete[] z1;
}