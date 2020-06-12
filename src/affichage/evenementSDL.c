/** @file evenementSDL.c
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 09 Jun 2020 10:34
 *
 *  @brief
 *
 */

#include "evenementSDL.h"

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Thu 11 Jun 2020 15:29
 *
 *  @brief
 *
 *  @param[in]
 *
 */
void execBouton(etatJeu *jeu, uint idBouton, Buttons *buttons)
{
	switch (jeu->etatJeu) {
		case JEU:
			switch (idBouton) {
				case 0:
					savJeu(jeu);
					break;

				default:
					break;
			}
			break;
		case VICTOIRE:
			switch (idBouton) {
				case 1:
					chargeEtat(2, jeu, buttons);
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
					savJeu(jeu);
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

void gestionEvenement(etatJeu *jeu, Buttons *buttons, SDL_Event *event)
{

	while (SDL_PollEvent(event)) {
		switch (event->type) {
			case SDL_QUIT:
				jeu->etatJeu = 0;
				break;
			case SDL_KEYDOWN:
				gestionTouche(jeu, buttons, event->key.keysym.sym);
				break;
			case SDL_MOUSEBUTTONDOWN:
				gestionCliqueSouris(jeu, buttons, &event->button);
				break;
			default:
				break;
		}
	}
}

void gestionTouche(etatJeu *jeu, Buttons *buttons, SDL_Keycode touche)
{
	uint deplacement = False;
	switch (touche) {
		case SDLK_ESCAPE:
			if (jeu->etatJeu == 2) {
				chargeEtat(PAUSE, jeu, buttons);
			} else {
				chargeEtat(JEU, jeu, buttons);
			}
			break;
		case SDLK_UP:
			deplacement = DirectionNord(jeu);
			break;
		case SDLK_DOWN:
			deplacement = DirectionSud(jeu);
			break;
		case SDLK_LEFT:
			deplacement = DirectionOuest(jeu);
			break;
		case SDLK_RIGHT:
			deplacement = DirectionEst(jeu);
			break;
		default:
			break;
	}

	if (deplacement) {
		finPartie(jeu);
		jeu->nbCoups++;
	}
	if (jeu->victoire == 1) {
		chargeEtat(jeu->victoire, jeu, buttons);
		jeu->victoire = 2;
	}
}

void gestionCliqueSouris(etatJeu *jeu, Buttons *buttons, SDL_MouseButtonEvent *event)
{
	uint	int_button;
	button *bouton;
	for (int_button = 0; int_button < buttons->nbButtons; int_button++) {
		bouton = buttons->tabButton[int_button];
		if (event->x > bouton->x - (bouton->w / 2) && event->y > bouton->y - (bouton->h / 2) && event->x < bouton->x + (bouton->w / 2) &&
			event->y < bouton->y + (bouton->h / 2)) {
			execBouton(jeu, int_button, buttons);
		}
	}
}
