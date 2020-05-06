/** @file jeuBase.c
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 06 May 2020 09:11
 *
 *  @brief
 *
 */

#include "jeuBase.h"

void erreur(err erreur, char *msg)
{
    fprintf(stderr, "[ERREUR %d] >%s", erreur, msg);
    switch (erreur)
    {
    case alloc:
        exit(EXIT_FAILURE);
        break;
    default:
        fprintf(stderr, "[ERREUR NON RECONUE] >%s", msg);
        exit(EXIT_FAILURE);
        break;
    }
}
