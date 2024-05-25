/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekocak@student.42.org.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 07:36    by ekocak            #+#    #+#             */
/*   Updated: 2023/08/15 07:36    by ekocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <stdint.h>


struct Data
{
    int         _i_data;
    std::string _s_data;
};

class Serializer
{
    private:
        Serializer();
        ~Serializer();
        Serializer(Serializer const &);
        Serializer &operator=(Serializer const &);
    public:
        static  uintptr_t    serialize(Data *);      
        static  Data         *deserialize(uintptr_t); 
};