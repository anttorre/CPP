/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 13:08:21 by anttorre          #+#    #+#             */
/*   Updated: 2024/08/19 14:23:44 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP
# include <iostream>
# include <stack>
# include <cstdlib>

class RPN
{
    private:
		std::stack<int> _data;
		RPN();
		bool check_values(std::string s);
		void calculate(std::string s);
    public:
		RPN(std::string s);
        RPN(const RPN &other);
        ~RPN();
        RPN& operator=(const RPN &other);
		class EmptyString : public std::exception
		{
			const char * what() const throw();
		};
		class WrongArguments : public std::exception
		{
			const char * what() const throw();
		};
		class NotEnoughNumbers : public std::exception
		{
			const char * what() const throw();
		};
		class NotEnoughTokens : public std::exception
		{
			const char * what() const throw();
		};
};

#endif