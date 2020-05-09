/** @file gestionAffichage.c
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Fri 08 May 2020 19:06
 *
 *  @brief
 *
 */

#include "gestionAffichage.h"

//------------Definition menu accueil-----------//

lListTabStr *initAccueil(etatJeu *jeu)
{
    lListTabStr *listeMenu = allocNoeudListTabStr(0, NULL, 0); // Variable de retour

    ajouteStringListe(listeMenu, ((jeu->plateau->taille * 5) / 2) - 1, "1-Jouer", True, 1);
    ajouteStringListe(listeMenu, ((jeu->plateau->taille * 5) / 2) + 1, "2-Quitter", False, 2);

    return (listeMenu);
}

void executeAccueil(etatJeu *jeu, int commande)
{
    switch (commande)
    {
    case 1:
        jeu->tabMenu->menus = (lListTabStr **)realloc(jeu->tabMenu->menus, sizeof(lListTabStr *));
        jeu->tabMenu->taille = 1;
        jeu->tabMenu->menus[0] = convertPlateau(jeu);
        break;
    case 2:
        jeu->actif = False;
        break;

    default:
        printf("Commande non reconue\r\n");
        break;
    }
}

//------------------------------------------------//

//---------------------Infos---------------------//

lListTabStr *initInfos(etatJeu *jeu)
{
    lListTabStr *listeInfo = allocNoeudListTabStr(0, NULL, 0); // Variable de retour

    ajouteStringListe(listeInfo, (jeu->plateau->taille * 5) - 1, "C-Quit | Up | Down", True, 1);

    return (listeInfo);
}

//------------------------------------------------//

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

    set_conio_terminal_mode();
    while (jeu->actif)
    {
        jeu->Ecran = allocEcran(jeu->plateau->taille * 5, jeu->plateau->taille * 10);
        initEcran(jeu->Ecran);
        uint int_str;
        for (int_str = 0; int_str < jeu->tabMenu->taille; int_str++)
        {
            affichesListeStringEcran(jeu->Ecran, jeu->tabMenu->menus[int_str]);
        }
        afficheEcran(jeu->Ecran);
        while (!(commande = testKey()))
        {
        }
        executeCmd(jeu, commande);
        freeEcran(jeu->Ecran);
    }
    reset_terminal_mode();
}

lListTabStr *convertPlateau(etatJeu *jeu)
{
    uint int_y;
    uint int_x;
    lListTabStr *listePlateau = allocNoeudListTabStr(0, NULL, 0);

    char *str0 = (char *)malloc(sizeof(char) * ((jeu->plateau->taille + 9) * 4));
    str0[0] = '#';
    str0[1] = '\0';
    for (int_x = 0; int_x < jeu->plateau->taille; int_x++)
    {
        char *sstr0 = (char *)malloc(sizeof(char) * 8);
        sprintf(sstr0, "      #");
        strcat(str0, sstr0);
        free(sstr0);
    }
    char *str2 = (char *)malloc(sizeof(char) * ((jeu->plateau->taille + 9) * 4));
    str2[0] = '#';
    str2[1] = '\0';
    for (int_x = 0; int_x < jeu->plateau->taille; int_x++)
    {
        char *sstr2 = (char *)malloc(sizeof(char) * 8);
        sprintf(sstr2, "#######");
        strcat(str2, sstr2);
        free(sstr2);
    }
    ajouteStringListe(listePlateau, (jeu->plateau->taille / 2) - 1, str2, False, 0);
    for (int_y = (jeu->plateau->taille) / 2; int_y < (jeu->plateau->taille * 4.5); int_y = int_y + 4)
    {
        char *str1 = (char *)malloc(sizeof(char) * ((jeu->plateau->taille + 9) * 4));
        str1[0] = '#';
        str1[1] = '\0';
        for (int_x = 0; int_x < jeu->plateau->taille; int_x++)
        {
            char *sstr1 = (char *)malloc(sizeof(char) * 8);
            sprintf(sstr1, " %d #", jeu->plateau->tab[(int_y - (jeu->plateau->taille / 2)) / 4][int_x]);
            strcat(str1, sstr1);
            free(sstr1);
        }
        ajouteStringListe(listePlateau, int_y, str0, False, int_y);
        ajouteStringListe(listePlateau, int_y + 1, str1, False, int_y);
        ajouteStringListe(listePlateau, int_y + 2, str0, False, int_y);
        ajouteStringListe(listePlateau, int_y + 3, str2, False, int_y);
        free(str1);
    }
    free(str0);
    free(str2);
    return (listePlateau);
}
