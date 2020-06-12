/** @file changementEtat.h
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 10 Jun 2020 12:19
 *
 *  @brief
 *
 */

#ifndef __CHANGEMENTETAT_H__
/**
 *  @def __CHANGEMENTETAT_H__
 *  Constante permettant de savoirs si le fichier à déjà été chargé.
 */
#define __CHANGEMENTETAT_H__

#include "../jeu2048.h"
#include "textureManager.h"

/**
 * @struct button
 *
 */
typedef struct
{
	/*!  */
	int	  x;
	int	  y;
	int	  size;
	int	  h;
	int	  w;
	char *texte;
} button;

/**
 * @struct tabButton
 *
 */
typedef struct
{
	/*!  */
	button **tabButton;
	uint	 nbButtons;
} Buttons;

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 10 Jun 2020 12:15
 *
 *  @brief
 *
 *  @param[in]
 *  @return
 *
 */
void chargeEtat(int Etat, etatJeu *jeu, Buttons *Buttons);

#endif // __CHANGEMENTETAT_H__
