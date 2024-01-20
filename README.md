Ce projet est un jeu de terrain basé sur des classes C++ qui simulent un environnement de jeu. 
Les joueurs peuvent interagir avec le terrain en déplaçant des personnages, en combattant des monstres et en collectant des objets afin de sortir du chateau.

Fonctionnalités
Terrain : Le terrain est généré avec une taille spécifiée et contient diverses cases telles que des cases vides, des murs, des pièces et des positions spéciales.
Aventurier : Les joueurs peuvent contrôler un aventurier, l'aventurier a des points de vie, des points de force, une positions, et des équipements (Epée/Armure).
Objets : Les personnages peuvent collecter des objets tels que des armures et des armes pour améliorer leurs capacités.
Combat : Les monstres et les aventuriers peuvent s'affronter en utilisant leurs points de force. Les résultats du combat sont déterminés par des probabilités et des attributs spécifiques.


Installation
Clonez le dépôt GitHub sur votre machine locale.
Assurez-vous d'avoir un compilateur C++ compatible installé sur votre système.
Compilez les fichiers source à l'aide de la commande de compilation appropriée.
Exécutez l'exécutable généré pour lancer le jeu.
Utilisation
Au démarrage du jeu, vous serez présenté avec un menu pour choisir différentes options.
Sélectionnez les options correspondant aux actions que vous souhaitez effectuer, telles que déplacer un personnage, combattre un monstre ou collecter un objet.
Suivez les instructions à l'écran pour interagir avec le jeu.
Explorez le terrain, affrontez des monstres, améliorez vos personnages et découvrez les secrets du jeu.
Exemple d'utilisation
Voici un exemple d'utilisation pour vous aider à démarrer :

Exemple de l'affichage du terrain 
//////////////////////////////////////////////
/############################################/
/#......A...................................#/
/#...######....######.......................#/
/#...P.....#.m.#.....#......................#/
/#.........#...#.....#.................M....#/
/#...M...............#......................#/
/#...................#......................#/
/#.........########..#......................#/
/#..............P.#..#......................#/
/#................#..#......................#/
/#.........########..#######................#/
/#.........#.M.............#................#/
/#.........#.............@.#................#/
/#.........#################................#/
/#..........................................#/
/#############+##############################/
//////////////////////////////////////////////


Voici les commandes disponibles dans le jeu :

W : Déplacer le personnage vers le haut.
S : Déplacer le personnage vers le bas.
A : Déplacer le personnage vers la gauche.
D : Déplacer le personnage vers la droite.
Q,E,Z,C : Déplacer le personnage en diagonale (haut-gauche, haut-droite, bas-gauche, bas-droite).
R : Réparer l'armure du personnage.
F : Réparer l'épée du personnage.
