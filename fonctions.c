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

//Variables globales
int aucun_argument = 0;
int index_argument;
//Options : lRrdtaAL1
int l_isset = 0;
int R_isset = 0;
int r_isset = 0;
int d_isset = 0;
int t_isset = 0;
int a_isset = 0;
int A_isset = 0;
int L_isset = 0;
int one_isset = 0;

int check_arg(int argc, char *argv[])
{
    int flags, opt;
    int nsecs, tfnd;

    nsecs = 0;
    tfnd = 0;
    flags = 0;

    my_debugstr("argc = ");
    my_debugnbr(argc);

    if (argc > 1 && argv[1][0] == '-')
    {
        while ((opt = getopt(argc, argv, "lRrdtaAL")) != -1)
        {
            switch (opt)
            {
                case 'l':
                    l_isset = 1;
                    my_debugstr("Option : ");
                    my_debugchar(opt);
                    break;
                case 'R':
                    R_isset = 1;
                    my_debugstr("Option : ");
                    my_debugchar(opt);
                    break;
                case 'r':
                    r_isset = 1;
                    my_debugstr("Option : ");
                    my_debugchar(opt);
                    break;
                case 'd':
                    d_isset = 1;
                    my_debugstr("Option : ");
                    my_debugchar(opt);
                    break;
                case 't':
                    t_isset = 1;
                    my_debugstr("Option : ");
                    my_debugchar(opt);
                    break;
                case 'a':
                    a_isset = 1;
                    my_debugstr("Option : ");
                    my_debugchar(opt);
                    break;
                case 'A':
                    A_isset = 1;
                    my_debugstr("Option : ");
                    my_debugchar(opt);
                    break;
                case 'L':
                    L_isset = 1;
                    my_debugstr("Option : ");
                    my_debugchar(opt);
                    break;

                default: /* ? */
                    my_putstr(argv[0]);
                    my_putstr(" - Erreur !");
                    my_putchar('\n');
                    exit(EXIT_FAILURE);
            }
        }
    }

    else {
        my_debugstr("Pas d'options");
        optind = 1;
    }

    if (argc == 1)
    {
        aucun_argument = 1;
    }


    // Garder en mémoire la valeur de optind puisque la suite des arguments contient la liste des fichier/répertoires passés en argument à ls
    my_debugnbr(optind);
    my_debugnbr(argc);

    index_argument = optind;
    //Lecture des arguments (autres que des options)
    if (optind < argc)
    {
        for (int i = optind; i < argc; i++)
        {
            my_debugstr("Argument : ");
            my_debugstr(argv[i]);
            my_debugchar('\n');
        }
    }
    /* Gérer les dossiers / fichiers passés en paramètres et le remplacement pas un . s'il n'y en pas */
    else
    {
        //On devra checker dans le main si aucun_argument == 1 : si oui, on affiche le contenu du dossier .
        //my_debugstr("Pas de nom de fichier précisé, sera remplacé par .");
        aucun_argument = 1;
    }

    //printf("name argument = %s\n", argv[optind]);

    /* Other code omitted */
    if (aucun_argument > 0)
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

void my_swap(char **a, char **b)
{
    char *a_bis = *a;
    *a = *b;
    *b = a_bis;
}

int my_strlen(const char *str)
{
    int letters = 0;
    while (str[letters] != '\0')
    {
        letters++;
    }
    return(letters);
}

int my_strcmp(const char *s1, const char *s2)
{
    int cont = 0;

    int diff = 0;

    while(s1[cont] != '\0' && s2[cont]!= '\0' && s1[cont] != s2[cont])
    {
        if(s1[cont] == s2[cont])
        {
            cont++;
        }
        else
        {
            diff = (s1[cont] - s2[cont]);
        }
    }
    return(diff);
}

void sortfiles(char *s1,char *s2)
{
    int cont = 0;


    while(s1[cont] != '\0' || s2[cont]!= '\0')
    {
        if (s1[cont] == s2[cont])
        {
            cont++;
        }
        else if (s1[cont] > s2[cont])
        {
            my_swap( &s1, &s2);
            break;
        }
        else
        {
            break;
        }
    }
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

    check_arg(argc, argv);
    base_ls(argc, argv);
    my_debugstr("aucun_argument =");
    my_debugnbr(aucun_argument);
}

#endif