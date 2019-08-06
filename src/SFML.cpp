/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SFML.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 13:43:24 by ppreez            #+#    #+#             */
/*   Updated: 2019/08/06 13:45:43 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SFML.hpp"
#include <iostream>

SFML::SFML()
{}

SFML::SFML(unsigned int width, unsigned int height, unsigned int size)
:m_grid_width(width), m_grid_height(height), m_size(size)
{
    m_screen_width = m_grid_width * m_size;
    m_screen_height = m_grid_height * m_size;
}

SFML::SFML(SFML const &rhs)
{
    *this = rhs;
}

SFML &SFML::operator=(SFML const &rhs)
{
    if (this != &rhs)
    {
        *this = rhs;
    }
    return *this;
}

SFML::~SFML()
{}

void SFML::createWindow()
{
    m_window.create(sf::VideoMode(m_screen_width, m_screen_height), "Nibbler");
}

void SFML::closeWindow()
{
    m_window.close();
}

int SFML::retrieveInput()
{
    sf::Event e;
    while (m_window.pollEvent(e))
    {
        if (e.type == sf::Event::Closed || e.key.code == sf::Keyboard::Escape)
        {
            return EXIT;
        }
        if (e.type == sf::Event::EventType::KeyPressed)
        {
            if (e.key.code == sf::Keyboard::Up)
                return UP;
            if (e.key.code == sf::Keyboard::Right)
                return RIGHT;
            if (e.key.code == sf::Keyboard::Down)
                return DOWN;
            if (e.key.code == sf::Keyboard::Left)
                return LEFT;
            if (e.key.code == sf::Keyboard::Num1)
                return OPENGL_KEY;
            if (e.key.code == sf::Keyboard::Num2)
                return SDL_KEY;
            if (e.key.code == sf::Keyboard::Num3)
                return SFML_KEY;
            
        }
    }
    return NONE;
}

void SFML::drawSquare(unsigned int x, unsigned int y, struct s_color color)
{
    sf::RectangleShape rs({static_cast<float>(m_size), static_cast<float>(m_size)});
    rs.setPosition(x * m_size, m_screen_height - (y + 1) * m_size);
    rs.setFillColor({color.r, color.g, color.b});
    m_window.draw(rs);
}

void SFML::startFrame()
{
    m_window.clear(sf::Color(26, 10, 107, 255));
}

void SFML::endFrame()
{
    m_window.display();
}

void SFML::refresh()
{

}

extern "C"
{
    IGlib *create_renderer(unsigned int width, unsigned int height, unsigned int size)
    {
        return new SFML(width, height, size);
    }
}