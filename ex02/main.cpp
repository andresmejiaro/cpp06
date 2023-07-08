/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 23:54:38 by amejia            #+#    #+#             */
/*   Updated: 2023/07/09 00:07:20 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base * generate(){
	Base *ptr;

	switch (std::rand() % 3)
	{
	case 0:
		ptr = new A;
		break;
	case 1:
		ptr = new B;
		break;
	case 2:
		ptr = new C;
		break;
	}	
	return (ptr);
}
void identify(Base* p){
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "The poiner is class A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "The poiner is class B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "The poiner is class C" << std::endl;
}

void identify(Base& p){
	
}


int main(void){
	std:srand(std::time(0));
	return (0);
}