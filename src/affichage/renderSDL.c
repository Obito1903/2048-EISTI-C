/** @file renderSDL.c
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 09 Jun 2020 10:29
 *
 *  @brief
 *
 */

#include "renderSDL.h"

void renderTxt(SDL_Renderer *ren, const char *str, TTF_Font *font, int size, int x, int y)
{
	SDL_Rect dst;
	int		 reduc = 0;
	dst.x		   = x;
	dst.y		   = y;

	SDL_Color	 color	 = {255, 255, 255, 255};
	SDL_Surface *surface = TTF_RenderText_Blended(font, str, color);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(ren, surface);
	SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);
	reduc = (dst.h / size);
	dst.h = dst.h / reduc;
	dst.w = dst.w / reduc;
	SDL_RenderCopy(ren, texture, NULL, &dst);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}

void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int h, int w)
{
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
	if (h != 0 && w != 0) {
		dst.w = w;
		dst.h = h;
	}
	SDL_RenderCopy(ren, tex, NULL, &dst);
}

void renderButtons(button *button, SDL_Renderer *ren, TTF_Font *font)
{
	SDL_Rect	 dst;
	int			 reduc	 = 0;
	SDL_Color	 color	 = {255, 255, 255, 255};
	SDL_Surface *surface = TTF_RenderText_Blended(font, button->texte, color);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(ren, surface);
	SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);
	reduc = (dst.h / button->size);
	dst.h = dst.h / reduc;
	dst.w = dst.w / reduc;
	dst.x = button->x - (dst.w / 2);
	dst.y = button->y - (dst.h / 2);
	// Dessine fond
	SDL_SetRenderDrawColor(ren, 176, 176, 176, 255);
	SDL_RenderFillRect(ren, &dst);
	// Dessine texte
	SDL_RenderCopy(ren, texture, NULL, &dst);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
	SDL_SetRenderDrawColor(ren, 52, 52, 52, 255);

	button->h = dst.h;
	button->w = dst.w;
}
