/** @file changementEtat.c
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 10 Jun 2020 12:19
 *
 *  @brief
 *
 */

#include "changementEtat.h"

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

void chargeEtat(int Etat, jeu *Jeu)
{
	printf("Etat : %d", Etat);
	freeBoutons(Jeu->boutons);
	switch (Etat) {
		case VICTOIRE:
			Jeu->etatJeu->etatJeu = VICTOIRE;
			ajouteButton(Jeu->boutons, (Jeu->etatJeu->fenetreL / 2), (3 * Jeu->etatJeu->fenetreH) / 7,
						 Jeu->etatJeu->fenetreL / 30, "Victoire !");
			ajouteButton(Jeu->boutons, (Jeu->etatJeu->fenetreL / 2), (4 * Jeu->etatJeu->fenetreH) / 7,
						 Jeu->etatJeu->fenetreL / 30, "Continuer");
			ajouteButton(Jeu->boutons, (Jeu->etatJeu->fenetreL / 2), (5 * Jeu->etatJeu->fenetreH) / 7,
						 Jeu->etatJeu->fenetreL / 30, "Quitter");
			break;
		case JEU:
			Jeu->etatJeu->etatJeu = JEU;
			ajouteButton(Jeu->boutons, ((5 * Jeu->etatJeu->fenetreL) / 6) - (Jeu->etatJeu->fenetreL / 13),
						 Jeu->etatJeu->fenetreH / 2, Jeu->etatJeu->fenetreL / 25, "Sauvegarder");
			break;
		case PAUSE:
			Jeu->etatJeu->etatJeu = PAUSE;
			ajouteButton(Jeu->boutons, (Jeu->etatJeu->fenetreL / 2), (2 * Jeu->etatJeu->fenetreH) / 5,
						 Jeu->etatJeu->fenetreL / 25, "Sauvegarder");
			ajouteButton(Jeu->boutons, (Jeu->etatJeu->fenetreL / 2), (3 * Jeu->etatJeu->fenetreH) / 5,
						 Jeu->etatJeu->fenetreL / 25, "Quitter");
			break;
		case PERDU:
			Jeu->etatJeu->etatJeu = PERDU;
			ajouteButton(Jeu->boutons, (Jeu->etatJeu->fenetreL / 2), (3 * Jeu->etatJeu->fenetreH) / 5,
						 Jeu->etatJeu->fenetreL / 25, "Quitter");
			ajouteButton(Jeu->boutons, (Jeu->etatJeu->fenetreL / 2), (2 * Jeu->etatJeu->fenetreH) / 5,
						 Jeu->etatJeu->fenetreL / 25, "Perdu !");
			break;
		default:
			break;
	}
}
