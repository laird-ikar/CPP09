/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:05:42 by bguyot            #+#    #+#             */
/*   Updated: 2023/04/26 15:06:09 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/PmergeMe.hpp"

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        std::cout << "Usage: ./PmergeMe <list of positive integers>" << std::endl;
        return 1;
    }

    PmergeMe sorter(argc - 1, argv + 1);
    if (!sorter.isValid())
        return 1;
    sorter.sort();
}