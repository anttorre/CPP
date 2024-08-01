/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialicer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:05:38 by anttorre          #+#    #+#             */
/*   Updated: 2024/07/10 15:04:05 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALICER_HPP
# define SERIALICER_HPP
# include <iostream>
# include <cstring>
# include <climits>
# include <stdint.h>
# include "Data.hpp"

class Serialicer
{
	private:
		Serialicer();
		Serialicer(const Serialicer &src);
		Serialicer &operator=(const Serialicer &src);
	public:
		~Serialicer();
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};

#endif