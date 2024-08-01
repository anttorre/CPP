/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:56:30 by anttorre          #+#    #+#             */
/*   Updated: 2024/07/19 13:23:22 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename T> void swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T> T min(T &a, T&b)
{
	if (a < b)
		return a;
	return b;
}

template <typename T> T max(T &a, T&b)
{
	if (a > b)
		return a;
	return b;
}