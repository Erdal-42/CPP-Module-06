/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekocak@student.42.org.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 17:25:55 by ekocak            #+#    #+#             */
/*   Updated: 2023/08/13 10:25:55 by ekocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <unistd.h>
#include <iostream>


bool    consecutiveDigits(char *str);
bool    consecutiveDigitsAndPoint(char *str);
bool    consecutiveDigitsPointAndF(char *str);
bool    isEmpty(char *str);
int     ft_strlen(char *str);
bool    displayable(char);
int     ft_strcmp(char *, char *);
int     numberDecimalPlaces(char *);

std::string trim(const std::string &);
