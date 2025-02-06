/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pringles <pringles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:01:59 by pringles          #+#    #+#             */
/*   Updated: 2025/02/06 18:31:50 by pringles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
    public:
        ScalarConverter(const ScalarConverter &copy);
        ScalarConverter	&operator=(const ScalarConverter &copy);

        static  void    convert(std::string literal);
    private:
        ~ScalarConverter();
        ScalarConverter();
    
};

#endif