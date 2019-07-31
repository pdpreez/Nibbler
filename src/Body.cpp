/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Body.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 11:19:09 by ppreez            #+#    #+#             */
/*   Updated: 2019/07/31 12:43:40 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Body.hpp"

Body::Body()
{}

Body::Body(unsigned int x, unsigned int y)
{
    m_pos_x = x;
    m_pos_y = y;
}

Body::Body(Body const &rhs)
{
    *this = rhs;
}

Body &Body::operator=(Body const &rhs)
{
    if (this != &rhs)
    {
        *this = rhs;
    }
    return *this;
}
