/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:57:59 by anttorre          #+#    #+#             */
/*   Updated: 2024/07/19 14:51:25 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern &other)
{
	if (this != &other)
		*this = other;
}

Intern::~Intern()
{
}

Intern& Intern::operator=(Intern &other)
{
	(void) other;
	return *this;
}

AForm* Intern::makeForm(std::string name, std::string target)
{
	AForm *s = NULL;
	int i;
	std::string arr[3] = {"ShrubberyCreationForm", "PresidentialPardonForm", "RobotomyRequestForm"};
	for (i = 0; i < 3; i++)
		if (arr[i] == name)
			break;
	switch (i)
	{
		case 0:
			s = new ShrubberyCreationForm(target);
			std::cout << "Intern creates " << s->getName();
			return (s);
		case 1:
			s = new PresidentialPardonForm(target);
			std::cout << "Intern creates " << s->getName();
			return (s);
		case 2:
			s = new RobotomyRequestForm(target);
			std::cout << "Intern creates " << s->getName();
			return (s);
		default:
			std::cout << "The form u trying to create doesn't exist. Try again...";
			return s;
	}
}