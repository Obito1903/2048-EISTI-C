/** @file main.h
 *  @author Théo Paesa <theo.paesa@eisti.eu>
 *  @version 0.1
 *  @date Tue 05 May 2020 10:51
 *
 *  @brief Header de main.c
 *
 */

#ifndef __MAIN_H__
/**
*  @def __MAIN_H__
*  Constante permettant de savoir si le fichier a déjà été chargé.
*/
#define __MAIN_H__

#include "src/affichage/affichageSDL.h"
#include <time.h>
#include <unistd.h>

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 06 May 2020 14:10
 *
 *  @brief Traite les arguments passer en parametre de l'executable
 *
 *  @param[in] argc : nombre d'arguments
 *  @param[in] argv : Tableau d'arguments
 *
 */
void traitementArgs(int argc, char *argv[]);

/**
 *  @author William Meunier <william.meunier@eisti.eu>
 *  @version 0.1
 *  @date Tue 05 May 2020 10:58
 *
 *  @brief Fonction Principale
 *
 *  @param[in] argc
 *  @param[in] *argv[]
 *  @return EXIT_SUCCESS : le programme doit se terminer normalement
 *
 */
int main(int argc, char *argv[]);

#endif // __MAIN_H__
