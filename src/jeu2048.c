/** @file jeu2048.c
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sat 09 May 2020 16:56
 *
 *  @brief
 *
 */

#include "jeu2048.h"

int testKey(void)
{
    int commande; // Variable de retour

    while (!kbhit())
    {
        sleep(0.01);
    }
    int entre = getchar();
    while (entre == 27 || entre == 91)
    {
        entre = getchar();
    }

    switch (entre)
    {
    case 'c':
        commande = 1;
        break;
    case 65:
        commande = 2;
        break;
    case 66:
        commande = 3;
        break;
    case 67:
        commande = 4;
        break;
    case 68:
        commande = 5;
        break;
    case 115:
        commande = 6;
        break;
    default:
        break;
    }

    return (commande);
}

void executeCmd(etatJeu *jeu, int commande)
{
    Bool estDeplace = False;
    switch (commande)
    {
    case 1:
        jeu->jeuActif = False;
        break;
    case 2:
        estDeplace = deplacement(jeu, 0);
        break;
    case 3:
        estDeplace = deplacement(jeu, 1);
        break;
    case 4:
        estDeplace = deplacement(jeu, 2);
        break;
    case 5:
        estDeplace = deplacement(jeu, 3);
        break;
    case 6:
        savJeu(jeu);
        break;
    default:
        break;
    }
    if (estDeplace)
    {
        ajouteCase(jeu);
    }
}

int finPartie(etatJeu *jeu)
{
    int retour = 1; // Variable de retour
    int y;
    int x;
    int temp;
    for (y = 0; y < jeu->plateau->taille; y++)
    {
        for (x = 0; x < jeu->plateau->taille; x++)
        {
            if (jeu->plateau->tab[x][y] == 2048)
            {
                printf("2048 !\n\r");
                retour = 2;
            }
            if ((retour == 1) && (jeu->plateau->tab[x][y] == 0))
            {
                retour = 0;
            }
        }
    }

    return (retour);
}

void ajouteCase(etatJeu *jeu)
{
    tabCoord *tCoord = (tabCoord *)malloc(sizeof(tabCoord));
    tCoord->lCoord = (coord *)malloc(sizeof(coord));
    tCoord->taille = 0;
    coord coordActu;
    int int_y;
    int int_x;
    for (int_y = 0; int_y < jeu->plateau->taille; int_y++)
    {
        for (int_x = 0; int_x < jeu->plateau->taille; int_x++)
        {
            if (jeu->plateau->tab[int_y][int_x] == 0)
            {
                coordActu.x = int_x;
                coordActu.y = int_y;
                tCoord->taille++;
                tCoord->lCoord = (coord *)realloc(tCoord->lCoord, sizeof(coord) * tCoord->taille);
                tCoord->lCoord[tCoord->taille - 1] = coordActu;
            }
        }
    }
    coord Case = tCoord->lCoord[random() % tCoord->taille];
    jeu->plateau->tab[Case.y][Case.x] = ((random() % 2) + 1) * 2;
    free(tCoord->lCoord);
    free(tCoord);
}

void executeJeu(etatJeu *jeu)
{
    int commande;
    set_conio_terminal_mode();
    jeu->jeuActif = True;
    while (!finPartie(jeu) && jeu->jeuActif)
    {
        affichagePlateau(jeu);
        while (!(commande = testKey()))
        {
        }
        executeCmd(jeu, commande);
    }
    freeJeu(jeu);
    reset_terminal_mode();
}
