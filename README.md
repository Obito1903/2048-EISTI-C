# Projet 2020

Projet 2020.

[Git](https://gitlab.etude.eisti.fr/rodriguess/projet-2020)

## Utilisation

### Compilation

L'éxécutable se trouvera dans le dossier `bin`

#### Linux

Sous linux la compilation nécessite les bibliothèques suivantes :

- libsdl2-dev
- libsdl2-image-dev
- libsdl2-ttf-dev

Une fois les dependances nécessaires installées il suffit d'executer les commandes suivantes

```shell
make all && make clean
```

pour supprimer aussi l'éxécutable

```shell
make cleanall
```

#### Windows

Sous windows il faudra telecharger la bibliothèque de developpement SDL2 et extraire les fichiers de la bibliotèque où se trouvent les fichiers du jeu

Une fois les dépendances nécessaires installées il suffit d'executer la commande suivante

```shell
make win && make clean
```

### Execution

```shell
./projet
```

#### Options

```shell
./projet -t <taille>
```

Permet de spécifier la taille du plateau.

```shell
./projet -l <Chemain sav>
```

Permet de charger un fichier de sauvegarde.

#### Interaction

Le jeu se joue avec les flèches du clavier. La touche `echap` permet d'afficher un menu avec l'option de sauvegarder la partie ou bien quitter le jeu.

### Rapport

Rien pour l'instant.

### Docs

Rien pour l'instant.

### Wiki

Le wiki dispinible [ici](Docs/Wiki/Wiki.md) nous sert a expliquer comment chaque element du jeu est implementé.

## Outils

Quelques infos sur les outils que je conseille d'utiliser durant ce projet

### Git

Git est un outil permettant le partage et la gestion des modifications d'un code source.

Pour plus d'infos sur son utilisation [ici](Docs/GIT.md)

### VSCode

Je vous conseille d'utiliser VSCode comme éditeur etant donné que c'est un éditeur de code puissant et simple a prendre en main.
