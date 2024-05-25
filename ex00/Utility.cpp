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

/**
 * Removes leading and trailing whitespace characters (spaces and tabs) 
 * from the input string.
 *
 * @param str The input string to be trimmed.
 * @return A new string with leading and trailing whitespace removed.
 */
std::string trim(const std::string& str)
{
    size_t firstNonSpace = str.find_first_not_of(" \t");
    if (firstNonSpace == std::string::npos)
        return "";
    size_t lastNonSpace = str.find_last_not_of(" \t");
    return str.substr(firstNonSpace, lastNonSpace - firstNonSpace + 1);
}

/**
 * Compare two C-style strings (null-terminated character arrays).
 *
 * This function compares the two input strings, `s1` and `s2`, and 
 * returns an integer value representing their relationship:
 * - If `s1` is lexicographically less than `s2`, a negative value 
 * is returned.
 * - If `s1` is lexicographically greater than `s2`, a positive 
 * value is returned.
 * - If `s1` is equal to `s2`, zero is returned.
 *
 * @param s1 Pointer to the first C-style string to be compared.
 * @param s2 Pointer to the second C-style string to be compared.
 * @return An integer value indicating the comparison result.
 */
int     ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i] && s2[i])
        ++ i;
    return (s1[i] - s2[i]);
}

int     ft_strlen(const char *str)
{
    int i;

    if (!str)
        return (0);    
    i = 0;
    while (str[i])
        i ++;
    return (i); 
}


/**
 * Check if a string contains consecutive digits 
 * separated by spaces.
 *
 * This function examines the input string `str` and 
 * determines if it contains consecutive digits (0-9)
 * separated by spaces. It returns true if such 
 * consecutive digits are found; otherwise, it returns 
 * false.
 *
 * @param str A pointer to a C-style string to be 
 * checked.
 * @return True if the string contains consecutive 
 * digits separated by spaces, false otherwise.
 * Also returns false if the input string is empty or 
 * if it has fewer than 2 characters.
 */
bool consecutiveDigits2(char *str)
{
    if (!str || isEmpty(str))
        return false;
    
    if (ft_strlen(str) < 2)
    { 
        if (isdigit(str[0]))
            return true;
        return false;
    }

    int i = 0;
    while (str[i] && str[i+1])
    {
        if ((!isdigit(str[i]) && str[i] != ' ') || (!isdigit(str[i+1]) && str[i+1] != ' '))
            return false;
        else if (!isdigit(str[i]) && isdigit(str[i+1]))
            return false;
        ++i;
    }
    
    return true;
}

/**
 * Check if a string contains consecutive digits separated by 
 * spaces.
 *
 * This function examines the input string `str` and determines 
 * if it contains consecutive digits (0-9)
 * separated by spaces. It returns true if such consecutive 
 * digits are found; otherwise, it returns false.
 * A valid consecutive digits sequence must begin with a digit 
 * and be separated by spaces.
 *
 * @param str A pointer to a C-style string to be checked.
 * @return True if the string contains consecutive digits 
 * separated by spaces, false otherwise.
 *         Also returns false if the input string contains 
 * characters other than digits, spaces, or tabs.
 */
bool consecutiveDigits(const char *str)
{
    int digit_flag = 0; 
    int space_flag = 0;
    int i = 0;

    while (str[i] != '\0')
    {
        if (!isdigit(str[i]) && str[i] != ' ' && str[i] != '\t')
        {
            return false;
        }
        else if (isdigit(str[i]) && !digit_flag)
        {
            digit_flag = 1;
        }
        else if ((str[i] == ' ') && digit_flag && !space_flag)
        {
            space_flag = 1;
        }
        else if (space_flag && isdigit(str[i]))
        {
            return false;
        }
        ++i;
    }
    return digit_flag;
}


/**
 * Check if a string contains consecutive digits and, at most, 
 * one decimal point, separated by spaces.
 *
 * This function examines the input string `str` and determines 
 * if it contains consecutive digits (0-9) and, at most, one 
 * decimal point (.) separated by spaces. It returns true if 
 * such a sequence is found; otherwise, it returns false.
 * A valid sequence may start with a digit and should consist 
 * of digits, at most one decimal point, and spaces.
 *
 * @param str A pointer to a C-style string to be checked.
 * @return True if the string contains consecutive digits and, 
 * at most, one decimal point separated by spaces, false 
 * otherwise.
 * Also returns false if the input string contains characters 
 * other than digits, spaces, or a single decimal point.
 */
