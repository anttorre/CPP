/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:47:02 by anttorre          #+#    #+#             */
/*   Updated: 2024/07/11 14:43:38 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP
# include <iostream>
# include <stdlib.h>

class Base
{
	public:
		Base();
		virtual ~Base();
		virtual std::string getType() const;
};

Base *generate();
void identify(Base* p);
void identify(Base& p);

#endif