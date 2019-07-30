/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IEntity.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 11:35:04 by ppreez            #+#    #+#             */
/*   Updated: 2019/07/30 15:23:07 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IENTITY_HPP
#define IENTITY_HPP

class IEntity
{
    public:
        virtual unsigned int getX() const = 0;
        virtual unsigned int getY() const = 0;
        virtual unsigned int getColor() const = 0;
    protected:
        unsigned int m_pos_x;
        unsigned int m_pos_y;
        unsigned int m_priority;
        unsigned int m_color;
};

#endif