/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:06:23 by bguyot            #+#    #+#             */
/*   Updated: 2023/04/26 15:06:35 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(int nb_args, char **args)
{
    for (int i = 0; i < nb_args; i++)
    {
        try
        {
            if (std::stoi(args[i]) < 0)
                throw "oh no! my domain! its broken!";
        }
        catch (...)
        {
            std::cout << "Error while parsing: " << args[i] << std::endl;
            this->_valid = false;
            return;
        }
        if (std::find(this->_vector.begin(), this->_vector.end(), std::stoi(args[i])) != this->_vector.end())
            continue;
        this->_vector.push_back(std::stoi(args[i]));
        this->_set.insert(std::stoi(args[i]));
    }
    this->_valid = true;
}

PmergeMe::PmergeMe(PmergeMe const &src)
{
    *this = src;
}

PmergeMe::~PmergeMe(void)
{
}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs)
{
    if (this != &rhs)
    {
        this->_vector = rhs._vector;
        this->_set = rhs._set;
        this->_valid = rhs._valid;
    }
    return *this;
}

bool PmergeMe::isValid() const
{
    return this->_valid;
}

void PmergeMe::print_before()
{
    std::cout << "Before sort: ";
    for (std::vector<int>::iterator it = this->_vector.begin(); it != this->_vector.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void PmergeMe::print_after(std::vector<int> &v)
{
    std::cout << "After sort: ";
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void PmergeMe::sort()
{
    std::chrono::high_resolution_clock::time_point v_start = std::chrono::high_resolution_clock::now();
    std::vector<int> sorted_vector = sort_vector(this->_vector.begin(), this->_vector.end());
    std::chrono::high_resolution_clock::time_point v_end = std::chrono::high_resolution_clock::now();
    std::chrono::microseconds v_us = std::chrono::duration_cast<std::chrono::microseconds>(v_end - v_start);
    std::chrono::milliseconds v_ms = std::chrono::duration_cast<std::chrono::milliseconds>(v_end - v_start);

    std::chrono::high_resolution_clock::time_point s_start = std::chrono::high_resolution_clock::now();
    std::set<int> sorted_set = sort_set(this->_set.begin(), this->_set.end());
    std::chrono::high_resolution_clock::time_point s_end = std::chrono::high_resolution_clock::now();
    std::chrono::microseconds s_us = std::chrono::duration_cast<std::chrono::microseconds>(s_end - s_start);
    std::chrono::milliseconds s_ms = std::chrono::duration_cast<std::chrono::milliseconds>(s_end - s_start);

    print_before();
    print_after(sorted_vector);

    std::cout << "Time to process a range of " << this->_vector.size() << " elements with std::vector -> " << v_us.count() << "us (" << v_ms.count() << " ms)" << std::endl;
    std::cout << "Time to process a range of " << this->_vector.size() << " elements with std::set    -> " << s_us.count() << "us (" << s_ms.count() << " ms)" << std::endl;
}

std::vector<int> PmergeMe::sort_vector(
    std::vector<int>::iterator begin,
    std::vector<int>::iterator end)
{
    if (end - begin <= 1)
        return std::vector<int>(begin, end);
    std::vector<int>::iterator middle = begin + (end - begin) / 2;
    std::vector<int> left = sort_vector(begin, middle);
    std::vector<int> right = sort_vector(middle, end);
    std::vector<int> result;
    std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(result));
    return result;
}

std::set<int> PmergeMe::sort_set(
    std::set<int>::iterator begin,
    std::set<int>::iterator end)
{
    if (std::distance(begin, end) <= 1)
        return std::set<int>(begin, end);
    std::set<int>::iterator middle = begin;
    std::set<int>::iterator tmp = begin;
    while (tmp != end && ++tmp != end)
    {
        middle++;
        tmp++;
    }
    std::set<int> left = sort_set(begin, middle);
    std::set<int> right = sort_set(middle, end);
    std::set<int> result;
    std::merge(left.begin(), left.end(), right.begin(), right.end(), std::inserter(result, result.begin()));
    return result;
}