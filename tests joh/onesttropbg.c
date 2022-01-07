
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
    if (n < 0)
        {
            n = -n;
            my_putchar('-');
        }
    if ( n >= 10 )
        {
            my_putnbr(n/10);

        }
    my_putchar(n%10 +'0');
}

void my_strchar(char *str)
{
    int i = 0;
    while (str[i] != '\n' || str[i] != '\n' )
    {
        if (str[i] == '\n')
        {
            str[i] = '\0';
        }
        else
        {
            i++;
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