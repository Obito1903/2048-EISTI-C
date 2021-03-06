/** @file deplacement.h
 *  @author William Meunier <william.meunier@eisti.eu>
 *  @version 0.1
 *  @date Sat 09 May 2020 16:53
 *
 *  @brief
 *
 */

#ifndef __DEPLACEMENT_H__
/**
 *  @def __DEPLACEMENT_H__
 *  Constante permettant de savoir si le fichier a déjà été chargé.
 */
#define __DEPLACEMENT_H__

#include "jeuBase.h"

/**
 * @enum direction
 * direction
 */
typedef enum
{
	/*! Direction Nord */
	D_NORD = 0,
	/*! Direction SUD */
	D_SUD = 1,
	/*! Direction EST */
	D_EST = 2,
	/*! Direction OUEST */
	D_OUEST = 3
} direction;

/**
 *  @author Théo Paesa <theo.paesa@eisti.eu>
 *  @version 0.1
 *  @date Sat 09 May 2020 17:01
 *
 *  @brief commande pour direction "balayage" vers le haut (Nord)
 *
 *  @param[in,out] jeu : pointeur vers le plateau
 *
 */
uint DirectionNord(etatJeu *jeu);

/**
 *  @author Hugo Mosser <hugomosser@eisti.eu>
 *  @version 0.1
 *  @date Sat 09 May 2020 17:06
 *
 *  @brief commande pour direction "balayage" vers le bas (Sud)
 *
 *  @param[in,out] jeu : pointeur vers le plateau
 *
 *
 */
uint DirectionSud(etatJeu *jeu);

/**
 *  @author Théo Paesa <theo.paesa@eisti.eu>
 *  @version 0.1
 *  @date Sat 09 May 2020 17:54
 *
 *  @brief commande pour direction "balayage" vers la droite (Est)
 *
 *  @param[in,out] jeu : pointeur vers le plateau
 *
 */
uint DirectionEst(etatJeu *jeu);

/**
 *  @author Hugo Mosser<mosserhugo@eisti.eu>
 *  @version 0.1
 *  @date Sat 09 May 2020 17:59
 *
 *  @brief commande pour direction "balayage" vers la gauche (Ouest)
 *
 *  @param[in,out] jeu : pointeur vers le plateau
 *
 *
 */
uint DirectionOuest(etatJeu *jeu);

#endif // __DEPLACEMENT_H__
