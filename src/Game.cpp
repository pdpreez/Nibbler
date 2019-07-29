/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 11:32:38 by ppreez            #+#    #+#             */
/*   Updated: 2019/07/29 15:40:27 by ppreez           ###   ########.fr       */
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

unsigned int g_pos_x = 0;
unsigned int g_pos_y = 0;

void Game::run()
{
    (void)m_width;
    (void)m_height;
    glib = new class SDL(m_width, m_height);
    glib->createWindow();
    double fps = (1.0 / 60) * 1000;
    auto start = getTime();
    while (m_stayOpen)
    {
        auto current = getTime();
        double delta = current.count() - start.count();
        while (delta < fps)
        {
            current = getTime();
            delta = current.count() - start.count();
        }
        start = current;
        process_input();
        glib->startFrame();
        glib->drawSquare(g_pos_x, g_pos_y);
        glib->endFrame();
        
    }
    glib->closeWindow();
}

void Game::process_input()
{
    
    unsigned int key;
    key = glib->retrieveInput();
    if (key == EXIT)
        m_stayOpen = false;
}

std::chrono::milliseconds Game::getTime() const
{
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
}

void Game::fps_delay()
{
    
}