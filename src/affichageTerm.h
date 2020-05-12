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

#include <termios.h>
#include <string.h>
#include <sys/select.h>
#include <fcntl.h>
#include "jeuBase.h"

struct termios orig_termios;

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 06 May 2020 09:14
 *
 *  @brief Reinitialise le mode d'affichage du terminal
 *
 */
void reset_terminal_mode(void);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 06 May 2020 09:14
 *
 *  @brief Change le mode du terminal pour pouvoir desactiver les getchar blocquant
 *
 */
void set_conio_terminal_mode(void);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 06 May 2020 09:14
 *
 *  @brief Verifie si une entré clavier est faite
 *
 *  @return vrai si une entré est detecter, faux sinon
 *
 */
int kbhit(void);

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
