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


/**
 * Display the converted type and value of a scalar parameter.
 *
 * This member function of the `ScalarConverter` class takes a 
 * C-style string `param` as input and attempts to detect its 
 * type. It then displays the converted type and value of the 
 * scalar parameter. The function uses a pointer-to-member
 * function array to choose the appropriate display function 
 * based on the detected type. It processes the parameter string
 * by first trimming leading and trailing whitespace characters.
 *
 * @param param A pointer to a C-style string representing a 
 * scalar value to be displayed.
 */ 
void    ScalarConverter::convert(std::string param)
{
    TYPE            t;

    t = detectType(param);
    switch (t)
    {   case INTEGER:
            ScalarConverter::displayTypeInt(param.c_str());
            break ;
        case DOUBLE:
            ScalarConverter::displayTypeDouble(param.c_str());
            break ;
        case FLOAT:
            ScalarConverter::displayTypeFloat(param.c_str());
            break ;
        case CHAR:
            ScalarConverter::displayTypeChar(param.c_str());
            break ;
        case MISCELLANEOUS:
            ScalarConverter::displayTypeMiscellaneous(param.c_str());
            break;
        case NONE:
            ;
            break;
    }
}

/*
 * nan : "Not A Number" as a double precision (double) value. It 
 * serves the same purpose as  nanf but with double precision.
 * 
 * nanf: "Not A Number"  as a single precision (float) value. It
 * is used when you want to represent an undefined or 
 * unrepresentable value in single precision floating point
 * arithmetic.
 *  
 * inf (or INFINITY in C and C++): This represents positive 
 * infinity as a double-precision value. It is used to represent 
 * values that exceed the range of representable finite numbers 
 * in double-precision floating-point arithmetic.
 * 
 * inff (or INFINITYF in C and C++): Similar to inf, this 
 * represents positive infinity, but it is of single-precision 
 * (float) type. It is used to represent positive infinity in 
 * single-precision floating-point arithmetic.
 */
