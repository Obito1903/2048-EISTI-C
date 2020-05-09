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
    int retour = 0; // Variable de retour
    int y;
    int x;
    int temp;
    for (y = 0; y < jeu->plateau->taille; y++)
    {
        for (x = 0; x < jeu->plateau->taille; x++)
        {
            if (jeu->plateau->tab[x][y] == 2048)
            {
                retour = 1;
            }
            if (jeu->plateau->tab[x][y] == 0)
            {
                retour = 2;
            }
        }
    }

    return (retour);
}

void ajouteCase(etatJeu *jeu)
{
    Bool place = False;
    while (!place)
    {
        uint x = (random() % (jeu->plateau->taille - 1)) + 1;
        uint y = (random() % (jeu->plateau->taille - 1)) + 1;
        if (jeu->plateau->tab[x][y] == 0)
        {
            jeu->plateau->tab[x][y] = 2;
            place = True;
        }
    }
}
