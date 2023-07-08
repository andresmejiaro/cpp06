/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 22:42:35 by amejia            #+#    #+#             */
/*   Updated: 2023/07/08 22:54:27 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void){
	Data		midata;
	uintptr_t	ptr;
	
	ptr = Serializer::serialize( &midata);
		
			
	std::cout << ptr << std::endl;
	std::cout << Serializer::deserialize(ptr) << std::endl;
	std::cout << (&midata == Serializer::deserialize(ptr)) << std::endl;
	
	
	return (0);
}