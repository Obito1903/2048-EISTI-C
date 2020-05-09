/** @file samBase.c
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sat 09 May 2020 00:41
 *
 *  @brief Fonctions de base de la lib samLib
 *
 */

#include "samBase.h"

void erreur(err erreur, char *msg)
{
    char *nomErr = (char *)malloc(sizeof(char) * 20);
    switch (erreur)
    {
    case alloc:
        nomErr = "ALOCATION";
        break;
    default:
        fprintf(stderr, "[ERREUR NON RECONUE] >%s", msg);
        break;
    }
    fprintf(stderr, "[ERREUR %s] >%s", nomErr, msg);
    exit(EXIT_FAILURE);
}

void testAlloc(void *test, char *msg)
{
    if (test == NULL)
    {
        erreur(alloc, msg);
    }
}
