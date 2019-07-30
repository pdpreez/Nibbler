/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 12:02:37 by ppreez            #+#    #+#             */
/*   Updated: 2019/07/30 15:33:47 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Snake.hpp"

Snake::Snake()
{}

Snake::Snake(unsigned int x, unsigned int y)
{
    m_pos_x = x;
    m_pos_y = y;
    m_length = 4;
    m_vec_x = 1;
    m_vec_y = 0;
}

Snake::Snake(Snake const &rhs)
{
    *this = rhs;
}

Snake &Snake::operator=(Snake const &rhs)
{
    if (this != &rhs)
        *this = rhs;
    return *this;
}

Snake::~Snake()
{
    
}

void Snake::move()
{
    m_pos_x += m_vec_x;
    m_pos_y += m_vec_y;
}

unsigned int Snake::getX() const
{
    return m_pos_x;
}

unsigned int Snake::getY() const
{
    return m_pos_y;
}

unsigned int Snake::getColor() const
{
    return 1;
}

void Snake::setVec(int x, int y)
{
    m_vec_x = x;
    m_vec_y = y;
}