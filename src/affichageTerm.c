/** @file affichage.c
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sat 09 May 2020 17:04
 *
 *  @brief
 *
 */

#include "affichageTerm.h"

void reset_terminal_mode(void)
{
    tcsetattr(0, TCSANOW, &orig_termios);
    printf("\033[?25h\r\n");
}

void set_conio_terminal_mode(void)
{
    struct termios new_termios;

    /* take two copies - one for now, one for later */
    tcgetattr(0, &orig_termios);
    memcpy(&new_termios, &orig_termios, sizeof(new_termios));

    /* register cleanup handler, and set the new terminal mode */
    atexit(reset_terminal_mode);
    cfmakeraw(&new_termios);
    tcsetattr(0, TCSANOW, &new_termios);
    printf("\033[?25l\r\n");
}

int kbhit(void)
{
    struct timeval tv = {0L, 0L};
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(0, &fds);
    return select(1, &fds, NULL, NULL, &tv);
}

void affichagePlateau(etatJeu *jeu)
{
    system("clear");
    int i_coordy;
    int i_coordx;
    printf("\n\r╔");
    for (i_coordx = 1; i_coordx < jeu->plateau->taille; i_coordx++)
    {
        printf("══════╦");
    }
    printf("══════╗\n\r");
    for (i_coordy = 0; i_coordy < jeu->plateau->taille; i_coordy++)
    {
        printf("║");
        for (i_coordx = 0; i_coordx < jeu->plateau->taille; i_coordx++)
        {
            if (jeu->plateau->tab[i_coordy][i_coordx] == 0)
            {
                printf("      ║");
            }
            else if (jeu->plateau->tab[i_coordy][i_coordx] < 10)
            {
                printf("  \033[38;2;255;0;0m%d\033[39m   ║", jeu->plateau->tab[i_coordy][i_coordx]);
            }
            else if (jeu->plateau->tab[i_coordy][i_coordx] < 100)
            {
                printf("  \033[38;2;127;127;0m%d\033[39m  ║", jeu->plateau->tab[i_coordy][i_coordx]);
            }
            else if (jeu->plateau->tab[i_coordy][i_coordx] < 1000)
            {
                printf("  \033[38;2;0;255;0m%d\033[39m ║", jeu->plateau->tab[i_coordy][i_coordx]);
            }
            else if (jeu->plateau->tab[i_coordy][i_coordx] < 10000)
            {
                printf(" \033[38;2;0;255;0m%d\033[39m ║", jeu->plateau->tab[i_coordy][i_coordx]);
            }
        }
        printf("\n\r");
        if (i_coordy < jeu->plateau->taille - 1)
        {
            printf("╠");
            for (i_coordx = 0; i_coordx < jeu->plateau->taille - 1; i_coordx++)
            {
                printf("══════╬");
            }
            printf("══════╣\n\r");
        }
    }
    printf("╚");
    for (i_coordx = 1; i_coordx < jeu->plateau->taille; i_coordx++)
    {
        printf("══════╩");
    }
    printf("══════╝\n\r");

    printf("Coup n°%d\n\r", jeu->nbCoups);

    printf("Flèches pour deplacer\n\rC - Quitter | S - Sauvegarder\n\r");
}
