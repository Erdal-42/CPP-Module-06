/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekocak@student.42.org.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 17:25:55 by ekocak            #+#    #+#             */
/*   Updated: 2023/08/13 10:25:55 by ekocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string>
#include <cctype>
#include "Utility.hpp"
#include <cfloat>
#include <iomanip>
#include <limits>
#include <climits>


enum TYPE {INTEGER, DOUBLE, FLOAT, CHAR, MISCELLANEOUS, NONE};

class ScalarConverter
{
    public:
        ScalarConverter() {};
        ~ScalarConverter() {};
        static void     convert(std::string);

        static bool     isChar(const char *);
        
        static TYPE     detectType(std::string);
        static double   convertDouble(std::string);
        static float    convertFloat(std::string);
        static char     convertChar(std::string);  

        static void     outputInttoDouble(int);
        static void     outputInttoFloat(int);
        static void     outputDoubletoFloat(double, int);
        static void     outputDoubletoInt(double);
        static void     outputFloattoDouble(float, int);
        static void     outputFloattoInt(float);
        static void     outputChar();
        static void     outputInttoChar(int);
        static void     outputDoubletoChar(double);
        static void     outputFloattoChar(float);

        static void     outputImpossibleExceptions();
        
        static void     displayTypeMiscellaneous(const char *);
        static void     displayTypeInt(const char *);
        static void     displayTypeDouble(const char *);
        static void     displayTypeFloat(const char *);
        static void     displayTypeChar(const char *);

        class NonDisplayableException : public std::exception
        {
                public:
                        virtual const char *what() const throw();
        };
        class ImpossibleException : public std::exception
        {
                public:
                        virtual const char *what() const throw();
        };
};