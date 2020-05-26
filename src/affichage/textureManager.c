/** @file textureManager.c
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 26 May 2020 10:17
 *
 *  @brief
 *
 */

#include "textureManager.h"

TTF_Font *findFont(int fontSize)
{
    TTF_Font *font = TTF_OpenFont("./src/consola.ttf", fontSize);
    if (font == NULL)
    {
        TTF_Font *font = TTF_OpenFont("./bin/src/consola.ttf", fontSize);
        if (font == NULL)
        {
            TTF_Font *font = TTF_OpenFont("./consola.ttf", fontSize);
            if (font == NULL)
            {
                printf("TTF_OpenFont Error: %s \n", TTF_GetError());
                exit(EXIT_FAILURE);
            }
        }
    }
    return font;
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

tabTextures *allocTileTexture(tabTextures *tabTile, int *tileValue)
{
    if (tabTile->tabTex == NULL)
    {
        tabTile->tabTex = (SDL_Texture **)malloc(sizeof(SDL_Texture *));
        tabTile->taille = 1;
        *tileValue = 2;
    }
    else
    {
        tabTile->tabTex = (SDL_Texture **)realloc(tabTile->tabTex, sizeof(SDL_Texture *) * (tabTile->taille + 1));
        tabTile->taille++;
    }
    return tabTile;
}

tabTextures *createTileTexture(SDL_Renderer *ren, tabTextures *tabTile, TTF_Font *font, int taille, int tileValue)
{
    SDL_Rect dst = {0, 0, 0, 0};
    int reduc = 0;
    char str[30];
    tabTile = allocTileTexture(tabTile, &tileValue);
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

    SDL_Texture *alpha_Mask = loadTexture("./src/assets/template.bmp", ren);

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

    SDL_SetRenderDrawBlendMode(ren, SDL_BLENDMODE_ADD);
    SDL_RenderCopy(ren, alpha_Mask, NULL, &dst);

    SDL_RenderCopy(ren, texBackground, NULL, &r);
    SDL_RenderCopy(ren, texNumber, NULL, &dst);

    //SDL_SetTextureBlendMode(alpha_Mask, SDL_BLENDMODE_ADD);

    SDL_SetRenderTarget(ren, NULL);

    //Sauvegarde la texture
    tabTile->tabTex[tabTile->taille - 1] = texTarget;
    SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);

    SDL_DestroyTexture(texNumber);
    SDL_DestroyTexture(texBackground);
    SDL_FreeSurface(surface);
    return tabTile;
}
