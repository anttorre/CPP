/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:30:34 by anttorre          #+#    #+#             */
/*   Updated: 2024/07/01 16:42:15 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const		std::string name;
		bool		isSigned;
		const int	gradeRequired;
		const int	gradeToExecute;
	public:
		AForm();
		AForm(std::string name, int gradeRequired, int gradeToExecute);
		AForm(AForm &other);
		virtual ~AForm();
		AForm& operator=(AForm &other);
		std::string getName() const;
		bool	getIsSigned() const;
		int		getGradeRequired() const;
		int		getGradeToExecute() const;
		void	beSigned(Bureaucrat &b);
		virtual bool execute(Bureaucrat const &executor) const = 0;
	class GradeTooHighException : public std::exception
	{
		public:
			const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			const char *what() const throw();
	};
	class FormNotSignedException : public std::exception
	{
		public:
			const char *what() const throw();
	};
};

std::ostream& operator<<(std::ostream& o, const AForm& f);

#endif