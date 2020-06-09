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
