NAME		:=	fractol
B_NAME		:=	fractol_bonus
CC			:=	gcc
CFLAGS		:=	-Wall -Werror -Wextra
DFLAGS		:=	-MMD -MP
MFLAGS		:=	-fsanitize=address -g

SRCDIR		:=	./src
B_SRCDIR	:=	./b_src
OBJSDIR		:=	./objs
B_OBJSDIR	:=	./b_objs

LIBFTDIR	:=	./libft
LIBFT		:=	$(LIBFTDIR)/libft.a

MINILIBXDIR	:=	./minilibx-linux
MINILIBX	:=	$(MINILIBXDIR)/libmlx.a

IFLAGS		:=	-I ./include\
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

B_SRCS		:=	$(B_SRCDIR)/main_bonus.c\
				$(B_SRCDIR)/init_bonus.c\
				$(B_SRCDIR)/exit_bonus.c\
				$(B_SRCDIR)/draw_bonus.c\
				$(B_SRCDIR)/hook_1_bonus.c\
				$(B_SRCDIR)/hook_2_bonus.c\
				$(B_SRCDIR)/draw_mandelbrot_bonus.c\
				$(B_SRCDIR)/draw_julia_bonus.c\
				$(B_SRCDIR)/handle_argument_bonus.c

OBJS		:=	$(SRCS:$(SRCDIR)%.c=$(OBJSDIR)%.o)
DEPS		:=	$(SRCS:$(SRCDIR)%.c=$(OBJSDIR)%.d)

B_OBJS		:=	$(B_SRCS:$(B_SRCDIR)%.c=$(B_OBJSDIR)%.o)
B_DEPS		:=	$(B_SRCS:$(B_SRCDIR)%.c=$(B_OBJSDIR)%.d)

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

$(B_OBJSDIR)/%.o:$(B_SRCDIR)/%.c
	$(CC) $< $(CFLAGS) $(IFLAGS) $(DFLAGS) -c -o $@

clean:
	rm -f $(OBJS) && rm -f $(OBJSDIR)/*.d
	rm -f $(B_OBJS) && rm -f $(B_OBJSDIR)/*.d
	cd $(LIBFTDIR) && make clean
	cd $(MINILIBXDIR) && make clean

fclean:clean
	rm -f $(NAME)
	rm -f $(B_NAME)
	cd $(LIBFTDIR) && make fclean

re:fclean
	make

run:
	./fractol 1

debug:
	$(CFLAGS) += -g -fsanitize=address -fsanitize=undefined
	make re

bonus:$(B_NAME)

$(B_NAME): $(LIBFT) $(B_OBJS) $(MINILIBX)
	$(CC) $(B_OBJS)  $(LIBFT) $(MINILIBX) $(IFLAGS) $(LFLAGS) -o $(B_NAME)

-include $(DEPS)

.PHONY: all clean fclean re run debug

RED			=	"\033[31m"
GREEN		=	"\033[32m"
YELLOW		=	"\033[33m"
RESET		=	"\033[0m"