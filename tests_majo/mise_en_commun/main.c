#include <dirent.h> //dirent permettra de parcourir les fichiers
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"
#include "my_l.h"


void my_ls(const char *dir,int op_a,int op_A,int op_d, int op_l, int argc, char *argv[]) //Ajouter au fur et à mesure un paramètre par option ?? --> booléens / int
{
    struct dirent *d;  // on créé un objet dirent pour avoir accés à ses fonctions
    /*la fonction DIR permet de naviguer dans les fichiers
    la ligne suivante permet d'ouvrir le fichier demandé*/
	DIR *dh = opendir(dir);

    if (dh == NULL) /* Si le dossier n'a pas pu être ouvert */
    {
        //Préciser l'erreur !!
        my_putstr("Problème d'ouverture.\n");
        exit(1);
    }

    //Il faut maintenant afficher les fichiers dans le dossier.
    while ((d = readdir(dh)) != NULL)
    {

        //Variables temporaires en attendant check_arg !!!
        //int A_isset = 1;
        //int a_isset = 0;
        //op_A = 1;
        //op_a = 0;

        //1) Si le programme rencontre des fichiers cachés. (options -a et -A)
        //Option -A
        if (op_A == 1 && op_a == 0)
        {
            if(my_strlen (d->d_name) == 1 && d->d_name[0] == '.')
                continue;
            else if(d->d_name[0] == '.' && d->d_name[1] == '.')
                continue;

            else
            {
                my_putstr(d->d_name);
                my_putchar('\n');
            }
        }
        //Option -a (prioritaire sur -A)
        else if (op_a == 1)
        {
            my_putstr(d->d_name);
            my_putchar('\n');
        }


        //Autres options

        //Option -l
        if (op_l == 1 && op_d == 0)
        {
            my_l((char *)dir, op_a, op_A); //problème dir
            exit(0);
        }

        //Option -d
        if (op_d == 1)
        {
            if (argc-index_argument == 1)
            {
                my_putstr(argv[index_argument]);
                my_putchar('\n');
            }
            else if (argc-index_argument == 0) {
                my_putchar('.');
                my_putchar('\n');
            }
            else {
                for (int i = index_argument; i < argc; ++i) {
                    my_putstr(argv[i]);
                    my_putchar('\n');
                }
            }
            exit(0);
        }

        //Sans option
        else {
            if (op_a == 0 && d->d_name[0] == '.') //Car pas d'option -a ou -A
                continue;
            my_putstr(d->d_name);
            my_putchar('\n');
        }

    }
}

int main(int argc, char *argv[])
{
    check_arg(argc,argv);
    if (aucun_argument == 1)
    {
        my_ls(".",a_isset,A_isset,d_isset,l_isset,argc,argv);
        my_putchar('\n');
    }
    else
    {
        //my_putnbr(index_argument);
        //my_putnbr(argc);
        //my_putnbr(argc-index_argument);
        if (argc-index_argument == 1 || d_isset == 1)
        {
            my_ls(argv[index_argument],a_isset,A_isset,d_isset,l_isset,argc,argv);
        }
        else
        {
            for (int i = index_argument; i < argc; ++i) {
                my_putstr(argv[i]);
                my_putstr(" : \n");
                my_ls(argv[i],a_isset,A_isset,d_isset,l_isset,argc,argv);
                my_putchar('\n');
            }
        }

    }
}


