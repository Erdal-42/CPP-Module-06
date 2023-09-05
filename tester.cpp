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

void    test(ScalarConverter *sc, std::string str)
{
    std::cout << "#str = \"" + str + "\"" << std::endl;
    sc->displayType(&str[0]);
    std::cout << std::endl;    
}

void tester(void)
{
    ScalarConverter SC;
    std::string str;

//CHAR
    std::cout << "\n=======CHAR=======" << std::endl;
    str = "";
    test(&SC, str);

    str = " ";
    test(&SC, str);
    
    str = "  A";
    test(&SC, str);

    str = ".  ";
    test(&SC, str);

    str = "  a  ";
    test(&SC, str);

    str  = "  AA  ";
    test(&SC, str);

//INTEGER
    std::cout << "\n=======INTEGER=======" << std::endl;
    str = "0";
    test(&SC, str);

    str = "  11";
    test(&SC, str);

    str = "82  ";
    test(&SC, str);

    str = "  333  ";
    test(&SC, str);

    str = "  123456789  ";
    test(&SC, str);

    str = "  1234 5678  ";
    test(&SC, str);    

//FLOAT
    std::cout << "\n=======FLOAT=======" << std::endl;
    str = "0.f";
    test(&SC, str);

    str = "  .11f";
    test(&SC, str);

    str = "82.f  ";
    test(&SC, str);

    str = "  3.33f  ";
    test(&SC, str);

    str = "  12345.6789f  ";
    test(&SC, str);

    str = "  1234 .5678f  ";
    test(&SC, str);

//DOUBLE
    std::cout << "\n=======DOUBLE=======" << std::endl;
    str = "0.";
    test(&SC, str);
    
    str = "  .11";
    test(&SC, str);
    
    str = "22.  ";
    test(&SC, str);
    
    str = "  3.33  ";
    test(&SC, str);
    
    str = "  12345.6789  ";
    test(&SC, str);
    
    str = "  1234 .5678  ";
    test(&SC, str);

//MISCELLANEOUS
    std::cout << "\n=======MISCELLANEOUS=======" << std::endl;
    str = "nan";
    test(&SC, str);
    
    str = "  nan";
    test(&SC, str);
    
    str = "nan  ";
    test(&SC, str);
    
    str = "  nanf  ";
    test(&SC, str);
    
    str = "  -inf  ";
    test(&SC, str);
    
    str = "  +inf  ";
    test(&SC, str);
    
    str = "  -inff  ";
    test(&SC, str);
    
    str = "  +inff  ";
    test(&SC, str);
    
    str = "  -in.ff  ";
    test(&SC, str);  
}