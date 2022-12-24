NAME = fractol
CC = gcc
# CFLAGS = -Wall -Wextra -Werror -I $(LIBFTDIR)
CFLAGS = -fsanitize=address -g ./minilibx-linux/libmlx.a -lXext -lX11 -lm
LIBFT = $(LIBFTDIR)/libft.a
LIBFTDIR = $(PWD)/libft
OBJS = main.o utils.o

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(OBJS)  $(LIBFT) $(CFLAGS) -o $(NAME)

main.o: main.c
	$(CC) -c $(CFLAGS) -I $(LIBFTDIR) main.c -o main.o

init.o: init.c
	$(CC) -c $(CFLAGS) -I $(LIBFTDIR) init.c -o init.o

utils.o: utils.c
	$(CC) -c $(CFLAGS) -I $(LIBFTDIR) utils.c -o utils.o


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
