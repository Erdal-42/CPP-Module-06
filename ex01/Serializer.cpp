/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekocak@student.42.org.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 07:36    by ekocak            #+#    #+#             */
/*   Updated: 2023/08/15 07:36    by ekocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/**
 * @brief Default constructor for Serializer class.
 *
 * This constructor does not perform any specific initialization.
 */
Serializer::Serializer()
{}

/**
 * @brief Destructor for Serializer class.
 *
 * This destructor does not perform any specific cleanup since Serializer does not
 * manage any resources that require explicit deallocation.
 */
Serializer::~Serializer()
{}

/**
 * @brief Copy constructor for Serializer class.
 *
 * This constructor performs a shallow copy of the Serializer object.
 *
 * @param other The Serializer object to be copied.
 */
Serializer::Serializer(Serializer const &other)
{
    *this = other;
}

/**
 * @brief Assignment operator for Serializer class.
 *
 * This operator performs a shallow copy of the Serializer object.
 *
 * @param other The Serializer object to be copied.
 * @return A reference to the modified Serializer object.
 */
Serializer &Serializer::operator=(Serializer const &other)
{
    if (this != &other)
        *this = other;
    return (*this);
}

/**
 * @brief Serialize a pointer to uintptr_t.
 *
 * This function converts a pointer to a uintptr_t, which can be used for serialization.
 *
 * @param ptr The pointer to be serialized.
 * @return The serialized value as a uintptr_t.
 */
uintptr_t   Serializer::serialize(Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

/**
 * @brief Deserialize a uintptr_t to a pointer.
 *
 * This function converts a serialized value (uintptr_t) back to a pointer.
 *
 * @param raw The serialized value as a uintptr_t.
 * @return The deserialized pointer.
 */
Data         *Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}
