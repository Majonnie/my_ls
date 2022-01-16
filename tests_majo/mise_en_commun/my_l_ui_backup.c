#include <assert.h>
#include <dirent.h> //dirent permettra de parcourir les fichiers
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
//#include <sys/sysmacros.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include "fonctions.h"

void my_l(const char *dir, int op_a, int op_A)
{
    struct dirent *d;  // on créé un objet dirent pour avoir accés à ses fonctions
    /*la fonction DIR permet de naviguer dans les fichiers
    la ligne suivante permet d'ouvrir le fichier demandé*/
	DIR *dh = opendir(dir);  

	while ((d = readdir(dh)) != NULL)
	{
	 	struct stat modifdate;
	 	stat(d->d_name, &modifdate);
	 	char time[50];
     	strftime(time, 50, "%b %e %H:%M", localtime(&modifdate.st_mtime));

		struct stat fileStat;
		stat(d->d_name, &fileStat);


		//si le programme rencontre des fichiers cachés.
        if (d->d_name[0] == '.')
            my_putstr("Fichier caché rencontré ! | ");
            //continue;

		if (S_ISDIR(fileStat.st_mode)) {
			my_putchar('d');
		}
    	else if(S_ISCHR(fileStat.st_mode))
        	my_putchar('c');
		else if(S_ISBLK(fileStat.st_mode))
			my_putchar('b');
		else if(S_ISFIFO(fileStat.st_mode))
			my_putchar('f');
		else if(S_ISSOCK(fileStat.st_mode))
			my_putchar('s');
		else{
			my_putchar('-');
		}

		if (fileStat.st_mode & S_IRUSR){
			my_putchar('r');
		} else{
			my_putchar('-');
		}

		if (fileStat.st_mode & S_IWUSR){
			my_putchar('w');
		}else{
			my_putchar('-');
		}

		if (fileStat.st_mode & S_IXUSR){
			my_putchar('x');
		}else{
			my_putchar('-');
		}

		if (fileStat.st_mode & S_IRGRP){
			my_putchar('r');
		} else{
			my_putchar('-');
		}

		if (fileStat.st_mode & S_IWGRP){
			my_putchar('w');
		}else{
			my_putchar('-');
		}

		if (fileStat.st_mode & S_IXGRP){
			my_putchar('x');
		}else{
			my_putchar('-');
		}

		if (fileStat.st_mode & S_IROTH){
			my_putchar('r');
		} else{
			my_putchar('-');
		}

		if (fileStat.st_mode & S_IWOTH){
			my_putchar('w');
		}else{
			my_putchar('-');
		}

		if (fileStat.st_mode & S_IXOTH){
			my_putchar('x');
			my_putchar(' ');
		} else{
			my_putchar('-');
			my_putchar(' ');
		}

		struct stat hardlinks = {0};
    	lstat(d->d_name, &hardlinks);

		struct stat size;
		stat(d->d_name, &size);

    	struct stat sb;
		stat(d->d_name, &sb);


        //si le programme rencontre des fichiers cachés.
        if (d->d_name[0] == '.')
            my_putstr("Fichier caché rencontré ! | ");
            //continue;

		my_putnbr(hardlinks.st_nlink );
		my_putchar(' ');
		my_putstr(getpwuid(sb.st_uid)->pw_name);
		my_putchar(' ');
		my_putstr(getgrgid(sb.st_gid)->gr_name);
		my_putchar(' ');
		my_putnbr(size.st_size);
		my_putchar(' ');
		my_putstr(time);
		my_putchar(' ');
		my_putstr(d->d_name );
		my_putchar('\n');
    }
}

#ifdef TEST_L
int main ()
{
	my_l(".", a_isset, A_isset);
}
#endif