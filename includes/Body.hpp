/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Body.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 12:25:21 by ppreez            #+#    #+#             */
/*   Updated: 2019/07/14 12:35:04 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BODY_HPP
#define BODY_HPP

#include "IEntity.hpp"

class Body: public IEntity
{
    public:
        Body(unsigned int x, unsigned int y);      
    private:
};

#endif