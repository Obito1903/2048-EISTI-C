/** @file affichageSDL.c
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 12 May 2020 10:04
 *
 *  @brief
 *
 */

#include "affichageSDL.h"

void frameControl(double tmp)
{
	if (tmp < 0.016) {
		SDL_Delay(16 - tmp);
	} else {
		printf("jeu trop lent (%lf)\n", tmp);
	}
}

void mainAffichage(etatJeu *jeu)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		printf("SDL_Init Error: %s \n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	if (TTF_Init() == -1) {
		printf("TTF_Init Error: %s \n", TTF_GetError());
		exit(EXIT_FAILURE);
	}
	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
		printf("IMG_Init Error: %s \n", IMG_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_Window *win =
		SDL_CreateWindow("Hello World!", 100, 100, FENETRE_L, FENETRE_H, SDL_WINDOW_SHOWN);
	if (win == NULL) {
		printf("SDL_CreateWindow Error: %s \n", SDL_GetError());
		SDL_Quit();
		exit(EXIT_FAILURE);
	}

	SDL_Renderer *ren =
		SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == NULL) {
		SDL_DestroyWindow(win);
		printf("SDL_CreateRenderer Error: %s \n", SDL_GetError());
		SDL_Quit();
		exit(EXIT_FAILURE);
	}
	SDL_Event event;
	jeu->jeuActif = True;

	TTF_Font *font = findFont(FONTSIZE);

	clock_t start, end;
	double	cpu_time_used;

	TextureBank *TexBank = addTextureBank(NULL);
	TexBank				 = addTextureBank(TexBank);

	TexBank->bank[1]			= allocNewTexture(TexBank->bank[1], NULL);
	TexBank->bank[1]->tabTex[0] = loadTexture("./src/assets/template_background.png", ren);

	while (jeu->jeuActif) {
		start = clock();
		SDL_RenderClear(ren);
		gestionEvenement(jeu, &event);
		dessiner(ren, TexBank, jeu, font);
		SDL_RenderPresent(ren);
		end			  = clock();
		cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
		frameControl(cpu_time_used);
	}
	freeJeu(jeu);
	TTF_CloseFont(font);
	TTF_Quit();
	SDL_Quit();
}

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

void gestionTouche(etatJeu *jeu, SDL_Keycode touche)
{
	Bool deplacement = False;
	switch (touche) {
		case SDLK_ESCAPE:
			jeu->jeuActif = False;
			break;
		case SDLK_UP:
			deplacement = DirectionNord(jeu);
			break;
		case SDLK_DOWN:
			deplacement = DirectionSud(jeu);
			break;
		case SDLK_LEFT:
			deplacement = DirectionOuest(jeu);
			break;
		case SDLK_RIGHT:
			deplacement = DirectionEst(jeu);
			break;
		default:
			break;
	}

	if (deplacement) {
		jeu->jeuActif = ajouteCase(jeu);
		jeu->nbCoups++;
	}
}

void gestionEvenement(etatJeu *jeu, SDL_Event *event)
{

	while (SDL_PollEvent(event)) {
		switch (event->type) {
			case SDL_QUIT:
				jeu->jeuActif = False;
				break;
			case SDL_KEYDOWN:
				gestionTouche(jeu, event->key.keysym.sym);
				break;
			default:
				break;
		}
	}
}

void dessiner(SDL_Renderer *renderer, TextureBank *TexBank, etatJeu *jeu, TTF_Font *font)
{
	SDL_SetRenderDrawColor(renderer, 52, 52, 52, 255);

	dessinePlateau(renderer, TexBank, jeu, font);
}

int calcLongeurUNb(int nb)
{
	int taille = 0;

	while (nb > 0) {
		taille++;
		nb = nb / 10;
	}
	return taille;
}

void dessinePlateau(SDL_Renderer *renderer, TextureBank *TexBank, etatJeu *jeu, TTF_Font *font)
{
	int tailleCasePx  = FENETRE_H / (jeu->plateau->taille + 2);
	int decallageVert = tailleCasePx - (4 * (jeu->plateau->taille - 1));
	int int_y;
	int int_x;
	for (int_y = 0; int_y < jeu->plateau->taille; int_y++) {
		for (int_x = 0; int_x < jeu->plateau->taille; int_x++) {
			renderTexture(TexBank->bank[1]->tabTex[0], renderer,
						  (int_x * (tailleCasePx + 4)) + decallageVert - 2,
						  (int_y * (tailleCasePx + 4)) + decallageVert - 2, tailleCasePx + 4,
						  tailleCasePx + 4);
			if (jeu->plateau->tab[int_y][int_x] != 0) {
				if (TexBank->bank[0]->tabTex == NULL ||
					(TexBank->bank[0]->taille < (int)(log2(jeu->plateau->tab[int_y][int_x])))) {
					TexBank->bank[0] =
						createTileTexture(renderer, TexBank->bank[0], font, tailleCasePx,
										  jeu->plateau->tab[int_y][int_x]);
				}
				renderTexture(
					TexBank->bank[0]->tabTex[(int)(log2(jeu->plateau->tab[int_y][int_x])) - 1],
					renderer, (int_x * (tailleCasePx + 4)) + decallageVert,
					(int_y * (tailleCasePx + 4)) + decallageVert, tailleCasePx, tailleCasePx);
			}
		}
	}
}
