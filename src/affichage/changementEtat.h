/** @file changementEtat.h
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 10 Jun 2020 12:19
 *
 *  @brief
 *
 */

#ifndef __CHANGEMENTETAT_H__
/**
 *  @def __CHANGEMENTETAT_H__
 *  Constante permettant de savoirs si le fichier à déjà été chargé.
 */
#define __CHANGEMENTETAT_H__

#include "../jeu2048.h"
#include "textureManager.h"
#include "evenementSDL.h"

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 10 Jun 2020 12:15
 *
 *  @brief
 *
 *  @param[in]
 *  @return
 *
 */
void chargeEtat(int Etat, etatJeu *jeu, Buttons *Buttons, TextureBank *texBank, SDL_Renderer *ren);

#endif // __CHANGEMENTETAT_H__
