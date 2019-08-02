/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fruit.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:13:08 by ppreez            #+#    #+#             */
/*   Updated: 2019/08/02 09:38:49 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fruit.hpp"

Fruit::Fruit()
{

}

Fruit::Fruit(int width, int height)
:m_width(width), m_height(height)
{
    srand(time(NULL));
    reroll();
    m_color.r = 255;
    m_color.g = 0;
    m_color.b = 255;
    m_color.a = 255;
}

Fruit::Fruit(Fruit const &rhs)
{
    *this = rhs;
}

Fruit &Fruit::operator=(Fruit const &rhs)
{
    if (this != &rhs)
    {
        *this = rhs;
    }
    return *this;
}

void Fruit::reroll()
{
    m_pos_x = rand() % m_width;
    m_pos_y = rand() % m_height;
}