/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:48:53 by bguyot            #+#    #+#             */
/*   Updated: 2023/04/26 15:10:16 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "../incs/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./btc path/to/file" << std::endl;
        return (1);
    }

    std::ifstream input_file(argv[1]);
    std::ifstream db_file("data/data.csv");
    if (!input_file.is_open() || !db_file.is_open())
    {
        std::cout << "Error: file not found" << std::endl;
        return (1);
    }

    BitcoinExchange exchange(db_file);

    std::string line;
    std::getline(input_file, line);
    while (input_file.good())
    {
        std::getline(input_file, line);
        if (line.empty())
            continue;
        exchange.process(line);
    }
}