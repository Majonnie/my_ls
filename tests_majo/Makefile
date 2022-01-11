SRC = ./main.c \
	./source_header.c
OBJ = $(SRC:.c=.o)
# Ajouter -DTEST pour les tests du fichiers source_header.c ; et -DDEBUG pour les messages de debug.
CFLAGS += -Wall -Werror -Wextra
NAME = my_ls

$(NAME): $(OBJ)
	gcc -o $(NAME) -DDEBUG $(OBJ)

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)


re: fclean all