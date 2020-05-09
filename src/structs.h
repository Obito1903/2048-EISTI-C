/** @file structs.h
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sat 09 May 2020 01:15
 *
 *  @brief
 *
 */

#ifndef __STRUCTS_H__
/**
*  @def __STRUCTS_H__
*  Constante permettant de savoirs si le fichier à déjà été chargé.
*/
#define __STRUCTS_H__

#include "affichageTerm.h"

/**
 * @struct plateau
 *
 */
typedef struct
{
    /*!  */
    uint **tab;
    uint taille;
} plateau;

/**
 * @struct tabMenu
 *
 */
typedef struct
{
    /*!  */
    lListTabStr **menus;
    uint taille;
} tabMenu;

/**
 * @struct etatJeu
 *
 */
typedef struct
{
    /*!  */
    screen *Ecran;
    lListTabStr *menuCourant;
    tabMenu *tabMenu;
    plateau *plateau;
    Bool actif;
} etatJeu;

#endif // __STRUCTS_H__
