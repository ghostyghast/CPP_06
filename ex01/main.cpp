/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:22:10 by amaligno          #+#    #+#             */
/*   Updated: 2025/05/14 17:52:44 by amaligno         ###   ########.fr       */
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

	data.l = 10;
	data.i = 3;
	data.c = 'a';
	
	cout << "Data before seriailze :" << "\n";
	cout << "Data.l " << data.l << "\n";
	cout << "Data.i " << data.i << "\n";
	cout << "Data.c " << data.c << "\n";
	cout << "---------------\n";

	ptr = Serializer::serialize(&data);
	
	long	*long_ptr = reinterpret_cast<long*>(ptr);
	cout << "*long_ptr: " << *long_ptr++ << "\n";
	int		*int_ptr = reinterpret_cast<int*>(long_ptr);
	cout << "*int_ptr: " << *int_ptr++ << '\n';
	char	*char_ptr = reinterpret_cast<char*>(int_ptr);
	cout << "*char_ptr: " << *char_ptr << '\n';
	
	data_ptr = Serializer::deserialize(ptr);

	cout << "---------------\n";
	cout << "Data After seriailze :" << "\n";
	cout << "Data.l " << data.l << "\n";
	cout << "Data.i " << data.i << "\n";
	cout << "Data.c " << data.c << "\n";
	
}