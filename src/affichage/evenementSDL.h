/** @file evenementSDL.h
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 09 Jun 2020 10:34
 *
 *  @brief
 *
 */

#ifndef __EVENEMENTSDL_H__
/**
 *  @def __EVENEMENTSDL_H__
 *  Constante permettant de savoirs si le fichier à déjà été chargé.
 */
#define __EVENEMENTSDL_H__

#include <SDL2/SDL.h>

#include "../jeu2048.h"

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

#endif // __EVENEMENTSDL_H__
