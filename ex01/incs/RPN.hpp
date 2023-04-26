/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:03:51 by bguyot            #+#    #+#             */
/*   Updated: 2023/04/26 15:04:01 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stack>
#include <cstring>

#ifndef RPN_HPP
#define RPN_HPP

class RPN
{
private:
    std::stack<double> _values;
    std::string _str;

public:
    RPN();
    RPN(std::string str);
    RPN(RPN const &rpn);
    ~RPN();

    RPN &operator=(RPN const &rpn);
    void calculate();
};

#endif