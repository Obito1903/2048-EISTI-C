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

#include <SDL2/SDL_video.h>
#include <math.h>
#include <time.h>

#include "renderSDL.h"
#include "evenementSDL.h"

#define FENETRE_H 720
#define FENETRE_L 1280

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
void dessiner(SDL_Renderer *renderer, TextureBank *TexBank, etatJeu *jeu, TTF_Font *font, Buttons *buttons);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Thu 11 Jun 2020 15:01
 *
 *  @brief
 *
 *  @param[in]
 *
 */
void dessineBoutons(SDL_Renderer *renderer, TTF_Font *font, Buttons *buttons);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 12 May 2020 12:29
 *
 *  @brief
 *
 *  @param[in]
 *
 */
void dessineFin(SDL_Renderer *renderer, TextureBank *TexBank, etatJeu *jeu, TTF_Font *font, Buttons *buttons);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Fri 12 Jun 2020 13:57
 *
 *  @brief
 *
 *  @param[in]
 *
 */
void creationCase(SDL_Renderer *renderer, TextureBank *TexBank, uint valCase, TTF_Font *font, uint tailleCasePx);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 12 May 2020 12:29
 *
 *  @brief
 *
 *  @param[in]
 *
 */
void dessinePlateau(SDL_Renderer *renderer, TextureBank *TexBank, etatJeu *jeu, TTF_Font *font);

#endif // __AFFICHAGESDL_H__
