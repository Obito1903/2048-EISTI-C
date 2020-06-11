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
void execBouton(etatJeu *jeu, uint idBouton)
{
	switch (idBouton) {
		case 0:
			savJeu(jeu);
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
				jeu->etatJeu = False;
				break;
			case SDL_KEYDOWN:
				gestionTouche(jeu, event->key.keysym.sym);
				break;
			case SDL_MOUSEBUTTONDOWN:
				gestionCliqueSouris(jeu, buttons, &event->button);
				break;
			default:
				break;
		}
	}
}

void gestionTouche(etatJeu *jeu, SDL_Keycode touche)
{
	uint deplacement = False;
	switch (touche) {
		case SDLK_ESCAPE:
			jeu->etatJeu = False;
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
		jeu->etatJeu = ajouteCase(jeu);
		jeu->nbCoups++;
	}
}

void gestionCliqueSouris(etatJeu *jeu, Buttons *buttons, SDL_MouseButtonEvent *event)
{
	uint	int_button;
	button *bouton;
	for (int_button = 0; int_button < buttons->nbButtons; int_button++) {
		bouton = buttons->tabButton[int_button];
		if (event->x > bouton->x && event->y > bouton->y && event->x < bouton->x + bouton->w &&
			event->y < bouton->y + bouton->h) {
			execBouton(jeu, int_button);
		}
	}
}
