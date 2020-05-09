/** @file gestionAffichage.h
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Fri 08 May 2020 19:07
 *
 *  @brief
 *
 */

#ifndef __GESTIONAFFICHAGE_H__
/**
*  @def __GESTIONAFFICHAGE_H__
*  Constante permettant de savoirs si le fichier à déjà été chargé.
*/
#define __GESTIONAFFICHAGE_H__

#include "structs.h"

//------------Definition menu accueil-----------//

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Fri 08 May 2020 19:11
 *
 *  @brief initialise le menu d'accueil
 *
 *  @return liste des chaine a afficher
 *
 */
lListTabStr *initAccueil(etatJeu *jeu);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Fri 08 May 2020 19:32
 *
 *  @brief execute la commande demandé dans le menu Accueil
 *
 *  @param[in,out] listeCurrent : pointeur vers la liste de chaine actuellement affiché
 *  @param[in] commande : commande a afficher
 *
 */
void executeAccueil(etatJeu *jeu, int commande);

//------------------------------------------------//

//---------------------Infos---------------------//

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Fri 08 May 2020 19:11
 *
 *  @brief initialise l'affichage des infos
 *
 *  @return liste des chaine a afficher
 *
 */
lListTabStr *initInfos(etatJeu *jeu);

//------------------------------------------------//

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Fri 08 May 2020 19:24
 *
 *  @brief Execute la commande associer a la chaine du menu actuel
 *
 *  @param[in,out] listeCurrent : pointeur vers la liste de chaine affiché
 *
 */
void executeMenu(etatJeu *jeu);

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
 *  @date Wed 06 May 2020 21:25
 *
 *  @brief
 *
 *  @param[in]
 *
 */
void mainAffichage(etatJeu *jeu);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sat 09 May 2020 12:50
 *
 *  @brief
 *
 *  @param[in]
 *
 */
lListTabStr *convertPlateau(etatJeu *jeu);

#endif // __GESTIONAFFICHAGE_H__
