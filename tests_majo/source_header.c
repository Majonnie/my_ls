/*
** ETNA PROJECT, 04/01/2022 by bonhom_j
** /Users/majonnie/Desktop/ETNA/Projets/my_ls
** File description:
**      Librairie contenant des fonctions nécessaires pour le projet my_ls
*/

#include <unistd.h>
#include <stdlib.h>
#include <dirent.h> /*Permet d'utiliser opendir, readdir, etc*/

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(const char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        my_putchar(str[i]);
        i = i + 1;
    }
}

void my_putnbr(int n)
{
    if (n < 0)
    {
        n = -n;
        my_putchar('-');
    }
    if ( n >= 10 )
    {
        my_putnbr(n/10);

    }
    my_putchar(n%10 +'0');
}

char my_debugchar(char c)
{
#ifdef DEBUG
    my_putchar(c);
    my_putchar('\n');
#endif
    return (c);
}

const char *my_debugstr(const char *str)
{
#ifdef DEBUG
    my_putstr(str);
    my_putchar('\n');
#endif
    return (str);
}

int my_debugnbr(int n)
{
#ifdef DEBUG
    my_putnbr(n);
    my_putchar('\n');
#endif
    return (n);
}

int check_arg(int argc, char *argv[])
{
    int flags, opt;
    int nsecs, tfnd;

    nsecs = 0;
    tfnd = 0;
    flags = 0;

    int unique_dossier = 0;

    my_debugstr("argc = ");
    my_debugnbr(argc);

    if (argc > 1)
    {

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

    }


    //printf("optind=%d, argc =%d\n", optind, argc);
    else
    {
        unique_dossier = 1;
    }


    // Garder en mémoire la valeur de optind puisque la suite des arguments contient la liste des fichier/repertoire passé en argument à ls
    if (optind <= argc)
    {
        for (int i = optind; i < argc; i++)
        {
            my_putstr("Argument : ");
            my_putstr(argv[i]);
            my_putchar('\n');
        }
    }
    /* Gérer les dossiers / fichiers passés en paramètres et le remplacement pas un . s'il n'y en pas */
    else
    {
        //On devra checker dans le main si unique_dossier est défini : si oui, on affiche le contenu du dossier .
        my_putstr("Pas de nom de fichier précisé, sera remplacé par .");
        unique_dossier = 1;
    }

    //printf("name argument = %s\n", argv[optind]);

    /* Other code omitted */
    if (unique_dossier > 0)
    {
        my_debugstr("Aucun fichier n'a été passé en paramètre (devra être remplacé par .).");
    }
    else
    {
        my_debugstr("Au moins un fichier a été passé en paramètre.");
    }

    //exit(EXIT_SUCCESS);
    return (0);

}


int base_ls(int argc, char *argv[])
{
    struct dirent *sd;

    DIR *rep = NULL;
    //Remplacer argv[1] par le 1er (?) dossier après les options.
    rep = opendir(argv[1]); /* Ouverture d'un dossier */

    if (rep == NULL) /* Si le dossier n'a pas pu être ouvert */
    {
        //Gérer les différents types d'erreurs
        my_putstr("Problème d'ouverture.\n");
        exit(1); /* (mauvais chemin par exemple) */
    }

    my_debugstr("Le dossier a été ouvert avec succès\n");

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

    return (argc);
}



//Permet de tester les fonctions définies ci-dessus (écrire -DTEST lors de la compilation)
#ifdef TEST

int main(int argc, char **argv)
{
    my_putstr("ui");
    my_putchar('\n');

    my_putstr("test\n");

    my_debugchar('x');
    my_debugstr("Messages de debug : affichés.");
    my_debugnbr(69);

    //check_arg(argc, argv);
    base_ls(argc, argv);
}

#endif