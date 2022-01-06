#include <assert.h>
#include <dirent.h> //dirent permettra de parcourir les fichiers
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

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
	 	struct stat attrib;
	 	stat(d->d_name, &attrib);
	 	char time[50];
     	strftime(time, 50, "%Y-%m %H:%M", localtime(&attrib.st_mtime));

		struct stat fileStat;
		stat(d->d_name, &fileStat);
		//si le programme rencontre des fichiers cachés.
        if (d->d_name[0] == '.')
            continue;
		printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
		printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
		printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
		printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
		printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
		printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
		printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
		printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
		printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
		printf( (fileStat.st_mode & S_IXOTH) ? "x " : "- ");

        //si le programme rencontre des fichiers cachés.
        if (d->d_name[0] == '.')
            continue;
        printf("%s%s \n\n", ctime(&attrib.st_atime), d->d_name);
    }
}

int main ()
{
	my_ls(".");
}