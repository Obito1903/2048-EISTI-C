/** @file affichageSDL.c
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 12 May 2020 10:04
 *
 *  @brief
 *
 */

#include "affichageSDL.h"

void mainAffichage(etatJeu *jeu)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("SDL_Init Error: %s \n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    if (win == NULL)
    {
        printf("SDL_CreateWindow Error: %s \n", SDL_GetError());
        SDL_Quit();
        exit(EXIT_FAILURE);
    }

    SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ren == NULL)
    {
        SDL_DestroyWindow(win);
        printf("SDL_CreateRenderer Error: %s \n", SDL_GetError());
        SDL_Quit();
        exit(EXIT_FAILURE);
    }

    freeJeu(jeu);
    SDL_Quit();
}
