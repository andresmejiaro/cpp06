/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 20:22:33 by amejia            #+#    #+#             */
/*   Updated: 2023/07/08 21:00:00 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H
# include <iostream>
# include <cctype>
# include <limits>
#include <iomanip>

class ScalarConverter {
public:
	static void 		convert(std::string);
private:
	static char			convert_char(std::string );	
	static int			convert_int(std::string );	
	static float		convert_float(std::string );	
	static double		convert_double(std::string );
	static void			display_as_char(std::string );	
	static void			display_as_int(std::string );	
	static void			display_as_float(std::string );	
	static void			display_as_double(std::string );
	ScalarConverter();
	ScalarConverter(const ScalarConverter&);
	~ScalarConverter();
	ScalarConverter& operator=(const ScalarConverter&);
};

#endif // ScalarConverter_H