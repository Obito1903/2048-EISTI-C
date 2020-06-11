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
#include "deplacement.h"
#include "init2048.h"

/**
 * @struct coord
 * Stock des coordonées 2D
 */
typedef struct
{
	/*! Coord x */
	int x;
	/*! Coord y */
	int y;
} coord;

/**
 * @struct tabCoord
 * Stock un tableau de coordonées
 */
typedef struct
{
	/*! tableau de coord */
	coord *lCoord;
	/*! taille du tableau */
	int taille;
} tabCoord;
//#include "affichage.h"

/** @fn int finPartie (etatJeu *jeu)
 *  @author William Meunier <william.meunier@eisti.eu>
 *  @version 0.1
 *  @date Sat 09 May 2020 17:48
 *
 *  @brief Test les condition de fin de partie
 *
 *  @param[in] jeu : pointeur vers le jeu
 *  @return 1 si le plateau est plein, 2 si la partie est gagné, 0 si la partie continue
 *
 */

int finPartie(etatJeu *jeu);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sat 09 May 2020 18:19
 *
 *  @brief ajoute une case random entre 2 et 4 quand le joueur a fait un coup
 *
 *  @param[in,out] jeu : pointeur vers le jeu
 *
 */
uint ajouteCase(etatJeu *jeu);

#endif // __JEU2048_H__
