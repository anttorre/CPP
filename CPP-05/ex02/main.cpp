/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:57:25 by anttorre          #+#    #+#             */
/*   Updated: 2024/07/02 15:22:20 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat	*b1 = NULL;
	Bureaucrat	*b2 = NULL;
	AForm		*f1 = NULL;
	AForm		*f2 = NULL;
	AForm		*f3 = NULL;
	ShrubberyCreationForm *s1 = NULL;
	ShrubberyCreationForm *s2 = NULL;
	try
	{
		b1 = new Bureaucrat("Antonio", 150);
		b2 = new Bureaucrat("Juan", 4);
		f1 = new ShrubberyCreationForm("Pepe");
		f2 = new RobotomyRequestForm("wakana");
		f3 = new PresidentialPardonForm("Murder");
		
		std::cout << "--------MAIN---------" << std::endl;
		b2->signForm(*f1);
		b1->signForm(*f1);
		b1->executeForm(*f1);
		//b2->executeForm(*f1);
		b1->signForm(*f2);
		b2->signForm(*f2);
		b1->executeForm(*f2);
		b2->executeForm(*f2);
		b1->signForm(*f3);
		b2->signForm(*f3);
		b1->executeForm(*f3);
		b2->executeForm(*f3);
		std::cout << *f1 << std::endl;
		std::cout << *f2 << std::endl;
		std::cout << *f3 << std::endl;

		std::cout << std::endl;
		std::cout << "--------COPY TEST---------" << std::endl;
		s1 = new ShrubberyCreationForm("prueba");
		s2 = new ShrubberyCreationForm("pepe");
		*s2 = *s1;
		std::cout << s2->getTarget() << "\n" << s2->getName() << "\n" << s2->getGradeRequired() << "\n" << s2->getGradeToExecute() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete b1;
	delete b2;
	delete f1;
	delete s1;
	delete s2;
	delete f2;
	delete f3;
}