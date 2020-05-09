/** @file affichageTerm.c
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 05 May 2020 23:49
 *
 *  @brief Librairie pour la gestion de l'affichage dans un terminal
 *
 */

#include "affichageTerm.h"

void reset_terminal_mode(void)
{
    tcsetattr(0, TCSANOW, &orig_termios);
    printf("\033[?25h\r\n");
}

void set_conio_terminal_mode(void)
{
    struct termios new_termios;

    /* take two copies - one for now, one for later */
    tcgetattr(0, &orig_termios);
    memcpy(&new_termios, &orig_termios, sizeof(new_termios));

    /* register cleanup handler, and set the new terminal mode */
    atexit(reset_terminal_mode);
    cfmakeraw(&new_termios);
    tcsetattr(0, TCSANOW, &new_termios);
    printf("\033[?25l\r\n");
}

int kbhit(void)
{
    struct timeval tv = {0L, 0L};
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(0, &fds);
    return select(1, &fds, NULL, NULL, &tv);
}

screen *allocEcran(uint hauteur, uint largeur)
{
    uint int_h;
    screen *Ecran = (screen *)malloc(sizeof(screen)); // Variable de retour
    if (Ecran == NULL)
        erreur(alloc, "Echec allocation Ecran");
    Ecran->hauteur = hauteur;
    Ecran->largeur = largeur;

    Ecran->background = (pixelRGB **)malloc(sizeof(pixelRGB *) * hauteur);
    if (Ecran->background == NULL)
        erreur(alloc, "Echec allocation Ecran->background");
    for (int_h = 0; int_h < hauteur; int_h++)
    {
        Ecran->background[int_h] = (pixelRGB *)malloc(sizeof(pixelRGB) * largeur);
        if (Ecran->background[int_h] == NULL)
            erreur(alloc, "Echec allocation Ecran->background[]");
    }

    Ecran->foreground = (pixelRGB **)malloc(sizeof(pixelRGB *) * hauteur);
    if (Ecran->foreground == NULL)
        erreur(alloc, "Echec allocation Ecran->background");
    for (int_h = 0; int_h < hauteur; int_h++)
    {
        Ecran->foreground[int_h] = (pixelRGB *)malloc(sizeof(pixelRGB) * largeur);
        if (Ecran->foreground[int_h] == NULL)
            erreur(alloc, "Echec allocation Ecran->background[]");
    }
    return (Ecran);
}

void freeEcran(screen *Ecran)
{
    uint int_h;
    for (int_h = 0; int_h < Ecran->hauteur; int_h++)
    {
        free(Ecran->foreground[int_h]);
    }
    free(Ecran->foreground);

    for (int_h = 0; int_h < Ecran->hauteur; int_h++)
    {
        free(Ecran->background[int_h]);
    }
    free(Ecran->background);

    free(Ecran);
}

void initEcran(screen *Ecran)
{
    uint int_h;
    uint int_l;
    pixelRGB *bPixel;
    pixelRGB *fPixel;
    for (int_h = 0; int_h < Ecran->hauteur; int_h++)
    {
        for (int_l = 0; int_l < Ecran->largeur; int_l++)
        {
            bPixel = &Ecran->background[int_h][int_l];
            bPixel->color.r = 0;
            bPixel->color.g = 0;
            bPixel->color.b = 0;
            bPixel->element = 0;
            fPixel = &Ecran->foreground[int_h][int_l];
            fPixel->color.r = 255;
            fPixel->color.g = 255;
            fPixel->color.b = 255;
            fPixel->element = 32;
        }
    }
}

Bool afficheEcran(screen *Ecran)
{
    system("clear");
    uint int_h;
    uint int_l;
    pixelRGB *bPixel;
    pixelRGB *fPixel;
    for (int_h = 0; int_h < Ecran->hauteur; int_h++)
    {
        for (int_l = 0; int_l < Ecran->largeur; int_l++)
        {
            bPixel = &Ecran->background[int_h][int_l];
            if (bPixel->color.r && bPixel->color.g && bPixel->color.b)
            {
                printf("\033[48;2;%d;%d;%dm", bPixel->color.r, bPixel->color.g, bPixel->color.b);
            }
            fPixel = &Ecran->foreground[int_h][int_l];
            printf("\033[38;2;%d;%d;%dm%c\033[39m\033[49m", fPixel->color.r, fPixel->color.g, fPixel->color.b, fPixel->element);
        }
        printf("\r\n");
    }
    return (True);
}

