/** @file affichageSDL.h
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 12 May 2020 10:04
 *
 *  @brief
 *
 */

#ifndef __AFFICHAGESDL_H__
/**
*  @def __AFFICHAGESDL_H__
*  Constante permettant de savoirs si le fichier à déjà été chargé.
*/
#define __AFFICHAGESDL_H__

#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>

#include "jeu2048.h"

typedef struct
{
    SDL_Texture **tabTex;
    int taille;
} tabTextures;

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 12 May 2020 10:26
 *
 *  @brief Fonction principale de l'affichage
 *
 *  @param[in]
 *
 */
void mainAffichage(etatJeu *jeu);

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
SDL_Texture *loadTexture(const char *file, SDL_Renderer *ren);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 12 May 2020 11:47
 *
 *  @brief
 *
 *  @param[in]
 *  @return
 *
 */
tabTextures *chargeTextures(SDL_Renderer *ren);

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
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 12 May 2020 12:02
 *
 *  @brief
 *
 *  @param[in]
 *
 */
void gestionTouche(etatJeu *jeu, SDL_Keycode touche);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 12 May 2020 11:03
 *
 *  @brief
 *
 *  @param[in]
 *
 */
void gestionEvenement(etatJeu *jeu, SDL_Event *event);

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
void dessiner(SDL_Renderer *renderer, tabTextures *tabTex, etatJeu *jeu);

#endif // __AFFICHAGESDL_H__
