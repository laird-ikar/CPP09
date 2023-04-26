/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:59:52 by bguyot            #+#    #+#             */
/*   Updated: 2023/04/26 15:00:19 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <ctime>
#include <iomanip>

class BitcoinExchange
{
private:
    std::map<std::string, double> _rates;
    static bool _is_valid_date(const std::string &date);
    static bool _is_valid_rate(const std::string &date);

public:
    BitcoinExchange(void);
    BitcoinExchange(const BitcoinExchange &src);
    BitcoinExchange(std::ifstream &file);
    ~BitcoinExchange(void);

    BitcoinExchange &operator=(const BitcoinExchange &rhs);

    void process(const std::string &line);
};