/** @file samBase.h
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sat 09 May 2020 00:41
 *
 *  @brief Fonction et structures de base de samLib
 *
 */

#ifndef __SAMBASE_H__
/**
*  @def __SAMBASE_H__
*  Constante permettant de savoirs si le fichier à déjà été chargé.
*/
#define __SAMBASE_H__

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef unsigned char uint8;
typedef unsigned int uint;

/**
 * @enum err
 * Erreur
 */
typedef enum
{
    /*! Erreur d'alloc */
    alloc = 1
} err;

/**
 * @enum Bool
 * Boolean
 */
typedef enum
{
    /*! Valeur Faux (0) */
    False,
    /*! Valeur (1) */
    True
} Bool;

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 06 May 2020 10:14
 *
 *  @brief Affiche les message d'erreur
 *
 *  @param[in] erreur : id de l'erreur
 *  @param[in] msg : message d'erreur à afficher
 *
 */
void erreur(err erreur, char *msg);

/**
 *
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sat 09 May 2020 00:44
 *
 *  @brief Test si un pointeur a bien etait alloué
 *
 *  @param[in] test : pointeur a tester
 *  @param[in] msg : message a afficher en cas d'erreur
 *
 */
void testAlloc(void *test, char *msg);

#endif // __SAMBASE_H__
