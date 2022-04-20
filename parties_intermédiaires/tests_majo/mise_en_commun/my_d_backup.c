#include <dirent.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"

void my_d(char *dir)
{
	//int op_l = 0;
    struct dirent *d;  // on créé un objet dirent pour avoir accés à ses fonctions
    /*la fonction DIR permet de naviguer dans les fichiers
    la ligne suivante permet d'ouvrir le fichier demandé*/
	DIR *dh = opendir(dir);
    //Partie à copier
    while ((d = readdir(dh)) != NULL)
    {
        //Partie à copier
        int p = my_strlen(d->d_name);

        if(d->d_name[0] != '.')
            continue;
        else if(p > 1 )
            continue;
        else
        {
            my_putstr(d->d_name);
            my_putchar(' ');
            my_putchar(' ');
        }
    }
    my_putchar('\n');
}

int main ()
{
	my_d(".");
}