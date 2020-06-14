/** @file evenementSDL.c
 *  @author Théo Paesa <theo.paesa@eisti.eu>
 *  @version 0.1
 *  @date Tue 09 Jun 2020 10:34
 *
 *  @brief
 *
 */

#include "evenementSDL.h"

void execBouton(jeu *Jeu, uint idBouton)
{
	switch (Jeu->etatJeu->etatJeu) {
		case JEU:
			switch (idBouton) {
				case 0:
					savJeu(Jeu->etatJeu);
					break;

				default:
					break;
			}
			break;
		case VICTOIRE:
			switch (idBouton) {
				case 1:
					chargeEtat(2, Jeu);
					break;
				case 2:
					printf("Fin du jeu\n");
					exit(EXIT_SUCCESS);
					break;
				default:
					break;
			}
			break;
		case PAUSE:
			switch (idBouton) {
				case 0:
					savJeu(Jeu->etatJeu);
					break;
				case 1:
					printf("Fin du jeu\n");
					exit(EXIT_SUCCESS);
					break;
				default:
					break;
			}
			break;
		case PERDU:
			printf("Fin du jeu\n");
			exit(EXIT_SUCCESS);
			break;
		default:
			break;
	}
}

void gestionEvenement(jeu *Jeu, SDL_Event *event)
{

	while (SDL_PollEvent(event)) {
		switch (event->type) {
			case SDL_QUIT:
				Jeu->etatJeu->etatJeu = 0;
				break;
			case SDL_KEYDOWN:
				gestionTouche(Jeu, event->key.keysym.sym);
				break;
			case SDL_MOUSEBUTTONDOWN:
				gestionCliqueSouris(Jeu, &event->button);
				break;
			default:
				break;
		}
	}
}

void gestionTouche(jeu *Jeu, SDL_Keycode touche)
{
	uint deplacement = False;
	switch (touche) {
		case SDLK_ESCAPE:
			if (Jeu->etatJeu->etatJeu == 2) {
				chargeEtat(PAUSE, Jeu);
			} else {
				chargeEtat(JEU, Jeu);
			}
			break;
		case SDLK_UP:
			deplacement = DirectionNord(Jeu->etatJeu);
			break;
		case SDLK_DOWN:
			deplacement = DirectionSud(Jeu->etatJeu);
			break;
		case SDLK_LEFT:
			deplacement = DirectionOuest(Jeu->etatJeu);
			break;
		case SDLK_RIGHT:
			deplacement = DirectionEst(Jeu->etatJeu);
			break;
		default:
			break;
	}

	if (deplacement) {
		finPartie(Jeu->etatJeu);
		Jeu->etatJeu->nbCoups++;
	}
	if (Jeu->etatJeu->victoire == 1 || Jeu->etatJeu->victoire == -1) {
		chargeEtat(Jeu->etatJeu->victoire, Jeu);
		Jeu->etatJeu->victoire = 2;
	}
}

void gestionCliqueSouris(jeu *Jeu, SDL_MouseButtonEvent *event)
{
	uint	int_button;
	button *bouton;
	for (int_button = 0; int_button < Jeu->boutons->nbButtons; int_button++) {
		bouton = Jeu->boutons->tabButton[int_button];
		if (event->x > bouton->x - (bouton->w / 2) && event->y > bouton->y - (bouton->h / 2) &&
			event->x < bouton->x + (bouton->w / 2) && event->y < bouton->y + (bouton->h / 2)) {
			execBouton(Jeu, int_button);
		}
	}
}
