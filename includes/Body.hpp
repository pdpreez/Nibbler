/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Body.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 11:15:54 by ppreez            #+#    #+#             */
/*   Updated: 2019/07/31 12:43:10 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BODY_HPP
#define BODY_HPP

#include "AEntity.hpp"

class Body: public AEntity
{
    public:
        Body(unsigned int x, unsigned int y);
        Body(Body const &rhs);
        Body &operator=(Body const &rhs);
        ~Body();

    private:
        Body();

};

#endif