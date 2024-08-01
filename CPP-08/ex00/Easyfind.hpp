/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:09:00 by anttorre          #+#    #+#             */
/*   Updated: 2024/07/30 14:06:25 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <algorithm>

class ValueNotFound : public std::exception
{
	const char * what() const throw();
};

template <typename T>
typename T::iterator easyfind(T &container, int value);

#include "Easyfind.tpp"