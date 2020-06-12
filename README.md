# Projet 2020

Projet 2020.

[Git](https://gitlab.etude.eisti.fr/rodriguess/projet-2020)

## Utilisation

### Compilation

l'executable se trouvera dans le dossier `bin`

#### Linux

Sous linux la compilation nécessite les bibliothèques suivantes :

- libsdl2-dev
- libsdl2-image-dev
- libsdl2-ttf-dev

Une fois les dependances nécaissaire installé il suffit d'executé le commande suivante

```shell
make all && make clean
```

pour surpimer aussi l'executable

```shell
make cleanall
```

#### Windows

Sous windows il faudra telechargé la bibliothèque de developpement SDL2 et extraire les fichier de la bibliotèque ou ce trouve le les fichier du jeu

Une fois les dependances nécaissaire installé il suffit d'executé le commande suivante

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

Permet de specifier la taille du plateau.

```shell
./projet -l <Chemain sav>
```

Permet de charger un fichier de sauvegarde.

#### Interaction

Le jeu ce joue avec les flêches du clavier. La touche `echape` permet d'affiché un menu avec l'option de sauvegarder la partie ou bien quitter le jeu.

### Rapport

Rien pour l'instant.

### Docs

Rien pour l'instant.

### Wiki

Le wiki dispinible [ici](Docs/Wiki/Wiki.md) nous sert a expliqué comment chaque element du jeu est implementer.

## Outils

Quelques info sur les outils que je conseille d'utiliser durant ce projet

### Git

Git est un outil permettant le partage et la gestion des modification d'un code source.

Pour plus d'info sur son utilisation [ici](Docs/GIT.md)

### VSCode

Je vous conseille d'utiliser VSCode comme editeur etant donné que c'est un editeur de code puissant et simple a prendre en mains.
