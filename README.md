# Groupe de bonhom_j 944792

- --> À faire
+ --> Fait

* 03/01/2022
  - Passer le dossier en paramètre, retourner une erreur si le dossier ne peut pas être ouvert (nom inexistant, erreur d'accès...) ;

* 04/01/2022
  - Utilisation de printf ??
  + Lecture d'un dossier (readdir)
  - Gestion des erreurs (Joh ?)
  - Gestion des paramètres



1 ) Fonctions à faire
  affiche(char * str)
  debug(char *str ) appelle affiche(str) si DEBUG=1 si -D DEBUG
  debug (options/argc/argv)
1 )
si argc > 1 
  SI argv[1][0] == '-'
  GETOPT
  => options actives (debug)
  => Pointeur vers le argv[x] qui ets le premier argument de ls (nom de fichier/répertoire) (debug) (cas normal du ls -la tutu)
  Sinon => pas d'options et arguments = les argv (cas du ls toto tutu -l -r)
Sinon => pas d'options et arguments = '.' (cas du ls)


2 )
boucler sur les arguments >= optind (. ou liste des argv)
decode_arg
  lstat => détermine si rep ou fichier

fonction type_fichier(st_mode) return  cahracter
gérer st_mode de stat pour identifier le type de fichier (d,c,b,p,- = fichier,l)
if (decode == d) -> repeertoire à gérer

afficaheg des options de lstat dépendt des options passées (-l ou pas, -a)

