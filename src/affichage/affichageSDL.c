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

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 10 Jun 2020 12:12
 *
 *  @brief
 *
 *  @param[in]
 *
 */
void initSDL(void)
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
}

void mainAffichage(etatJeu *jeu)
{
	initSDL();

	SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, jeu->fenetreL, jeu->fenetreH, SDL_WINDOW_SHOWN);
	if (win == NULL) {
		printf("SDL_CreateWindow Error: %s \n", SDL_GetError());
		SDL_Quit();
		exit(EXIT_FAILURE);
	}

	SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == NULL) {
		SDL_DestroyWindow(win);
		printf("SDL_CreateRenderer Error: %s \n", SDL_GetError());
		SDL_Quit();
		exit(EXIT_FAILURE);
	}

	TextureBank *TexBank = addTextureBank(NULL);
	TexBank				 = addTextureBank(TexBank);

	SDL_Event event;
	TTF_Font *font = findFont(FONTSIZE);

	Buttons buttons;
	buttons.tabButton = NULL;
	buttons.nbButtons = 0;

	chargeEtat(2, jeu, &buttons);

	TexBank->bank[1]			= allocNewTexture(TexBank->bank[1], NULL);
	TexBank->bank[1]->tabTex[0] = loadTexture("./src/assets/template_background.png", ren);

	clock_t start, end;
	double	cpu_time_used;

	while (jeu->etatJeu) {
		start = clock();
		SDL_RenderClear(ren);
		gestionEvenement(jeu, &buttons, &event);
		dessiner(ren, TexBank, jeu, font, &buttons);
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

void dessiner(SDL_Renderer *renderer, TextureBank *TexBank, etatJeu *jeu, TTF_Font *font, Buttons *buttons)
{
	SDL_SetRenderDrawColor(renderer, 52, 52, 52, 255);
	switch (jeu->etatJeu) {
		case 2:
			dessinePlateau(renderer, TexBank, jeu, font);
			break;
		default:
			break;
	}
	dessineBoutons(renderer, font, buttons);
}

void dessineBoutons(SDL_Renderer *renderer, TTF_Font *font, Buttons *buttons)
{
	uint int_boutons;
	for (int_boutons = 0; int_boutons < buttons->nbButtons; int_boutons++) {
		renderButtons(buttons->tabButton[int_boutons], renderer, font);
	}
}

void creationCase(SDL_Renderer *renderer, TextureBank *TexBank, uint valCase, TTF_Font *font, uint tailleCasePx)
{
	int int_text;
	if (TexBank->bank[0]->tabTex == NULL) {
		TexBank->bank[0] = createTileTexture(renderer, TexBank->bank[0], font, tailleCasePx, valCase);
	} else if (TexBank->bank[0]->taille < (int)(log2(valCase))) {
		for (int_text = TexBank->bank[0]->taille; int_text < (int)(log2(valCase)); int_text++) {
			TexBank->bank[0] = createTileTexture(renderer, TexBank->bank[0], font, tailleCasePx, (int)pow(2, int_text + 1));
		}
	}
}

void dessinePlateau(SDL_Renderer *renderer, TextureBank *TexBank, etatJeu *jeu, TTF_Font *font)
{
	int tailleCasePx  = (jeu->fenetreH) / (jeu->plateau->taille + 2);
	int decallageVert = tailleCasePx - (4 * (jeu->plateau->taille - 1));
	int int_y;
	int int_x;
	for (int_y = 0; int_y < jeu->plateau->taille; int_y++) {
		for (int_x = 0; int_x < jeu->plateau->taille; int_x++) {
			renderTexture(TexBank->bank[1]->tabTex[0], renderer, (int_x * (tailleCasePx + 4)) + decallageVert - 2,
						  (int_y * (tailleCasePx + 4)) + decallageVert - 2, tailleCasePx + 4, tailleCasePx + 4);
			if (jeu->plateau->tab[int_y][int_x] != 0) {
				creationCase(renderer, TexBank, jeu->plateau->tab[int_y][int_x], font, tailleCasePx);
				renderTexture(TexBank->bank[0]->tabTex[(int)(log2(jeu->plateau->tab[int_y][int_x])) - 1], renderer,
							  (int_x * (tailleCasePx + 4)) + decallageVert, (int_y * (tailleCasePx + 4)) + decallageVert, tailleCasePx, tailleCasePx);
			}
		}
	}
}
