#include <stdlib.h>
#include <stdio.h>

#include <dirent.h> /*Permet d'utiliser opendir, readdir, etc*/

#include "onesttropbg.h"

int main(int argc, char **argv)
{
    my_putnbr(argc);
    my_putchar('\n');
    my_putstr(argv[1]);
    my_putchar('\n');
    my_putchar('\n');

    struct dirent *sd;

    DIR *rep = NULL;
    rep = opendir(argv[1]); /* Ouverture d'un dossier */

    if (rep == NULL) /* Si le dossier n'a pas pu être ouvert */
    {
        my_putstr("Problème d'ouverture.");
        exit(1); /* (mauvais chemin par exemple) */
    }

    my_putstr("Le dossier a été ouvert avec succès");
    my_putchar('\n');

    while ((sd = readdir(rep)) != NULL)
    {
        if (sd->d_name[0] != '.')
        {
            /* Changer l'affichage (en ligne la plupart du temps)*/
            const char *prompt = ">>";
            my_putstr(prompt);
            my_putstr("   ");
            my_putstr(sd->d_name);
            my_putchar('\n');
        }
    }

    if (closedir(rep) == -1) /* S'il y a eu un souci avec la fermeture */
    {
        my_putstr("Problème de fermeture.");
        exit(-1);
    }

    my_putstr("Le dossier a été fermé avec succès");
    my_putchar('\n');

    return 0;
}