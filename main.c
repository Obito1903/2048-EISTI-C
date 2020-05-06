/** @file main.c
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 05 May 2020 10:50
 *
 *  @brief Fichier principale du projet 2020
 *
 */

#include "main.h"

void reset_terminal_mode()
{
    tcsetattr(0, TCSANOW, &orig_termios);
}

void set_conio_terminal_mode()
{
    struct termios new_termios;

    /* take two copies - one for now, one for later */
    tcgetattr(0, &orig_termios);
    memcpy(&new_termios, &orig_termios, sizeof(new_termios));

    /* register cleanup handler, and set the new terminal mode */
    atexit(reset_terminal_mode);
    cfmakeraw(&new_termios);
    tcsetattr(0, TCSANOW, &new_termios);
}

int kbhit()
{
    struct timeval tv = {0L, 0L};
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(0, &fds);
    return select(1, &fds, NULL, NULL, &tv);
}

int main(int argc, char const *argv[])
{
    set_conio_terminal_mode();

    bool jeuActif = TRUE;
    char KeyStrok;
    while (!kbhit())
    {
    }
    KeyStrok = getchar();
    printf("KeyStrok: %d\n", KeyStrok);

    reset_terminal_mode();

    return (0);
}
