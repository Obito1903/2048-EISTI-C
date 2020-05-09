/** @file affichage.h
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sat 09 May 2020 17:04
 *
 *  @brief
 *
 */

#ifndef __AFFICHAGE_H__
/**
*  @def __AFFICHAGE_H__
*  Constante permettant de savoirs si le fichier à déjà été chargé.
*/
#define __AFFICHAGE_H__

#include "jeuBase.h"

/**
 *  @author William Meunier <william.meunier@eisti.eu>
 *  @version 0.1
 *  @date Sat 09 May 2020 17:15
 *
 *  @brief Affiche le plateau
 *
 *  @param[in,out] jeu : pointeur vers le plateau
 *
 */

void affichagePlateau(etatJeu *jeu);

#endif // __AFFICHAGE_H__
