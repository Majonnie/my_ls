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