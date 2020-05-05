/** @file main.h
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 05 May 2020 10:51
 *
 *  @brief Header de main.c
 *
 */

#ifndef __MAIN_H__
/**
*  @def __MAIN_H__
*  Constante permettant de savoirs si le fichier à déjà été chargé.
*/
#define __MAIN_H__

#include <stdio.h>
#include <stdlib.h>

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
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
int main(int argc, char const *argv[]);

#endif // __MAIN_H__
