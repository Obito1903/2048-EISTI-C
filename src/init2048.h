/** @file init2048.c
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sat 09 May 2020 16:28
 *
 *  @brief
 *
 */

#ifndef __INIT2048_H__
/**
*  @def __INIT2048_H__
*  Constante permettant de savoirs si le fichier à déjà été chargé.
*/
#define __INIT2048_H__

#include "jeuBase.h"

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sat 09 May 2020 16:43
 *
 *  @brief Alloue l'espace memoire pour le jeu
 *
 *  @param[in] taille : taille du plateau
 *  @return pointeur vers le jeu
 *
 */
etatJeu *allocJeu(int taille);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sat 09 May 2020 16:39
 *
 *  @brief Initialise le jeu
 *
 *  @param[in] taille : taille du plateau de jeu
 *  @return pointeur vers le jeu
 *
 */
etatJeu *initJeu(int taille);

#endif // __INIT2048_H__
