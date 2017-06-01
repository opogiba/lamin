LIB     = libft/
NAME    = lem_in
CFLAGS  = -Wall -Wextra -Werror
CC      = gcc

SRCS    = main.c deikstra_algoritm.c ft_do_link.c \
            ft_do_matrix.c ft_do_road.c ft_do_room.c \
            ft_error.c ft_parsing_lamin.c ft_realloc.c \
            help_functions.c prinnnt.c
OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	@make -C $(LIB)
	@$(CC) $(CFLAGS) $(SRCS) $(LIB)libftprintf.a -o $(NAME)

.c.o:
	@printf "[CC] %s                                                  \r" $<
	@$(CC) $(CFLAGS) -c $<  -o $@

clean:
	@make -C $(LIB) clean
	@rm -rf $(OBJS)

fclean: clean
	@make -C $(LIB) fclean
	@rm -rf $(NAME)

re: fclean all