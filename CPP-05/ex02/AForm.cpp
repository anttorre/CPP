/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:54:25 by anttorre          #+#    #+#             */
/*   Updated: 2024/06/26 13:11:00 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"


AForm::AForm() : name("Default AForm"), isSigned(false), gradeRequired(1), gradeToExecute(1)
{
}

AForm::AForm(std::string name, int gradeRequired, int gradeToExecute) : name(name), isSigned(false), gradeRequired(gradeRequired), gradeToExecute(gradeToExecute)
{
	if (this->gradeRequired < 1)
		throw AForm::GradeTooHighException();
	else if (this->gradeRequired > 150)
		throw AForm::GradeTooLowException();
	if (this->gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (this->gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(AForm &other) : name(other.name), isSigned(other.isSigned), gradeRequired(other.gradeRequired), gradeToExecute(other.gradeToExecute)
{
	if (other.gradeRequired < 1)
		throw AForm::GradeTooHighException();
	else if (other.gradeRequired > 150)
		throw AForm::GradeTooLowException();
	if (other.gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (other.gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::~AForm()
{
}

AForm& AForm::operator=(AForm &other)
{
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	return *this;
}

std::string AForm::getName() const
{
	return this->name;
}

bool AForm::getIsSigned() const
{
	return this->isSigned;
}

int	AForm::getGradeRequired() const
{
	return this->gradeRequired;
}

int AForm::getGradeToExecute() const
{
	return this->gradeToExecute;
}

void	AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > this->gradeRequired)
		throw AForm::GradeTooLowException();
	this->isSigned = true;
}

std::ostream& operator<<(std::ostream& o, const AForm &f)
{
	std::string sign = "false";
	if (f.getIsSigned() == true)
		sign = "true";
	o << "\n-----------------AForm info-----------------\n";
	o << "AForm name: " << f.getName() << ".\nRequired grade: " << f.getGradeRequired() << ".\nGrade to execute: " << f.getGradeToExecute() << ".\nAForm signed: " << sign;
	return o;
}

const char * AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low.";
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high.";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form isn't signed";
}