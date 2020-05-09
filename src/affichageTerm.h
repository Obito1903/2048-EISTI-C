/** @file affichageTerm.h
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 05 May 2020 23:49
 *
 *  @brief Header de gestionAffichage
 *
 */

#ifndef __AFFICHAGE_TERM_H__
/**
*  @def __GESTION_AFFICHAGE_H__
*  Constante permettant de savoirs si le fichier à déjà été chargé.
*/
#define __AFFICHAGE_TERM_H__

#include "../lib/samBase.h"
#include <string.h>
#include <termios.h>
#include <sys/select.h>
#include <fcntl.h>

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
    uint id;
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
 *  @param[in,out] Ecran : pointeur vers l'écran a initialiser
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
 *  @date Wed 06 May 2020 11:49
 *
 *  @brief divise la chaine de caractères en plusieur chaine si
 * la chaine est plus longue que l'ecran
 *
 *  @param[in] lMax : longeur max que peut prendre un chaine
 *  @param[in] str : chaine a diviser
 *  @return un tableau contenant les sous chaines
 *
 */
tabStr *divString(uint lMax, char *str);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 06 May 2020 11:28
 *
 *  @brief ajoute les chaine de caractère a l'affichage
 *
 *  @param[in,out] Ecran : Pointeur vers l'écran
 *  @param[in] hauteur : position ou afficher la string
 *  @param[in] strOrig : la chaine a afficher
 *  @param[in] selection : l'etat de selection de la chaine
 *  @return Le nombre de ligne pris par la chaine
 *
 */
uint __AfficheStringEcran(screen *Ecran, uint hauteur, char *strOrig, Bool selection);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 06 May 2020 16:59
 *
 *  @brief Affiche la liste de chaine a l'écran
 *
 *  @param[in,out] Ecran : pointeur vers l'écran
 *  @param[in] listtStr : La liste de chaine a afficher
 *
 */
void affichesListeStringEcran(screen *Ecran, lListTabStr *listeStr);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 06 May 2020 17:10
 *
 *  @brief alloue et initialise un noeud d'un liste de chaine
 *
 *  @param[in] hauteur : hauteur de la chaine a ajouter
 *  @param[in] str : chaine a ajouter
 *  @return le noeud créé
 *
 */
noeudListTabStr *allocNoeudListTabStr(uint hauteur, char *str, uint id);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 06 May 2020 17:08
 *
 *  @brief Ajoute un chaine a une liste de chaine
 *
 *  @param[in,out] liste : pointeur vers la liste ou ajouté la chaine
 *  @param[in] hauteur : position de la nouvel chaine
 *  @param[in] str : chaine a ajouter
 *  @param[in] selection : si la chaine ajouter est selectione ou pas
 *
 */
void ajouteStringListe(lListTabStr *liste, uint hauteur, char *str, Bool selection, uint id);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 06 May 2020 21:34
 *
 *  @brief Trouve la chaine actuellement selectioné dans la liste
 *
 *  @param[in] liste : pointeur vers la liste
 *  @return pointeur vers la chaine selctionné
 *
 */
noeudListTabStr *trouveStrSelection(lListTabStr *liste);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 06 May 2020 21:26
 *
 *  @brief Change la chaine selctionné dans une liste
 *
 *  @param[in,out] liste : pointeur vers la liste
 *  @param[in] direction : direction de la prochaine selection (0 pour suivante, 1 pour la precdente)
 *
 */
void changeSelection(lListTabStr *liste, int direction);

#endif // __AFFICHAGE_H__
