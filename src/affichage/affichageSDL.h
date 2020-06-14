/** @file affichageSDL.h
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 12 May 2020 10:04
 *
 *  @brief
 *
 */

#ifndef __AFFICHAGESDL_H__
/**
 *  @def __AFFICHAGESDL_H__
 *  Constante permettant de savoirs si le fichier à déjà été chargé.
 */
#define __AFFICHAGESDL_H__

#include <SDL2/SDL_video.h>
#include <math.h>
#include <time.h>

#include "renderSDL.h"
#include "evenementSDL.h"

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 12 May 2020 10:26
 *
 *  @brief Permet de controler la fréquence refraichissement de l'ecran
 *
 *  @param[in] tmp: temp mis pour le rendu de la frame actuel
 *
 */
void frameControl(double tmp);

/**
 *  @author William Meunier <william.meunier@eisti.eu>
 *  @version 0.1
 *  @date Wed 10 Jun 2020 12:12
 *
 *  @brief Initialise la SDL et les modules associé
 *
 */
void initSDL(void);

/**
 *  @author William Meunier <william.meunier@eisti.eu>
 *  @version 0.1
 *  @date Wed 10 Jun 2020 12:12
 *
 *  @brief Initialise l'affichage et la banque de texture
 *
 *  @param[in] EtatJeu : structure contenant l'etat du jeu
 *  @return La structure contenant tout ce qui est necaissaire a l'affichage du jeu
 *
 */
jeu *initAffichage(etatJeu *EtatJeu);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 12 May 2020 10:26
 *
 *  @brief Fonction principale de l'affichage
 *
 *  @param[in] EtatJeu : structure contenant l'etat du jeu
 *
 */
void mainAffichage(etatJeu *EtatJeu);

/**
 *  @author William Meunier <william.meunier@eisti.eu>
 *  @version 0.1
 *  @date Tue 12 May 2020 11:12
 *
 *  @brief Fonction permettant d'appeler les fonction de dessin specifique aux differents Etats du jeu
 *
 *  @param[in,out] Jeu : Structure contenant les donnés necaissaire a l'affichage
 *
 */
void dessiner(jeu *Jeu);

/**
 *  @author William Meunier <william.meunier@eisti.eu>
 *  @version 0.1
 *  @date Thu 11 Jun 2020 15:01
 *
 *  @brief Dessines les boutons a l'écran
 *
 *  @param[in,out] Jeu : Structure contenant les donnés necaissaire a l'affichage
 *
 */
void dessineBoutons(jeu *Jeu);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Fri 12 Jun 2020 13:57
 *
 *  @brief Lance la création des texture pour les case dont la valeurs n'a pas de texture associé
 *
 *  @param[in,out] Jeu : Structure contenant les donnés necaissaire a l'affichage
 *  @param[in] valCase : valeur de la case dont la texture doit être créé
 *  @param[in] tailleCasePx : taille en pixel de la texture a créer
 *
 */
void creationTextureCase(jeu *Jeu, uint valCase, uint tailleCasePx);

/**
 *  @author William Meunier <william.meunier@eisti.eu>
 *  @version 0.1
 *  @date Tue 12 May 2020 12:29
 *
 *  @brief Dessine le plateau de jeu a l'écran
 *
 *  @param[in,out] Jeu : Structure contenant les donnés necaissaire a l'affichage
 *
 */
void dessinePlateau(jeu *Jeu);

#endif // __AFFICHAGESDL_H__
