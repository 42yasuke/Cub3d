# 🧱 cub3D

**cub3D** est un projet graphique de l'école 42 inspiré de Wolfenstein 3D. Il consiste à créer un moteur de rendu 3D basé sur le **raycasting**, permettant à un joueur de se déplacer dans un labyrinthe en pseudo-3D à partir d’une carte en 2D.

## 🎯 Objectif

Implémenter un moteur 3D minimaliste avec raycasting, textures et déplacements immersifs à partir d’un environnement 2D, en utilisant uniquement la **MiniLibX**.

## 🧩 Fonctionnalités

- 🎮 Mouvements du joueur : avancer, reculer, tourner
- 🔍 Moteur de **raycasting** pour la perspective 3D
- 🖼️ Affichage de textures sur les murs
- 💥 Détection de collisions
- 📜 Parsing de fichiers `.cub` :
  - Résolution de l’écran
  - Chemins vers les textures (`NO`, `SO`, `WE`, `EA`)
  - Couleurs du sol et du plafond
  - Carte du monde (murs, vide, position du joueur)

## 🛠️ Compilation

```bash
make
```

## ▶️ Exécution

```bash
./cub3D maps/map.cub
```

## 📜 Format de la map

Un fichier `.cub` contient :

```bash
NO ./textures/wall_north.xpm
SO ./textures/wall_south.xpm
WE ./textures/wall_west.xpm
EA ./textures/wall_east.xpm
F 220,100,0
C 225,30,0

1111111111111
1000000000001
1011110111101
100000P000001
1111111111111
```
* `NO`, `SO`, `WE`, `EA` : chemins vers les textures murales
* `F`, `C` : couleurs du sol (Floor) et du plafond (Ceiling)
* La carte utilise :
  * `1` pour les murs
  * `0` pour l’espace vide
  * `P` ou `N`, `S`, `E`, `W` pour la position et orientation de départ du joueur

## 🎮 Contrôles

| Touche        | Action                         |
|---------------|--------------------------------|
| `W` / `S` | Avancer / Reculer |
| `A` / `D` | Déplacements latéraux |
| `←` / `→` |	Tourner à gauche / droite |
| `ESC` | Quitter le jeu |
