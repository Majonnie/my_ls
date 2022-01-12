#include <dirent.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include "onesttropbg.h"

void my_R(char *dir)
{
	//int op_l = 0;
    struct dirent *d;  // on créé un objet dirent pour avoir accés à ses fonctions
    /*la fonction DIR permet de naviguer dans les fichiers
    la ligne suivante permet d'ouvrir le fichier demandé*/
	DIR *dh = opendir(dir);
    while ((d = readdir(dh)) != NULL)
    {
        struct stat fileStat;
		stat(d->d_name, &fileStat);

        if (S_ISDIR(fileStat.st_mode))
        {
            my_putstr(d->d_name);
            my_putchar(':');
            my_putchar('\n');
     
        }                  
        else
        continue;
        my_putchar('\n');
    }    
}

int main ()
{
	my_R(".");
}