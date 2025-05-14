/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pringles <pringles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:10:18 by pringles          #+#    #+#             */
/*   Updated: 2025/05/02 04:14:50 by pringles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>
#include <limits>
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

static int checkInput(const string& literal, int type)
{
	string::const_iterator	it = literal.begin();
	string::const_iterator	end = literal.end();
	
	if (type == FLOAT && (literal.find('f') != literal.rfind('f')))
		return -1;
	if ((type == FLOAT || type == DOUBLE) && (literal.find('.') != literal.rfind('.')))
		return -1;
	if (strchr("+-", *it))
		it++;
	while (it != end)
	{
		if (type != INT && !strchr(".f", *it) && !isdigit(*it))
			return -1;
		if (type == INT && !isdigit(*it))
			return -1;
		it++;
	}
	return (type);
}

static int  getScalarType(const string& literal)
{
	int	type;

	if (literal == "+inf" || literal == "-inf" || literal == "nan")
		return DOUBLE;
	if (literal == "+inff" || literal == "-inff" || literal == "nanf")
		return FLOAT;
	if (literal.size() == 1 && (isalpha(*literal.begin()) || ispunct(*literal.begin())))
		return CHAR;

	if (literal.find('.') != string::npos)
	{
		if (literal[literal.size() - 1] == 'f')
			type = FLOAT;
		else
			type = DOUBLE;
	}
	else
		type = INT;
	return (checkInput(literal, type));
}

template <typename T> void toChar(T value)
{
	cout << "char: ";
	if (value > std::numeric_limits<char>::max() || value < std::numeric_limits<char>::min() || std::isnan(value))
		cout << "impossible";
	else if (!isprint(static_cast<char>(value)))
		cout << "non displayable";
	else
		cout << '\'' << static_cast<char>(value) << '\'';
	cout << "\n";
}

template <typename T> void toInt(T value)
{
	cout << "int: ";
	if ((value >= std::numeric_limits<int>::max() || value <= std::numeric_limits<int>::min() || std::isnan(value) || value == std::numeric_limits<T>::infinity()))
		cout << "impossible";
	else
		cout << static_cast<int>(value);
	cout << "\n";
}

template <typename T> void toFloat(T value)
{
	cout << "float: ";
	if ((value != std::numeric_limits<float>::infinity() && value != -std::numeric_limits<float>::infinity()) &&
		(value == std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max() || value < -std::numeric_limits<float>::max()))
		cout << "impossible";
	else
		cout << static_cast<float>(value) << 'f';
	cout << '\n';
}

template <typename T> void toDouble(T value)
{
	cout << "double: ";
	if ((value != std::numeric_limits<double>::infinity() && value != -std::numeric_limits<double>::infinity()) &&
		(value == std::numeric_limits<double>::max() || value > std::numeric_limits<double>::max() || value < -std::numeric_limits<double>::max()))
		cout << "impossible";
	else
		cout << static_cast<double>(value);	
	cout << '\n';
}

template <typename T>	static void convertFromType(T value)
{
	toChar<T>(value);
	toInt<T>(value);
	toFloat<T>(value);
	toDouble<T>(value);
}


void    ScalarConverter::convert(string literal)
{
	cout << std::fixed;
	// cout << std::setprecision(1);
	switch (getScalarType(literal))
	{
		case CHAR:
			convertFromType<char>(literal[0]);
			break;
		case INT:
			convertFromType<long>(strtol(literal.c_str(), NULL, 10));
			break;
		case FLOAT:
			convertFromType<float>(strtof(literal.c_str(), NULL));
			break;
		case DOUBLE:
			convertFromType<double>(strtod(literal.c_str(), NULL));
			break;
		default:
			cout << "Invalid Input\n";
	}
}
	// template <typename T>	void	covertFromType(T value)
	// {
	// 	cout << "char: ";
	// 	if (value > std::numeric_limits<char>::max() || value < std::numeric_limits<char>::min())
	// 		cout << "impossible";
	// 	else if (!isprint(static_cast<char>(value)))
	// 		cout << "non displayable";
	// 	else
	// 		cout << '\'' << static_cast<char>(value) << '\'';
	// 	cout << "\n";
	
	// 	cout << "int: ";
	// 	if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::max() || value == INFINITY || value ==inAN)
	// 		cout << "impossible";
	// 	else
	// 		cout << static_cast<int>(value);
	// 	cout << "\n";
		
	// 	cout << "float: ";
	// 	if (value == std::numeric_limits<float>::max() || (errno == ERANGE))
	// 		cout << "impossible";
	// 	else
	// 		cout << value << 'f';
	// 	cout << '\n';
	// 	if (value)
	// 	cout << "double: " << static_cast<double>(value) << "\n";
	// }
	
