/** @file textureManager.h
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 26 May 2020 10:17
 *
 *  @brief
 *
 */

#ifndef __TEXTUREMANAGER_H__
/**
*  @def __TEXTUREMANAGER_H__
*  Constante permettant de savoirs si le fichier à déjà été chargé.
*/
#define __TEXTUREMANAGER_H__

#define FONTSIZE 200

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

typedef struct
{
    SDL_Texture **tabTex;
    int taille;
} tabTextures;

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 26 May 2020 10:21
 *
 *  @brief
 *
 *  @param[in]
 *  @return
 *
 */
TTF_Font *findFont(int fontSize);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 26 May 2020 10:21
 *
 *  @brief
 *
 *  @param[in]
 *  @return
 *
 */
SDL_Texture *loadTexture(const char *file, SDL_Renderer *ren);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 26 May 2020 10:21
 *
 *  @brief
 *
 *  @param[in]
 *  @return
 *
 */
SDL_Color setTileColor(int tileValue);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 26 May 2020 10:21
 *
 *  @brief
 *
 *  @param[in]
 *  @return
 *
 */
tabTextures *allocTileTexture(tabTextures *tabTile, int *tileValue);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 26 May 2020 10:21
 *
 *  @brief
 *
 *  @param[in]
 *  @return
 *
 */
tabTextures *createTileTexture(SDL_Renderer *ren, tabTextures *tabTile, TTF_Font *font, int taille, int tileValue);

#endif // __TEXTUREMANAGER_H__
