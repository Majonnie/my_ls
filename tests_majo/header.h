/*
** ETNA PROJECT, 04/01/2022 by bonhom_j
** /Users/majonnie/Desktop/ETNA/Projets/my_ls
** File description:
**      Librairie contenant des fonctions nécessaires pour le projet my_ls
*/
#ifndef POOL_FUNC
#define POOL_FUNC
void my_putchar(char c);

void my_putstr(const char *str);

void my_putnbr(int n);

char my_debugchar(char c);

const char *my_debugstr(const char *str);

int my_debugnbr(int n);

int check_arg(int argc, char *argv[]);

int base_ls(int argc, char *argv[]);

#endif