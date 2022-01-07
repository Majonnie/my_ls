#include <stdlib.h> /* À supprimer ??*/

#include <dirent.h> /*Permet d'utiliser opendir, readdir, etc*/

#include "header.h"

int main(int argc, char **argv)
{
    my_debugnbr(argc);
    if (argc > 1)
    {
        my_debugstr(argv[1]);
    }

    struct dirent *sd;

    DIR *rep = NULL;
    rep = opendir(argv[1]); /* Ouverture d'un dossier */

    if (rep == NULL) /* Si le dossier n'a pas pu être ouvert */
    {
        my_putstr("Problème d'ouverture.\n");
        exit(1); /* (mauvais chemin par exemple) */
    }

    my_putstr("Le dossier a été ouvert avec succès\n");

    while ((sd = readdir(rep)) != NULL)
    {
        /* Commencer par gérer les options -a et-A */

        if (sd->d_name[0] != '.')
        {
            /* Changer l'affichage (en ligne la plupart du temps)*/
            my_putstr(">>  ");
            my_putstr(sd->d_name);
            my_putchar('\n');
        }
    }

    if (closedir(rep) == -1) /* S'il y a eu un souci avec la fermeture */
    {
        my_putstr("Problème de fermeture.\n");
        exit(-1);
    }

    my_putstr("Le dossier a été ouvert et fermé avec succès\n");
    my_debugstr("uwu");
    my_putstr("Fin owo\n");
    return 0;
}