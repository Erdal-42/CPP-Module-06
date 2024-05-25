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


bool    consecutiveDigits(const char *str);
bool    consecutiveDigitsAndPoint(const char *str);
bool    consecutiveDigitsPointAndF(const char *str);
bool    isEmpty(const char *str);
int     ft_strlen(const char *str);
bool    displayable(char);
int     ft_strcmp(char *, char *);
int     numberDecimalPlaces(const char *);

std::string trim(const std::string &);
