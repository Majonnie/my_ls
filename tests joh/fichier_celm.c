#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdint.h>
#include <pwd.h>
#include <grp.h>

void my_ls(DIR *dir) // création de la fonction ls
{
    struct dirent *dirent; // création d'une structure
    struct stat sb;

    while ((dirent = readdir(dir)) != NULL) // boucle : tant que la lecture du dossier est différent de nul
    {
        if (dirent->d_name[0] != '.') // condition : si la structure de d_name[0] n'est pas un "."
        {
            stat(dirent->d_name, &sb);
            printf("%s %s %s\n", dirent->d_name, getpwuid(sb.st_uid)->pw_name, getgrgid(sb.st_gid)->gr_name);
        }
    }
}

int main(int argc, char *argv[]) // fonction principal
{
    DIR *dir;                                       //DIR = dir
    char *folder_name = (argc < 2) ? "." : argv[1]; // folder_name =

    if ((dir = opendir(folder_name)) == NULL) // si le dossier = nul
    {
        printf("./a.out: '%s': No such file or directory\n", folder_name); // affichage
        return (1);
    }
    my_ls(dir);    // lancement de la fonction my_ls
    closedir(dir); // fermer le dossier

    return 0;
}