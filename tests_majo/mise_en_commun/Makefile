SRC = ./main.c \
	./fonctions.c
OBJ = $(SRC:.c=.o)
CFLAGS += -Wall -Werror -Wextra
NAME = my_ls

# Ajouter -DTEST pour les tests du fichiers source_header.c ; et -DDEBUG pour les messages de debug.
$(NAME): $(OBJ)
	gcc -o $(NAME) -DDEBUG $(OBJ)

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)


re: fclean all