PRINTFUNCTION = ft_printf.c \
				ft_print_array.c \
				ft_print_hexa.c \
				ft_print_integer.c \
				ft_print_positif_integer.c \
				ft_utils.c \
				ft_putchar_fd.c \
				ft_putstr.c \
				ft_strlen.c

SRC = $(PRINTFUNCTION) \
	  main.c \
	  pixel_manip.c \
	  map.c \
	  math.c \
	  mandelbrot.c \
	  event.c \
	  update_back.c \
	  init_all.c \
	  system_zoom.c \
	  homothety.c \
	  prototype.c \
	  error.c \
	  optim_zoom.c \
	  julia.c \
	  render.c \
	  translation.c \
	  ft_strcmp.c \
	  arg_valide.c

CC = cc
LIB_PATH=minilibx-linux
FLAGS = -I$(LIB_PATH) -L$(LIB_PATH) -I./printf -lmlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -Wall -Wextra -Werror
NAME = fractol
OBJ=$(SRC:.c=.o)

all: object_file minilibx $(NAME)

object_file:
	@(test ! -e obj && mkdir obj) || echo "obj already exist!!"

minilibx:
	@(test ! -e minilibx-linux.tgz && wget https://cdn.intra.42.fr/document/document/26487/minilibx-linux.tgz) || echo "minilibix already here!!"
	tar -xf minilibx-linux.tgz
	cd $(LIB_PATH) && make

%.o: %.c fractol.h
	$(CC) -g -c $< -o obj/$@

$(NAME): $(OBJ)
	cd obj && $(CC) $(OBJ) -o ../$(NAME) $(FLAGS) -L../$(LIB_PATH) -I../$(LIB_PATH)

clean:
	rm -Rf obj

fclean: clean
	rm -rf $(LIB_PATH)
	rm -f $(NAME)

list:
	ls -l *.c

norm: fclean
	norminette

re: fclean all

vpath %.o obj
vpath %.c ./printf
vpath $(OBJ) obj

.PHONY: all clean fclean re object_file minilibx
