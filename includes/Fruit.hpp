/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fruit.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:12:04 by ppreez            #+#    #+#             */
/*   Updated: 2019/07/31 14:19:46 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRUIT_HPP
#define FRUIT_HPP

#include "AEntity.hpp"
#include <random>

class Fruit: public AEntity
{
    public:
        Fruit(int width, int height);
        Fruit(Fruit const &rhs);
        Fruit &operator=(Fruit const &rhs);
        ~Fruit();

        void reroll();
    private:
        int m_width;
        int m_height;
        Fruit();
};

#endif