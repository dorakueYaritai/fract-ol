NAME		:=	fractol
CC			:=	gcc
CFLAGS		:=	-Wall -Werror -Wextra
DFLAGS		:=	-MMD -MP
MFLAGS		:=	-fsanitize=address -g

SRCDIR		:=	./src

OBJSDIR		:=	./objs
LIBFTDIR	:=	./libft
MINILIBXDIR	:=	./minilibx-linux

IFLAGS		:=	-I $(PWD)/include\
				-I $(LIBFTDIR)\
				-I $(MINILIBXDIR)\

LFLAGS		:=	-lXext\
				-lX11\
				-lm\

SRCS		:=	$(SRCDIR)/main.c\
				$(SRCDIR)/init.c\
				$(SRCDIR)/exit.c\
				$(SRCDIR)/draw.c\
				$(SRCDIR)/hook_1.c\
				$(SRCDIR)/hook_2.c\
				$(SRCDIR)/draw_mandelbrot.c\
				$(SRCDIR)/draw_julia.c\
				$(SRCDIR)/handle_argument.c

OBJS		:=	$(SRCS:$(SRCDIR)%.c=$(OBJSDIR)%.o)
DEPS		:=	$(SRCS:$(SRCDIR)%.c=$(OBJSDIR)%.d)
LIBFT		:=	$(LIBFTDIR)/libft.a
MINILIBX	:=	$(MINILIBXDIR)/libmlx.a


all:$(NAME)

$(NAME): $(LIBFT) $(OBJS) $(MINILIBX)
	$(CC) $(OBJS)  $(LIBFT) $(MINILIBX) $(IFLAGS) $(LFLAGS) -o $(NAME)

$(LIBFT):
	@echo $(GREEN)"----- $(LIBFT) make start-----"$(RESET)
	$(MAKE) bonus -C $(LIBFTDIR)/
	@echo $(GREEN)"----- $(LIBFT) $(CC) done-----"$(RESET)

$(MINILIBX):
	@echo $(GREEN)"----- $(MINILIBX) make start-----"$(RESET)
	$(MAKE) -C $(MINILIBXDIR)/
	@echo $(GREEN)"----- $(MINILIBX) $(CC) done-----"$(RESET)

$(OBJSDIR)/%.o:$(SRCDIR)/%.c
	$(CC) $< $(CFLAGS) $(IFLAGS) $(DFLAGS) -c -o $@

clean:
	rm -f $(OBJS) && rm -f $(OBJSDIR)/*.d
	cd $(LIBFTDIR) && make clean
	cd $(MINILIBXDIR) && make clean

fclean:clean
	rm -f $(NAME)
	cd $(LIBFTDIR) && make fclean

re:fclean
	make

run:
	./fractol 1

debug:
	$(CFLAGS) += -g -fsanitize=address -fsanitize=undefined
	make re

-include $(DEPS)

.PHONY: all clean fclean re run debug

RED			=	"\033[31m"
GREEN		=	"\033[32m"
YELLOW		=	"\033[33m"
RESET		=	"\033[0m"