SRC = ./main.c \
	./fonctions.c \
	./my_l.c
OBJ = $(SRC:.c=.o)
CFLAGS += -Wall -Werror -Wextra
#define DEBUG
NAME = my_ls

# Ajouter -DTEST ou -DTEST_L pour les tests des fichiers fonctions.c ou my_l.c ; et -DDEBUG pour les messages de debug. --> hors Makefile
$(NAME): $(OBJ)
	gcc $(CFLAGS) -o $(NAME) $(OBJ)

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)


re: fclean all