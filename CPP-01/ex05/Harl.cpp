/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:07:36 by anttorre          #+#    #+#             */
/*   Updated: 2024/06/04 12:39:10 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{}

Harl::~Harl()
{
	std::cout << "Destroying Harl." << std::endl;
}

void	Harl::debug()
{
	std::cout << "\"DEBUG\" level: Debug messages contain contextual information. They are mostly used for problem diagnosis.\nExample: \"I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\"" << std::endl;
}

void	Harl::info()
{
	std::cout << "\"INFO\" level: These messages contain extensive information. They are helpful for tracing program execution in a production environment.\nExample: \"I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\"" << std::endl;
}

void	Harl::warning()
{
	std::cout << "\"WARNING\" level: Warning messages indicate a potential issue in the system. However, it can be handled or ignored.\nExample: \"I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\"" << std::endl;	
}

void	Harl::error()
{
	std::cout << "\"ERROR\" level: These messages indicate an unrecoverable error has occurred. This is usually a critical issue that requires manual intervention.\nExample: \"This is unacceptable! I want to speak to the manager now.\"" << std::endl;
}

void	Harl::complain(std::string level)
{
	void(Harl::*funcs[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[] = {"debug", "info", "warning", "error"};
	for(int i = 0; i < 4; i++)
		if (level == levels[i])
		{
			(this->*funcs[i])();
			break ;
		}
}