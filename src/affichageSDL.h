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
void mainAffichage(void);

#endif // __AFFICHAGESDL_H__
