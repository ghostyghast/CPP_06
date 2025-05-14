/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:24:04 by amaligno          #+#    #+#             */
/*   Updated: 2025/05/14 17:48:49 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <inttypes.h>

typedef struct Data
{
	long	l;
	int		i;
	char	c;
}	s_data;

class Serializer{
	public:
		
		static uintptr_t	serialize(Data *ptr);
		static Data		*deserialize(uintptr_t raw);
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer &copy);
		Serializer &operator=(const Serializer &copy);
};