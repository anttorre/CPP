/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:07:31 by anttorre          #+#    #+#             */
/*   Updated: 2024/07/25 14:38:07 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "Easyfind.hpp"

const char * ValueNotFound::what() const throw()
{
	return "Value not found";
}

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator i = std::find(container.begin(), container.end(), value);
	if (i != container.end())
		return i;
	else
		throw ValueNotFound();
}