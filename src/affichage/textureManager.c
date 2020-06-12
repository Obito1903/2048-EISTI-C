/** @file textureManager.c
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 26 May 2020 10:17
 *
 *  @brief
 *
 */

#include "textureManager.h"

TextureBank *ajouteTextureBank(TextureBank *texBank)
{
	if (texBank == NULL) {
		texBank					 = (TextureBank *)malloc(sizeof(TextureBank));
		texBank->bank			 = (tabTextures **)malloc(sizeof(tabTextures *));
		texBank->bank[0]		 = (tabTextures *)malloc(sizeof(tabTextures));
		texBank->bank[0]->tabTex = NULL;
		texBank->taille			 = 1;
	} else {
		texBank->bank = (tabTextures **)realloc(texBank->bank, sizeof(tabTextures *) * (texBank->taille + 1));
		texBank->bank[texBank->taille]		   = (tabTextures *)malloc(sizeof(tabTextures));
		texBank->bank[texBank->taille]->tabTex = NULL;
		texBank->taille++;
	}

	return (texBank);
}

tabTextures *allocNouvelleTexture(tabTextures *tabTex)
{
	if (tabTex->tabTex == NULL) {
		tabTex->tabTex = (SDL_Texture **)malloc(sizeof(SDL_Texture *));
		tabTex->taille = 1;

	} else {
		tabTex->tabTex = (SDL_Texture **)realloc(tabTex->tabTex, sizeof(SDL_Texture *) * (tabTex->taille + 1));
		tabTex->taille++;
	}
	return tabTex;
}

TTF_Font *trouvePolice(int fontSize)
{
	TTF_Font *font = TTF_OpenFont("./src/consola.ttf", fontSize);
	if (font == NULL) {
		TTF_Font *font = TTF_OpenFont("./bin/src/consola.ttf", fontSize);
		if (font == NULL) {
			TTF_Font *font = TTF_OpenFont("./consola.ttf", fontSize);
			if (font == NULL) {
				printf("TTF_OpenFont Error: %s \n", TTF_GetError());
				exit(EXIT_FAILURE);
			}
		}
	}
	return font;
}

SDL_Texture *chargeTexture(const char *file, SDL_Renderer *ren)
{
	SDL_Texture *texture = NULL;
	// Charge l'image
	SDL_Surface *loadedImage = IMG_Load(file);
	if (loadedImage != NULL) {
		texture = SDL_CreateTextureFromSurface(ren, loadedImage);
		SDL_FreeSurface(loadedImage);
		if (texture == NULL) {
			fprintf(stdout, "Erreur :CreateTextureFromSurface\n");
		}
	} else {
		fprintf(stdout, "Erreur : Chargement BMP\n");
	}
	return texture;
}

SDL_Color definieCouleurCase(int tileValue)
{
	SDL_Color couleur = {0, 0, 0, 255};
	if (tileValue <= 8) {
		couleur.r = 252;
		couleur.g = 88;
		couleur.b = 76;
	} else if (tileValue <= 64) {
		couleur.r = 252;
		couleur.g = 155;
		couleur.b = 76;
	} else if (tileValue <= 512) {
		couleur.r = 208;
		couleur.g = 76;
		couleur.b = 252;
	} else if (tileValue <= 2048) {
		couleur.r = 74;
		couleur.g = 180;
		couleur.b = 255;
	} else {
		couleur.r = 165;
		couleur.g = 191;
		couleur.b = 209;
	}
	return couleur;
}

tabTextures *creeTextureCase(SDL_Renderer *renderer, tabTextures *tabCase, TTF_Font *font, int taille, int tileValue)
{
	SDL_Rect dst   = {0, 0, 0, 0};
	int		 reduc = 0;
	char	 str[30];
	tabCase = allocNouvelleTexture(tabCase);

	// Crée le texture du texte
	sprintf(str, "%d", tileValue);
	SDL_Rect	 r		   = {0, 0, taille, taille};
	SDL_Color	 color	   = {255, 255, 255, 255};
	SDL_Surface *surface   = TTF_RenderText_Blended(font, str, color);
	SDL_Texture *texNumber = SDL_CreateTextureFromSurface(renderer, surface);

	// Crée la texture de support
	SDL_Texture *texTarget = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_UNKNOWN, SDL_TEXTUREACCESS_TARGET, taille, taille);
	SDL_Texture *texBackground = chargeTexture("./src/assets/template.png", renderer);
	SDL_Color	 couleur	   = definieCouleurCase(tileValue);
	SDL_SetTextureColorMod(texBackground, couleur.r, couleur.g, couleur.b);

	// Reduit et place au centre le nombre
	SDL_QueryTexture(texNumber, NULL, NULL, &dst.w, &dst.h);
	if (dst.h >= dst.w) {
		reduc = (dst.h / taille) + 1;
	} else {
		reduc = (dst.w / taille) + 1;
	}
	dst.h = dst.h / reduc;
	dst.w = dst.w / reduc;
	dst.x = (r.w - dst.w) / 2;
	dst.y = (r.h - dst.h) / 2;

	// Fusionne le nombre a l'arriere plan
	SDL_SetRenderTarget(renderer, texTarget);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texBackground, NULL, &r);
	SDL_RenderCopy(renderer, texNumber, NULL, &dst);

	SDL_SetRenderTarget(renderer, NULL);

	// Sauvegarde la texture
	tabCase->tabTex[tabCase->taille - 1] = texTarget;
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	SDL_DestroyTexture(texNumber);
	SDL_DestroyTexture(texBackground);
	SDL_FreeSurface(surface);
	return tabCase;
}