bool    consecutiveDigitsAndPoint(const char *str)
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

/**
 * Check if a string contains consecutive digits, at most one decimal point, and ends with 'f'.
 *
 * This function examines the input string `str` and determines if it contains consecutive digits (0-9),
 * at most one decimal point (.), and ends with the character 'f'. It returns true if such a sequence is found;
 * otherwise, it returns false. A valid sequence may start with a digit and should consist of digits, at most one decimal point,
 * and spaces. The 'f' character must appear at the end of the string.
 *
 * @param str A pointer to a C-style string to be checked.
 * @return True if the string contains consecutive digits, at most one decimal point, and ends with 'f', false otherwise.
 *         Also returns false if the input string contains characters other than digits, spaces, '.', or 'f' or if the 'f' character
 *         does not appear at the end of the string.
 */
bool consecutiveDigitsPointAndF(const char *str)
{   
    int digit_flag = 0; 
    int space_flag = 0; 
    int dot_flag = 0;   
    int f_flag = 0;    
    int i = 0;

    while (str[i])
    {
        if (str[i] == '.')
        {
            if (dot_flag || f_flag)
                return false;
            dot_flag = 1;
            digit_flag = 1;
        }
        else if (str[i] == 'f')
        {
            if (f_flag)
                return false;
            f_flag = 1;
        }
        else if (!isdigit(str[i]) && !digit_flag)
        {
            break;
        }
        else if (isdigit(str[i]) && !digit_flag)
        {
            digit_flag = 1;
        }
        else if ((str[i] == ' ') && digit_flag && !space_flag)
        {
            space_flag = 1;
        }
        else if ((space_flag && isdigit(str[i])) || (f_flag && isdigit(str[i])))
        {
            return false;
        }
        ++i;
    }
    return (digit_flag && f_flag);
}


/**
 * Check if a C-style string consists of only whitespace 
 * characters.
 *
 * This function examines the input string `str` and 
 * determines if it contains only whitespace characters,
 * such as spaces (' '). It returns true if the string 
 * consists solely of whitespace characters; otherwise, 
 * it returns false.
 *
 * @param str A pointer to a C-style string to be checked.
 * @return True if the string consists only of whitespace 
 * characters, false otherwise.
 */
bool    isEmpty(const char *str)
{
    while (*str)
    {
        if (*str != ' ')
            return (false);
        ++ str;
    }
    return (true);
}

/**
 * Check if a character is displayable in the ASCII 
 * character set.
 *
 * This function examines the input character `c` 
 * and determines if it falls within the range of 
 * ASCII characters (32-126)
 * that are typically displayable. It returns true 
 * if the character is displayable; otherwise, it 
 * returns false.
 *
 * @param c The character to be checked.
 * @return True if the character is displayable in 
 * the ASCII character set (32-126), false otherwise.
 */
bool    displayable(char c)
{
    if (c >= 32 && c <= 126)
        return (true);
    return (false);
}

/**
 * Calculate the number of decimal places in a C-style string representing a floating-point number.
 *
 * This function examines the input string `str` and counts the number of decimal places in the string,
 * assuming it represents a floating-point number. It returns the count of decimal places found in the string.
 * A decimal point ('.') indicates the presence of a decimal place, and the function counts the digits following it
 * until a non-digit character, typically 'f', is encountered.
 *
 * @param str A pointer to a C-style string representing a floating-point number.
 * @return The number of decimal places in the string. Returns 0 if the input string is empty or if it contains no decimal places.
 */
int numberDecimalPlaces(const char *str)
{
    int i = 0;
    
     if (!str)
        return 0;
    while (str[i])
    {
        if (str[i++] == '.')
            break;
    }
    int j = 0; 
    while (str[i])
    {
        if (str[i++] != 'f')
            j++;
    }
    return j;
}