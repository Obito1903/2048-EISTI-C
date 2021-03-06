/** @file evenementSDL.h
 *  @author Théo Paesa <theo.paesa@eisti.eu>
 *  @version 0.1
 *  @date Tue 09 Jun 2020 10:34
 *
 *  @brief
 *
 */

#ifndef __EVENEMENTSDL_H__
/**
 *  @def __EVENEMENTSDL_H__
 *  Constante permettant de savoir si le fichier a déjà été chargé.
 */
#define __EVENEMENTSDL_H__

#include <SDL2/SDL.h>

#include "../jeu2048.h"
#include "changementEtat.h"

/**
 *  @author Théo Paesa <theo.paesa@eisti.eu>
 *  @version 0.1
 *  @date Thu 11 Jun 2020 15:29
 *
 *  @brief Exectute la fonction associée au bouton cliqué
 *
 *  @param[in,out] Jeu : Structure contenant les données necessaire a l'affichage
 *  @param[in] idBouton : id du bouton qui doit etre executé
 *
 */
void execBouton(jeu *Jeu, uint idBouton);

/**
 *  @author Théo Paesa <theo.paesa@eisti.eu>
 *  @version 0.1
 *  @date Tue 12 May 2020 11:03
 *
 *  @brief Gére et execute les fonctions associées aux differents evenements
 *
 *  @param[in,out] Jeu : Structure contenant les données necessaire a l'affichage
 *  @param[in] event : evenement a traiter
 *
 */
void gestionEvenement(jeu *Jeu, SDL_Event *event);

/**
 *  @author Théo Paesa <theo.paesa@eisti.eu>
 *  @version 0.1
 *  @date Tue 12 May 2020 12:02
 *
 *  @brief Execute la fonction associée a la touche entrée en paramètre
 *
 *  @param[in,out] Jeu : Structure contenant les données necessaire a l'affichage
 *  @param[in] touche : id de la touche
 *
 */
void gestionTouche(jeu *Jeu, SDL_Keycode touche);

/**
 *  @author Théo Paesa <theo.paesa@eisti.eu>
 *  @version 0.1
 *  @date Tue 09 Jun 2020 10:52
 *
 *  @brief Execute la fonction associée au clique souris
 *
 *  @param[in,out] Jeu : Structure contenant les données necessaire a l'affichage
 *  @param[in] event : evenemet souris a traiter
 *
 */
void gestionCliqueSouris(jeu *Jeu, SDL_MouseButtonEvent *event);

#endif // __EVENEMENTSDL_H__
