/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 20:22:33 by amejia            #+#    #+#             */
/*   Updated: 2023/07/09 22:29:20 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H
# include <iostream>
# include <cctype>
# include <limits>
# include <iomanip>
# include <sstream>

class ScalarConverter {
public:
	static void 		convert(std::string);
	class CannotConvert: public std::exception{
                public:
                const char* what() const throw();
    };
private:
	static char			convert_char(std::string& );	
	static int			convert_int(std::string& );	
	static float		convert_float(std::string& );	
	static double		convert_double(std::string& );
	static void			display_as_char(std::string& );	
	static void			display_as_int(std::string& );	
	static void			display_as_float(std::string& );	
	static void			display_as_double(std::string& );
	ScalarConverter();
	ScalarConverter(const ScalarConverter&);
	~ScalarConverter();
	ScalarConverter& operator=(const ScalarConverter&);
};

#endif // ScalarConverter_H