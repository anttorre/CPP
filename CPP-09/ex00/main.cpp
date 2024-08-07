/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <anttorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:07:14 by anttorre          #+#    #+#             */
/*   Updated: 2024/08/07 16:42:18 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./program <file>" << std::endl;
		return (1);
	}
	std::string input(argv[1]);
	BitcoinExchange bc;
	bc.init(input, "data.csv");
	return (0);
}


/*

 // Fecha dada
    int añoDado = 2010;

    // Fechas en la base de datos
    std::vector<int> fechasBD; // Años en la base de datos
	fechasBD.push_back(2008);
	fechasBD.push_back(2011);
    time_t tiempoDado = crearFecha(añoDado);

    time_t fechaMasCercana = -1; // Inicializa con un valor que indica que no se encontró

    for (int año : fechasBD) {
        time_t tiempoBD = crearFecha(año);
        if (tiempoBD < tiempoDado) {
            if (fechaMasCercana == -1 || tiempoBD > fechaMasCercana) {
                fechaMasCercana = tiempoBD;
            }
        }
    }

    if (fechaMasCercana != -1) {
        // Convertir de time_t a año
        struct tm *tmFecha = localtime(&fechaMasCercana);
        int añoEncontrado = tmFecha->tm_year + 1900; // Ajustar el año
        std::cout << "La fecha más cercana hacia abajo de " << añoDado << " es: " << añoEncontrado << std::endl;
    } else {
        std::cout << "No se encontró ninguna fecha en la base de datos que sea menor que " << añoDado << std::endl;
    }

    return 0;

 */

/* PARA IMPRIMIR POR PANTALLA LAS FECHAS GUARDADAS COMO TIME_T
for(std::map<time_t, double>::iterator it = this->_data.begin(); it != this->_data.end(); it++)
	{
		tm* timeinfo = localtime(&it->first);
		char buffer[80];
		strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);
		std::cout << buffer << " : " << it->second << std::endl;
	}
*/