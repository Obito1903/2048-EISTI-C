/** @file changementEtat.c
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 10 Jun 2020 12:19
 *
 *  @brief
 *
 */

#include "changementEtat.h"

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 10 Jun 2020 12:41
 *
 *  @brief
 *
 *  @param[in]
 *
 */
void ajouteButton(Buttons *buttons, uint x, uint y, uint size, char *texte)
{
	if (!buttons->tabButton) {
		buttons->tabButton = (button **)malloc(sizeof(button *));
		buttons->nbButtons = 1;
	} else {
		buttons->nbButtons++;
		buttons->tabButton = (button **)realloc(buttons->tabButton, sizeof(button *) * buttons->nbButtons);
	}
	buttons->tabButton[buttons->nbButtons - 1]		  = (button *)malloc(sizeof(button));
	buttons->tabButton[buttons->nbButtons - 1]->x	  = x;
	buttons->tabButton[buttons->nbButtons - 1]->y	  = y;
	buttons->tabButton[buttons->nbButtons - 1]->w	  = 0;
	buttons->tabButton[buttons->nbButtons - 1]->h	  = 0;
	buttons->tabButton[buttons->nbButtons - 1]->size  = size;
	buttons->tabButton[buttons->nbButtons - 1]->texte = texte;
}

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Fri 12 Jun 2020 14:24
 *
 *  @brief
 *
 *  @param[in]
 *
 */
void freeBoutons(Buttons *Buttons)
{
	uint int_bouton;
	for (int_bouton = 0; int_bouton < Buttons->nbButtons; int_bouton++) {
		free(Buttons->tabButton[int_bouton]);
	}
	free(Buttons->tabButton);
	Buttons->nbButtons = 0;
	Buttons->tabButton = NULL;
}

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 10 Jun 2020 12:15
 *
 *  @brief
 *
 *  @param[in]
 *  @return
 *
 */
void chargeEtat(int Etat, etatJeu *jeu, Buttons *Buttons)
{
	printf("Etat : %d", Etat);
	freeBoutons(Buttons);
	switch (Etat) {
		case VICTOIRE:
			jeu->etatJeu = VICTOIRE;
			ajouteButton(Buttons, (jeu->fenetreL / 2), (3 * jeu->fenetreH) / 7, jeu->fenetreL / 30, "Victoire !");
			ajouteButton(Buttons, (jeu->fenetreL / 2), (4 * jeu->fenetreH) / 7, jeu->fenetreL / 30, "Continuer");
			ajouteButton(Buttons, (jeu->fenetreL / 2), (5 * jeu->fenetreH) / 7, jeu->fenetreL / 30, "Quitter");
			break;
		case JEU:
			jeu->etatJeu = JEU;
			ajouteButton(Buttons, ((5 * jeu->fenetreL) / 6) - (jeu->fenetreL / 13), jeu->fenetreH / 2, jeu->fenetreL / 25, "Sauvegarder");
			break;
		case PAUSE:
			jeu->etatJeu = PAUSE;
			ajouteButton(Buttons, (jeu->fenetreL / 2), (2 * jeu->fenetreH) / 5, jeu->fenetreL / 25, "Sauvegarder");
			ajouteButton(Buttons, (jeu->fenetreL / 2), (3 * jeu->fenetreH) / 5, jeu->fenetreL / 25, "Quitter");
			break;
		case PERDU:
			jeu->etatJeu = PERDU;
			ajouteButton(Buttons, (jeu->fenetreL / 2), (3 * jeu->fenetreH) / 5, jeu->fenetreL / 25, "Quitter");
			ajouteButton(Buttons, (jeu->fenetreL / 2), (2 * jeu->fenetreH) / 5, jeu->fenetreL / 25, "Perdu !");
			break;
		default:
			break;
	}
}
