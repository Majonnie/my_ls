#include <stdlib.h>
#include <stdio.h>

#include <dirent.h> /*Permet d'utiliser opendir, readdir, etc*/

int main(int argc, char **argv)
{
    printf("%d\n", argc);
    printf("%s\n", argv[1]);

    struct dirent *sd;

    DIR *rep = NULL;
    rep = opendir(argv[1]); /* Ouverture d'un dossier */

    if (rep == NULL) /* Si le dossier n'a pas pu être ouvert */
    {
        puts("Problème d'ouverture.");
        exit(1); /* (mauvais chemin par exemple) */
    }

    puts("Le dossier a ete ouvert avec succes");

    while ((sd = readdir(rep)) != NULL)
    {
        printf(">> %s\n", sd->d_name);
    }

    if (closedir(rep) == -1) /* S'il y a eu un souci avec la fermeture */
    {
        puts("Problème de fermeture.");
        exit(-1);
    }

    puts("Le dossier a ete ferme avec succes");

    return 0;
}