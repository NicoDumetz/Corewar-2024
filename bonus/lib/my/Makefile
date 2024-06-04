##
## EPITECH PROJECT, 2023
## makrfile libmy.a
## File description:
## makefile to create lib
##

MY_PRINTF_RESSOURCES_PATH = my_printf/ressources

MY_PRINTF_FLAGS_PATH = my_printf/flags

MY_PRINTF_SRC =	$(MY_PRINTF_RESSOURCES_PATH)/my_convert_base.c \
		$(MY_PRINTF_RESSOURCES_PATH)/my_putstr.c \
		$(MY_PRINTF_RESSOURCES_PATH)/my_intlen.c \
		$(MY_PRINTF_RESSOURCES_PATH)/my_put_float.c \
		$(MY_PRINTF_RESSOURCES_PATH)/my_put_sci_nbr.c \
		$(MY_PRINTF_RESSOURCES_PATH)/point_g.c \
		$(MY_PRINTF_RESSOURCES_PATH)/my_getnbr.c \
		$(MY_PRINTF_RESSOURCES_PATH)/my_put_nbr.c \
		$(MY_PRINTF_RESSOURCES_PATH)/print_a.c \
		$(MY_PRINTF_RESSOURCES_PATH)/error_handling.c \
		$(MY_PRINTF_FLAGS_PATH)/flags.c \
		$(MY_PRINTF_FLAGS_PATH)/flags2.c \
		$(MY_PRINTF_FLAGS_PATH)/flags3.c \
		$(MY_PRINTF_FLAGS_PATH)/flags4.c \
		$(MY_PRINTF_FLAGS_PATH)/check_mod.c \
		$(MY_PRINTF_FLAGS_PATH)/print_float.c \
		$(MY_PRINTF_FLAGS_PATH)/print_int.c \
		$(MY_PRINTF_FLAGS_PATH)/print_g.c \
		my_printf/my_printf.c

SRC 	= 	my_compute_power_rec.c \
		my_compute_square_root.c \
		my_find_prime_sup.c \
		my_getnbr.c \
		my_isneg.c \
		my_is_prime.c \
		my_putchar.c \
		my_put_nbr.c \
		my_putstr.c \
		my_revstr.c \
		my_showmem.c \
		my_showstr.c \
		my_show_word_array.c \
		my_sort_int_array.c \
		my_strcapitalize.c \
		my_strcat.c \
		my_strcmp.c \
		my_strcpy.c \
		my_str_isalpha.c \
		my_str_islower.c \
		my_str_isnum.c \
		my_str_isprintable.c \
		my_str_isupper.c \
		my_strlen.c \
		my_strlowcase.c \
		my_strncat.c \
		my_strncmp.c \
		my_strncpy.c \
		my_strstr.c \
		my_str_to_word_array.c \
		my_str_to_array.c \
		my_strupcase.c \
		my_swap.c \
		my_strdup.c \
		$(MY_PRINTF_SRC)

OBJ	=	$(SRC:.c=.o)

NAME = libmy.a

CFLAGS += -Wall -Werror -Wextra

all: $(NAME)

$(NAME): condition $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ..
	cp my.h ../../include/

condition:
	make header -C my_printf

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re: fclean all
