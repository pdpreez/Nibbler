/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 11:32:38 by ppreez            #+#    #+#             */
/*   Updated: 2019/07/24 13:50:36 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

Game::Game()
:m_stayOpen(true), m_width(100), m_height(100)
{
}

Game::Game(unsigned int width, unsigned int height)
:m_stayOpen(true), m_width(width), m_height(height)
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
    while (m_stayOpen)
    {
        process_input();
        glib->refresh();
    }
    glib->closeWindow();
}

void Game::process_input()
{
    unsigned int key;
    key = glib->retrieveInput();
    if (key != 1)
        std::cout << key << std::endl;
    if (key == EXIT)
        m_stayOpen = false;
}