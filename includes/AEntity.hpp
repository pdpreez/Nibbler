/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntity.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 11:35:04 by ppreez            #+#    #+#             */
/*   Updated: 2019/07/31 12:41:46 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AENTITY_HPP
#define AENTITY_HPP

#include "KeyCodes.hpp"

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
        int getColor() const;
    protected:
        int m_pos_x;
        int m_pos_y;
        unsigned int m_priority;
        unsigned int m_color;
};

#endif