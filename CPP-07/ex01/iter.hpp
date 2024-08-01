/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:06:55 by anttorre          #+#    #+#             */
/*   Updated: 2024/07/19 14:38:49 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename T> void iter(T *arr, size_t size, void (*f)(T &))
{
	for(size_t i = 0; i < size; i++)
	{
		std::cout << "Index " << i << ": ";
		f(arr[i]);
	}
}

template <typename T> void	print(T &a)
{
	std::cout << a << std::endl;
}