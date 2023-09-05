/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekocak@student.42.org.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 17:25:55 by ekocak            #+#    #+#             */
/*   Updated: 2023/08/13 10:25:55 by ekocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

       
ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    *this = other;
}


void    ScalarConverter::displayType(char *param)
{
    TYPE            t;
    enum TYPE       type;
    int             i;
    char            *str;

    t = this->detectType(param);
    void (ScalarConverter::*displayCorrespondingTypes[5])(char *) =
    {
            &ScalarConverter::_displayTypeInt,
            &ScalarConverter::_displayTypeDouble,
            &ScalarConverter::_displayTypeFloat,
            &ScalarConverter::_displayTypeChar,
            &ScalarConverter::_displayTypeMiscellaneous
    };
    str = &(trim(param))[0];
    for (i = INTEGER; i < 5; i ++)
    {
        type = (enum TYPE)i;
        if (t == type)
        {
            (this->*displayCorrespondingTypes[i])(str);
            break ;
        }
    } 
}

void ScalarConverter::_displayTypeInt(char *str)
{
    displayTypeInt(str);
}

void ScalarConverter::_displayTypeDouble(char *str)
{
    displayTypeDouble(str);
}

void ScalarConverter::_displayTypeFloat(char *str)
{
    displayTypeFloat(str);
}

void ScalarConverter::_displayTypeChar(char *str)
{
    displayTypeChar(str);
}

void ScalarConverter::_displayTypeMiscellaneous(char *str)
{
    displayTypeMiscellaneous(str);
}

void    ScalarConverter::displayTypeMiscellaneous(char *param)
{
    std::string str;

    str = std::string(param);
    std::cout << "char : impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << str;
    if (str == "nan" || str == "-inf" || str == "+inf")
    {
        std::cout << "f";     
    }
    std::cout << std::endl;
    std::cout << "double: ";
    if (str == "-inff")
        std::cout << "-inf";
    else if (str == "+inff")
        std::cout << "+inf";
    else if (str == "nanf")
        std::cout << "nan";
    else
        std::cout << str;
    std::cout << std::endl; 
}

void    ScalarConverter::displayTypeInt(char *str)
{
    int n;
    
    n = convertInt(str);
    std::cout << "char: ";
    outputInttoChar(n);
    std::cout << "int: " << n << std::endl;
    std::cout << "float: "; 
    outputInttoFloat(n);
    std::cout << std::endl;
    std::cout << "double: ";
    outputInttoDouble(n);
    std::cout << std::endl; 
}

void    ScalarConverter::displayTypeDouble(char *str)
{
    double  d;
    int     dp; 

    d = convertDouble(str);
    dp = numberDecimalPlaces(str);
    std::cout << "char: ";
    outputDoubletoChar(d);
    std::cout << "int: " << static_cast<int>(d) << std::endl;
    std::cout << "float: ";
    outputDoubletoFloat(d, dp);
    std::cout << std::endl;
    std::cout << "double: " << d << std::endl;
}

void    ScalarConverter::displayTypeFloat(char *str)
{
    float   f;
    int     dp; 

    f = convertFloat(str);
    dp = numberDecimalPlaces(str);
    
    std::cout << "char: ";
    outputFloattoChar(f);
    std::cout << "int: " << static_cast<int>(f) << std::endl;
    std::cout << std::fixed << std::setprecision(dp); 
    std::cout << "float: " << f << 'f' << std::endl;
    std::cout << "double: ";
    outputFloattoDouble(f, dp);
    std::cout << std::endl;
}

void    ScalarConverter::displayTypeChar(char *str)
{
    char    c;
    
    c = convertChar(str);
    std::cout << "char: '" << c << "\'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << std::fixed << std::setprecision(1); 
    std::cout << "float: " << static_cast<float>(c) << 'f' << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl; 
}


/*
 * The largest positive finite value that can be represented 
 * by a double is approximately 1.79769 x 10^308. This value 
 * is defined as DBL_MAX in the <cfloat> header.
 *
 * The smallest positive normalized value (greater than zero) 
 * that can be represented by a double is approximately 
 * 2.22507 x 10^-308. This value is defined as DBL_MIN in the 
 * <cfloat> header.
 */

