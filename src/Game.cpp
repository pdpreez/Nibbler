/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 11:32:38 by ppreez            #+#    #+#             */
/*   Updated: 2019/07/14 13:33:58 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

Game::Game()
:m_width(100), m_height(100)
{
}

Game::Game(unsigned int width, unsigned int height)
:m_width(width), m_height(height)
{
}

Game::Game(Game const &rhs)
{
    *this = rhs;
}

Game &Game::operator=(Game const &rhs)
{
    if (this != &rhs)
        *this = rhs;
    return *this;
}

Game::~Game()
{
}

void Game::run()
{
    (void)m_width;
    (void)m_height;
    glib = new OpenGL();
    glib->createWindow();
    while (1)
    {
        glib->refresh();
    }
}