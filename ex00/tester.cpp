/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekocak@student.42.org.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 17:25:55 by ekocak            #+#    #+#             */
/*   Updated: 2023/08/13 10:25:55 by ekocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "tester.hpp"

/**
 * @brief Helper function to test conversion of a string.
 *
 * This function takes a string, prints it, and then calls the `ScalarConverter::convert` function
 * with the string to test its conversion.
 *
 * @param str The string to be tested.
 */
void    test(std::string str)
{
    std::cout << "#str = \"" + str + "\"" << std::endl;
    ScalarConverter::convert(&str[0]);
    std::cout << std::endl;    
}

/**
 * @brief Test function for ScalarConverter class.
 *
 * This function tests various conversion scenarios using the `convert` function of the
 * ScalarConverter class. It tests conversion of characters, integers, floats, doubles, and
 * special values like NaN and infinity.
 */
void tester(void)
{
    std::string str;


    std::cout << "\n=======CHAR=======" << std::endl;
    str = "";
    test(str);

    str = " ";
    test(str);
    
    str = 'A';
    test(str);

    str = ".";
    test(str);

    str = "a";
    test(str);


    std::cout << "\n=======INTEGER=======" << std::endl;
    str = "0";
    test(str);

    str = "-42";
    test(str);

    str = "42";
    test(str);

    str = "11";
    test(str);

    str = "82";
    test(str);

    str = "333";
    test(str);

    str = "123456789";
    test(str);

    str = "2147483647";
    test(str);  

    str = "2147483648";
    test(str);

    str = "-2147483648";
    test(str);

    str = "-2147483649";
    test(str);


    std::cout << "\n=======FLOAT=======" << std::endl;
    str = "0.0f";
    test(str);

    str = "0.11f";
    test(str);

        str = "32.0f";
    test(str);

    str = "31.9f";
    test(str);

    str = "126.126f";
    test(str);

    str = "127.0f";
    test(str);

    str = "128.111f";
    test(str);

    str = "-10.8f";
    test(str);

    str = "82.f";
    test(str);

    str = "3.33f";
    test(str);

    str = "12345.6789f";
    test(str);



    std::cout << "\n=======DOUBLE=======" << std::endl;
    str = "0.0";
    test(str);

    str = "32.3";
    test(str);

    str = "31.9";
    test(str);

    str = "126.126";
    test(str);

    str = "127.0";
    test(str);

    str = "128.111";
    test(str);
    
    str = "6.11";
    test(str);
    
    str = "22.8";
    test(str);
    
    str = "3.33";
    test(str);
    
    str = "12345.6789";
    test(str);

    str = "2147483645.5";
    test(str);

    str = "2147483649.5";
    test(str);

    str = "-2147483645.5";
    test(str);

    str = "-2147483649.5";
    test(str);



    std::cout << "\n=======MISCELLANEOUS=======" << std::endl;
    
    str = "nan";
    test(str);
    
    str = "nanf";
    test(str);
    
    str = "-inf";
    test(str);
    
    str = "+inf";
    test(str);
    
    str = "-inff";
    test(str);
    
    str = "+inff";
    test(str);
    
    str = "-in.ff";
    test(str);
}