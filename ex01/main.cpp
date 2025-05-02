/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:22:10 by amaligno          #+#    #+#             */
/*   Updated: 2025/05/02 18:33:39 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

using std::cout;

int main(void)
{
	Data		data;
	uintptr_t	ptr;
	Data		*data_ptr;

	data.i = 3;
	data.c = 3;
	data.f = 3;

	cout << "data.i: " << data.i << '\n';
	
	ptr = Serializer::serialize(&data);
	
	int		*int_ptr = reinterpret_cast<int*>(ptr);
	cout << "*int_ptr: " << *int_ptr++ << '\n';
	char	*char_ptr = reinterpret_cast<char*>(int_ptr);
	cout << "*char_ptr: " << *char_ptr++ << '\n';
	float	*float_ptr = reinterpret_cast<float*>(char_ptr);
	cout << "*float_tr: " << *float_ptr<< "\n";
	
	data_ptr = Serializer::deserialize(ptr);
	cout << "data_ptr->i: " << data_ptr->i << "\n";
}