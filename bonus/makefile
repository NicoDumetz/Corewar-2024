##
## EPITECH PROJECT, 2024
## Makefile libmy.a
## File description:
## create lib for my_printf
##

SRC = main.c \
	  draw_rect.c \
	  draw_cube.c \
	  game_loop_gl.c \

OBJ = $(SRC:.c=.o)


NAME = corewar

all: $(NAME)

CFLAGS += -Wall -Wextra

LDFLAGS = -lGL -lGLU -lglut -lglfw -lm

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(OBJ)
	rm -f $(NAME)

re: fclean all