/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Obstacle.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 09:53:41 by ppreez            #+#    #+#             */
/*   Updated: 2019/08/09 10:05:42 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Obstacle.hpp"

Obstacle::Obstacle()
{

}

Obstacle::Obstacle(int x, int y)
{
    m_pos_x = x;
    m_pos_y = y;
    m_color.r = 75;
    m_color.g = 75;
    m_color.b = 75;
    m_color.a = 255;
}

Obstacle::Obstacle(Obstacle const &rhs)
{
    *this = rhs;
}

Obstacle &Obstacle::operator=(Obstacle const &rhs)
{
    if (this != &rhs)
    {
        *this = rhs;
    }
    return *this;
}

Obstacle::~Obstacle()
{

}

