/** @file deplacement.c
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sat 09 May 2020 16:53
 *
 *  @brief
 *
 */

#include "deplacement.h"

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sat 09 May 2020 16:58
 *
 *  @brief
 *
 *  @param[in]
 *
 */

Bool deplacement(etatJeu *jeu, direction direction)
{
    Bool estDeplace = True;
    printf("A\n");
    switch (direction)
    {
    case D_NORD:
        printf("A Nord\n");
        DirectionNord(jeu);
        break;
    case D_SUD:
        DirectionSud(jeu);
        break;
    case D_EST:
        DirectionEst(jeu);
        break;
    case D_OUEST:
        DirectionOuest(jeu);
        break;
    default:
        printf("Cette direction n'existe pas , veuillez rentrer une commande valide");
        estDeplace = False;
        break;
    }
    return estDeplace;
}

void DirectionNord(etatJeu *jeu)
{
    int int_x;
    int int_y;
    for (int_y = 0; int_y < jeu->plateau->taille; int_y++)
    {
        for (int_x = 0; int_x < jeu->plateau->taille; int_x++)
        {
            if (jeu->plateau->tab[int_y][int_x] != 0)
            {
                int y = int_y;
                while ((y - 1 >= 0) && (jeu->plateau->tab[y - 1][int_x] == 0))
                {
                    jeu->plateau->tab[y - 1][int_x] = jeu->plateau->tab[y][int_x];
                    jeu->plateau->tab[y][int_x] = 0;
                    y--;
                }
                if ((y - 1 >= 0) && (jeu->plateau->tab[y - 1][int_x] == jeu->plateau->tab[y][int_x]))
                {
                    jeu->plateau->tab[y - 1][int_x] = jeu->plateau->tab[y - 1][int_x] * 2;
                    jeu->plateau->tab[y][int_x] = 0;
                }
            }
        }
    }
}

void DirectionSud(etatJeu *jeu)
{
    int int_x;
    int int_y;
    for (int_y = jeu->plateau->taille - 1; int_y >= 0; int_y--)
    {
        for (int_x = 0; int_x < jeu->plateau->taille; int_x++)
        {
            if (jeu->plateau->tab[int_y][int_x] != 0)
            {
                int y = int_y;
                while ((y + 1 < jeu->plateau->taille) && (jeu->plateau->tab[y + 1][int_x] == 0))
                {
                    jeu->plateau->tab[y + 1][int_x] = jeu->plateau->tab[y][int_x];
                    jeu->plateau->tab[y][int_x] = 0;
                    y++;
                }
                if ((y + 1 < jeu->plateau->taille) && (jeu->plateau->tab[y + 1][int_x] == jeu->plateau->tab[y][int_x]))
                {
                    jeu->plateau->tab[y + 1][int_x] = jeu->plateau->tab[y + 1][int_x] * 2;
                    jeu->plateau->tab[y][int_x] = 0;
                }
            }
        }
    }
}

void DirectionEst(etatJeu *jeu)
{
    int int_x;
    int int_y;
    for (int_x = 0; int_x < jeu->plateau->taille; int_x++)
    {
        for (int_y = 0; int_y < jeu->plateau->taille; int_y++)
        {
            if (jeu->plateau->tab[int_y][int_x] != 0)
            {
                int x = int_x;
                while ((x - 1 >= 0) && (jeu->plateau->tab[int_y][x - 1] == 0))
                {
                    jeu->plateau->tab[int_y][x - 1] = jeu->plateau->tab[int_y][x];
                    jeu->plateau->tab[int_y][x] = 0;
                    x--;
                }
                if ((x - 1 >= 0) && (jeu->plateau->tab[int_y][x - 1] == jeu->plateau->tab[int_y][x]))
                {
                    jeu->plateau->tab[int_y][x - 1] = jeu->plateau->tab[int_y][x - 1] * 2;
                    jeu->plateau->tab[int_y][x] = 0;
                }
            }
        }
    }
}

void DirectionOuest(etatJeu *jeu)
{
    int int_x;
    int int_y;
    for (int_x = jeu->plateau->taille - 1; int_x > 0; int_x--)
    {
        for (int_y = 0; int_y < jeu->plateau->taille; int_y++)
        {
            if (jeu->plateau->tab[int_y][int_x] != 0)
            {
                int x = int_x;
                while ((x + 1 < jeu->plateau->taille) && (jeu->plateau->tab[int_y][x + 1] == 0))
                {
                    jeu->plateau->tab[int_y][x + 1] = jeu->plateau->tab[int_y][x];
                    jeu->plateau->tab[int_y][x] = 0;
                    x++;
                }
                if ((x + 1 < jeu->plateau->taille) && (jeu->plateau->tab[int_y][x + 1] == jeu->plateau->tab[int_y][x]))
                {
                    jeu->plateau->tab[int_y][x + 1] = jeu->plateau->tab[int_y][x + 1] * 2;
                    jeu->plateau->tab[int_y][x] = 0;
                }
            }
        }
    }
}
