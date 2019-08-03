/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SDL.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 14:11:19 by ppreez            #+#    #+#             */
/*   Updated: 2019/08/03 14:48:55 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SDL_HPP
#define SDL_HPP

#include "IGlib.hpp"
#include "SDL.h"
#include <iostream>

class SDL: public IGlib
{
    public:
        SDL(unsigned int width, unsigned int height);
        SDL(SDL const &rhs);
        SDL &operator=(SDL const &rhs);
        virtual ~SDL();

        virtual void refresh();
        virtual void startFrame();
        virtual void endFrame();
        virtual void drawSquare(unsigned int x, unsigned int y, struct s_color color);
        virtual void createWindow();
        virtual void closeWindow();
        virtual int retrieveInput();
    private:
        SDL();
        unsigned int m_width;
        unsigned int m_height;
        SDL_Window *m_window;
        SDL_Renderer *m_renderer;
};

extern "C"
{
    IGlib *create_renderer(unsigned int width, unsigned int height);
}


#endif