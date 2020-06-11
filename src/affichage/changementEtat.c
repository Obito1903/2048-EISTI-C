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
	printf("BB\n");
	if (!buttons->tabButton) {
		printf("BBA\n");
		buttons->tabButton = (button **)malloc(sizeof(button *));
		buttons->nbButtons = 1;
	} else {
		printf("BBB\n");
		buttons->nbButtons++;
		buttons->tabButton =
			(button **)realloc(buttons->tabButton, sizeof(button *) * buttons->nbButtons);
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
 *  @date Wed 10 Jun 2020 12:15
 *
 *  @brief
 *
 *  @param[in]
 *  @return
 *
 */
void chargeEtat(int Etat, etatJeu *jeu, Buttons *Buttons, TextureBank *texBank, SDL_Renderer *ren)
{
	switch (Etat) {
		case 1:
			jeu->etatJeu = 1;

			texBank->bank[1]			= allocNewTexture(texBank->bank[1], NULL);
			texBank->bank[1]->tabTex[0] = loadTexture("./src/assets/template_background.png", ren);
			ajouteButton(Buttons, 800, 500, 50, "Sauvegarder");
			break;
		case 2:

		default:
			break;
	}
}
