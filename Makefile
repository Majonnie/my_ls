SRC = ./main.c
OBJ = $(SRC:.c=.o)
CFLAGS += -Wall -Werror -Wextra
NAME = my_ls

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)


re: fclean all