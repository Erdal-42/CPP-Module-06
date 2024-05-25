/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekocak@student.42.org.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:50    by ekocak            #+#    #+#             */
/*   Updated: 2023/08/17 10:50    by ekocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

/**
 * @brief Default constructor for Base class.
 *
 * This constructor does not perform any specific initialization.
 */
Base::Base()
{}

/**
 * @brief Destructor for Base class.
 *
 * This destructor does not perform any specific cleanup since Base does not
 * manage any resources that require explicit deallocation.
 */
Base::~Base()
{}

/**
 * @brief Generate a new instance of a derived class of Base.
 *
 * This function generates a new instance of a class derived from Base (A, B, or C)
 * based on a randomly generated number. It also prints a message indicating the
 * class that was generated.
 *
 * @return A pointer to the newly generated instance.
 */
Base    *Base::generate(void)
{
    int         c;
    Base        *instance;
    std::string str;   

    str = "Generated an instance of class ";
    instance = NULL;

    c = generateRandom();
    switch (c)
    {
        case 0:
            instance = new A();
            std::cout <<  str + "A." << std::endl;
            break ;
        case 1:
            instance = new B();
            std::cout <<  str + "B." << std::endl;
            break ;
        case 2:
            instance = new C();
            std::cout <<  str + "C." << std::endl;
            break ;
    }
    return (instance);
}


/* 
 * We use the dynamic_cast function in the function below.
 * Unlike static_cast, which performs compile-time type checking, 
 * dynamic_cast performs runtime type checking. It checks whether 
 * the conversion is valid based on the actual type of the object 
 * pointed to by the base pointer/reference.
 * 
 * dynamic_cast<DerivedType*>(basePointer);
 * dynamic_cast<DerivedType&>(baseReference);
 */
void    Base::identify(Base *p)
{
    std::string str = "Pointer points to an instance of derived class ";
    if (dynamic_cast<A *>(p))
        std::cout << str + "A." << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << str + "B." << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << str + "C." << std::endl;
    else 
        std::cout << "This is an instance of a the parent class." << std::endl; 
}

/*
 * We cast the parameter reference p to references of each of the
 * derived classes in series at runtime. Whilst before this 
 * static_cast performed compile time type checking, dynamic_cast 
 * is used for performing runtime type checking. 
 * In any of the try-casting cases if no exception is thrown, then we 
 * announce that we have identified the type of the instance and
 * return out of the function.
 * If the conversion is not valid (e.g., if the object is not 
 * actually an instance of the derived class), dynamic_cast 
 * returns a null pointer (for pointer conversion) or throws a 
 * std::bad_cast exception (for reference conversion). 
 */ 
void Base::identify(Base &p)
{
    std::string str = "Reference references an instance of derived class ";
    Base base;

    try 
    {
        base = dynamic_cast<A &>(p);
        std::cout << str + "A." << std::endl;
        return;
    } 
    catch (const std::exception &e) {}
    try 
    {
        base = dynamic_cast<B &>(p);
        std::cout << str + "B." << std::endl;
        return;
    } 
    catch (const std::exception &e) {}
    try 
    {
        base = dynamic_cast<C &>(p);
        std::cout << str + "C." << std::endl;
        return;
    } 
    catch (const std::exception &e) {}
    std::cout << "This is an instance of the parent class." << std::endl;
}



A::A()
{}
        
A::~A()
{}

B::B()
{}
        
B::~B()
{}

C::C()
{}
        
C::~C()
{}

/**
 * @brief Generate a random number.
 *
 * This function generates a random number using the current time as a seed.
 * It uses the microseconds part of the current time to generate a random number
 * between 0 and 2 (inclusive).
 *
 * @return A random integer between 0 and 2.
 */
int generateRandom()
{
    struct timeval  tv;

    gettimeofday(&tv, NULL);
    return  (tv.tv_usec % 3);    
}