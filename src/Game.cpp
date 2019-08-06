/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 11:32:38 by ppreez            #+#    #+#             */
/*   Updated: 2019/08/06 09:53:41 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

Game::Game()
:m_stayOpen(true), m_width(40), m_height(30), m_size(20), m_fps(15), m_renderer(0)
{
    glib = nullptr;
}

Game::Game(int width, int height)
:m_stayOpen(true), m_size(20), m_fps(15), m_renderer(0)
{
    m_width = std::clamp(width, 20, 50);
    m_height = std::clamp(height, 20, 40);
    glib = nullptr;
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
    delete snake;
    delete glib;
    delete fruit;

}

void Game::run()
{
    snake = new Snake(m_height / 4, m_width / 4);
    fruit = new Fruit(m_width, m_height);

    glib = create_renderer("shared/OpenGL.so", m_width, m_height, m_size);
    if (glib)
        glib->createWindow();
    auto start = getTime();
    while (m_stayOpen)
    {
        double fps = (1.0 / m_fps) * 1000;
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
        glib->drawSquare(snake->getX(), snake->getY(), snake->getColor());
        for (auto a = snake->m_body.begin(); a != snake->m_body.end(); a++)
        {
            glib->drawSquare((*a)->getX(), (*a)->getY(), (*a)->getColor());
        }
        glib->drawSquare(fruit->getX(), fruit->getY(), fruit->getColor());
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
    if (key == OPENGL_KEY || key == SDL_KEY)
        change_renderer(key);
    snake->move(key);
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
        m_fps += 2;
        snake->grow();
        fruit->reroll();
    }
    for (auto a = snake->m_body.begin(); a != snake->m_body.end(); a++)
    {
        if (((*a)->getX() == x && (*a)->getY() == y) 
        || (snake->getX() < 0 || snake->getX() >= m_width || snake->getY() < 0 || snake->getY() >= m_height ) 
        || (*a)->getX() < 0 || (*a)->getX() >= m_width || (*a)->getY() < 0 || (*a)->getY() >= m_height)
        {
            m_stayOpen = false;
        }
    }
}

void Game::change_renderer(unsigned int key)
{
    std::string path = "shared/";
    if (m_renderer != key)
    {
        if (key == OPENGL_KEY)
            path += "OpenGL.so";
        else if (key == SDL_KEY)
            path += "SDL.so";
        glib->closeWindow();
        delete glib;
        try 
        {
            glib = create_renderer(path, m_width, m_height, m_size);
        }
        catch (std::exception &e)
        {
            m_stayOpen = false;
            return ;
        }
        glib->createWindow();
        m_renderer = key;
    }
}

IGlib *Game::create_renderer(std::string const &str, unsigned int width, unsigned int height, unsigned int size)
{
    void *handle = dlopen(str.c_str(), RTLD_NOW | RTLD_GLOBAL);
    if (!handle)
        throw std::exception();
    createFunc func = (createFunc)dlsym(handle, "create_renderer");
    if (!func)
        throw std::exception();
    return (*func)(width, height, size);
}