void  ScalarConverter::outputInttoDouble(int n)
{
    //an int can never surpass a double value under any platform.
    if (n < -DBL_MAX || n > DBL_MAX)
    {
        try
        {        
            throw (ScalarConverter::ImpossibleException());
        }
        catch (const ImpossibleException &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    else
    {
        std::cout << std::fixed << std::setprecision(1);
        std::cout << static_cast<double>(n);
    }
}

void   ScalarConverter::outputDoubletoFloat(double d, int dp)
{
    if (d < -FLT_MAX || d > FLT_MAX)
    {
        try
        {
            throw ScalarConverter::ImpossibleException();
        }
        catch (const ImpossibleException &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    else
    {
        std::cout << std::fixed << std::setprecision(dp);
        std::cout << static_cast<float>(d) << 'f';
    }
}

void    ScalarConverter::outputFloattoDouble(float f, int dp)
{
    if (f < -DBL_MAX || f > DBL_MAX)
    {
        try
        {
            throw (ScalarConverter::ImpossibleException());
        }
        catch (const ImpossibleException &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    else
    {
        std::cout << std::fixed << std::setprecision(dp);
        std::cout << (double)(f);
    } 
}

/* 
 * FLT_MAX: The maximum positive finite value that a float can 
 * represent.
 * FLT_MIN: The minimum positive normalized value that a float 
 * can represent.
 * In C++98, you can use the <cfloat> header to access the 
 * macros that define the limits of the float data type. 
 */

void   ScalarConverter::outputInttoFloat(int n)
{
    if (n < -FLT_MAX || n > FLT_MAX)
    {
        try
        {        
            throw (ScalarConverter::ImpossibleException());
        }
        catch (const ImpossibleException &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    else
    {
        std::cout << std::fixed << std::setprecision(1);
        std::cout << static_cast<float>(n) << 'f';
    }
}

/*
 * int: This is typically a 32-bit signed integer on most 
 * modern systems, with a range of approximately 
 * -2,147,483,648 to 2,147,483,647.
 */
void    ScalarConverter::outputInttoChar(int n)
{
    if (n < 32 || n > 126)
    {
        try
        {        
            throw (ScalarConverter::NonDisplayableException());
        }
        catch (const NonDisplayableException &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    else
        std::cout << "\'" << (char)n << "\'" << std::endl;
}

void    ScalarConverter::outputDoubletoChar(double d)
{
    if (d < 32 || d > 126)
    {
        try
        {        
            throw (ScalarConverter::NonDisplayableException());
        }
        catch (const NonDisplayableException &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    else 
        std::cout << "\'" << static_cast<char>(d) << "\'" << std::endl;
}

void    ScalarConverter::outputFloattoChar(float f)
{
    if (f < 32 || f > 126)
    {
        try
        {
            throw (ScalarConverter::NonDisplayableException());
        }
        catch (const NonDisplayableException &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    else
        std::cout << "\'" <<static_cast<char>(f) << "\'" << std::endl;
}

int     ScalarConverter::convertInt(std::string str)
{
    int val;

    try
    {
        val = std::stoi(str);
    }
    catch (const std::out_of_range& e) 
    { 
        std::cerr << e.what() << std::endl;
    }
    return (val);
}

double  ScalarConverter::convertDouble(std::string str)
{
    double  val;

    try
    {
        val = std::stod(str);
    }
    catch (const std::out_of_range& e) 
    {
        std::cerr << e.what() << std::endl;
    }
    return (val);
}

float  ScalarConverter::convertFloat(std::string str)
{
    float val;

    try
    {
        val = std::atof(str.c_str());
    }
    catch (const std::out_of_range& e) 
    {
        std::cerr << e.what() << std::endl;
    }
    return (val);
}

char    ScalarConverter::convertChar(std::string str)
{
    char val;

    try
    {
        val = (trim(str))[0]; 
    }
    catch (const std::out_of_range& e) 
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return (val); 
}

TYPE    ScalarConverter::detectType(char *str)
{
    int     i;
    char    *str_trimmed;
    std::string std_str_trimmed;
    
    if (!ft_strlen(str))
    {   
        std::cout << "Empty String" << std::endl;
        return (NONE);
    }
    str_trimmed = &(trim(str))[0];
    i = 0;
    if (str_trimmed[i] && (str_trimmed[i] == '+' || str_trimmed[i] == '-'))
        ++ i;
    std_str_trimmed = (std::string) str_trimmed;
    if (std_str_trimmed == "nan" || std_str_trimmed == "-inf" || std_str_trimmed == "nanf" ||
             std_str_trimmed == "+inf" || std_str_trimmed == "-inff" || std_str_trimmed == "+inff")
        return (MISCELLANEOUS);
    else if (consecutiveDigits(str_trimmed + i))
        return (INTEGER);
    else if (consecutiveDigitsAndPoint(str_trimmed + i))
        return (DOUBLE);
    else if (consecutiveDigitsPointAndF(str_trimmed + i))
        return (FLOAT);
    else if (isChar(str_trimmed))
        return (CHAR);
    return ( std::cout << "Unrecognised Class" << std::endl, NONE); 
}

bool    ScalarConverter::isChar(char *str)
{
    if (ft_strlen(str) != 1)
        return (false);
    if (!displayable(str[0]))
        std::cout << "The character entered cannot be displayed." << std::endl;
    return (true);
}

const char *ScalarConverter::NonDisplayableException::what() const throw()
{
    return ("Non displayable");
}

const char  *ScalarConverter::ImpossibleException::what() const throw()
{
    return ("Impossible");
}
