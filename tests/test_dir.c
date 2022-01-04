#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <dirent.h> /*Permet d'utiliser opendir, readdir, etc*/

int main(void)
{
    DIR *rep = NULL;
    rep = opendir("pouet"); /* Ouverture d'un dossier */

    if (rep == NULL) /* Si le dossier n'a pas pu être ouvert */
    {
        puts("Problème d'ouverture.");
        exit(1); /* (mauvais chemin par exemple) */
    }

    puts("Le dossier a ete ouvert avec succes");

    if (closedir(rep) == -1) /* S'il y a eu un souci avec la fermeture */
    {
        puts("Problème de fermeture.");
        exit(-1);
    }

    puts("Le dossier a ete ferme avec succes");

    return 0;
}