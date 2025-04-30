/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pringles <pringles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:10:18 by pringles          #+#    #+#             */
/*   Updated: 2025/04/30 21:56:27 by pringles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iostream>
#include <climits>
#include <cmath>
#include <cstring>
#include <cfloat>
#include <inttypes.h>
#include <iomanip>
#include <cerrno>
using   std::string;
using   std::cerr;
using   std::cout;

enum
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

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
	(void)copy;
	return(*this);
}

static int  getScalarType(string& literal)
{
	if (literal.size() == 1 && (isalpha(*literal.begin()) || ispunct(*literal.begin())))
		return CHAR;
	if (literal == "+inf" || literal == "-inf" || literal == "nan")
		return DOUBLE;
	if (literal == "+inff" || literal == "-inff" || literal == "nanf")
		return FLOAT;	
	if (literal.find('.') != string::npos)
	{
		if (literal[literal.size() - 1] == 'f')
			return FLOAT;
		return DOUBLE;
	}
	return INT;
}

static void convertFromInt(const string& literal)
{
	long	l = strtol(literal.c_str(), NULL , 10);
	int		i = static_cast<int>(l);
	double	d = static_cast<double>(i);
	
	cout << "char: ";
	if (i > CHAR_MAX || i < CHAR_MIN)
		cout << "impossible";
	else if (!std::isprint(i))
		cout << "Non Displayable";
	else
		cout << '\'' << static_cast<char>(i) << '\'';
	cout << '\n';

	cout << "int: ";
	if (l > INT_MAX || l < INT_MIN)
		cout << "impossible";
	else
		cout << i;
	cout << '\n';

	cout << "float: ";
	if (d > FLT_MAX || d < -FLT_MAX)
		cout << "impossible";
	else
		cout << static_cast<float>(i);
	cout << '\n';
	cout << "double: ";
	cout << d << '\n';	
}

static void	convertFromChar(char c)
{
	cout << "char: '" << c << "'\n";
	cout << "int: " << static_cast<int>(c) << '\n';
	cout << "float: " << static_cast<float>(c) << "f\n";
	cout << "double: " << static_cast<double>(c) << '\n';
}

static void convertFromFloat(const string& literal)
{
	float	f = strtof(literal.c_str(), NULL);
	
	cout << "char: ";
	if (f > CHAR_MAX || f < CHAR_MIN)
		cout << "impossible";
	else if (!isprint(static_cast<char>(f)))
		cout << "non displayable";
	else
		cout << '\'' << static_cast<char>(f) << '\'';
	cout << "\n";

	cout << "int: ";
	if (f > INT_MAX || f < INT_MIN || f == INFINITY || f == NAN)
		cout << "impossible";
	else
		cout << static_cast<int>(f);
	cout << "\n";
	
	cout << "float: ";
	if (f == HUGE_VAL || (errno == ERANGE))
		cout << "impossible";
	else
		cout << f << 'f';
	cout << '\n';

	cout << "double: " << static_cast<double>(f) << "\n";
}

void    ScalarConverter::convert(string literal)
{
	cout << std::fixed;
	cout << std::setprecision(1);
	switch (getScalarType(literal))
	{
		case CHAR:
			convertFromChar(literal[0]);
			break;
		case INT:
			convertFromInt(literal);
			break;
		case FLOAT:
			convertFromFloat(literal);
			break;
		case DOUBLE:
			break;
		default:
			cout << "Invalid Input\n";
	}
}
