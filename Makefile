NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I $(LIBFTDIR)
LIBFT = $(LIBFTDIR)/libft.a
LIBFTDIR = $(PWD)/libft
SRCS = \
main.c\
exit_no_leak.c\
utils.c\
handle_argument.c\
fractol_init.c\
drow_mandelbrot.c\
drow_julia.c\
fractol_init_hock.c\
fractol_init_hock_fanc.c\

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(OBJS)  $(LIBFT) ./minilibx-linux/libmlx.a -lXext -lX11 -lm -o $(NAME)

# main.o: main.c
# 	$(CC) -c $(CFLAGS) -I $(LIBFTDIR) main.c -o main.o

# init.o: init.c
# 	$(CC) -c $(CFLAGS) -I $(LIBFTDIR) init.c -o init.o

# utils.o: utils.c
# 	$(CC) -c $(CFLAGS) -I $(LIBFTDIR) utils.c -o utils.o


$(LIBFT):
	cd $(LIBFTDIR) && make bonus

clean:
	rm $(OBJS)
	cd $(LIBFTDIR) && make clean


bonus:
	make WITH_BONUS=1

fclean: clean
	rm $(NAME)
	cd $(LIBFTDIR) && make fclean

re:fclean all
