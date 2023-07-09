/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 20:28:00 by amejia            #+#    #+#             */
/*   Updated: 2023/07/09 22:52:07 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string string){
	display_as_char(string);
	display_as_int(string);
	display_as_float(string);
	display_as_double(string);
}

float ScalarConverter::convert_float(std::string &string){
	std::istringstream iss(string);
	float 		result;
	if (!(iss >> result)){
		throw ScalarConverter::CannotConvert();
	}
	return (result);
}

int	ScalarConverter::convert_int(std::string &string){
	int ret = 0;
	
	if (string.size() == 1)
		ret = static_cast<int>( string[0]);
	else
	{
		std::istringstream iss(string);
		int check = 0;
		int point  = 0;
		for(unsigned int i = 0; i < string.size(); i++){
			if (string[i] == '.')
				point++;
			if ((!std::isdigit(string[i]) && string[i] != '.') || point > 1)
				check++;
		}
		if (!(iss >> ret) || check){
			throw ScalarConverter::CannotConvert();
		}
	} 
	
	return(ret);
}

char ScalarConverter::convert_char(std::string &string){
	return(string[0]);
}

double ScalarConverter::convert_double(std::string &string){
	std::istringstream iss(string);
	double 		result;
	if (!(iss >> result)){
		throw ScalarConverter::CannotConvert();
	}
	return (result);
}

void	ScalarConverter::display_as_char(std::string &string){
	char c;
	
	if (string.size() == 1 && std::isprint(string[0])){
		std::cout << "char: " + string << std::endl;
	}
	else {
		try {
			c = static_cast<char> (convert_int(string));
			if (std::isprint(c)){
				std::cout << "char: " << c << std::endl;
			}
			else {
				std::cout << "char: not printable" << std::endl;
			}
		}
		catch (...){
			std::cout << "char: not possible" << std::endl;
		}
	}
		return ;
}

void	ScalarConverter::display_as_int(std::string &string){
	int newInt;
		
	try{
		newInt = convert_int(string);
	}
	catch(...){
		std::cout << "int: not possible"  << std::endl;
		return ;
	}
	std::cout << "int: " << newInt << std::endl;
}	

void	ScalarConverter::display_as_float(std::string &string){
	float flo;
	
	try {
		if (string.size() == 1 && std::isprint(string[0]))
			flo = static_cast<float>(static_cast<int>(string[0]));
		else
			flo = convert_float(string);
		std::cout << "float: " << std::fixed << std::setprecision(1) 
			<< flo << "f" << std::endl;			
	}
	catch(...) {
		std::cout << "float: impossible" << std::endl;	
	}
}	

void	ScalarConverter::display_as_double(std::string &string){
	double flo;
	
	try {
		if (string.size() == 1 && std::isprint(string[0]))
			flo = static_cast<double>(static_cast<int>(string[0]));
		else
			flo = convert_double(string);
		std::cout << "double: " << std::fixed << std::setprecision(1) 
			<< flo << std::endl;			
	}
	catch(...) {
		std::cout << "double: not possible" << std::endl;	
	}
}	


const char *ScalarConverter::CannotConvert::what() const throw(){
	return("Cannot Convert!");
}