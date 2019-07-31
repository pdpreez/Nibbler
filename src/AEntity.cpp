/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntity.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 11:33:20 by ppreez            #+#    #+#             */
/*   Updated: 2019/07/31 12:42:51 by ppreez           ###   ########.fr       */
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

int AEntity::getColor() const
{
    return 1;
}