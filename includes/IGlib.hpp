/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IGlib.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 12:16:50 by ppreez            #+#    #+#             */
/*   Updated: 2019/07/31 11:32:48 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IGLIB_HPP
#define IGLIB_HPP

#include "AEntity.hpp"
#include <exception>

#define KEY_QUIT 0
#define KEY_UP 100;
#define KEY_RIGHT 101;
#define KEY_DOWN 102;
#define KEY_LEFT 103;

class IGlib
{
    public:
        virtual ~IGlib(){};
        virtual void refresh() = 0;
        virtual void startFrame() = 0;
        virtual void endFrame() = 0;
        virtual void drawSquare(unsigned int x, unsigned int y) = 0;
        virtual void createWindow() = 0;
        virtual void closeWindow() = 0;
        virtual int retrieveInput() = 0;
};

#endif