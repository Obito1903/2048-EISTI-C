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
    SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, FENETRE_L, FENETRE_H, SDL_WINDOW_SHOWN);
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
        SDL_RenderClear(ren);
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
    tabTex->tabTex = (SDL_Texture **)malloc(sizeof(SDL_Texture *) * 11);
    tabTex->tabTex[0] = loadTexture("./src/assets/2.bmp", ren);
    tabTex->tabTex[1] = loadTexture("./src/assets/4.bmp", ren);
    tabTex->tabTex[2] = loadTexture("./src/assets/8.bmp", ren);
    tabTex->tabTex[3] = loadTexture("./src/assets/16.bmp", ren);
    tabTex->tabTex[4] = loadTexture("./src/assets/32.bmp", ren);
    tabTex->tabTex[5] = loadTexture("./src/assets/64.bmp", ren);
    tabTex->tabTex[6] = loadTexture("./src/assets/128.bmp", ren);
    tabTex->tabTex[7] = loadTexture("./src/assets/256.bmp", ren);
    tabTex->tabTex[8] = loadTexture("./src/assets/512.bmp", ren);
    tabTex->tabTex[9] = loadTexture("./src/assets/1024.bmp", ren);
    tabTex->tabTex[10] = loadTexture("./src/assets/2048.bmp", ren);

    return (tabTex);
}

void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int h, int w)
{
    //Setup the destination rectangle to be at the position we want
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    //Query the texture to get its width and height to use
    SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
    dst.w = w;
    dst.h = h;
    SDL_RenderCopy(ren, tex, NULL, &dst);
}

void gestionTouche(etatJeu *jeu, SDL_Keycode touche)
{
    Bool deplacement = False;
    switch (touche)
    {
    case SDLK_ESCAPE:
        jeu->jeuActif = False;
        break;
    case SDLK_UP:
        deplacement = DirectionNord(jeu);
        break;
    case SDLK_DOWN:
        deplacement = DirectionSud(jeu);
        break;
    case SDLK_LEFT:
        deplacement = DirectionOuest(jeu);
        break;
    case SDLK_RIGHT:
        deplacement = DirectionEst(jeu);
        break;
    default:
        break;
    }

    if (deplacement)
    {
        ajouteCase(jeu);
        jeu->nbCoups++;
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
    dessinePlateau(renderer, tabTex, jeu);
}

void dessinePlateau(SDL_Renderer *renderer, tabTextures *tabTex, etatJeu *jeu)
{
    int tailleCasePx = FENETRE_H / (jeu->plateau->taille + 2);
    int decallageVert = tailleCasePx - (4 * (jeu->plateau->taille - 1));
    int int_y;
    int int_x;
    for (int_y = 0; int_y < jeu->plateau->taille; int_y++)
    {
        for (int_x = 0; int_x < jeu->plateau->taille; int_x++)
        {
            if (jeu->plateau->tab[int_y][int_x] != 0)
            {
                renderTexture(tabTex->tabTex[(int)(log2(jeu->plateau->tab[int_y][int_x])) - 1], renderer, (int_x * (tailleCasePx + 4)) + decallageVert, (int_y * (tailleCasePx + 4)) + decallageVert, tailleCasePx, tailleCasePx);
            }
        }
    }
}
