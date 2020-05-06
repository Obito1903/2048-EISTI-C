/** @file affichage.h
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 05 May 2020 23:49
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

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <termios.h>
#include <sys/select.h>
#include <fcntl.h>
#include "jeuBase.h"

struct termios orig_termios;

/**
 * @struct couleurPix
 * Couleur d'un pixel
 */
typedef struct
{
    /*!  */
    uint8 r;
    uint8 g;
    uint8 b;
} couleurPix;

/**
 * @struct pixel
 * Pixel de l'ecran de jeu
 */
typedef struct
{
    /*!  */
    couleurPix color;
    char element;
} pixelRGB;

/**
 * @struct screen
 * Stock l'écran de jeu
 */
typedef struct
{
    uint hauteur;
    uint largeur;
    pixelRGB **foreground;
    pixelRGB **background;
} screen;

/**
 * @struct tabStr
 * Tableau de chaine de caractères
 */
typedef struct
{
    /*!  */
    uint taille;
    uint hauteur;
    char **tab;
} tabStr;

typedef struct noeudListTabStr noeudListTabStr;
/**
 * @struct lListTabStr
 * Liste lié de tableau de chaine de caractère
 */
struct noeudListTabStr
{
    /*! pionteur vers element Precedent */
    noeudListTabStr *precedent;
    /*! pionteur vers element courant*/
    char *str;
    uint hauteur;
    Bool selection;

    /*! pionteur vers element Suivant */
    noeudListTabStr *suivant;
};

typedef noeudListTabStr lListTabStr;

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
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 06 May 2020 10:08
 *
 *  @brief Alloue l'espace memoir nécessaire a un écran
 *
 *  @param[in] hauteur : hauteur de l'écran
 *  @param[in] largeur : largeur de l'écran
 *  @return pointeur vers l'écran
 *
 */
screen *allocEcran(uint hauteur, uint largeur);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 06 May 2020 10:28
 *
 *  @brief libère l'espace memoire de l'écran
 *
 *  @param[in] Ecran : pointeur vers l'écran a libérer
 *
 */
void freeEcran(screen *Ecran);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 06 May 2020 10:35
 *
 *  @brief Initialise un ecran
 *
 *  @param[in]
 *
 */
void initEcran(screen *Ecran);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 06 May 2020 09:27
 *
 *  @brief Affiche l'écran
 *
 *  @param[in] Ecran : pointeur vers l'écran a afficher
 *  @return Vrais si l'écran a pu être afficher, Faux sinon
 *
 */
Bool afficheEcran(screen *Ecran);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 06 May 2020 11:28
 *
 *  @brief
 *
 *  @param[in]
 *
 */
uint __AfficheStringEcran(screen *Ecran, uint hauteur, char *strOrig, Bool selection);

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
void mainAffichage(void);

#endif // __AFFICHAGE_H__
