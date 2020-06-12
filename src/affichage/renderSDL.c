/** @file renderSDL.c
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 09 Jun 2020 10:29
 *
 *  @brief
 *
 */

#include "renderSDL.h"

void renderTexte(SDL_Renderer *renderer, const char *str, TTF_Font *font, int taille, int x, int y)
{
	SDL_Rect dst;
	int		 reduc = 0;
	dst.x		   = x;
	dst.y		   = y;

	SDL_Color	 color	 = {255, 255, 255, 255};
	SDL_Surface *surface = TTF_RenderText_Blended(font, str, color);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);
	reduc = (dst.h / taille);
	dst.h = dst.h / reduc;
	dst.w = dst.w / reduc;
	SDL_RenderCopy(renderer, texture, NULL, &dst);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}

void renderTexture(SDL_Texture *texture, SDL_Renderer *renderer, int x, int y, int h, int w)
{
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);
	if (h != 0 && w != 0) {
		dst.w = w;
		dst.h = h;
	}
	SDL_RenderCopy(renderer, texture, NULL, &dst);
}

void renderButtons(button *bouton, SDL_Renderer *renderer, TTF_Font *font)
{
	SDL_Rect	 dst;
	int			 reduc	 = 0;
	SDL_Color	 color	 = {255, 255, 255, 255};
	SDL_Surface *surface = TTF_RenderText_Blended(font, bouton->texte, color);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);
	reduc = (dst.h / bouton->size);
	dst.h = dst.h / reduc;
	dst.w = dst.w / reduc;
	dst.x = bouton->x - (dst.w / 2);
	dst.y = bouton->y - (dst.h / 2);
	// Dessine fond
	SDL_SetRenderDrawColor(renderer, 176, 176, 176, 255);
	SDL_RenderFillRect(renderer, &dst);
	// Dessine texte
	SDL_RenderCopy(renderer, texture, NULL, &dst);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
	SDL_SetRenderDrawColor(renderer, 52, 52, 52, 255);

	bouton->h = dst.h;
	bouton->w = dst.w;
}
