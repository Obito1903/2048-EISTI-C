/** @file changementEtat.h
 *  @author Théo Paesa <theo.paesa@eisti.eu>
 *  @version 0.1
 *  @date Wed 10 Jun 2020 12:19
 *
 *  @brief
 *
 */

#ifndef __CHANGEMENTETAT_H__
/**
 *  @def __CHANGEMENTETAT_H__
 *  Constante permettant de savoir si le fichier à déjà été chargé.
 */
#define __CHANGEMENTETAT_H__

#include "../jeu2048.h"
#include "textureManager.h"

/**
 * @struct button
 * Contient les informations pour pouvoir afficher un bouton et connaître son emplacement
 */
typedef struct
{
	/*! Position en x et y sur l'écran */
	int x;
	int y;
	/*! Taille de la police du texte à l'interieur */
	int size;
	/*! Taille du bouton */
	int h;
	int w;
	/*! Texte à afficher à l'interieur du bouton */
	char *texte;
} button;

/**
 * @struct tabButton
 * Tableau de bouton
 */
typedef struct
{
	/*! Tableau de pointeur vers des boutons*/
	button **tabButton;
	/*! Taille du tableau*/
	uint nbButtons;
} Buttons;

typedef struct
{
	etatJeu *	  etatJeu;
	SDL_Window *  window;
	SDL_Renderer *renderer;
	TTF_Font *	  font;
	TextureBank * TextureBank;
	Buttons *	  boutons;
} jeu;

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 10 Jun 2020 12:41
 *
 *  @brief Créé un nouveau bouton et l'ajoute au tableau de boutons
 *
 *  @param[in,out] boutons : tableau de bouton
 *  @param[in] x : position du centre en x sur l'écran
 *  @param[in] y : position du centre en y sur l'écran
 *  @param[in] texte : texte a afficher dans le bouton
 *
 */
void ajouteButton(Buttons *boutons, uint x, uint y, uint size, char *texte);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Fri 12 Jun 2020 14:24
 *
 *  @brief Supprime les boutons dans le tableau
 *
 *  @param[in,out] tableau de boutons
 *
 */
void freeBoutons(Buttons *Buttons);

/**
 *  @author Théo Paesa <theo.paesa@eisti.eu>
 *  @version 0.1
 *  @date Wed 10 Jun 2020 12:15
 *
 *  @brief Charge l'etat du jeu demandé
 *
 * 	@param[in] Etat : id de l'etat vers lequel changé
 *  @param[in,out] Jeu : Structure contenant les données necessaire a l'affichage
 *
 */
void chargeEtat(int Etat, jeu *Jeu);

#endif // __CHANGEMENTETAT_H__
