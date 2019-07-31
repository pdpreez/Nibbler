/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 12:02:37 by ppreez            #+#    #+#             */
/*   Updated: 2019/07/31 14:30:17 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Snake.hpp"

// Coplien Form

Snake::Snake()
{}

Snake::Snake(unsigned int x, unsigned int y)
{
    m_pos_x = x;
    m_pos_y = y;
    m_length = 4;
    m_vec_x = 1;
    m_vec_y = 0;
    m_speed = 1;
    m_last_key = RIGHT;

    for (unsigned int i = 0; i < m_length; i++)
    {
        m_body.push_back(new Body(m_pos_x - (i + 1), m_pos_y));
    }
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

// Methods

void Snake::move(unsigned int key)
{
    if (key == UP && m_last_key != DOWN)
    {
        m_last_key = key;
        setVec(0, m_speed);
    }
    if (key == RIGHT && m_last_key != LEFT)
    {
        m_last_key = key;
        setVec(m_speed, 0);
    }
    if (key == DOWN && m_last_key != UP)
    {
        m_last_key = key;
        setVec(0, -m_speed);
    }
    if (key == LEFT && m_last_key != RIGHT)
    {
        m_last_key = key;
        setVec(-m_speed, 0);
    }
    Body *temp = m_body.back();
    m_body.pop_back();
    temp->setX(m_pos_x);
    temp->setY(m_pos_y);
    m_body.push_front(temp);
    m_pos_x += m_vec_x;
    m_pos_y += m_vec_y;
}

void Snake::grow()
{
    Body *temp = new Body(m_body.back()->getX(), m_body.back()->getY());
    m_body.push_back(temp);
}

// Getters and Setters

void Snake::setVec(int x, int y)
{
    m_vec_x = x;
    m_vec_y = y;
}