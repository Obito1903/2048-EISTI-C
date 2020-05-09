/** @file affichage.c
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sat 09 May 2020 17:04
 *
 *  @brief
 *
 */

#include "affichage.h"

void affichagePlateau(etatJeu *jeu)
{
    int y;
    int x;

    for (y = 0; y < jeu->plateau->taille; y++)
    {
        for (x = 0; x < jeu->plateau->taille; x++)
        {
            if (jeu->plateau->tab[y][x] < 100)
            {
                printf("| %d   |", jeu->plateau->tab[y][x]);
            }
        }
        printf("\n");
    }
    printf("prout\n");
}
