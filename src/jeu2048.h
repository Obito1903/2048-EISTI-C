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

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 06 May 2020 23:25
 *
 *  @brief Test les entrées utilisateurs et renvoi l'indice de la commande associé
 *
 *  @return indice de la commande associé avec l'entré
 *
 */
int testKey(void);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Fri 08 May 2020 19:15
 *
 *  @brief Execute la commande associé avec l'entrer utilisateur
 *
 *  @param[in,out] listeCurrent :pointeur vers la liste de chaine affiché
 *  @param[in] commande : indice de la commande associé a l'entré effectué
 *
 */
void executeCmd(etatJeu *jeu, int commande);

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
Bool ajouteCase(etatJeu *jeu);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sun 10 May 2020 15:40
 *
 *  @brief Execute une partie
 *
 *  @param[in,out] jeu : pointeur vers le jeu
 *
 */
void executeJeu(etatJeu *jeu);

#endif // __JEU2048_H__
