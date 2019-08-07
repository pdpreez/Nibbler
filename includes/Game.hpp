/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 11:32:04 by ppreez            #+#    #+#             */
/*   Updated: 2019/08/07 15:30:12 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <chrono>
#include <dlfcn.h>
#include <iostream>
#include "Snake.hpp"
#include "Fruit.hpp"
#include "graphics/IGlib.hpp"

typedef IGlib * (*createFunc)(unsigned int width, unsigned int height, unsigned int size);

class Game
{
    public:
        Game(int width, int height, int speed, char increase);
        Game(int speed, char increase);
        Game(Game const &rhs);
        Game &operator=(Game const &rhs);
        ~Game();

        void run();
    private:
        Game();
        IGlib *glib;
        Snake *snake;
        Fruit *fruit;
        bool m_stayOpen;
        int m_width;
        int m_height;
        int m_size;
        int m_fps;
        int m_speed;
        int m_score;
        bool m_increase;
        unsigned int m_renderer;
        void *m_handle;

        std::chrono::milliseconds getTime() const;
        void process_input();
        void collisions();
        bool body_conflicts(int x, int y);
        void change_renderer(unsigned int key);
        IGlib *create_renderer(std::string const &str, unsigned int width, unsigned int height, unsigned int size);
};

#endif