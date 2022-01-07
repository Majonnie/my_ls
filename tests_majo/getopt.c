/*
** ETNA PROJECT, 06/01/2022 by bonhom_j
** /Users/majonnie/Desktop/ETNA/Projets/my_ls
** File description:
**      Programme permettant de récupérer les options passées où non lors de l'exécution de my_ls.
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "header.h"

int check_arg(int argc, char *argv[])
{
    int flags, opt;
    int nsecs, tfnd;

    nsecs = 0;
    tfnd = 0;
    flags = 0;

    my_debugstr("argc = ");
    my_debugnbr(argc);

    if (argv[1][0] == '-')
    {
        while ((opt = getopt(argc, argv, "lRrdtaAL1")) != -1)
        {
            switch (opt)
            {
            case 'l':
                my_putstr("Option : ");
                my_putchar(opt);
                my_putchar('\n');
                break;
            case 'R':
                my_putstr("Option : ");
                my_putchar(opt);
                my_putchar('\n');
                break;
            case 'r':
                my_putstr("Option : ");
                my_putchar(opt);
                my_putchar('\n');
                break;
            case 'd':
                my_putstr("Option : ");
                my_putchar(opt);
                my_putchar('\n');
                break;
            case 't':
                my_putstr("Option : ");
                my_putchar(opt);
                my_putchar('\n');
                break;
            case 'a':
                my_putstr("Option : ");
                my_putchar(opt);
                my_putchar('\n');
                break;
            case 'A':
                my_putstr("Option : ");
                my_putchar(opt);
                my_putchar('\n');
                break;
            case 'L':
                my_putstr("Option : ");
                my_putchar(opt);
                my_putchar('\n');
                break;
            case '1':
                my_putstr("Option : ");
                my_putchar(opt);
                my_putchar('\n');
                break;

            default: /* ? */
                //fprintf(stderr, "Usage: %s -lRd\n", argv[0]);
                my_putstr(argv[0]);
                my_putstr(" - Erreur !");
                my_putchar('\n');
                exit(EXIT_FAILURE);
            }
        }
    }

    else
    {
        my_putstr("Pas d'options");
        my_putchar('\n');
        optind = 1;
    }

    printf("optind=%d, argc =%d\n", optind, argc);
    // Garder en mémoire la valeur de optind puisque la suite des arguments contient la liste des fichier/repertoire passé en argument à ls
    if (optind <= argc) /* Gérer les dossiers / fichiers passés en paramètres et le remplacement pas un . s'il n'y en pas */
    {
        for (int i = optind; i < argc; i++)
            printf("argument %s\n", argv[i]);
    }

    //printf("name argument = %s\n", argv[optind]);

    /* Other code omitted */

    exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[])
{
    check_arg(argc, argv);
}
