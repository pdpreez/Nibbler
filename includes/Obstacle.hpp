/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Obstacle.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 09:52:15 by ppreez            #+#    #+#             */
/*   Updated: 2019/08/09 10:07:28 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

#include "AEntity.hpp"

class Obstacle: public AEntity
{
    public:
        Obstacle(int x, int y);
        Obstacle(Obstacle const &rhs);
        Obstacle &operator=(Obstacle const &rhs);
        ~Obstacle();

    private:
        Obstacle();
};

#endif