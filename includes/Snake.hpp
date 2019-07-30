/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 12:02:48 by ppreez            #+#    #+#             */
/*   Updated: 2019/07/30 15:33:15 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "IEntity.hpp"

class Snake: public IEntity
{
    public:
        Snake(unsigned int x, unsigned int y);
        Snake(Snake const &rhs);
        Snake &operator=(Snake const &rhs);
        ~Snake();

        void move();
        void setVec(int x, int y);
        virtual unsigned int getX() const;
        virtual unsigned int getY() const;
        virtual unsigned int getColor() const;
    private:
        Snake();
        unsigned int m_length;
        unsigned int m_vec_x;
        unsigned int m_vec_y;
};

#endif