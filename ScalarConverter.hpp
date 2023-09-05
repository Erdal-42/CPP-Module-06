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

enum TYPE {INTEGER, DOUBLE, FLOAT, CHAR, MISCELLANEOUS, NONE};

class ScalarConverter
{
    public:
        ScalarConverter() {};
        ~ScalarConverter() {};
        ScalarConverter(const ScalarConverter &);

        static bool isChar(char *);
        
        static TYPE     detectType(char *);
        static int      convertInt(std::string);
        static double   convertDouble(std::string);
        static float    convertFloat(std::string);
        static char     convertChar(std::string);  

        static void     outputInttoDouble(int);
        static void     outputInttoFloat(int);
        static void     outputDoubletoFloat(double, int);
        static void     outputFloattoDouble(float, int);
        static void     outputChar();
        static void     outputInttoChar(int);
        static void     outputDoubletoChar(double);
        static void     outputFloattoChar(float);
        
        //display
        static void     displayTypeMiscellaneous(char *);
        static void     displayTypeInt(char *);
        static void     displayTypeDouble(char *);
        static void     displayTypeFloat(char *);
        static void     displayTypeChar(char *);

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

        void            displayType(char *);
        void            _displayTypeInt(char *);
        void            _displayTypeDouble(char *);
        void            _displayTypeFloat(char *);
        void            _displayTypeChar(char *);
        void            _displayTypeMiscellaneous(char *);
};