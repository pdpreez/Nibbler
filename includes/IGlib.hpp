/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IGlib.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 12:16:50 by ppreez            #+#    #+#             */
/*   Updated: 2019/07/14 13:27:29 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IGLIB_HPP
#define IGLIB_HPP

#include "IEntity.hpp"
#include <exception>

class IGlib
{
    public:
        virtual void refresh() = 0;
        virtual void drawEntity(IEntity const &) = 0;
        virtual void createWindow() = 0;
        virtual void closeWindow() = 0;
        virtual unsigned int retrieveInput() = 0;
};

#endif