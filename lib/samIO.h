/*! @file samIO.h
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.2
 *  @date Thu Nov 21 09:10:46 2019
 *
 *  @brief Ensemble de fonction permettant de verfier que la saisie est correct
 *
 *
 */

// Inclusion des entêtes de librairies

#ifndef __SAMIO_H__
#define __SAMIO_H__

#include <stdlib.h>
#include <stdio.h>

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.2
 *  @date Fri Nov 15 14:17:58 2019
 *
 *  @brief Verifie si la valeur est bien un entier
 *
 *  @return la valeur entré par l'utilisateur
 *
 */
int saisieInt(void);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 17 Mar 2020 10:38
 *
 *  @brief Permet de saisir un entier et de verifier si ca valeur est dans l'intervalle attendu et affiche un texte avant la saisie
 *
 *  @param min : valeur maximum que peut prendre la valeur entrer
 *  @param max : valeur minimum que peut prendre la valeur entrer
 *  @param txt : (Optionel) permet d'ajouter un texte avant la saisie
 *  @return la valeur entré par l'utilisateur
 *
 */
int intTest(int min, int max, char *txt);

/**
 * @def varIntTest
 * Création d'un macro variadic pour pouvoir avoir un nombre variable d'argument
 */
#define varIntTest(min, max, txt, ...) (min), (max), (txt)
/**
 * @def saisieIntTest
 * Création d'un macro variadic pour pouvoir avoir un nombre variable d'argument
 */
#define saisieIntTest(...) intTest(varIntTest(__VA_ARGS__, "", ""))

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.2
 *  @date Fri Nov 15 14:17:58 2019
 *
 *  @brief Verifie si la valeur est bien un entier
 *
 *  @param[in,out] i_resultat : Pointeur vers l'entier
 *
 */
void ptSaisieInt(int *i_resultat);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 17 Mar 2020 10:38
 *
 *  @brief Permet de saisir un entier et de verifier si ca valeur est dans l'intervalle attendu et affiche un texte avant la saisie
 *
 *  @param i_val : pointeur vers la valeur a entrer
 *  @param min : valeur maximum que peut prendre la valeur entrer
 *  @param max : valeur minimum que peut prendre la valeur entrer
 *  @param txt : (Optionel) permet d'ajouter un texte avant la saisie
 *
 */
void ptIntTest(int *i_val, int min, int max, char *txt);

/**
 * Création d'un macro variadic pour pouvoir avoir un nombre variable d'argument
 */
#define varPtIntTest(i_val, min, max, txt, ...) (i_val), (min), (max), (txt)
/**
 * Création d'un macro variadic pour pouvoir avoir un nombre variable d'argument
 */
#define ptSaisieIntTest(...) ptIntTest(varPtIntTest(__VA_ARGS__, "", "", ""))

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.2
 *  @date Thu Nov 21 09:42:17 2019
 *
 *  @brief Verifie si la valeur est bien un double
 *
 *  @param[in,out] d_resultat : Retourne la valeur saisie si c'est bien un double
 *
 */
void saisieDouble(double *d_resultat);

/** @fn void doubleTest(double *d_val, double min, double max, char *txt)
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 17 Mar 2020 10:38
 *
 *  @brief Permet de saisir un entier et de verifier si ca valeur est dans l'intervalle attendu et affiche un texte avant la saisie
 *
 *  @param d_val : pointeur vers la valeur a entrer
 *  @param min : valeur maximum que peut prendre la valeur entrer
 *  @param max : valeur minimum que peut prendre la valeur entrer
 *  @param txt : (Optionel) permet d'ajouter un texte avant la saisie
 *
 */
void doubleTest(double *d_val, double min, double max, char *txt);

/**
 * Création d'un macro variadic pour pouvoir avoir un nombre variable d'argument
 */
#define varDoubleTest(d_val, min, max, txt, ...) (d_val), (min), (max), (txt)
/**
 * Création d'un macro variadic pour pouvoir avoir un nombre variable d'argument
 */
#define saisieDoubleTest(...) doubleTest(varDoubleTest(__VA_ARGS__, "", "", ""))

/*! @fn void saisieFloat (float* f_resultat)
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.2
 *  @date Thu Nov 21 09:42:17 2019
 *
 *  @brief Verifie si la valeur est bien un double
 *
 *
 *  @param[in,out] f_resultat : Retourne la valeur saisie si c'est bien un float
 *
 */
void saisieFloat(float *f_resultat);

/** @fn void floatTest(float *f_val, float min, float max, char *txt)
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 17 Mar 2020 10:38
 *
 *  @brief Permet de saisir un entier et de verifier si ca valeur est dans l'intervalle attendu et affiche un texte avant la saisie
 *
 *  @param f_val : pointeur vers la valeur a entrer
 *  @param min : valeur maximum que peut prendre la valeur entrer
 *  @param max : valeur minimum que peut prendre la valeur entrer
 *  @param txt : (Optionel) permet d'ajouter un texte avant la saisie
 *
 */
void floatTest(float *f_val, float min, float max, char *txt);

/**
 * Création d'un macro variadic pour pouvoir avoir un nombre variable d'argument
 */
#define varFloatTest(i_val, min, max, txt, ...) (i_val), (min), (max), (txt)
/**
 * Création d'un macro variadic pour pouvoir avoir un nombre variable d'argument
 */
#define saisieFloatTest(...) floatTest(varFloatTest(__VA_ARGS__, "", "", ""))

#endif
