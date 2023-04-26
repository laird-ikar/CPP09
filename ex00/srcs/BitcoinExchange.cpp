/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:59:33 by bguyot            #+#    #+#             */
/*   Updated: 2023/04/26 15:00:25 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
    *this = src;
}

BitcoinExchange::BitcoinExchange(std::ifstream &file)
{
    std::string line;
    std::getline(file, line);
    while (file.good())
    {
        std::getline(file, line);
        if (line.length() > 0)
        {
            std::string date = line.substr(0, line.find_first_of(','));
            std::string rate = line.substr(line.find_first_of(',') + 1);
            if (!_is_valid_date(date) || !_is_valid_rate(rate) || stod(rate) < 0)
            {
                std::cout << "Error: bad input => " << line << std::endl;
                exit(1);
            }
            this->_rates[date] = stod(rate);
        }
    }
}

BitcoinExchange::~BitcoinExchange(void)
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
    if (this != &rhs)
    {
        this->_rates = rhs._rates;
    }
    return (*this);
}

bool BitcoinExchange::_is_valid_date(const std::string &date)
{
    struct tm tm;
    if (!strptime(date.c_str(), "%Y-%m-%d", &tm))
        return (false);
    return (true);
}

bool BitcoinExchange::_is_valid_rate(const std::string &rate)
{
    try
    {
        std::stod(rate);
    }
    catch (...)
    {
        return false;
    }
    return true;
}

void BitcoinExchange::process(const std::string &line)
{
    if (line.length() == 0)
        return;
    std::string date = line.substr(0, line.find_first_of('|') - 1);
    std::string rate = line.substr(line.find_first_of('|') + 2);
    if (!_is_valid_date(date) || !_is_valid_rate(rate))
    {
        std::cout << "Error: bad input => " << line << std::endl;
        return;
    }
    double nb = std::stod(rate);
    if (nb < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return;
    }
    if (nb > 2147483647)
    {
        std::cout << "Error: too large number." << std::endl;
        return;
    }

    std::map<std::string, double>::iterator it = this->_rates.upper_bound(date);
    if (it != this->_rates.begin())
    {
        --it;
    }

    std::cout << date << " => " << rate << " = " << (nb * it->second) << std::endl;
}