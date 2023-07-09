/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 23:54:38 by amejia            #+#    #+#             */
/*   Updated: 2023/07/09 22:19:42 by amejia           ###   ########.fr       */
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
		std::cout << "The pointer is class A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "The pointer is class B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "The pointer is class C" << std::endl;
	else
		std::cout << "The pointer is unknown class" << std::endl;
}

void identify(Base& p){
	Base BB;
	
	try{ 
		BB = dynamic_cast<A&>(p);
		std::cout << "The reference is class A" << std::endl;
	}
	catch (const std::bad_cast& e){
		try{ 
			BB = dynamic_cast<B&>(p);
			std::cout << "The reference is class B" << std::endl;
			
		}catch(const std::bad_cast& e){
			try{ 
				 BB = dynamic_cast<C&>(p);
				std::cout << "The reference is class C" << std::endl;
				
			}catch(const std::bad_cast& e){
				std::cout << "The reference is class unknown" << std::endl;
			}
			
		}
		
	} 
}

int main(void){
	std::srand(std::time(0));
	
	for(int i = 0; i < 10; i++){
		Base *p = generate();
		identify(p);
		identify(*p);
		delete p;	
	}
	return (0);
}
