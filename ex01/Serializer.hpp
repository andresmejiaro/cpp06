/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 22:24:00 by amejia            #+#    #+#             */
/*   Updated: 2023/07/08 22:49:02 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_H
#define SERIALIZER_H
# include <cstdint>
# include <iostream>
# include "Data.h"


class Serializer {
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
private:
  Serializer();
  Serializer(const Serializer&);
  ~Serializer();
  Serializer& operator=(const Serializer&);
};

#endif // Serializer_H