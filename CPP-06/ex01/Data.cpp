/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:38:57 by anttorre          #+#    #+#             */
/*   Updated: 2024/07/10 14:53:11 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data()
{
	this->name = "Default";
}

Data::Data(Data& other)
{
	*this = other;
}

Data& Data::operator=(Data &other)
{
	if (this != &other)
	{
		this->name = other.name;
	}
	return *this;
}

Data::~Data()
{
}

std::string Data::getName() const
{
	return this->name;
}