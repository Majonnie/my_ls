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

//Variables globales
int aucun_argument;
int index_argument;
//Options : lRrdtaAL1
int l_isset;
int R_isset;
int r_isset;
int d_isset;
int t_isset;
int a_isset;
int A_isset;
int L_isset;

int check_arg(int argc, char *argv[]);

int base_ls(int argc, char *argv[]); //Ça dégage

void my_swap(char **a, char **b);

int my_strlen(const char *str);

int my_strcmp(const char *s1, const char *s2);

void sortfiles(char *s1,char *s2);


#endif