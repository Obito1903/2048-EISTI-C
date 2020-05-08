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
    lListTabStr *listeMenu = allocNoeudListTabStr(0, NULL); // Variable de retour

    ajouteStringListe(listeMenu, 11, "1-Jouer", True, 1);
    ajouteStringListe(listeMenu, 13, "2-Quitter", False, 2);

    return (listeMenu);
}

void executeAccueil(lListTabStr *listeCurrent, int commande)
{
    switch (commande)
    {
    case 1:
        printf("Le jeu n'est pas encore implenter\r\n");
        jeuON = False;
        break;
    case 2:
        jeuON = False;
        break;

    default:
        printf("Commande non reconue\r\n");
        break;
    }
}

void executeMenu(lListTabStr *listeCurrent)
{
    int commande = trouveStrSelection(listeCurrent)->id;

    if (commande < 3)
    {
        executeAccueil(listeCurrent, commande);
    }
}

void executeCmd(lListTabStr *listeCurrent, int commande)
{
    switch (commande)
    {
    case 1:
        jeuON = False;
        break;
    case 2:
        changeSelection(listeCurrent, 0);
        break;
    case 3:
        changeSelection(listeCurrent, 1);
        break;
    case 4:
        executeMenu(listeCurrent);
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

void mainAffichage(void)
{
    jeuON = True;
    int commande;
    lListTabStr *listeSelectionCurrent;
    lListTabStr *listeStrInfo = allocNoeudListTabStr(0, NULL);

    lListTabStr *lAcceuil = initAccueil();

    listeSelectionCurrent = lAcceuil;

    ajouteStringListe(listeStrInfo, 24, "C-Quit | Up | Down", True, 1);

    set_conio_terminal_mode();

    while (jeuON)
    {
        screen *Ecran = allocEcran(25, 50);
        initEcran(Ecran);
        affichesListeStringEcran(Ecran, listeSelectionCurrent);
        affichesListeStringEcran(Ecran, listeStrInfo);
        afficheEcran(Ecran);
        while (!(commande = testKey()))
        {
        }
        executeCmd(listeSelectionCurrent, commande);
        freeEcran(Ecran);
    }
    reset_terminal_mode();
}
