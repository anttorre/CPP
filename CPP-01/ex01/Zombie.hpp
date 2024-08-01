/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:35:10 by anttorre          #+#    #+#             */
/*   Updated: 2024/05/29 16:35:21 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
    private:
        std::string name;
		
    public:
		Zombie(void);
        Zombie(std::string name);
        ~Zombie(void);
        void announce(void);
        std::string getName(void);
};

Zombie*	zombieHorde(int N, std::string name);

#endif