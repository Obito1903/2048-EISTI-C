/** @file affichageSDL.c
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 12 May 2020 10:04
 *
 *  @brief
 *
 */

#include "affichageSDL.h"

TTF_Font *findFont()
{
    TTF_Font *font = TTF_OpenFont("./src/consola.ttf", FONTSIZE);
    if (font == NULL)
    {
        TTF_Font *font = TTF_OpenFont("./bin/src/consola.ttf", FONTSIZE);
        if (font == NULL)
        {
            TTF_Font *font = TTF_OpenFont("./consola.ttf", FONTSIZE);
            if (font == NULL)
            {
                printf("TTF_OpenFont Error: %s \n", TTF_GetError());
                exit(EXIT_FAILURE);
            }
        }
    }
    return font;
}

void frameControl(double tmp)
{
    if (tmp < 0.016)
    {
        SDL_Delay(16 - tmp);
    }
    else
    {
        printf("jeu trop lent (%lf)\n", tmp);
    }
}

void mainAffichage(etatJeu *jeu)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("SDL_Init Error: %s \n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    if (TTF_Init() == -1)
    {
        printf("TTF_Init Error: %s \n", TTF_GetError());
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
    SDL_Event event;
    jeu->jeuActif = True;

    TTF_Font *font = findFont();

    clock_t start, end;
    double cpu_time_used;

    tabTextures tabTile;
    tabTile.tabTex = NULL;
    tabTile.taille = 0;

    while (jeu->jeuActif)
    {
        start = clock();
        SDL_RenderClear(ren);
        gestionEvenement(jeu, &event);
        dessiner(ren, &tabTile, jeu, font);
        SDL_RenderPresent(ren);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        frameControl(cpu_time_used);
    }
    freeJeu(jeu);
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();
}

SDL_Texture *loadTexture(const char *file, SDL_Renderer *ren)
{
    SDL_Texture *texture = NULL;
    //Charge l'image
    SDL_Surface *loadedImage = SDL_LoadBMP(file);
    if (loadedImage != NULL)
    {
        texture = SDL_CreateTextureFromSurface(ren, loadedImage);
        SDL_FreeSurface(loadedImage);
        if (texture == NULL)
        {
            fprintf(stdout, "Erreur :CreateTextureFromSurface\n");
        }
    }
    else
    {
        fprintf(stdout, "Erreur : Chargement BMP\n");
    }
    return texture;
}

SDL_Color setTileColor(int tileValue)
{
    SDL_Color couleur = {0, 0, 0, 255};
    if (tileValue <= 8)
    {
        couleur.r = 252;
        couleur.g = 88;
        couleur.b = 76;
    }
    else if (tileValue <= 64)
    {
        couleur.r = 252;
        couleur.g = 155;
        couleur.b = 76;
    }
    else if (tileValue <= 512)
    {
        couleur.r = 208;
        couleur.g = 76;
        couleur.b = 252;
    }
    else if (tileValue <= 2048)
    {
        couleur.r = 74;
        couleur.g = 180;
        couleur.b = 255;
    }
    else
    {
        couleur.r = 165;
        couleur.g = 191;
        couleur.b = 209;
    }
    return couleur;
}

tabTextures *createTileTexture(SDL_Renderer *ren, tabTextures *tabTile, TTF_Font *font, int taille, int tileValue)
{
    SDL_Rect dst = {0, 0, 0, 0};
    int reduc = 0;
    char str[30];
    if (tabTile->tabTex == NULL)
    {
        tabTile->tabTex = (SDL_Texture **)malloc(sizeof(SDL_Texture *));
        tabTile->taille = 1;
        tileValue = 2;
    }
    else
    {
        tabTile->tabTex = (SDL_Texture **)realloc(tabTile->tabTex, sizeof(SDL_Texture *) * (tabTile->taille + 1));
        tabTile->taille++;
    }

    //Crée le texture du texte
    sprintf(str, "%d", tileValue);
    printf("%d\n", tileValue);
    SDL_Rect r = {0, 0, taille, taille};
    SDL_Color color = {255, 255, 255, 255};
    SDL_Surface *surface = TTF_RenderText_Blended(font, str, color);
    SDL_Texture *texNumber = SDL_CreateTextureFromSurface(ren, surface);

    //Crée la texture de support
    SDL_Texture *texTarget = SDL_CreateTexture(ren, SDL_PIXELFORMAT_UNKNOWN,
                                               SDL_TEXTUREACCESS_TARGET, taille, taille);
    SDL_Texture *texBackground = loadTexture("./src/assets/template.bmp", ren);
    SDL_Color couleur = setTileColor(tileValue);
    SDL_SetTextureColorMod(texBackground, couleur.r, couleur.g, couleur.b);

    //Reduit et place le au centre le nombre
    SDL_QueryTexture(texNumber, NULL, NULL, &dst.w, &dst.h);
    reduc = (dst.w / taille) + 1;
    dst.h = dst.h / reduc;
    dst.w = dst.w / reduc;
    dst.x = (r.w - dst.w) / 2;
    dst.y = (r.h - dst.h) / 2;

    //Fusionne le nombre a l'arriere plan
    SDL_SetRenderTarget(ren, texTarget);
    SDL_RenderClear(ren);
    SDL_RenderCopy(ren, texBackground, NULL, &r);
    SDL_RenderCopy(ren, texNumber, NULL, &dst);
    SDL_SetRenderTarget(ren, NULL);

    //Sauvegarde la texture
    tabTile->tabTex[tabTile->taille - 1] = texTarget;
    SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);

    SDL_DestroyTexture(texNumber);
    SDL_DestroyTexture(texBackground);
    SDL_FreeSurface(surface);
    return tabTile;
}

void renderTxt(SDL_Renderer *ren, const char *str, TTF_Font *font, int size, int x, int y)
{
    SDL_Rect dst;
    int reduc = 0;
    dst.x = x;
    dst.y = y;

    SDL_Color color = {255, 255, 255, 255};
    SDL_Surface *surface = TTF_RenderText_Blended(font, str, color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(ren, surface);
    SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);
    reduc = (dst.h / size);
    dst.h = dst.h / reduc;
    dst.w = dst.w / reduc;
    SDL_RenderCopy(ren, texture, NULL, &dst);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int h, int w)
{
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
    if (h != 0 && w != 0)
    {
        dst.w = w;
        dst.h = h;
    }
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
        jeu->jeuActif = ajouteCase(jeu);
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

void dessiner(SDL_Renderer *renderer, tabTextures *tabTex, etatJeu *jeu, TTF_Font *font)
{
    dessinePlateau(renderer, tabTex, jeu, font);
}

int calcLongeurUNb(int nb)
{
    int taille = 0;

    while (nb > 0)
    {
        taille++;
        nb = nb / 10;
    }
    return taille;
}

void dessinePlateau(SDL_Renderer *renderer, tabTextures *tabTex, etatJeu *jeu, TTF_Font *font)
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
                if (tabTex->tabTex == NULL || (tabTex->taille < (int)(log2(jeu->plateau->tab[int_y][int_x]))))
                {
                    tabTex = createTileTexture(renderer, tabTex, font, tailleCasePx, jeu->plateau->tab[int_y][int_x]);
                }
                renderTexture(tabTex->tabTex[(int)(log2(jeu->plateau->tab[int_y][int_x])) - 1], renderer, (int_x * (tailleCasePx + 4)) + decallageVert, (int_y * (tailleCasePx + 4)) + decallageVert, tailleCasePx, tailleCasePx);
            }
        }
    }
}
