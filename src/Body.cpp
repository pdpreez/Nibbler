/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Body.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 11:19:09 by ppreez            #+#    #+#             */
/*   Updated: 2019/08/02 09:31:35 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Body.hpp"

Body::Body()
{}

Body::Body(unsigned int x, unsigned int y, struct s_color color)
{
    m_pos_x = x;
    m_pos_y = y;
    m_color.r = color.r / 2;
    m_color.g = color.g / 2;
    m_color.b = color.b / 2;
    m_color.a = color.a;
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
