/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekocak@student.42.org.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 17:25:55 by ekocak            #+#    #+#             */
/*   Updated: 2023/08/13 10:25:55 by ekocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "tester.hpp"


int main(int argc, char **argv)
{
    ScalarConverter SC;

    if (argc == 1)
    {
        tester();
    }
    if (argc == 2)
    {
        SC.displayType(argv[1]);
    } 
    return 0;
}
