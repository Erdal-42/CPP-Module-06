/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekocak@student.42.org.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:50    by ekocak            #+#    #+#             */
/*   Updated: 2023/08/17 10:50    by ekocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
/*
    * We define a pointer instance of the 
    * base class inorder to call 
    * the member functions.
    *
    * We define a pointer instance tempPtr of
    * the base class inorder to generate an
    * instance of one of 3 derived classes at 
    * random. This will be used for the first test.
    * 
    * We define a referance to an instance of derived 
    * class B, tempRef. This will be used for the 
    * second test.
    *
    * We generate an instance of one of three derived 
    * classes at random and let our variable tempPtr point 
    * at it. 
    *
    * We identify which of the three classes the newly 
    * generated instance belongs to using the 
    * identify(Base *) method.
    *
    * Next we test to see if the identify(Base &) function
    * can deduce the derived class of reference temp2.
    */ 

int main()
{
    for (int i = 0; i < 10; i ++)
    {
        Base    *base = new Base();
        Base    *tempPtr = base->generate();
        Base    &tempRef = *tempPtr;

        base->identify(tempPtr);
        base->identify(tempRef);
        std::cout << std::endl;

        delete base;
        delete tempPtr;
    }
}
