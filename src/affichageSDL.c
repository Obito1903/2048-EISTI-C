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
    tabTextures *tabTex = chargeTextures(ren);
    SDL_Event event;
    jeu->jeuActif = True;
    while (jeu->jeuActif)
    {
        gestionEvenement(jeu, &event);
        dessiner(ren, tabTex, jeu);
        SDL_RenderPresent(ren);
        SDL_Delay(16);
    }
    freeJeu(jeu);
    SDL_Quit();
}

SDL_Texture *loadTexture(const char *file, SDL_Renderer *ren)
{
    //Initialize to nullptr to avoid dangling pointer issues
    SDL_Texture *texture = NULL;
    //Load the image
    SDL_Surface *loadedImage = SDL_LoadBMP(file);
    //If the loading went ok, convert to texture and return the texture
    if (loadedImage != NULL)
    {
        texture = SDL_CreateTextureFromSurface(ren, loadedImage);
        SDL_FreeSurface(loadedImage);
        //Make sure converting went ok too
        if (texture == NULL)
        {
            fprintf(stdout, "CreateTextureFromSurface");
        }
    }
    else
    {
        fprintf(stdout, "LoadBMP");
    }
    return texture;
}

tabTextures *chargeTextures(SDL_Renderer *ren)
{
    tabTextures *tabTex = (tabTextures *)malloc(sizeof(tabTextures)); // Variable de retour
    tabTex->tabTex = (SDL_Texture **)malloc(sizeof(SDL_Texture *) * 1);
    tabTex->tabTex[0] = loadTexture("./src/assets/image1.bmp", ren);
    return (tabTex);
}

void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y)
{
    //Setup the destination rectangle to be at the position we want
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    //Query the texture to get its width and height to use
    SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
    SDL_RenderCopy(ren, tex, NULL, &dst);
}

void gestionTouche(etatJeu *jeu, SDL_Keycode touche)
{
    switch (touche)
    {
    case SDLK_ESCAPE:
        jeu->jeuActif = False;
        break;
    case SDLK_UP:
        break;

    case SDLK_DOWN:
        break;

    case SDLK_LEFT:
        break;

    case SDLK_RIGHT:
        break;
    default:
        break;
    }
}

void gestionEvenement(etatJeu *jeu, SDL_Event *event)
{

    while (SDL_PollEvent(event))
    {
        switch (event->type)
        {
        case SDL_QUIT:
            jeu->jeuActif = False;
            break;
        case SDL_KEYDOWN:
            gestionTouche(jeu, event->key.keysym.sym);
            break;
        default:
            break;
        }
    }
}

void dessiner(SDL_Renderer *renderer, tabTextures *tabTex, etatJeu *jeu)
{
    /*
    SDL_Surface *cube2 = NULL;
    SDL_Surface *cube4 = NULL;
    SDL_Surface *cube8 = NULL;
    SDL_Surface *cube16 = NULL;
    SDL_Surface *cube32 = NULL;
    SDL_Surface *cube64 = NULL;
    SDL_Surface *cube128 = NULL;
    SDL_Surface *cube256 = NULL;
    SDL_Surface *cube512 = NULL;
    SDL_Surface *cube1024 = NULL;
    SDL_Surface *cube2048 = NULL;

    cube2 = IMG_Load("image cube 2");
    cube4 = IMG_Load("image cube 4");
    cube8 = IMG_Load("image cube 8");
    cube16 = IMG_Load("image cube 16");
    cube32 = IMG_Load("image cube 32");
    cube64 = IMG_Load("image cube 64");
    cube128 = IMG_Load("image cube 128");
    cube256 = IMG_Load("image cube 256");
    cube512 = IMG_Load("image cube 512");
    cube1024 = IMG_Load("image cube 1024");
    cube2048 = IMG_Load("image cube 2048");

    creer une fonction jouer pour blit les surfaces
    */

    renderTexture(tabTex->tabTex[0], renderer, 10, 10);
    renderTexture(tabTex->tabTex[0], renderer, 200, 10);
}
