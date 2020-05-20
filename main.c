/** @file main.c
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 05 May 2020 10:50
 *
 *  @brief Fichier principale du projet 2020
 *
 */

#include "main.h"

void traitementArgs(int argc, char *argv[])
{
    int taille = 4;
    etatJeu *jeu = NULL;
    if (argc > 1)
    {
        int int_arg;
        for (int_arg = 0; int_arg < argc; int_arg++)
        {
            if (!strcmp(argv[int_arg], "-t"))
            {
                taille = atoi(argv[int_arg + 1]);
                jeu = initJeu(taille);
            }
            if (!strcmp(argv[int_arg], "-l"))
            {
                jeu = chargeJeu(argv[int_arg + 1]);
            }
        }
    }
    if (jeu == NULL)
    {
        jeu = initJeu(4);
    }
    mainAffichage(jeu);
    //executeJeu(jeu);
}

int main(int argc, char *argv[])
{

    srand(time(NULL));
    traitementArgs(argc, argv);

    return (0);
}
