/** @file jeuBase.h
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sat 09 May 2020 16:01
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

#include "../lib/samBase.h"
#include "../lib/samIO.h"
#include <string.h>

/**
 * @struct plateau
 * contient le plateau de jeu
 */
typedef struct
{
    /*! Tableau a deux dimension d'entier non signé */
    uint **tab;
    /*! taille du plateau */
    int taille;
} plateau;

/**
 * @struct etatJeu
 * Contient l'etat du jeu
 */
typedef struct
{
    /*! pointeur vers plateau  */
    plateau *plateau;
    /*! compteur du nombre de coups */
    uint nbCoups;
} etatJeu;

#endif // __JEUBASE_H__
