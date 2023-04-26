/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:03:20 by bguyot            #+#    #+#             */
/*   Updated: 2023/04/26 15:03:34 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(std::string str)
{
    // if ((str.size() == 1 && !isdigit(str[0])) || str.size() == 2 || !(isdigit(str[0]) && isdigit(str[1])))
    // {
    //     std::cout << "Error 1" << std::endl;
    //     exit(1);
    // }
    this->_str = str;

    std::string::iterator it = str.begin();
    while (it != str.end())
    {
        if (*it != ' ')
        {
            if (!isdigit(*it) && *it != '+' && *it != '-' && *it != '*' && *it != '/')
            {
                std::cout << "Error" << std::endl;
                exit(1);
            }
        }
        it++;
    }
}

RPN::RPN(RPN const &rpn)
{
    *this = rpn;
}

RPN::~RPN()
{
}

RPN &RPN::operator=(RPN const &rpn)
{
    if (this != &rpn)
    {
        this->_values = rpn._values;
    }
    return (*this);
}

void RPN::calculate()
{
    std::string::iterator it = this->_str.begin();
    while (it != this->_str.end())
    {
        if (*it == ' ')
        {
            it++;
            continue;
        }
        if (isdigit(*it))
        {
            this->_values.push(*it - '0');
            it++;
            continue;
        }
        if (*it == '+' || *it == '-' || *it == '*' || *it == '/')
        {
            if (this->_values.size() < 2)
            {
                std::cout << "Error" << std::endl;
                return;
            }
            int a = this->_values.top();
            this->_values.pop();
            int b = this->_values.top();
            this->_values.pop();
            if (*it == '+')
                this->_values.push(b + a);
            if (*it == '-')
                this->_values.push(b - a);
            if (*it == '*')
                this->_values.push(b * a);
            if (*it == '/')
            {
                if (a == 0)
                {
                    std::cout << "Error" << std::endl;
                    return;
                }
                this->_values.push(b / a);
            }
            it++;
            continue;
        }
    }
    if (this->_values.size() != 1)
    {
        std::cout << "Error" << std::endl;
        return;
    }
    std::cout << this->_values.top() << std::endl;
}