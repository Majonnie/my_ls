#include <stdlib.h>
#include <stdio.h>

#include <dirent.h> /*Permet d'utiliser opendir, readdir, etc*/

#include "onesttropbg.h"

int main(int argc, char **argv)
{
    printf("%d\n", argc);
    my_putchar('\n');
    printf("%s\n", argv[1]);
    my_putchar('\n');

    struct dirent *sd;

    DIR *rep = NULL;
    rep = opendir(argv[1]); /* Ouverture d'un dossier */

    if (rep == NULL) /* Si le dossier n'a pas pu être ouvert */
    {
        puts("Problème d'ouverture.");
        exit(1); /* (mauvais chemin par exemple) */
    }

    puts("Le dossier a été ouvert avec succès");

    while ((sd = readdir(rep)) != NULL)
    {
        if (sd->d_name[0] != '.')
        {
            printf(">> %s\n", sd->d_name);
        }
    }

    if (closedir(rep) == -1) /* S'il y a eu un souci avec la fermeture */
    {
        puts("Problème de fermeture.");
        exit(-1);
    }

    puts("Le dossier a été fermé avec succès");

    return 0;
}