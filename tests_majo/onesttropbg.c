/*
** ETNA PROJECT, 04/01/2022 by bonhom_j
** /Users/majonnie/Desktop/ETNA/Projets/my_ls
** File description:
**      Librairie contenant des fonctions nécessaires pour le projet my_ls
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(const char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        my_putchar(str[i]);
        i = i + 1;
    }
}

void my_putnbr(int n)
{
    int res;
    // On teste si le nombre est négatif
    // Pour afficher le signe dès le début et mettre le nombre en positif pour pouvoir effectuer les calculs
    if (n >= -2147483648 && n <= 2147483647)
    {
        if (n < 0)
        {
            n = -n;
            my_putchar('-');
        }
        // On calcule le modulo (reste de la division)
        // cela nous donne le chiffre des unités du nombre manipulé
        res = n % 10;
        if (n <= 9 && n >= 0)
        {
            // Le nombre est composé d'un seul chiffre, on l'affiche directement
            my_putchar('0' + res);
        }
        else if (n > 9)
        {
            // On s'appelle en récursif pour décomposer le reste du nombre
            my_putnbr(n / 10);
            my_putchar('0' + res);
        }
    }
}

const char *my_debug(const char *str)
{
#ifdef DEBUG
    my_putstr(str);
    my_putchar('\n');
#endif
    return (str);
}

//Permet de tester les fonctions définies ci-dessus (écrire -DTEST lors de la compilation)
#ifdef TEST

int main(void)
{
    my_putstr("ui");
    my_putchar('\n');

    my_debug("Messages de debug : affichés.");
}

#endif