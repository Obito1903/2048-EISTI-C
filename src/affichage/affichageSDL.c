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
	// Si le rendu a pris moins de 16ms alors on attend jusqu'a ce que le temp totale soit de 16ms
	if (tmp < 0.016) {
		SDL_Delay(16 - tmp);

	} else /*Sinon on ne fait rien*/ {
		printf("jeu trop lent (%lf)\n", tmp);
	}
}

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

jeu *initAffichage(etatJeu *EtatJeu)
{
	jeu *Jeu = (jeu *)malloc(sizeof(jeu));
	initSDL();
	Jeu->etatJeu = EtatJeu;
	// Création de la fenêtre
	Jeu->window = SDL_CreateWindow("2048", 100, 100, EtatJeu->fenetreL, EtatJeu->fenetreH, SDL_WINDOW_SHOWN);
	if (Jeu->window == NULL) {
		printf("SDL_CreateWindow Error: %s \n", SDL_GetError());
		SDL_Quit();
		exit(EXIT_FAILURE);
	}
	// Création de l'ecran
	Jeu->renderer = SDL_CreateRenderer(Jeu->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (Jeu->renderer == NULL) {
		SDL_DestroyWindow(Jeu->window);
		printf("SDL_CreateRenderer Error: %s \n", SDL_GetError());
		SDL_Quit();
		exit(EXIT_FAILURE);
	}

	// Création de la banque de texture qui contiedra toutes les textures necaissaire a l'affichage
	Jeu->TextureBank					 = ajouteTextureBank(NULL);
	Jeu->TextureBank					 = ajouteTextureBank(Jeu->TextureBank);
	Jeu->TextureBank->bank[1]			 = allocNouvelleTexture(Jeu->TextureBank->bank[1]);
	Jeu->TextureBank->bank[1]->tabTex[0] = chargeTexture("./src/assets/template_background.png", Jeu->renderer);
	Jeu->font							 = trouvePolice(FONTSIZE);

	// Création d'un tableau qui contiendra les boutons a affiché a l'écran
	Jeu->boutons			= (Buttons *)malloc(sizeof(Buttons));
	Jeu->boutons->tabButton = NULL;
	Jeu->boutons->nbButtons = 0;
	return Jeu;
}

void mainAffichage(etatJeu *EtatJeu)
{
	jeu *	  Jeu = initAffichage(EtatJeu);
	SDL_Event event;

	chargeEtat(JEU, Jeu);

	clock_t start, end;
	double	cpu_time_used;

	while (EtatJeu->etatJeu) {
		start = clock();
		SDL_RenderClear(Jeu->renderer);
		gestionEvenement(Jeu, &event);
		dessiner(Jeu);
		SDL_RenderPresent(Jeu->renderer);
		end			  = clock();
		cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
		frameControl(cpu_time_used);
	}
	freeJeu(EtatJeu);
	TTF_CloseFont(Jeu->font);
	TTF_Quit();
	SDL_Quit();
}

void dessiner(jeu *Jeu)
{
	// On reinitialise la couleur de dessin
	SDL_SetRenderDrawColor(Jeu->renderer, 52, 52, 52, 255);
	switch (Jeu->etatJeu->etatJeu) {
		case 2:
			dessinePlateau(Jeu);
			break;
		default:
			break;
	}
	dessineBoutons(Jeu);
}

void dessineBoutons(jeu *Jeu)
{
	uint int_boutons;
	// On parcour le tableau de boutons et on les affichage un par un
	for (int_boutons = 0; int_boutons < Jeu->boutons->nbButtons; int_boutons++) {
		renderButtons(Jeu->boutons->tabButton[int_boutons], Jeu->renderer, Jeu->font);
	}
}

void creationTextureCase(jeu *Jeu, uint valCase, uint tailleCasePx)
{
	int int_text;
	// Si le tableau de texture des cases est vide alors on l'aloue et on y crée la premiere texture
	if (Jeu->TextureBank->bank[0]->tabTex == NULL) {
		Jeu->TextureBank->bank[0] =
			creeTextureCase(Jeu->renderer, Jeu->TextureBank->bank[0], Jeu->font, tailleCasePx, valCase);
	} else if (Jeu->TextureBank->bank[0]->taille < (int)(log2(valCase))) {
		// On crée la texture correspondant a la valeur de la case tout en s'assurant que les texture pour les valeurs
		// precedantes existes
		for (int_text = Jeu->TextureBank->bank[0]->taille; int_text < (int)(log2(valCase)); int_text++) {
			Jeu->TextureBank->bank[0] = creeTextureCase(Jeu->renderer, Jeu->TextureBank->bank[0], Jeu->font, tailleCasePx,
														(int)pow(2, int_text + 1));
		}
	}
}

void dessinePlateau(jeu *Jeu)
{
	int tailleCasePx  = (Jeu->etatJeu->fenetreH) / (Jeu->etatJeu->plateau->taille + 2);
	int decallageVert = tailleCasePx - (4 * (Jeu->etatJeu->plateau->taille - 1));
	int int_y;
	int int_x;
	for (int_y = 0; int_y < Jeu->etatJeu->plateau->taille; int_y++) {
		for (int_x = 0; int_x < Jeu->etatJeu->plateau->taille; int_x++) {
			// On dessine l'arriere plan (la grille)
			renderTexture(Jeu->TextureBank->bank[1]->tabTex[0], Jeu->renderer,
						  (int_x * (tailleCasePx + 4)) + decallageVert - 2, (int_y * (tailleCasePx + 4)) + decallageVert - 2,
						  tailleCasePx + 4, tailleCasePx + 4);
			// Puis on dessine les case si leur valeur est superieur a 0
			if (Jeu->etatJeu->plateau->tab[int_y][int_x] != 0) {
				creationTextureCase(Jeu, Jeu->etatJeu->plateau->tab[int_y][int_x], tailleCasePx);
				renderTexture(Jeu->TextureBank->bank[0]->tabTex[(int)(log2(Jeu->etatJeu->plateau->tab[int_y][int_x])) - 1],
							  Jeu->renderer, (int_x * (tailleCasePx + 4)) + decallageVert,
							  (int_y * (tailleCasePx + 4)) + decallageVert, tailleCasePx, tailleCasePx);
			}
		}
	}
}
