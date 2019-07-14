/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 12:02:48 by ppreez            #+#    #+#             */
/*   Updated: 2019/07/14 12:25:06 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "IEntity.hpp"

class Snake: public IEntity
{
    public:
        Snake();
        Snake(Snake const &rhs);
        Snake &operator=(Snake const &rhs);
        ~Snake();
    private:
        unsigned int length;
        
};

#endif