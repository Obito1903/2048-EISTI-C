/** @file gestionAffichage.c
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Fri 08 May 2020 19:06
 *
 *  @brief
 *
 */

#include "gestionAffichage.h"

lListTabStr *initAccueil(void)
{
    lListTabStr *listeMenu = allocNoeudListTabStr(0, NULL, 0); // Variable de retour

    ajouteStringListe(listeMenu, 11, "1-Jouer", True, 1);
    ajouteStringListe(listeMenu, 13, "2-Quitter", False, 2);

    return (listeMenu);
}

void executeAccueil(etatJeu *jeu, int commande)
{
    switch (commande)
    {
    case 1:
        printf("Le jeu n'est pas encore implenter\r\n");
        jeu->actif = False;
        break;
    case 2:
        jeu->actif = False;
        break;

    default:
        printf("Commande non reconue\r\n");
        break;
    }
}

void executeMenu(etatJeu *jeu)
{
    int commande = trouveStrSelection(jeu->menuCourant)->id;

    if (commande < 3)
    {
        executeAccueil(jeu, commande);
    }
}

void executeCmd(etatJeu *jeu, int commande)
{
    switch (commande)
    {
    case 1:
        jeu->actif = False;
        break;
    case 2:
        changeSelection(jeu->menuCourant, 0);
        break;
    case 3:
        changeSelection(jeu->menuCourant, 1);
        break;
    case 4:
        executeMenu(jeu);
        break;
    default:
        break;
    }
}

int testKey(void)
{
    int commande; // Variable de retour

    while (!kbhit())
    {
    }
    int entre = getchar();
    printf("entre %d\r\n", entre);

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
    case 13:
        commande = 4;
        break;
    default:
        break;
    }

    return (commande);
}

void mainAffichage(etatJeu *jeu)
{
    int commande;
    //lListTabStr *listeStrInfo = allocNoeudListTabStr(0, NULL);

    //ajouteStringListe(listeStrInfo, 24, "C-Quit | Up | Down", True, 1);

    set_conio_terminal_mode();

    while (jeu->actif)
    {
        jeu->Ecran = allocEcran(25, 50);
        initEcran(jeu->Ecran);
        affichesListeStringEcran(jeu->Ecran, jeu->menuCourant);
        //affichesListeStringEcran(jeu->Ecran, listeStrInfo);
        afficheEcran(jeu->Ecran);
        while (!(commande = testKey()))
        {
        }
        executeCmd(jeu, commande);
        freeEcran(jeu->Ecran);
    }
    reset_terminal_mode();
}
