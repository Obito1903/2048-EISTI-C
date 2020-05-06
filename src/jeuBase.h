/** @file jeuBase.h
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 06 May 2020 09:10
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

#include <stdio.h>
#include <stdlib.h>

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

#endif // __JEUBASE_H__
