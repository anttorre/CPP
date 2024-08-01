/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:55:43 by anttorre          #+#    #+#             */
/*   Updated: 2024/07/10 12:54:35 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv){
    if(argc != 2){
        std::cout << "Usage: ./Convert [something to convert]\n";
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}