##
## EPITECH PROJECT, 2024
## Makefile libmy.a
## File description:
## create lib for my_printf
##

SRC = main.c \
	  draw_rect.c \
	  manage_img.c \
	  manage_text.c \

OBJ = $(SRC:.c=.o)

NAME = corewar

all: $(NAME)

CFLAGS += -Wall -Wextra $(shell pkg-config --cflags freetype2)

LDFLAGS = -lGL -lGLU -lglut -lm -lfreetype


$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS) -lglfw

clean:
	rm -f $(OBJ)m

fclean: clean
	rm -f $(NAME)

re: fclean all