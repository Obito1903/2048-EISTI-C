/** @file jeuBase.c
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 06 May 2020 09:11
 *
 *  @brief
 *
 */

#include "jeuBase.h"

etatJeu *allocJeu(uint taille)
{
    etatJeu *jeu = (etatJeu *)malloc(sizeof(etatJeu)); // Variable de retour
    testAlloc(jeu, "Allocation impossible : jeu");
    jeu->tabMenu = (tabMenu *)malloc(sizeof(tabMenu));
    testAlloc(jeu->tabMenu, "Allocation impossible : jeu->plateau");

    jeu->tabMenu->taille = 1;
    jeu->tabMenu->menus = (lListTabStr **)malloc(sizeof(lListTabStr *));

    testAlloc(jeu->tabMenu->menus, "Allocation impossible : jeu->tabMenu->menus");

    jeu->plateau = (plateau *)malloc(sizeof(plateau));
    testAlloc(jeu->plateau, "Allocation impossible : jeu->plateau");

    jeu->plateau->taille = taille;
    jeu->plateau->tab = (uint **)malloc(sizeof(uint *) * taille);
    testAlloc(jeu->plateau->tab, "Allocation impossible : jeu->plateau->tab");

    uint int_y;
    for (int_y = 0; int_y < taille; int_y++)
    {
        jeu->plateau->tab[int_y] = (uint *)malloc(sizeof(uint) * taille);
        testAlloc(jeu->plateau->tab[int_y], "Allocation impossible : jeu->plateau->tab[]");
    }

    return (jeu);
}

etatJeu *initJeu(uint taille)
{
    etatJeu *jeu = allocJeu(taille); // Variable de retour
    jeu->tabMenu->menus[0] = initInfos(jeu);
    jeu->tabMenu->menus = (lListTabStr **)realloc(jeu->tabMenu->menus, sizeof(lListTabStr *) * (jeu->tabMenu->taille + 1));
    jeu->tabMenu->taille++;
    jeu->tabMenu->menus[1] = initAccueil(jeu);
    jeu->menuCourant = jeu->tabMenu->menus[1];
    jeu->actif = True;
    uint int_y;
    uint int_x;
    for (int_y = 0; int_y < jeu->plateau->taille; int_y++)
    {
        for (int_x = 0; int_x < jeu->plateau->taille; int_x++)
        {
            jeu->plateau->tab[int_y][int_x] = 2048;
        }
    }
    return (jeu);
}

void freeJeu(etatJeu *jeu)
{
    uint int_y;
    lListTabStr *ListeCourante;
    for (int_y = 0; int_y < jeu->plateau->taille; int_y++)
    {
        free(jeu->plateau->tab[int_y]);
    }
    free(jeu->plateau->tab);
    free(jeu->plateau);
    for (int_y = 0; int_y < jeu->tabMenu->taille; int_y++)
    {
        ListeCourante = jeu->tabMenu->menus[int_y];
        while (ListeCourante->suivant != NULL)
        {
            ListeCourante = ListeCourante->suivant;
            free(ListeCourante->precedent->str);
            free(ListeCourante->precedent);
        }
        free(ListeCourante->str);
        free(ListeCourante);
    }
    free(jeu->tabMenu->menus);
    free(jeu->tabMenu);
    free(jeu);
}
