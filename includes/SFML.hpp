/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SFML.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 13:42:51 by ppreez            #+#    #+#             */
/*   Updated: 2019/08/06 15:35:23 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SFML_HPP
#define SFML_HPP

#include "IGlib.hpp"
#include "SFML/Graphics.hpp"

class SFML: public IGlib
{
    public:
        SFML(unsigned int width, unsigned int height, unsigned int size);
        SFML(SFML const &rhs);
        SFML &operator=(SFML const &rhs);
        virtual ~SFML();

        virtual void startFrame();
        virtual void endFrame();
        virtual void drawSquare(unsigned int x, unsigned int y, struct s_color color);
        virtual void createWindow();
        virtual void closeWindow();
        virtual int retrieveInput();
    private:
        sf::RenderWindow m_window;
        unsigned int m_grid_width;
        unsigned int m_grid_height;
        unsigned int m_screen_width;
        unsigned int m_screen_height;
        unsigned int m_size;
        SFML();
};

extern "C"
{
    IGlib *create_renderer(unsigned int width, unsigned int height, unsigned int size);
}

#endif