void    ScalarConverter::displayTypeMiscellaneous(const char *param)
{
    std::string str;

    str = std::string(param);
    std::cout << "char\t: impossible" << std::endl;
    std::cout << "int\t: impossible" << std::endl;
    std::cout << "float\t: " << str;
    if (str == "nan" || str == "-inf" || str == "+inf")
    {
        std::cout << "f";     
    }
    std::cout << std::endl;
    std::cout << "double\t: ";
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

/**
 * @brief Outputs the impossible exceptions for converting a scalar value.
 * 
 * This function creates an instance of the ImpossibleException class and outputs
 * its message for each scalar type (char, int, float, double).
 * 
 */
void    ScalarConverter::outputImpossibleExceptions()
{
    const ImpossibleException e;
    {
        std::cout << "char\t: ";
        std::cerr << e.what() << std::endl;
        std::cout << "int\t: ";
        std::cerr << e.what() << std::endl;
        std::cout << "float\t: ";
        std::cerr << e.what() << std::endl;
        std::cout << "double\t: ";
        std::cerr << e.what() << std::endl;
    }
}

/**
 * @brief An integer is input as a string. Which is then converted to other data types.
 * 
 * This function converts the input string to a long long value using std::stol
 * and then checks if the value is within the range of an int. If it is within
 * the range, it displays the converted value as a char, int, float, and double.
 * Otherwise, it calls outputImpossibleExceptions to indicate that the conversion
 * is impossible.
 * 
 * @param str An integer that is input as a string.
 */
void    ScalarConverter::displayTypeInt(const char *str)
{
    long long val;
    
    val = std::stol(str);
    if (val > INT_MAX || val < INT_MIN)
    {
        outputImpossibleExceptions();
    }
    else 
    {
        std::cout << "char\t: ";
        outputInttoChar(val);
        std::cout << "int\t: ";
        std::cout << val << std::endl;
        std::cout << "float\t: "; 
        outputInttoFloat(val);
        std::cout << std::endl;
        std::cout << "double\t: ";
        outputInttoDouble(val);
        std::cout << std::endl; 
    }
}

/**
 * @brief A double is input as a string. Which is then converted to other data types.
 * 
 * This function converts the input string to a double value using the convertDouble
 * function and then checks if the value is within the range of a double. If it is within
 * the range, it displays the converted value as a char, int, float, and double.
 * Otherwise, it calls outputImpossibleExceptions to indicate that the conversion
 * is impossible.
 * 
 * @param str A double that is input as a string.
 */
void    ScalarConverter::displayTypeDouble(const char *str)
{
    double  d;
    int     dp;
    d = convertDouble(str);
    std::cout << "char\t: ";
    
    outputDoubletoChar(d);
    d = convertDouble(str);
    if (d < -DBL_MAX || d > DBL_MAX) 
    {
        outputImpossibleExceptions();
        return ;
    } 
    dp = numberDecimalPlaces(str);
    std::cout << "int\t: ";
    outputDoubletoInt(d);
    std::cout << "float\t: ";
    outputDoubletoFloat(d, dp);
    std::cout << std::endl;
    std::cout << "double\t: " << d << std::endl;
}

/**
 * @brief A float is input as a string. Which is then converted to other data types.
 * 
 * This function converts the input string to a float value using the convertFloat
 * function and then displays the converted value as a char, int, float, and double.
 * The number of decimal places in the input string is determined using the
 * numberDecimalPlaces function and is used to set the precision of the float output.
 * 
 * @param str A float that is input as a string.
 */
void    ScalarConverter::displayTypeFloat(const char *str)
{
    float   f;
    int     dp; 

    f = convertFloat(str);
    dp = numberDecimalPlaces(str);
    
    std::cout << "char\t: ";
    outputFloattoChar(f);
    std::cout << "int\t: ";
    outputFloattoInt(f);
    std::cout << std::fixed << std::setprecision(dp); 
    std::cout << "float\t: " << str << std::endl;
    std::cout << "double\t: ";
    outputFloattoDouble(f, dp);
    std::cout << std::endl;
}

/**
 * @brief Displays the character, its integer, float, and double representations.
 *
 * This function takes a string, converts it to a character, and displays
 * the character along with its corresponding integer, float, and double
 * representations. If the input string is empty, it assigns a space character (' ').
 *
 * @param str The input string to be converted and displayed.
 */
void    ScalarConverter::displayTypeChar(const char *str)
{
    char    c;
    
    if (isEmpty(str))
        c = ' ';
    else 
        c = convertChar(str);
    std::cout << "char\t: '" << c << "\'" << std::endl;
    std::cout << "int\t: " << static_cast<int>(c) << std::endl;
    std::cout << std::fixed << std::setprecision(1); 
    std::cout << "float\t: " << static_cast<float>(c) << 'f' << std::endl;
    std::cout << "double\t: " << static_cast<double>(c) << std::endl; 
}


/**
 * @brief Outputs the integer as a double with one decimal precision.
 *
 * This function takes an integer, converts it to a double, and outputs it 
 * with a fixed-point notation and one decimal place of precision.
 *
 * @param n The integer to be converted and output as a double.
 */
void  ScalarConverter::outputInttoDouble(int n)
{
    std::cout << std::fixed << std::setprecision(1);
    std::cout << static_cast<double>(n);
}

/**
 * @brief Converts a double to an integer and outputs it.
 *
 * This function takes a double, converts it to an integer, and outputs it.
 * If the double value is outside the range of representable integers, it throws
 * an `ImpossibleException` and catches it, outputting the exception's message.
 *
 * @param d The double to be converted and output as an integer.
 */
void    ScalarConverter::outputDoubletoInt(double d)
{
    if (d < INT_MIN || d > INT_MAX)
    {
        try
        {
            throw ScalarConverter::ImpossibleException();
        }
        catch (const ImpossibleException &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    else
    {   
        std::cout << static_cast<int>(d) << std::endl;
    }
}


/**
 * @brief Converts a float to an integer and outputs it.
 *
 * This function takes a float, converts it to an integer, and outputs it.
 * If the float value is outside the range of representable integers, it throws
 * an `ImpossibleException` and catches it, outputting the exception's message.
 *
 * @param f The float to be converted and output as an integer.
 */
void    ScalarConverter::outputFloattoInt(float f)
{
    if (f < INT_MIN || f > INT_MAX)
    {
        try
        {
            throw ScalarConverter::ImpossibleException();
        }
        catch (const ImpossibleException &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    else
    {
        std::cout << static_cast<int>(f) << std::endl;
    }    
}


/**
 * @brief Converts a double to a float and outputs it with specified decimal precision.
 *
 * This function takes a double, converts it to a float, and outputs it with a fixed-point notation 
 * and specified number of decimal places. If the double value is outside the range of representable 
 * floats, it throws an `ImpossibleException` and catches it, outputting the exception's message.
 *
 * @param d The double to be converted and output as a float.
 * @param dp The number of decimal places for the output.
 */
void    ScalarConverter::outputDoubletoFloat(double d, int dp)
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

/**
 * @brief Converts a float to a double and outputs it with specified decimal precision.
 *
 * This function takes a float, converts it to a double, and outputs it with a fixed-point notation 
 * and specified number of decimal places. If the float value is outside the range of representable 
 * doubles, it throws an `ImpossibleException` and catches it, outputting the exception's message.
 *
 * @param f The float to be converted and output as a double.
 * @param dp The number of decimal places for the output.
 */
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
        std::cout << static_cast<double>(f);
    } 
}


/**
 * @brief Converts an integer to a float and outputs it with one decimal precision.
 *
 * This function takes an integer, converts it to a float, and outputs it with a fixed-point notation 
 * and one decimal place of precision. If the integer value is outside the range of representable 
 * floats, it throws an `ImpossibleException` and catches it, outputting the exception's message.
 *
 * @param n The integer to be converted and output as a float.
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

/**
 * @brief Converts an integer to a character and outputs it.
 *
 * This function takes an integer, converts it to a character, and outputs it. If the integer value
 * corresponds to a non-displayable ASCII character (0-31 or 127), it throws a `NonDisplayableException` 
 * and catches it, outputting the exception's message. If the integer value is outside the range of 
 * representable ASCII characters (less than 0 or greater than 127), it throws an `ImpossibleException` 
 * and catches it, outputting the exception's message.
 *
 * @param n The integer to be converted and output as a character.
 */
void    ScalarConverter::outputInttoChar(int n)
{
    if ((n >= 0 && n < 32) || n == 127)
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
    else if (n < 0 || n > 127)
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
        std::cout << "\'" << static_cast<char>(n) << "\'" << std::endl;
}


/**
 * @brief Converts a double to a character and outputs it.
 *
 * This function takes a double, converts it to a character, and outputs it. If the double value
 * corresponds to a non-displayable ASCII character (0-31 or 127), it throws a `NonDisplayableException` 
 * and catches it, outputting the exception's message. If the double value is outside the range of 
 * representable ASCII characters (less than 0 or greater than 127), it throws an `ImpossibleException` 
 * and catches it, outputting the exception's message.
 *
 * @param d The double to be converted and output as a character.
 */
void    ScalarConverter::outputDoubletoChar(double d)
{
    if ((d >= 0 && d < 32) || d == 127)
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
    else if (d < 0 || d > 127)
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
        std::cout << "\'" << static_cast<char>(d) << "\'" << std::endl;
}


/**
 * @brief Converts a float to a character and outputs it.
 *
 * This function takes a float, converts it to a character, and outputs it. If the float value
 * corresponds to a non-displayable ASCII character (0-31 or 127), it throws a `NonDisplayableException` 
 * and catches it, outputting the exception's message. If the float value is outside the range of 
 * representable ASCII characters (less than 0 or greater than 127), it throws an `ImpossibleException` 
 * and catches it, outputting the exception's message.
 *
 * @param f The float to be converted and output as a character.
 */
void    ScalarConverter::outputFloattoChar(float f)
{
    if ((f >= 0 && f < 32) || f == 127)
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
    else if (f < 0 || f > 127)
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
        std::cout << "\'" << static_cast<char>(f) << "\'" << std::endl;
}

/**
 * @brief Converts a string to a double.
 *
 * This function takes a string and converts it to a double using std::stod. If the conversion
 * fails due to the string being out of the range of representable doubles, it catches the
 * std::out_of_range exception and outputs the exception's message to std::cerr.
 *
 * @param str The string to be converted to a double.
 * @return The double value of the input string, or 0.0 if the conversion fails.
 */
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

/**
 * @brief Converts a string to a float.
 *
 * This function takes a string and converts it to a float using std::atof. If the conversion
 * fails due to the string being out of the range of representable floats, it catches the
 * std::out_of_range exception and outputs the exception's message to std::cerr.
 *
 * @param str The string to be converted to a float.
 * @return The float value of the input string, or 0.0f if the conversion fails.
 */
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

/**
 * @brief Converts a string to a character.
 *
 * This function takes a string and converts it to a character by taking the first character
 * after trimming leading and trailing whitespaces. If the string is empty after trimming, it
 * returns a space character ' '. If the string is empty before trimming, it throws an
 * std::out_of_range exception.
 *
 * @param str The string to be converted to a character.
 * @return The character value of the first non-whitespace character in the input string, or
 *         a space character ' ' if the string is empty after trimming.
 */
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


/**
 * @brief Detects the type of a string.
 *
 * This function takes a string and determines its type, which can be one of:
 * - CHAR: if the string represents a single character.
 * - INTEGER: if the string represents an integer.
 * - DOUBLE: if the string represents a double.
 * - FLOAT: if the string represents a float.
 * - MISCELLANEOUS: if the string represents special values like "nan", "+inf", etc.
 * - NONE: if the string is empty or does not fit any other type.
 *
 * @param str The string to be analyzed.
 * @return The detected type of the string.
 */
TYPE    ScalarConverter::detectType(std::string str)
{    
    const char *str2 = str.c_str();
    if (isEmpty(str2) && str.length() > 0)
        return (CHAR);
    if (!str.length())
    {   
        std::cout << "Empty Input" << std::endl;
        return (NONE);
    }
    if (str == "nan" || str == "-inf" || str == "nanf" ||
             str == "+inf" || str == "-inff" || str == "+inff")
        return (MISCELLANEOUS);
    if (str2[0] == '-')
        str2 ++;
    if (consecutiveDigits(str2))
        return (INTEGER);
    else if (consecutiveDigitsAndPoint(str2))
        return (DOUBLE);
    else if (consecutiveDigitsPointAndF(str2))
        return (FLOAT);
    else if (isChar(str2))
        return (CHAR);
    std::cout << "Invalid Type" << std::endl;
    return (NONE); 
}

/**
 * @brief Checks if a string represents a single character.
 *
 * This function checks if the input string has a length of 1, indicating that it represents
 * a single character. If the character is non-displayable, it outputs a message to std::cout.
 *
 * @param str The string to be checked.
 * @return True if the string represents a single character, false otherwise.
 */
bool    ScalarConverter::isChar(const char *str)
{
    if (ft_strlen(str) != 1)
        return (false);
    if (!displayable(str[0]))
        std::cout << "The character entered cannot be displayed." << std::endl;
    return (true);
}

/**
 * @brief Returns a message indicating a non-displayable character.
 * This function returns a constant string message indicating that the character is non-displayable.
 *
 * @return A constant string message indicating a non-displayable character.
 */
const char *ScalarConverter::NonDisplayableException::what() const throw()
{
    return ("Non displayable");
}

/**
 * @brief Returns a message indicating an impossible conversion.
 * This function returns a constant string message indicating that the conversion is impossible.
 *
 * @return A constant string message indicating an impossible conversion.
 */
const char  *ScalarConverter::ImpossibleException::what() const throw()
{
    return ("Impossible");
}
