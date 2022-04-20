##
## ETNA PROJECT, 05/01/2022 by bonhom_j
## /Users/majonnie/Desktop/ETNA/Projets/my_ls
## File description:
##      Makefile
##

SRC = ./test_sans_printf.c
      ./onesttropbg.c

OBJ = $(SRC:.c=.o)

CFLAGS += -Werror -Wextra -I./include

NAME = my_ls

$(NAME): $(OBJ)
         gcc -o $(NAME) $(OBJ)

all:     $(NAME)

