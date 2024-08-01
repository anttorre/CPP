/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:04:36 by anttorre          #+#    #+#             */
/*   Updated: 2024/07/30 14:47:00 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stack>
#include <algorithm>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(const MutantStack &other);
		~MutantStack();
		MutantStack& operator=(const MutantStack &other);
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin();
		iterator end();
};

# include "MutantStack.tpp"