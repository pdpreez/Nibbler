/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 11:30:10 by ppreez            #+#    #+#             */
/*   Updated: 2019/07/29 15:38:57 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include "SDL.h"

int main()
{
    // (void)argc;
    // (void)argv;
    // SDL_Window *window = NULL;
    // SDL_Surface *surface = NULL;
    
    // if (SDL_Init(SDL_INIT_VIDEO) < 0)
    // {
    //     std::cout << "SDL could not be initialised" << std::endl;
    //     std::cout << SDL_GetError() << std::endl;
    // }
    // else
    // {
    //     window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    //     if (window == NULL)
    //     {
    //         std::cout << "Failed to create window" << std::endl;
    //         std::cout << SDL_GetError() << std::endl;
    //     }
    //     else
    //     {
    //         surface = SDL_GetWindowSurface(window);
    //         SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0xff, 0x00, 0x00));
    //         SDL_UpdateWindowSurface(window);
    //         SDL_Event e;
    //         bool quit = false;
    //         while (!quit){
    //             while (SDL_PollEvent(&e)){
    //                 if (e.type == SDL_QUIT){
    //                     quit = true;
    //                 }
    //                 if (e.type == SDL_KEYDOWN){
    //                     quit = true;
    //                 }
    //                 if (e.type == SDL_MOUSEBUTTONDOWN){
    //                     quit = true;
    //                 }
    //             }
    //         }
    //     }
    // }
    // SDL_DestroyWindow(window);
    // SDL_Quit();
    Game game;
    game.run();
}