tabStr *divString(uint lMax, char *str)
{
    tabStr *listeStr = (tabStr *)malloc(sizeof(tabStr)); // Variable de retour
    listeStr->taille = 1;
    listeStr->tab = (char **)malloc(sizeof(char *));
    listeStr->tab[0] = str;
    uint int_i;
    uint int_str = 0;
    while (strlen(listeStr->tab[int_str]) > lMax)
    {
        listeStr->taille++;
        listeStr->tab = (char **)realloc(listeStr->tab, sizeof(char *) * listeStr->taille);
        listeStr->tab[int_str + 1] = (char *)malloc(sizeof(char) * (strlen(listeStr->tab[int_str]) - (lMax - 1)));
        for (int_i = lMax; int_i < strlen(listeStr->tab[int_str]); int_i++)
        {
            listeStr->tab[int_str + 1][int_i - lMax] = listeStr->tab[int_str][int_i];
        }

        char *strTmp = (char *)malloc(sizeof(char) * (lMax + 1));
        strncpy(strTmp, listeStr->tab[int_str], lMax);
        strTmp[lMax] = '\0';
        listeStr->tab[int_str] = (char *)malloc(sizeof(char) * strlen(strTmp) + 1);
        strcpy(listeStr->tab[int_str], strTmp);
        free(strTmp);
        int_str++;
    }
    return (listeStr);
}

uint __AfficheStringEcran(screen *Ecran, uint hauteur, char *strOrig, Bool selection)
{
    uint retour = 0;
    uint posLargeur;
    uint int_i;
    uint int_char;
    tabStr *listeStr = divString(Ecran->largeur - 2, strOrig);

    couleurPix couleurbSelection = {255, 255, 255};
    couleurPix couleurfSelection = {0, 0, 0};

    listeStr->hauteur = hauteur;

    for (int_i = 0; int_i < listeStr->taille; int_i++)
    {
        for (int_char = 0; int_char < strlen(listeStr->tab[int_i]); int_char++)
        {
            posLargeur = (((Ecran->largeur) - strlen(listeStr->tab[int_i])) / 2) + int_char;
            if (selection)
            {
                Ecran->background[hauteur][posLargeur].color = couleurbSelection;
                Ecran->foreground[hauteur][posLargeur].color = couleurfSelection;
            }
            Ecran->foreground[hauteur][posLargeur].element = listeStr->tab[int_i][int_char];
        }
        hauteur++;
    }
    retour = listeStr->taille - 1;
    for (int_i = 0; int_i < listeStr->taille; int_i++)
    {
        free(listeStr->tab);
    }
    free(listeStr);
    return retour;
}

void affichesListeStringEcran(screen *Ecran, lListTabStr *listeStr)
{
    uint decalage = 0;
    noeudListTabStr *listeStrActu = listeStr;
    while (listeStrActu != NULL)
    {
        decalage = decalage + __AfficheStringEcran(Ecran, listeStrActu->hauteur + decalage, listeStrActu->str, listeStrActu->selection);
        listeStrActu = listeStrActu->suivant;
    }
}

noeudListTabStr *allocNoeudListTabStr(uint hauteur, char *str, uint id)
{
    noeudListTabStr *elementListe = (noeudListTabStr *)malloc(sizeof(noeudListTabStr)); // Variable de retour

    if (str != NULL)
    {
        elementListe->str = (char *)malloc(sizeof(char) * (strlen(str) + 1));
        strcpy(elementListe->str, str);
    }
    else
    {
        elementListe->str = NULL;
    }

    elementListe->id = id;
    elementListe->hauteur = hauteur;
    elementListe->selection = False;
    elementListe->precedent = NULL;
    elementListe->suivant = NULL;

    return (elementListe);
}

void ajouteStringListe(lListTabStr *liste, uint hauteur, char *str, Bool selection, uint id)
{
    if (liste->str == NULL)
    {
        liste->str = (char *)malloc(sizeof(char) * (strlen(str) + 1));
        strcpy(liste->str, str);
        liste->id = id;
        liste->hauteur = hauteur;
        liste->selection = selection;
    }
    else
    {
        noeudListTabStr *nouveauNoeud = allocNoeudListTabStr(hauteur, str, id);
        noeudListTabStr *noeudActu = liste;
        while (noeudActu->suivant != NULL)
        {
            noeudActu = noeudActu->suivant;
        }
        nouveauNoeud->precedent = noeudActu;
        nouveauNoeud->selection = selection;
        noeudActu->suivant = nouveauNoeud;
    }
}

noeudListTabStr *trouveStrSelection(lListTabStr *liste)
{
    noeudListTabStr *noeudSelection = NULL; // Variable de retour
    noeudListTabStr *noeudActu = liste;
    while ((noeudActu != NULL) && (noeudSelection == NULL))
    {
        if (noeudActu->selection)
        {
            noeudSelection = noeudActu;
        }
        noeudActu = noeudActu->suivant;
    }
    return (noeudSelection);
}

void changeSelection(lListTabStr *liste, int direction)
{
    noeudListTabStr *currentString = trouveStrSelection(liste);
    if (direction && (currentString->suivant != NULL))
    {
        currentString->selection = False;
        currentString->suivant->selection = True;
    }
    else if (!direction && currentString->precedent != NULL)
    {
        currentString->selection = False;
        currentString->precedent->selection = True;
    }
}
