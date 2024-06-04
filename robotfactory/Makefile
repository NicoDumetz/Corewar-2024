##
## EPITECH PROJECT, 2024
## Makefile libmy.a
## File description:
## create lib for my_printf
##

SRC = main.c \
	  op.c \
	  ressources/header.c \
	  ressources/my_memset.c \
	  ressources/board.c \
	  ressources/body.c \
	  ressources/write_number.c \
	  ressources/int_to_str.c \
	  ressources/my_convert_base.c \
	  ressources/labels.c \
	  ressources/error_handling.c

OBJ = $(SRC:.c=.o)

CFLAGS += -Llib -lmy -Iinclude

NAME = asm

all: $(NAME)

CFLAGS += -Wall -Wextra -Werror

required:
	make -C lib/my

$(NAME): required $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)
	make clean -C lib/my

fclean: clean
	rm -f $(NAME)
	make fclean -C lib/my

re: fclean all
