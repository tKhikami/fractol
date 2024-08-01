CC=cc
FLAGS= -Wall -Wextra -Werror

NAME=libftprintf.a

SRC=ft_printf.c \
	ft_putchar_fd.c \
	ft_putstr.c \
	ft_strlen.c \
	ft_utils.c \
	ft_print_array.c \
	ft_print_hexa.c \
	ft_print_integer.c \
	ft_print_positif_integer.c

OBJ=$(SRC:.c=.o)

all: object_file $(NAME)

object_file:
	(test ! -e o_file && mkdir o_file) || echo "o_file already exist!!"

%.o: %.c
	$(CC) $(FLAGS) -o o_file/$@ -c $<

$(NAME): $(OBJ)
	cd o_file && ar -rcs ../$(NAME) $(OBJ)

clean:
	rm -Rf o_file

fclean: clean
	rm -f $(NAME)

re: fclean
	make all

vpath = o_file
vpath %.o o_file

.PHONY: all clean fclean re object_file
