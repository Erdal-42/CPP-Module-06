/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekocak@student.42.org.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:50    by ekocak            #+#    #+#             */
/*   Updated: 2023/08/17 10:50    by ekocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <string>
#include <sys/time.h>

class A;
class B;
class C;

class Base
{
    public:
        Base();
        virtual ~Base();
        Base    *generate(void);
        void    identify(Base *);
        void    identify(Base &);
};

class A : public Base
{
    public:
        A();
        ~A();
};

class B : public Base
{
    public:
        B();
        ~B();
};

class C : public Base
{
    public:
        C();
        ~C();
};

int generateRandom();