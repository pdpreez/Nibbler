/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SFML.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 13:43:24 by ppreez            #+#    #+#             */
/*   Updated: 2019/08/05 14:38:28 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SFML.hpp"

SFML::SFML()
{}

SFML::SFML(unsigned int width, unsigned int height)
:m_width(width * 20), m_height(height * 20)
{
    m_window.create(sf::VideoMode(width * 20, height * 20), "Nibbler");
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
    m_window.create(sf::VideoMode(m_width * 20, m_height * 20), "Nibbler");
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
        if (e.type == sf::Event::Closed)
        {
            return EXIT;
        }
    }
    return NONE;
}

void SFML::drawSquare(unsigned int x, unsigned int y, struct s_color color)
{
    (void)x;
    (void)y;
    (void)color;
}

void SFML::startFrame()
{

}

void SFML::endFrame()
{

}

void SFML::refresh()
{

}