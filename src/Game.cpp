/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 11:32:38 by ppreez            #+#    #+#             */
/*   Updated: 2019/07/31 15:04:41 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

Game::Game()
:m_stayOpen(true), m_width(20), m_height(20)
{
}

Game::Game(int width, int height)
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
    // delete[] snake;
    // delete[] glib;

}

void Game::run()
{
    snake = new Snake(m_height / 4, m_width / 4);
    fruit = new Fruit(m_width, m_height);
    glib = new class SDL(m_width, m_height);
    glib->createWindow();
    double fps = (1.0 / 15) * 1000;
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
        collisions();
        glib->startFrame();
        glib->drawSquare(snake->getX(), snake->getY(), 2);
        for (auto a = snake->m_body.begin(); a != snake->m_body.end(); a++)
            glib->drawSquare((*a)->getX(), (*a)->getY(), 2);
        glib->drawSquare(fruit->getX(), fruit->getY(), 1);
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
    snake->move(key);
    if (snake->getX() < 0 || snake->getX() > m_width
        || snake->getY() < 0 || snake->getY() > m_height)
            m_stayOpen = false;
}

std::chrono::milliseconds Game::getTime() const
{
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
}

void Game::fps_delay()
{
    
}

void Game::collisions()
{
    int x = snake->getX();
    int y = snake->getY();
    if (x == fruit->getX() && y == fruit->getY())
    {
        snake->grow();
        fruit->reroll();
    }
    for (auto a = snake->m_body.begin(); a != snake->m_body.end(); a++)
    {
        if ((*a)->getX() == x && (*a)->getY() == y)
        {
            m_stayOpen = false;
        }
    }

}