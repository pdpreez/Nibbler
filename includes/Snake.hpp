/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 12:02:48 by ppreez            #+#    #+#             */
/*   Updated: 2019/07/31 13:30:10 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "Body.hpp"
#include <list>

class Body;

class Snake: public AEntity
{
    public:
        Snake(unsigned int x, unsigned int y);
        Snake(Snake const &rhs);
        Snake &operator=(Snake const &rhs);
        ~Snake();

        void move(unsigned int key);
        bool collide(unsigned int x, unsigned int y);
        std::list<Body *> m_body;
        void grow();
    private:
        Snake();
        void setVec(int x, int y);
        unsigned int m_last_key;
        unsigned int m_length;
        unsigned int m_vec_x;
        unsigned int m_vec_y;
        unsigned int m_speed;
};

#endif