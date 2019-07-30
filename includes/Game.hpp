/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 11:32:04 by ppreez            #+#    #+#             */
/*   Updated: 2019/07/30 15:22:42 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <chrono>
#include "Snake.hpp"
#include "IGlib.hpp"
#include "OpenGL.hpp"
#include "SDL.hpp"

struct colors 
{
    unsigned int r;
    unsigned int g;
    unsigned int b;
    unsigned int a;
};

enum keys 
{
    EXIT,
    OPENGL,
    SDL,
    SFML,
    UP = 100,
    RIGHT = 101,
    DOWN = 102,
    LEFT = 103,
    PAUSE = 42
};

class Game
{
    public:
        Game();
        Game(unsigned int width, unsigned int height);
        Game(Game const &rhs);
        Game &operator=(Game const &rhs);
        ~Game();

        void run();
    private:
        IGlib *glib;
        Snake *snake;
        bool m_stayOpen;
        unsigned int m_width;
        unsigned int m_height;
        std::chrono::milliseconds getTime() const;

        void process_input();
        void fps_delay();
};

#endif