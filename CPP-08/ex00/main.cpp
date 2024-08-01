/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:18:13 by anttorre          #+#    #+#             */
/*   Updated: 2024/07/25 14:41:45 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Easyfind.hpp"
#include <vector>

int main(int, const char**) {
	
	int	const				amounts[]	= {10, 20, 30, 40, 50};
	size_t const			amounts_size( sizeof(amounts) / sizeof(int) );
	std::vector<int>  		numeros( amounts, amounts + amounts_size );
	try
	{
		std::vector<int>::iterator it = easyfind(numeros, 30);
        if (it != numeros.end()) {
            std::cout << "El valor encontrado es: " << *it << std::endl;
        } else {
            throw std::runtime_error("El valor no fue encontrado en el vector.");
        }
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}