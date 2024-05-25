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

/**
 * @brief Entry point of the program.
 *
 * This function serves as the entry point for the program. If the program is run without any
 * command line arguments, it calls the `tester` function. If the program is run with one
 * command line argument, it calls the `ScalarConverter::convert` function with the argument
 * provided.
 *
 * @param argc The number of command line arguments.
 * @param argv An array of C-style strings representing the command line arguments.
 * @return 0 on successful execution.
 */
int main(int argc, char **argv)
{
    if (argc == 1)
    {
        tester();
    }
    if (argc == 2)
    {
        ScalarConverter::convert((std::string)argv[1]);
    } 

    return 0;
}
