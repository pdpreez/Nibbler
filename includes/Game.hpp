/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 11:32:04 by ppreez            #+#    #+#             */
/*   Updated: 2019/07/14 13:29:02 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
// #include "IEntity.hpp"
#include "IGlib.hpp"
#include "OpenGL.hpp"

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
        unsigned int m_width;
        unsigned int m_height;
        // std::vector<IEntity> snake;
};

#endif