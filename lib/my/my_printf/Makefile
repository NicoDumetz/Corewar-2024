##
## EPITECH PROJECT, 2023
## Makefile libmy.a
## File description:
## create lib for my_printf
##

RESSOURCES_PATH = ressources

FLAGS_PATH = flags

SRC =	$(RESSOURCES_PATH)/my_convert_base.c \
	$(RESSOURCES_PATH)/my_putchar.c \
	$(RESSOURCES_PATH)/my_put_nbr.c \
	$(RESSOURCES_PATH)/my_putstr.c \
	$(RESSOURCES_PATH)/my_intlen.c \
	$(RESSOURCES_PATH)/my_put_float.c \
	$(RESSOURCES_PATH)/my_put_sci_nbr.c \
	$(RESSOURCES_PATH)/my_strlen.c \
	$(RESSOURCES_PATH)/point_g.c \
	$(RESSOURCES_PATH)/my_getnbr.c \
	$(RESSOURCES_PATH)/my_strcat.c \
	$(RESSOURCES_PATH)/print_a.c \
	$(RESSOURCES_PATH)/error_handling.c \
	$(FLAGS_PATH)/flags.c \
	$(FLAGS_PATH)/flags2.c \
	$(FLAGS_PATH)/flags3.c \
	$(FLAGS_PATH)/flags4.c \
	$(FLAGS_PATH)/check_mod.c \
	$(FLAGS_PATH)/print_float.c \
	$(FLAGS_PATH)/print_int.c \
	$(FLAGS_PATH)/print_g.c \
	my_printf.c

TEST_SRC =	tests/test_my_printf.c \
		tests/test_my_printf_di.c \
		tests/test_my_printf_sc.c \
		tests/test_my_printf_percent.c \
		tests/test_my_printf_f.c \
		tests/test_my_printf_oux.c

OBJ = $(SRC:.c=.o)

TEST_OBJ = $(TEST_SRC:.c=.o)

NAME = libmy.a

all: $(NAME)

header:
	cp $(RESSOURCES_PATH)/my_printf.h include

test: $(NAME)
	gcc main.c -L./ -lmy
	./a.out

$(NAME): header $(OBJ)
	ar rc $(NAME) $(OBJ)

unit_tests: fclean $(NAME) $(TEST_OBJ)
	gcc -o unit_tests $(TEST_OBJ) -lcriterion -L./ -lmy

tests_run: unit_tests
	./unit_tests

clean:
	rm -f $(OBJ)
	rm -f $(TEST_OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f include/my_printf.h
	rm -f unit_tests

re: fclean all
