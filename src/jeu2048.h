/** @file jeu2048.h
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sat 09 May 2020 16:56
 *
 *  @brief
 *
 */

#ifndef __JEU2048_H__
/**
*  @def __JEU2048_H__
*  Constante permettant de savoirs si le fichier à déjà été chargé.
*/
#define __JEU2048_H__

#include "jeuBase.h"

/** @fn int finPartie (etatJeu *jeu)
 *  @author William Meunier <william.meunier@eisti.eu>
 *  @version 0.1
 *  @date Sat 09 May 2020 17:48
 *
 *  @brief retourne 0 pour une partie gagné, retourne 1 pour une partie perdu.
 *
 *  @param
 *  @return
 *
 *  @remarks
 */

int finPartie(etatJeu *jeu);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sat 09 May 2020 18:19
 *
 *  @brief ajoute une case random entre 2 et 4 quand le joueur a fait un coup
 *
 *  @param[in]
 *
 */
void ajouteCase(etatJeu *jeu);

#endif // __JEU2048_H__
