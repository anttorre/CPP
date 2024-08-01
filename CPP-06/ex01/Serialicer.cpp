/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialicer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:05:36 by anttorre          #+#    #+#             */
/*   Updated: 2024/07/10 15:02:39 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialicer.hpp"


Serialicer::Serialicer()
{
}

Serialicer::Serialicer(const Serialicer &other)
{
	*this = other;
}

Serialicer& Serialicer::operator=(const Serialicer &other)
{
	(void) other;
	return *this;
}

Serialicer::~Serialicer()
{
}

uintptr_t Serialicer::serialize(Data *ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serialicer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}