/** @file renderSDL.h
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 09 Jun 2020 10:30
 *
 *  @brief
 *
 */

#ifndef __RENDERSDL_H__
/**
 *  @def __RENDERSDL_H__
 *  Constante permettant de savoirs si le fichier à déjà été chargé.
 */
#define __RENDERSDL_H__

#include "../jeu2048.h"
#include "textureManager.h"

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 12 May 2020 11:12
 *
 *  @brief
 *
 *  @param[in]
 *
 */
void renderTxt(SDL_Renderer *ren, const char *str, TTF_Font *font, int size, int x, int y);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 12 May 2020 11:12
 *
 *  @brief
 *
 *  @param[in]
 *
 */
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int h, int w);

#endif // __RENDERSDL_H__
