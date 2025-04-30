/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pringles <pringles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:07:22 by pringles          #+#    #+#             */
/*   Updated: 2025/04/29 00:45:25 by pringles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
using   std::cout;

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Invalid argument amount\n";   
        return (1);
    }
    ScalarConverter::convert(argv[1]);
}