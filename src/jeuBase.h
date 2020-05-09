/** @file jeuBase.h
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 06 May 2020 09:10
 *
 *  @brief
 *
 */

#ifndef __JEUBASE_H__
/**
*  @def __JEUBASE_H__
*  Constante permettant de savoirs si le fichier à déjà été chargé.
*/
#define __JEUBASE_H__

#include "structs.h"
#include "gestionAffichage.h"

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sat 09 May 2020 00:38
 *
 *  @brief alloue l'espace memoire pour le jeu
 *
 *  @param[in] taille : taille du plateau
 *  @return pointeur vers le jeu
 *
 */
etatJeu *allocJeu(uint taille);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sat 09 May 2020 00:35
 *
 *  @brief initialise le jeu
 *
 *  @param[in] taille : taille du plateau
 *  @return pointeur vers le jeu
 *
 */
etatJeu *initJeu(uint taille);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sat 09 May 2020 01:19
 *
 *  @brief libère l'espace memoir du jeu
 *
 *  @param[in] jeu : pointeur vers le jeu
 *
 */
void freeJeu(etatJeu *jeu);

#endif // __JEUBASE_H__
