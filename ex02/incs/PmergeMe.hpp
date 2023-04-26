/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:06:51 by bguyot            #+#    #+#             */
/*   Updated: 2023/04/26 15:06:53 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <chrono>

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

class PmergeMe
{
private:
    std::vector<int> _vector;
    std::set<int> _set;
    bool _valid;

public:
    PmergeMe();
    PmergeMe(PmergeMe const &src);
    PmergeMe(int nb_args, char **args);
    ~PmergeMe(void);

    PmergeMe &operator=(PmergeMe const &rhs);

    void sort();
    std::vector<int> sort_vector(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    std::set<int> sort_set(std::set<int>::iterator begin, std::set<int>::iterator end);

    bool isValid() const;

    void print_before();
    void print_after(std::vector<int> &v);
};

#endif