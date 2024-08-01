/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:33:12 by anttorre          #+#    #+#             */
/*   Updated: 2024/05/31 14:26:01 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>

class Weapon
{
	private:
		std::string	type;

	public:
		Weapon(std::string type);
		~Weapon();
		
		/*Getters*/
		const std::string& getType(void);

		/*Setters*/
		void	setType(std::string type);
};

#endif

