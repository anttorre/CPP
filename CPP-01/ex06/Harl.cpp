/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:07:36 by anttorre          #+#    #+#             */
/*   Updated: 2024/06/04 18:13:44 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{}

Harl::~Harl()
{}

void	Harl::debug()
{
	std::cout << "[ DEBUG ]\nDebug messages contain contextual information. They are mostly used for problem diagnosis.\nExample: \"I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\"" << std::endl;
}

void	Harl::info()
{
	std::cout << "[ INFO ]\nThese messages contain extensive information. They are helpful for tracing program execution in a production environment.\nExample: \"I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\"" << std::endl;
}

void	Harl::warning()
{
	std::cout << "[ WARNING ]\nWarning messages indicate a potential issue in the system. However, it can be handled or ignored.\nExample: \"I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\"" << std::endl;	
}

void	Harl::error()
{
	std::cout << "[ ERROR ]\nThese messages indicate an unrecoverable error has occurred. This is usually a critical issue that requires manual intervention.\nExample: \"This is unacceptable! I want to speak to the manager now.\"" << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string	filter[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	std::string	filter2[] = {"debug", "info", "warning", "error"};
	int	i;
	for (i = 0; i < 4; i++)
		if (level == filter[i] || level == filter2[i])
			break;
	switch (i)
	{
		case 0 :
			this->debug();
			this->info();
			this->warning();
			this->error();
			break;
		case 1:
			this->info();
			this->warning();
			this->error();
			break;
		case 2:
			this->warning();
			this->error();
			break;
		case 3:
			this->error();
			break;	
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
			break;
	}
}