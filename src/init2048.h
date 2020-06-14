/** @file init2048.c
 *  @author William Meunier <william.meunier@eisti.eu>
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
#include "jeu2048.h"
#include <sys/types.h>
#include <sys/stat.h>

/**
 *  @author William Meunier <william.meunier@eisti.eu>
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
 *  @author William Meunier <william.meunier@eisti.eu>
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

/**
 *  @author William Meunier <william.meunier@eisti.eu>
 *  @version 0.1
 *  @date Sun 10 May 2020 16:04
 *
 *  @brief libère l'espace memoire du jeu
 *
 *  @param[in] jeu : pointeur vers le jeu
 *
 */
void freeJeu(etatJeu *jeu);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sun 10 May 2020 16:08
 *
 *  @brief Sauvegarde le jeu dans un fichier
 *
 *  @param[in] jeu : pointeur ver le jeu a sauvegarder
 *
 */
void savJeu(etatJeu *jeu);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sun 10 May 2020 16:22
 *
 *  @brief
 *
 *  @param[in] chemin : chemin vers la sauvegarde
 *  @return pointeur vers le jeu chargé
 *
 */
etatJeu *chargeJeu(char *chemin);

#endif // __INIT2048_H__
