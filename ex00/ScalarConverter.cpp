/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pringles <pringles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:10:18 by pringles          #+#    #+#             */
/*   Updated: 2025/02/06 19:24:31 by pringles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <stdlib.h>
#include <iostream>
using   std::string;
using   std::cerr;
using   std::cout;

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
    *this = copy;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter    &ScalarConverter::operator=(const ScalarConverter &copy)
{
    return(*this);
}

static void display(char c, int i, float f, double d)
{
    cout << "char: " << c << '\n';
    cout << "int: " << i << '\n';
    cout << "float: " << f << '\n';
    cout << "double: " << d << '\n';
}

void    ScalarConverter::convert(string literal)
{
    string::iterator     it = literal.begin();
    string::iterator     end = literal.end();
    char    c;
    int     i;
    float   f;
    double  d;

    if (*it == '\'')
    {
        it++;
        c = static_cast<char>(*it);
        it++;
        if (*it != '\'')
        {
            std::cerr << "Invalid character syntax";
            return ;
        }
        
    }
    else
    {
        while (it != end)
        {
        }
    }
}
