/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utility.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekocak@student.42.org.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 17:25:55 by ekocak            #+#    #+#             */
/*   Updated: 2023/08/13 10:25:55 by ekocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utility.hpp"


std::string trim(const std::string& str)
{
    size_t firstNonSpace = str.find_first_not_of(" \t");
    if (firstNonSpace == std::string::npos)
        return "";
    size_t lastNonSpace = str.find_last_not_of(" \t");
    return str.substr(firstNonSpace, lastNonSpace - firstNonSpace + 1);
}


int     ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i] && s2[i])
        ++ i;
    return (s1[i] - s2[i]);
}

int     ft_strlen(char *str)
{
    int i;

    if (!str)
        return (0);    
    i = 0;
    while (str[i])
        i ++;
    return (i); 
}

/*
 * consecutiveDigits will check for a non-digit
 * between two digits. If the digits are not
 * consecutive, then it will return false,
 * True otherwise. 
 * The initial space and sign characters of the
 * passed parameters will have already been skipped.  
 */

bool    consecutiveDigits2(char *str)
{
    int i;

    if (!str || isEmpty(str))
        return (false);
    if (ft_strlen(str) < 2)
    { 
        if(isdigit(str[0]))
            return (true);
        return (false);
    }
    i = 0;
    while (str[i] && str[i+1])
    {
        if ((!isdigit(str[i]) && str[i] != ' ') || (!isdigit(str[i+1]) && str[i+1] != ' '))
            return (false);
        else if (!isdigit(str[i]) && isdigit(str[i+1]))
            return (false);
        ++ i;
    }
    return (true);
}


bool    consecutiveDigits(char *str)
{   
    int digit_flag = 0; //raised if a digit is encountered after a space or positive, negative sign
    int space_flag = 0; //raised if a space is encountered after a space
    int i = 0;

    while (str[i] != '\0')
    {
        if (!isdigit(str[i]) && str[i] != ' ' && str[i] != '\t')
        {

            return (false);
        }
        else if (isdigit(str[i]) && !digit_flag)
            digit_flag = 1;
        else if ((str[i] == ' ') && digit_flag && !space_flag)
            space_flag = 1;
        else if ((space_flag && isdigit(str[i])))
            return (false);
        ++ i;
    }
    return (digit_flag);
}

bool    consecutiveDigitsAndPoint(char *str)
{
    int i;
    int point_flag;
    int digit_flag;

    if (!str || isEmpty(str))
        return (false);
    i = 0;
    point_flag = 0;
    digit_flag = 0;
    while (str[i] && str[i+1])
    {
        if (!isdigit(str[i]) && str[i] != ' ' && str[i] != '.')
            return (false);
        else if (!isdigit(str[i+1]) && str[i+1] != ' ' && str[i+1] != '.')
            return (false);
        else if ((!isdigit(str[i]) && str[i] != '.') && (isdigit(str[i+1]) || str[i+1] == '.'))
            return (false);
        if (str[i] == '.' || str[i+1] == '.')
        {
            if (point_flag)
                return (false);
            if (str[i] == '.')
                point_flag = 1;
        }
        if (!digit_flag && (isdigit(str[i]) || isdigit(str[i+1])))
            digit_flag = 1;
        ++ i;
    }
    return (digit_flag);
}

bool    consecutiveDigitsPointAndF(char *str)
{   
    int digit_flag = 0; //raised if a digit is encountered after a space or positive, negative sign
    int space_flag = 0; //raised if a space is encountered after a space
    int dot_flag = 0;
    int f_flag = 0;
    int i = 0;

    while (str[i])
    {
        if (str[i] == '.')
        {
            if (dot_flag || f_flag)
                return (false);
            dot_flag = 1;
            digit_flag = 1;
        }
        else if (str[i] == 'f')
        {
            if (f_flag)
                return (false);
            f_flag = 1;
        }
        else if (!isdigit(str[i]) && !digit_flag)
            break ;
        else if (isdigit(str[i]) && !digit_flag)
            digit_flag = 1;
        else if ((str[i] == ' ') && digit_flag && !space_flag)
            space_flag = 1;
        else if ((space_flag && isdigit(str[i])) || (f_flag && isdigit(str[i])))
            return (false);
        ++ i;
    }
    return (digit_flag && f_flag);
}


bool    isEmpty(char *str)
{
    while (*str)
    {
        if (*str != ' ')
            return (false);
        ++ str;
    }
    return (true);
}

bool    displayable(char c)
{
    if (c >= 32 && c <= 126)
        return (true);
    return (false);
}

int     numberDecimalPlaces(char *str)
{
    int i;
    int j;

    if (!str)
        return (0);
    i = 0;
    while (str[i])
    {
        if ((str[i ++]) == '.')
            break ;
    }
    j = 0;
    while (str[i])
    {
        if (str[i ++] != 'f')
            j ++;
    }
    return (j);
}