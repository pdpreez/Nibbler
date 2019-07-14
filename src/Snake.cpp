/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 12:02:37 by ppreez            #+#    #+#             */
/*   Updated: 2019/07/14 12:05:43 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Snake.hpp"

Snake::Snake()
{
    
}

Snake::Snake(Snake const &rhs)
{
    *this = rhs;
}

Snake &Snake::operator=(Snake const &rhs)
{
    if (this != &rhs)
        *this = rhs;
    return *this;
}

Snake::~Snake()
{
    
}