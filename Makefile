##
## EPITECH PROJECT, 2024
## Makefile libmy.a
## File description:
## create lib for my_printf
##

SRC = main.c \
	  op.c \
	  src/create_champ.c \
	  src/display.c \
	  src/init_memory.c \
	  src/game_loop/game_loop.c \
	  src/game_loop/win_conditions.c \
	  src/command/tab_com.c \
	  src/command/live.c



OBJ = $(SRC:.c=.o)

CFLAGS += -Llib -lmy -Iinclude

NAME = corewar

all: $(NAME)

CFLAGS += -Wall -Wextra -g

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
