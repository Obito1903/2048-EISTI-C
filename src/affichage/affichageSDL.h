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
 *  Constante permettant de savoir si le fichier a déjà été chargé.
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
 *  @brief Permet de contrôler la fréquence refraichissement de l'écran
 *
 *  @param[in] tmp: temps mis pour le rendu de la frame actuel
 *
 */
void frameControl(double tmp);

/**
 *  @author William Meunier <william.meunier@eisti.eu>
 *  @version 0.1
 *  @date Wed 10 Jun 2020 12:12
 *
 *  @brief Initialise la SDL et les modules associés
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
 *  @return La structure contenant tout ce qui est necessaire à l'affichage du jeu
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
 *  @param[in] EtatJeu : structure contenant l'état du jeu
 *
 */
void mainAffichage(etatJeu *EtatJeu);

/**
 *  @author William Meunier <william.meunier@eisti.eu>
 *  @version 0.1
 *  @date Tue 12 May 2020 11:12
 *
 *  @brief Fonction permettant d'appeler les fonctions de dessin spécifiques aux differents Etats du jeu
 *
 *  @param[in,out] Jeu : Structure contenant les données necessaire à l'affichage
 *
 */
void dessiner(jeu *Jeu);

/**
 *  @author William Meunier <william.meunier@eisti.eu>
 *  @version 0.1
 *  @date Thu 11 Jun 2020 15:01
 *
 *  @brief Dessines les boutons à l'écran
 *
 *  @param[in,out] Jeu : Structure contenant les données necessaire à l'affichage
 *
 */
void dessineBoutons(jeu *Jeu);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Fri 12 Jun 2020 13:57
 *
 *  @brief Lance la création des textures pour les cases dont la valeur n'a pas de texture associée
 *
 *  @param[in,out] Jeu : Structure contenant les données necessaire à l'affichage
 *  @param[in] valCase : valeur de la case dont la texture doit être créée
 *  @param[in] tailleCasePx : taille en pixel de la texture à créer
 *
 */
void creationTextureCase(jeu *Jeu, uint valCase, uint tailleCasePx);

/**
 *  @author William Meunier <william.meunier@eisti.eu>
 *  @version 0.1
 *  @date Tue 12 May 2020 12:29
 *
 *  @brief Dessine le plateau de jeu à l'écran
 *
 *  @param[in,out] Jeu : Structure contenant les données necessaire à l'affichage
 *
 */
void dessinePlateau(jeu *Jeu);

#endif // __AFFICHAGESDL_H__
