#include <dirent.h> //dirent permettra de parcourir les fichiers
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"


void my_ls(const char *dir,int op_a,int op_A,int op_1) //Ajouter au fur et à mesure un paramètre par option ?? --> booléens / int
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

    //si on ne peut pas acceder au dossier, grace à la 3e librairie, on va gerer les erreurs.
    // if (!dh)
	// {
	// 	if (errno = ENOENT) // "ENOENT Directory does not exist, or name is an empty string." Explication du man opendir.
	// 	{
	// 		perror("Directory doesn't exist"); //UTILISER STRERROR
	// 	}
	// 	else // pour les autres erreurs, on dit qu'on ne peut pas lire le dossier demandé.
	// 	{
	// 		perror("Unable to read directory");//UTILISER STRERROR
	// 	}
	// 	exit(EXIT_FAILURE);
	// }

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
            //Partie à copier
            if(my_strlen (d->d_name) == 1 && d->d_name[0] == '.')
                continue;
            else if(d->d_name[0] == '.' && d->d_name[1] == '.')
                continue;

            else
            {
                my_putstr(d->d_name);
                my_putchar(' ');
                my_putchar(' ');
            }
        }
        //Option -a (prioritaire sur -A)
        else {
            if (a_isset == 0 && d->d_name[0] == '.')
                continue;
            my_putstr(d->d_name);
            my_putchar(' ');
            my_putchar(' ');
            if (op_1)
                my_putchar('\n');
        }
    }
}

int main(int argc, char *argv[])
{
    check_arg(argc,argv);
    if (aucun_argument == 1)
    {
        my_ls(".",a_isset,A_isset,one_isset);
        my_putchar('\n');
    }
    else
    {
        my_ls(argv[index_argument],a_isset,A_isset,one_isset);
        //Seg fault ici
        my_putchar('\n');
    }
}


