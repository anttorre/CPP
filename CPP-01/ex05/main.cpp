/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:39:22 by anttorre          #+#    #+#             */
/*   Updated: 2024/06/04 12:45:25 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl *harl = new Harl();
	harl->complain("debug");
	harl->complain("info");
	harl->complain("warning");
	harl->complain("error");
	delete(harl);
	return 0;
}
