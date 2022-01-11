#include <dirent.h> //dirent permettra de parcourir les fichiers
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "onesttropbg.h"


void my_ls(const char *dir,int op_a,int op_1)
{
    struct dirent *d;  // on créé un objet dirent pour avoir accés à ses fonctions
    /*la fonction DIR permet de naviguer dans les fichiers
    la ligne suivante permet d'ouvrir le fichier demandé*/
	DIR *dh = opendir(dir);

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
        //si le programme rencontre des fichiers cachés.
        if (!op_a && d->d_name[0] == '.')
            continue;
        my_putstr( d->d_name);
		my_putchar(' ');
		if(op_1) 
			my_putchar('\n');
    }
	if(!op_1)
		my_putchar('\n');
}

int main(int argc, const char *argv[])
{
    if (argc == 1)
	{
		my_ls(".",0,0);
	}

    else if (argc == 2)
	{
		if (argv[1][0] == '-')
		{
			
			int op_a = 0, op_1 = 0;
			char *p = (char*)(argv[1] + 1);
			while(*p){
				if(*p == 'a') op_a = 1;
				else if(*p == '1') op_1 = 1;
				else{
					exit(EXIT_FAILURE);
				}
				p++;
			}
			my_ls(".",op_a,op_1);
		}
	}
}