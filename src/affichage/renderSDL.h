/** @file renderSDL.h
 *  @author Hugo Mosser <hugomosser@eisti.eu>
 *  @version 0.1
 *  @date Tue 09 Jun 2020 10:30
 *
 *  @brief
 *
 */

#ifndef __RENDERSDL_H__
/**
 *  @def __RENDERSDL_H__
 *  Constante permettant de savoirs si le fichier à déjà été chargé.
 */
#define __RENDERSDL_H__

#include "../jeu2048.h"
#include "changementEtat.h"

/**
 *  @author Hugo Mosser <hugomosser@eisti.eu>
 *  @version 0.1
 *  @date Tue 12 May 2020 11:12
 *
 *  @brief Réalise le rendu d'un texte sur l'écran
 *
 *  @param[in,out] renderer : Ecran vers lequel faire le rendu
 *  @param[in] str : texte a affiché
 *  @param[in] font : Police a utiliser
 *  @param[in] taille : taille de la police a utiliser
 *  @param[in] x : position horizontal du texte sur l'ecran
 *  @param[in] y : position vertical du texte sur l'écran
 *
 */
void renderTexte(SDL_Renderer *renderer, const char *str, TTF_Font *font, int taille, int x, int y);

/**
 *  @author Hugo Mosser <hugomosser@eisti.eu>
 *  @version 0.1
 *  @date Tue 12 May 2020 11:12
 *
 *  @brief Réalise le rendu d'une texture a l'écran
 *
 *  @param[in] texture : texture a affiché
 *  @param[in,out] renderer : Ecran vers lequel faire le rendu
 *  @param[in] x : position horizontal du texte sur l'ecran
 *  @param[in] y : position vertical du texte sur l'écran
 *  @param[in] h : taille horizontal
 *  @param[in] w : taille vertical
 *
 */
void renderTexture(SDL_Texture *texture, SDL_Renderer *renderer, int x, int y, int h, int w);

/**
 *  @author Hugo Mosser <hugomosser@eisti.eu>
 *  @version 0.1
 *  @date Wed 10 Jun 2020 12:31
 *
 *  @brief Réalise le rendu d'un bouton
 *
 *  @param[in] bouton : bouton a afficher
 *  @param[in,out] renderer : Ecran vers lequel faire le rendu
 *  @param[in] font : police avec laquel afficher le texte
 *
 */
void renderButtons(button *bouton, SDL_Renderer *renderer, TTF_Font *font);

#endif // __RENDERSDL_H__
