
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

void my_swap(char **a, char **b)
{
    char *a_bis = *a;
    *a = *b;
    *b = a_bis;
}

int my_strlen(const char *str) 
{
    int letters = 0;
    while (str[letters] != '\0')
        {
            letters++;  
        }
    return(letters);
}

int my_strcmp(const char *s1, const char *s2)
{
    int cont = 0;
    
    int diff = 0;

    while(s1[cont] != '\0' && s2[cont]!= '\0' && s1[cont] != s2[cont])
        {
            if(s1[cont] == s2[cont])
                {
                    cont++;
                }
            else
                {
                        diff = (s1[cont] - s2[cont]);
                }
        }
    return(diff);
}

void sortfiles(char *s1,char *s2)
{
    int cont = 0;


    while(s1[cont] != '\0' || s2[cont]!= '\0')
    {
        if (s1[cont] == s2[cont])
        {
            cont++;
        }
        else if (s1[cont] > s2[cont])
        {
            my_swap( &s1, &s2);
            break;
        }
        else 
        {
            break;
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