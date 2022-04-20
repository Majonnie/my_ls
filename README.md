# my_ls
Réimplémentation de la commande ls en C.

* Lancement du projet :
  * Entrez les commandes suivantes :
    - `make`
    - `./my_ls` + -[paramètre(s) de votre choix parmi ceux disponibles] + [dossier(s)]

* Paramètres disponibles : *-a, -A, -l et -d* (tous combinables)
  - -a : Affiche tous les fichiers et dossiers cachés (dont `.` et `..`) ;
  - -A : Affiche tous les fichiers et dossiers cachés (sauf `.`et `..`) ;
  - -l : Affiche des informations sur les fichiers et dossiers (type de fichier, droits, utilisateurs et groupes propriétaires, taille en octets, date de création, nom) ;
  - -d : Affiche les répertoires avec la même présentation que les fichiers, sans lister leur contenu.