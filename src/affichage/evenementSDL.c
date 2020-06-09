/** @file evenementSDL.c
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 09 Jun 2020 10:34
 *
 *  @brief
 *
 */

#include "evenementSDL.h"

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

void gestionEvenement(etatJeu *jeu, SDL_Event *event)
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
				gestionCliqueSouris(jeu, &event->button);
				break;
			default:
				break;
		}
	}
}

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 09 Jun 2020 10:52
 *
 *  @brief
 *
 *  @param[in]
 *
 */
void gestionCliqueSouris(jeu, SDL_MouseButtonEvent *event)
{
	switch (expression) {
		case /* constant-expression */:
			/* code */
			break;

		default:
			break;
	}
}

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 09 Jun 2020 10:44
 *
 *  @brief
 *
 *  @param[in]
 *  @return
 *
 */
Bool testMouseZone(param)
{
	Bool retour; // Variable de retour

	return (retour);
}
