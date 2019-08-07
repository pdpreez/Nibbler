/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 11:30:10 by ppreez            #+#    #+#             */
/*   Updated: 2019/08/07 15:33:45 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

int main(int argc, char **argv)
{
    int speed = 0;
    char increase = 'Y';
    std::cout << "Please pick a speed from 1 - 10:" << std::endl;
    std::cin >> speed;
    speed = std::clamp(speed, 1, 10);
    std::cout << "Speed picked is : " << speed << std::endl;
    std::cout << "Should snake increase speed when eating fruit? [Y/N]" << std::endl;
    std::cin >> increase;
    if ((increase != 'y' && increase != 'Y') || increase == 'n')
        increase = 'N';
    if (argc == 3)
    {
        int a = atoi(argv[1]);
        int b = atoi(argv[2]);
        Game game(a, b, speed, increase);
        game.run();

    }
    else
    {
        Game game(speed, increase);
        game.run();
    }
}