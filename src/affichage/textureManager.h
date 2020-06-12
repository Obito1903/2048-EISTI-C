/** @file textureManager.h
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 26 May 2020 10:17
 *
 *  @brief
 *
 */

#ifndef __TEXTUREMANAGER_H__
/**
 *  @def __TEXTUREMANAGER_H__
 *  Constante permettant de savoirs si le fichier à déjà été chargé.
 */
#define __TEXTUREMANAGER_H__

#define FONTSIZE 200

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

/**
 * @struct tabTexture
 * tableau de texture
 */
typedef struct
{
	/*! tableau de pointeur vers des textures */
	SDL_Texture **tabTex;
	/*! nombre de texture */
	int taille;
} tabTextures;

/**
 * @struct TextureBank
 * contient la liste des tableau de texture
 */
typedef struct
{
	/*! Tableau de pointeur vers des tableaux de texture */
	tabTextures **bank;
	/*! Nombre de tableau */
	int taille;
} TextureBank;

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 03 Jun 2020 13:26
 *
 *  @brief Ajoute un tableau de texture a la banque de texture
 *
 *  @param[in,out] texBank : Banque de texture à modifier
 *  @return pointeur vers la banque modifié
 *
 */
TextureBank *ajouteTextureBank(TextureBank *texBank);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 26 May 2020 10:21
 *
 *  @brief Alloue un nouvel espace dans le tableau de texture pour y ajouter
 *  un pointeur vers la nouvel texture
 *
 *  @param[in,out] tabTile : tableau dans lequel ajouter la texture
 *  @return le tableau de texture modifié
 *
 */
tabTextures *allocNouvelleTexture(tabTextures *tabTile);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 26 May 2020 10:21
 *
 *  @brief Cherche la police a utilisé dans les fichier du jeu et la charge en memoire
 *
 *  @param[in] fontsize : taille de la police
 *  @return pointeur vers le police
 *
 */
TTF_Font *trouvePolice(int fontSize);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 26 May 2020 10:21
 *
 *  @brief Charge une texture en memoire
 *
 *  @param[in] file : chemin vers la texture a charger
 *  @param[in,out] ren : écran dans lequel la texture doit être chargé
 *  @return pointeur vers la texture chargé en memoire
 *
 */
SDL_Texture *chargeTexture(const char *file, SDL_Renderer *ren);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 26 May 2020 10:21
 *
 *  @brief Defini un couleur en fonction de la valeur de la case
 *
 *  @param[in] tileValue : valeur de la case
 *  @return une couleur au format RGBA
 *
 */
SDL_Color definieCouleurCase(int tileValue);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 26 May 2020 10:21
 *
 *  @brief Crée la texture pour une case de la valeur donnée
 *
 *  @param[in,out] renderer : ecran auquel attacher la texture
 *  @param[in,out] tabCase : tableau de texture ou sont stocké les textures des cases
 *  @param[in] font : police a utiliser
 *  @param[in] taille : taille de la texture en pixel
 *  @param[in] tileValue : valeur de la case pourlequel la texture doit être créé
 *  @return pointeur vers le tableau de texture modifié
 *
 */
tabTextures *creeTextureCase(SDL_Renderer *renderer, tabTextures *tabCase, TTF_Font *font, int taille, int tileValue);

#endif // __TEXTUREMANAGER_H__
