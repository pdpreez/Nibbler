/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntity.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 11:35:04 by ppreez            #+#    #+#             */
/*   Updated: 2019/08/02 09:29:09 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AENTITY_HPP
#define AENTITY_HPP

#include "KeyCodes.hpp"
struct s_color
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
};


class AEntity
{
    public:
        AEntity();
        AEntity(AEntity const &rhs);
        AEntity &operator=(AEntity const &rhs);
        ~AEntity();
        void setX(int x);
        void setY(int y);
        int getX() const;
        int getY() const;
        struct s_color getColor() const;
    protected:
        int m_pos_x;
        int m_pos_y;
        unsigned int m_priority;
        struct s_color m_color;
};

#endif