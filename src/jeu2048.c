/** @file jeu2048.c
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sat 09 May 2020 16:56
 *
 *  @brief
 *
 */

#include "jeu2048.h"

int finPartie(etatJeu *jeu)
{
	int retour = 1; // Variable de retour
	int y;
	int x;
	for (y = 0; y < jeu->plateau->taille; y++) {
		for (x = 0; x < jeu->plateau->taille; x++) {
			if (jeu->plateau->tab[x][y] == 2048) {
				printf("2048 !\n\r");
				retour = 2;
			}
			if ((retour == 1) && (jeu->plateau->tab[x][y] == 0)) {
				printf("Perdu !\n\r");
				retour = 0;
			}
		}
	}

	return (retour);
}

Bool ajouteCase(etatJeu *jeu)
{
	tabCoord *tCoord = (tabCoord *)malloc(sizeof(tabCoord));
	tCoord->lCoord	 = (coord *)malloc(sizeof(coord));
	tCoord->taille	 = 0;
	Bool  retour	 = False;
	coord coordActu;
	int	  int_y;
	int	  int_x;
	for (int_y = 0; int_y < jeu->plateau->taille; int_y++) {
		for (int_x = 0; int_x < jeu->plateau->taille; int_x++) {
			if (jeu->plateau->tab[int_y][int_x] == 0) {
				coordActu.x = int_x;
				coordActu.y = int_y;
				tCoord->taille++;
				tCoord->lCoord = (coord *)realloc(tCoord->lCoord, sizeof(coord) * tCoord->taille);
				tCoord->lCoord[tCoord->taille - 1] = coordActu;
			}
		}
	}
	if (tCoord->taille) {
		coord Case						  = tCoord->lCoord[rand() % tCoord->taille];
		jeu->plateau->tab[Case.y][Case.x] = ((rand() % 2) + 1) * 2;
		retour							  = True;
	}

	free(tCoord->lCoord);
	free(tCoord);
	return retour;
}
