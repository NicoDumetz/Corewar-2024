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
	  op.c \
	  src/create_champ.c \
	  src/display.c \
	  src/init_memory.c \
	  src/game_loop/game_loop.c \
	  src/game_loop/win_conditions.c \
	  src/command/tab_com.c \
	  src/command/live.c \
	  src/command/ld.c \
	  src/command/read_param.c \
	  src/command/stock.c \
	  src/command/add.c \
	  src/command/sub.c \
	  src/command/and.c \
	  src/command/or.c \
	  src/command/xor.c \
	  src/command/zjmp.c \
	  src/command/ldi.c \
	  src/command/sti.c \
	  src/command/fork.c \
	  src/command/lld.c \
	  src/command/lldi.c \
	  src/command/lfork.c \
	  src/command/aff.c \
	  src/nbr_live.c \
	  src/dec_to_octet.c \
	  src/write_in_mem.c \
	  src/check_dump.c \
	  src/fetch_options.c \
	  src/set_pc_champ.c \
	  src/insert_champ.c \
	  src/check_var.c

OBJ = $(SRC:.c=.o)


NAME = corewar

all: $(NAME)

LDFLAGS = -lGL -lGLU -lglut -lglfw -lm

CFLAGS += -Wall -Wextra -g -Llib -lmy -Iinclude

required:
	make -C lib/my

$(NAME): required $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(OBJ)
	make clean -C lib/my

fclean: clean
	rm -f $(NAME)
	make fclean -C lib/my

re: fclean all
