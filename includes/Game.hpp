/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 11:32:04 by ppreez            #+#    #+#             */
/*   Updated: 2019/07/29 15:39:20 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <chrono>
// #include "IEntity.hpp"
#include "IGlib.hpp"
#include "OpenGL.hpp"
#include "SDL.hpp"

enum keys 
{
    EXIT,
    OPENGL,
    SDL,
    SFML,
    UP = 100,
    DOWN = 101,
    LEFT = 102,
    RIGHT = 103,
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
        bool m_stayOpen;
        unsigned int m_width;
        unsigned int m_height;
        std::chrono::milliseconds getTime() const;
        // std::vector<IEntity> snake;

        void process_input();
        void fps_delay();
};

#endif