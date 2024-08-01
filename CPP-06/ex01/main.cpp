/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:55:43 by anttorre          #+#    #+#             */
/*   Updated: 2024/07/10 15:10:30 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialicer.hpp"
#include "Data.hpp"

int main(){
    
    Data *src = new Data();
    uintptr_t rawSrc = Serialicer::serialize(src);
    Data *dest = Serialicer::deserialize(rawSrc);

    std::cout << "Source: " << src->getName() << "\n";
    std::cout << "Serialiced and Deserialiced : " << dest->getName() << "\n";
    std::cout << &src << "\n" << &dest << "\n" << rawSrc << std::endl;
    delete src;

    return 0;
}