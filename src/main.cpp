/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 11:30:10 by ppreez            #+#    #+#             */
/*   Updated: 2019/08/09 11:08:54 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

int main(int argc, char **argv)
{
    std::string input;
    int speed = 0;
    char increase = 'Y';
    bool obstacles = true;
    std::cout << "Please pick a speed from 1 - 10:" << std::endl;
    std::getline(std::cin, input);
    speed = atoi(input.c_str());
    speed = std::clamp(speed, 1, 10);
    std::cout << "Speed picked is : " << speed << std::endl;
    std::cout << "Should snake increase speed when eating fruit? [Y/N]" << std::endl;
    std::getline(std::cin, input);
    increase = input[0];
    if ((increase != 'y' && increase != 'Y') || increase == 'n')
        increase = 'N';
    std::cout << "Obstacles? [Y/N]" << std::endl;
    std::getline(std::cin, input);
    if ((input[0] != 'y' && input[0] != 'Y') || input[0] == 'n')
        obstacles = false;
    if (argc == 3)
    {
        int a = atoi(argv[1]);
        int b = atoi(argv[2]);
        Game game(a, b, speed, increase, obstacles);
        game.run();

    }
    else
    {
        Game game(speed, increase, obstacles);
        game.run();
    }
}