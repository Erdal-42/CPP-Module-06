/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekocak@student.42.org.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 07:36    by ekocak            #+#    #+#             */
/*   Updated: 2023/08/15 07:36    by ekocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"


/**
 * @brief Main function for testing serialization and deserialization of a pointer.
 *
 * This function creates a new instance of the Data class, sets its member variables,
 * serializes the pointer to this instance using the Serializer class, deserializes the
 * serialized value, and prints the original and deserialized pointers along with their
 * contents to demonstrate that the data content has been successfully maintained.
 *
 * @return 0 on successful execution.
 */
int main()
{
    Data        *ptr = new Data;
    uintptr_t   ui;
     
    ptr->_i_data = 42;
    ptr->_s_data = "Kocaeli";
    std::cout << "The value at the memory data pointer points to\t\t: " << ptr->_i_data << ", " << ptr->_s_data << std::endl;
    std::cout << "The memory that pointer points to initially\t\t: " << ptr << std::endl;
    std::cout << std::endl; 
    std::cout << "We serialize the pointer value.." << std::endl;
    std::cout << std::endl;
    ui = Serializer::serialize(ptr);
    std::cout << "Serialized memory that pointer points to\t\t: " << ui << std::endl;
    std::cout << std::endl;
    std::cout << "We deserialize the serialized value.." << std::endl;
    std::cout << std::endl;
    std::cout << "The memory that pointer points to finally\t\t: " << Serializer::deserialize(ui) << std::endl;
    std::cout << "The value at the memory data pointer points to\t\t: " << ptr->_i_data << ", " << ptr->_s_data << std::endl;
    std::cout << std::endl;
    std::cout << "Data Content has been successfully maintained!!" << std::endl;
    delete ptr;
}