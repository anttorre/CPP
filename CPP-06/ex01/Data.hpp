/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:31:43 by anttorre          #+#    #+#             */
/*   Updated: 2024/07/10 14:47:05 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP
# include <iostream>

class Data
{
	private:
		std::string name;
	public:
		Data();
		Data(Data& other);
		Data& operator=(Data &other);
		~Data();
		std::string getName() const;
};
#endif