# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: izelensk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 12:17:24 by izelensk          #+#    #+#              #
#    Updated: 2017/03/23 20:31:58 by opogiba          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FOLDER = libft/
FOLDER1 = printf/parssing/
FOLDER2 = printf/utilites/
FOLDER3 =  printf/print/
FOLDER4 = printf/utilites_for_double/

SRC1 = $(FOLDER)ft_bzero.c $(FOLDER)ft_memset.c $(FOLDER)ft_memcpy.c \
	   $(FOLDER)ft_strcmp.c $(FOLDER)ft_strncmp.c $(FOLDER)ft_atoi.c \
	   $(FOLDER)ft_strnew.c $(FOLDER)ft_strdel.c $(FOLDER)ft_strclr.c \
	   $(FOLDER)ft_memcmp.c $(FOLDER)ft_strlen.c $(FOLDER)ft_strdup.c \
	   $(FOLDER)ft_strcpy.c $(FOLDER)ft_strncpy.c $(FOLDER)ft_strcat.c \
$(FOLDER)ft_strrchr.c $(FOLDER)ft_strstr.c $(FOLDER)ft_strnstr.c \
$(FOLDER)ft_memccpy.c $(FOLDER)ft_memmove.c $(FOLDER)ft_memchr.c \
$(FOLDER)ft_strncat.c $(FOLDER)ft_strlcat.c $(FOLDER)ft_strchr.c \
$(FOLDER)ft_isalpha.c $(FOLDER)ft_isdigit.c $(FOLDER)ft_isalnum.c \
$(FOLDER)ft_isascii.c $(FOLDER)ft_isprint.c $(FOLDER)ft_toupper.c \
$(FOLDER)ft_tolower.c $(FOLDER)ft_memalloc.c $(FOLDER)ft_memdel.c \
$(FOLDER)ft_striter.c $(FOLDER)ft_striteri.c $(FOLDER)ft_strmap.c \
$(FOLDER)ft_strmapi.c $(FOLDER)ft_strequ.c $(FOLDER)ft_strnequ.c \
$(FOLDER)ft_strsub.c $(FOLDER)ft_strjoin.c $(FOLDER)ft_strtrim.c \
$(FOLDER)ft_itoa.c $(FOLDER)ft_putchar.c $(FOLDER)ft_putstr.c \
$(FOLDER)ft_putendl.c $(FOLDER)ft_putnbr.c $(FOLDER)ft_putchar_fd.c \
$(FOLDER)ft_putstr_fd.c $(FOLDER)ft_putendl_fd.c $(FOLDER)ft_putnbr_fd.c \
$(FOLDER)ft_lstnew.c $(FOLDER)ft_lstdelone.c $(FOLDER)ft_lstdel.c \
$(FOLDER)ft_lstadd.c $(FOLDER)ft_lstiter.c $(FOLDER)ft_lstmap.c \
$(FOLDER)ft_strsplit.c $(FOLDER)ft_swap.c $(FOLDER)ft_sqrt.c \
$(FOLDER)ft_sort_integer_table.c \
$(FOLDER)ft_print_params.c \
$(FOLDER)ft_strrev.c $(FOLDER)ft_iterative_factorial.c \
$(FOLDER)ft_sort_wordtab.c $(FOLDER)ft_foreach.c \
$(FOLDER)ft_rrange.c $(FOLDER)ft_realloc.c $(FOLDER)ft_abs.c\
$(FOLDER)ft_pow.c $(FOLDER)ft_itoa_base.c $(FOLDER)ft_clean_two_char.c \
$(FOLDER)ft_clean_str.c $(FOLDER)ft_join_char.c $(FOLDER)ft_atoi_base.c \
$(FOLDER)ft_join_free.c get_next_line/get_next_line.c\
get_next_line/get_next_line_list.c

SRC2 =  printf/ft_handle_specifier.c printf/ft_printf.c \
$(FOLDER1)ft_parsing.c $(FOLDER2)ft_join_prefix.c \
$(FOLDER1)ft_parsing_accuracy.c $(FOLDER1)ft_parsing_width.c \
$(FOLDER1)ft_parsing_flags.c $(FOLDER1)ft_parsing_length.c \
$(FOLDER1)ft_parsing_specifier.c $(FOLDER1)ft_parsing_brace.c \
$(FOLDER2)ft_utoa_base.c $(FOLDER2)ft_join_symbols.c \
$(FOLDER2)ft_print.c $(FOLDER2)ft_wchar.c $(FOLDER2)ft_join_symbol.c \
	$(FOLDER2)ft_clean.c $(FOLDER2)ft_convert_time.c \
$(FOLDER2)ft_put_apostrophe.c $(FOLDER2)ft_change_list.c \
$(FOLDER2)ft_choose_color.c $(FOLDER2)ft_choose_fd.c \
$(FOLDER2)ft_nbrlen.c $(FOLDER2)ft_cust.c $(FOLDER3)ft_print_int.c \
$(FOLDER3)ft_print_string.c $(FOLDER3)ft_print_char.c \
$(FOLDER3)ft_print_memory.c $(FOLDER3)ft_print_time.c \
$(FOLDER3)ft_print_nonprintable.c $(FOLDER3)ft_print_exponent.c \
$(FOLDER3)ft_print_double.c $(FOLDER3)ft_print_float_or_exponent.c \
$(FOLDER3)ft_pointer_to_int.c $(FOLDER3)ft_print_double_hexdecimal.c \
$(FOLDER4)ft_check_inf.c $(FOLDER4)ft_round.c $(FOLDER4)ft_check_len.c \
$(FOLDER4)ft_parsing_znak_double.c $(FOLDER4)ft_del_zero.c \
$(FOLDER4)ft_check_spec_g.c $(FOLDER4)ft_dot_to_float.c \
$(FOLDER4)ft_round_double.c $(FOLDER4)ft_count_acc_for_a.c \
$(FOLDER4)ft_help_a.c $(FOLDER3)ft_print_float.c


SRC = $(SRC1) $(SRC2)

OBJS = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)

.c.o:
	@printf "[CC] %s                                                      \r" $<
	@gcc $(FLAGS) -c $<  -o $@

clean:
	@/bin/rm -f $(OBJS)

fclean:	clean
	@/bin/rm -f $(NAME)

re: fclean all
