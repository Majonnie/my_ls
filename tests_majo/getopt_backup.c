/*
** ETNA PROJECT, 06/01/2022 by bonhom_j
** /Users/majonnie/Desktop/ETNA/Projets/my_ls
** File description:
**      [BACKUP] Programme permettant de récupérer les options passées où non lors de l'exécution de my_ls.
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int flags, opt;
    int nsecs, tfnd;
    nsecs = 0;
    tfnd = 0;
    flags = 0;
    printf("argc =%d\n", argc);
    if (argv[1][0] == '-')
    {
        while ((opt = getopt(argc, argv, "lrRdtaAL")) != -1)
        {
            switch (opt)
            {
            case 'l':
                printf("option l\n");
                break;
            case 'R':
                printf("option R\n");
                break;
            case 'd':
                printf("option d\n");
                break;
            case 'A':
                printf("option %c\n", opt);
                break;
            case 'a':
                printf("option %c\n", opt);
                break;
            case 'r':
                printf("option %c\n", opt);
                break;
            default: /* ? */
                fprintf(stderr, "Usage: %s -lRd\n", argv[0]);
                exit(EXIT_FAILURE);
            }
        }
    }
    else
    {
        printf("pas d'options\n");
        optind = 1;
    }

    printf("optind=%d, argc =%d\n", optind, argc);
    // Garder en mémoire la valeur de optind puisque la suite des arguments contient la liste des fichier/repertoire passé en argument à ls
    if (optind <= argc)
    {
        for (int i = optind; i < argc; i++)
            printf("argument %s\n", argv[i]);
    }

    //printf("name argument = %s\n", argv[optind]);

    /* Other code omitted */

    exit(EXIT_SUCCESS);
}
