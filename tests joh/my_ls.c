#include <assert.h>
#include <dirent.h> //dirent permettra de parcourir les fichiers
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

void my_ls(const char *dir)
{
	//int op_l = 0;
    struct dirent *d;  // on créé un objet dirent pour avoir accés à ses fonctions
    /*la fonction DIR permet de naviguer dans les fichiers
    la ligne suivante permet d'ouvrir le fichier demandé*/
	DIR *dh = opendir(dir);  

     //si on ne peut pas acceder au dossier, grace à la 3e librairie, on va gerer les erreurs.
    if (!dh)
	{
		if (errno = ENOENT) // "ENOENT Directory does not exist, or name is an empty string." Explication du man opendir.
		{
            perror("Directory doesn't exist"); //UTILISER STRERROR
		}
		else // pour les autres erreurs, on dit qu'on ne peut pas lire le dossier demandé.
		{
			perror("Unable to read directory"); //UTILISER STRERROR
		}
		exit(EXIT_FAILURE);        
	}

	while ((d = readdir(dh)) != NULL)
	{
		time_t rawtime;
		struct tm *info;
		char buffer[80];

		time( &rawtime );

		info = localtime( &rawtime );

		strftime(buffer,80,"%b  %d %H:%M", info);
        //si le programme rencontre des fichiers cachés.
        if (d->d_name[0] == '.')
            continue;
        printf("%s %s \n", buffer, d->d_name);
    }
}

int main ()
{
		my_ls(".");
}