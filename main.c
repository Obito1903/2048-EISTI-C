/** @file main.c
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 05 May 2020 10:50
 *
 *  @brief Fichier principale du projet 2020
 *
 */

#include "main.h"

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 06 May 2020 14:10
 *
 *  @brief
 *
 *  @param[in]
 *
 */
void traitementArgs(int argc, char const *argv[])
{
    int int_arg;
    for (int_arg = 0; int_arg < argc; int_arg++)
    {
        if (strcmp(argv[int_arg], "prout"))
        {
            printf("prout\n");
        }
    }
}

int main(int argc, char const *argv[])
{

    srandom(time(NULL));

    if (argc > 1)
    {
        traitementArgs(argc, argv);
    }

    etatJeu *jeu = initJeu(4);
    while (finPartie(jeu))
    {
        ajouteCase(jeu);
        affichagePlateau(jeu);
        printf("quel direction ?\n");
        direction direction = saisieIntTest(0, 3);
        deplacement(jeu, direction);
    }

    return (0);
}
