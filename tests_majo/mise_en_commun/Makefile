SRC = ./main.c \
	./fonctions.c \
	./my_l.c
OBJ = $(SRC:.c=.o)
CFLAGS += -Wall -Werror -Wextra
#define DEBUG
NAME = my_ls

# Ajouter -DTEST pour les tests du fichiers fonctions.c ; et -DDEBUG pour les messages de debug.
$(NAME): $(OBJ)
	gcc $(CFLAGS) -o $(NAME) -DDEBUG $(OBJ)

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)


re: fclean all