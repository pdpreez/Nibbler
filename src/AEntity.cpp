/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntity.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 11:33:20 by ppreez            #+#    #+#             */
/*   Updated: 2019/08/02 09:29:21 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AEntity.hpp"

AEntity::AEntity()
{}

AEntity::AEntity(AEntity const &rhs)
{
    *this = rhs;
}

AEntity &AEntity::operator=(AEntity const &rhs)
{
    if (this != &rhs)
        *this = rhs;
    return *this;
}

AEntity::~AEntity()
{

}

void AEntity::setX(int x)
{
    m_pos_x = x;
}

void AEntity::setY(int y)
{
    m_pos_y = y;
}

int AEntity::getX() const
{
    return m_pos_x;
}

int AEntity::getY() const
{
    return m_pos_y;
}

struct s_color AEntity::getColor() const
{
    return m_color;
}