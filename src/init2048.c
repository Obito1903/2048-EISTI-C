/** @file init2048.c
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sat 09 May 2020 16:28
 *
 *  @brief
 *
 */

#include "init2048.h"

etatJeu *allocJeu(int taille)
{
    etatJeu *jeu = (etatJeu *)malloc(sizeof(etatJeu)); // Variable de retour
    testAlloc(jeu, "Probleme d'allocation : jeu");

    jeu->plateau = (plateau *)malloc(sizeof(plateau));
    testAlloc(jeu->plateau, "Probleme d'allocation : jeu->plateau");

    jeu->plateau->tab = (uint **)malloc(sizeof(uint *) * taille);
    jeu->plateau->taille = taille;
    testAlloc(jeu->plateau->tab, "Probleme d'allocation : jeu->plateau->tab");
    int int_y;
    for (int_y = 0; int_y < taille; int_y++)
    {
        jeu->plateau->tab[int_y] = (uint *)malloc(sizeof(uint) * taille);
        testAlloc(jeu->plateau->tab[int_y], "Probleme d'allocation : jeu->plateau->tab[]");
    }

    return (jeu);
}

etatJeu *initJeu(int taille)
{
    etatJeu *jeu = allocJeu(taille);
    jeu->nbCoups = 0;

    int int_y;
    int int_x;
    for (int_y = 0; int_y < jeu->plateau->taille; int_y++)
    {
        for (int_x = 0; int_x < jeu->plateau->taille; int_x++)
        {
            jeu->plateau->tab[int_y][int_x] = 0;
        }
    }
    ajouteCase(jeu);
    return (jeu);
}

void freeJeu(etatJeu *jeu)
{
    int int_y;
    for (int_y = 0; int_y < jeu->plateau->taille; int_y++)
    {
        free(jeu->plateau->tab[int_y]);
    }
    free(jeu->plateau->tab);
    free(jeu->plateau);
    free(jeu);
}

void savJeu(etatJeu *jeu)
{
    int int_y;
    int int_x;
    mkdir("./Savs", 0700);
    FILE *fichierSauv = fopen("./Savs/sav.bin", "wb");
    fwrite(&jeu->plateau->taille, sizeof(int), 1, fichierSauv);
    fwrite(&jeu->nbCoups, sizeof(uint), 1, fichierSauv);
    for (int_y = 0; int_y < jeu->plateau->taille; int_y++)
    {
        for (int_x = 0; int_x < jeu->plateau->taille; int_x++)
        {
            fwrite(&jeu->plateau->tab[int_y][int_x], sizeof(int), 1, fichierSauv);
        }
    }
    fclose(fichierSauv);
    printf("Partei sauvegarder !\n\r");
    jeu->jeuActif = False;
}

etatJeu *chargeJeu(char *chemin)
{
    int int_y;
    int int_x;
    FILE *fichierSauv;
    fichierSauv = fopen(chemin, "rb");
    int taille;
    if (fichierSauv == NULL)
    {
        fprintf(stderr, "Le fichier de sauvegarde n'existe pas");
        exit(EXIT_FAILURE);
    }
    fread(&taille, sizeof(int), 1, fichierSauv);
    etatJeu *jeu = initJeu(taille); // Variable de retour
    fread(&jeu->nbCoups, sizeof(uint), 1, fichierSauv);
    for (int_y = 0; int_y < jeu->plateau->taille; int_y++)
    {
        for (int_x = 0; int_x < jeu->plateau->taille; int_x++)
        {
            fread(&jeu->plateau->tab[int_y][int_x], sizeof(int), 1, fichierSauv);
        }
    }
    fclose(fichierSauv);
    return (jeu);
}
