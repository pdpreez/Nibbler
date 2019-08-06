/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SDL.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 14:14:42 by ppreez            #+#    #+#             */
/*   Updated: 2019/08/06 13:36:43 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.hpp"

SDL::SDL()
{}

SDL::SDL(unsigned int width, unsigned int height, unsigned int size)
:m_width(width * size), m_height(height * size), m_size(size)
{

}

SDL::SDL(SDL const &rhs)
{
    *this = rhs;
}

SDL &SDL::operator=(SDL const &rhs)
{
    if (this != &rhs)
    {
        *this = rhs;
    }
    return *this;
}

SDL::~SDL()
{

}

void SDL::createWindow()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "start frame" << std::endl;
        throw std::exception();
    }
    m_window = SDL_CreateWindow("Nibbler", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_width, m_height, SDL_WINDOW_SHOWN);
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
}

void SDL::closeWindow()
{
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

void SDL::refresh()
{
    
}

void SDL::startFrame()
{
    SDL_SetRenderDrawColor(m_renderer, 0, 30, 30, 255);
    SDL_RenderClear(m_renderer);
}

void SDL::drawSquare(unsigned int x, unsigned int y, struct s_color color)
{
    // x += y;
    
    int xpos = static_cast<int>(x * m_size);
    int ypos = static_cast<int>(m_height - (y + 1) * m_size);
    int xsize = static_cast<int>(m_size);
    int ysize = static_cast<int>(m_size);
    SDL_Rect fillrect = {xpos, ypos, xsize, ysize};
    SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(m_renderer, &fillrect);
    SDL_SetRenderDrawColor(m_renderer, color.r / 2, color.g / 2, color.b / 2, color.a);
    SDL_RenderDrawRect(m_renderer, &fillrect);
}

void SDL::endFrame()
{
    SDL_RenderPresent(m_renderer);
}

int SDL::retrieveInput()
{
    SDL_Event e;
    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_KEYDOWN)
        {
            if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE)
                return EXIT;
            else if (e.key.keysym.sym == SDLK_UP)
                return UP;
            else if (e.key.keysym.sym == SDLK_RIGHT)
                return RIGHT;
            else if (e.key.keysym.sym == SDLK_DOWN)
                return DOWN;
            else if (e.key.keysym.sym == SDLK_LEFT)
                return LEFT;
            else if (e.key.keysym.sym == SDLK_1)
                return OPENGL_KEY;
            else if (e.key.keysym.sym == SDLK_2)
                return SDL_KEY;
            else if (e.key.keysym.sym == SDLK_3)
                return SFML_KEY;
        }
    }
    return NONE;
}

extern "C"
{
    IGlib *create_renderer(unsigned int width, unsigned int height, unsigned int size)
    {
        return new SDL(width, height, size);
    }
}