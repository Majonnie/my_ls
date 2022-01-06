/*
** ETNA PROJECT, 04/01/2022 by bonhom_j
** /Users/majonnie/Desktop/ETNA/Projets/my_ls
** File description:
**      Tests avec argc et argv
*/

#include <stdio.h>

int main(int argc, char **argv)
{
    printf("%d\n", argc);
    printf("%s\n", argv[1]);

    int i;
    for (i = 0; i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }

    return (0);
}