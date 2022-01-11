#include "header.h"

int main(int argc, char **argv)
{
    check_arg(argc, argv);

    base_ls(argc, argv);

    //Permet d'éviter l'erreur "unused parameter..."
    (void)argc;
    (void)argv;

    return(0);
}