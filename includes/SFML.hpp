/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SFML.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 13:42:51 by ppreez            #+#    #+#             */
/*   Updated: 2019/08/05 15:59:21 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SFML_HPP
#define SFML_HPP

#include "IGlib.hpp"
#include "SFML/Window.hpp"

class SFML: public IGlib
{
    public:
        SFML(unsigned int width, unsigned int height);
        SFML(SFML const &rhs);
        SFML &operator=(SFML const &rhs);
        virtual ~SFML();

        virtual void refresh();
        virtual void startFrame();
        virtual void endFrame();
        virtual void drawSquare(unsigned int x, unsigned int y, struct s_color color);
        virtual void createWindow();
        virtual void closeWindow();
        virtual int retrieveInput();
    private:
        sf::Window m_window;
        unsigned int m_width;
        unsigned int m_height;
        SFML();
};

#endif