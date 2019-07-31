/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 11:32:04 by ppreez            #+#    #+#             */
/*   Updated: 2019/07/31 14:21:15 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <chrono>
#include "Snake.hpp"
#include "Fruit.hpp"
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

class Game
{
    public:
        Game();
        Game(int width, int height);
        Game(Game const &rhs);
        Game &operator=(Game const &rhs);
        ~Game();

        void run();
    private:
        IGlib *glib;
        Snake *snake;
        Fruit *fruit;
        bool m_stayOpen;
        int m_width;
        int m_height;
        std::chrono::milliseconds getTime() const;

        void process_input();
        void fps_delay();
        void collisions();
};

#endif