#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/20 20:11:43 by tmaslyan          #+#    #+#              #
#    Updated: 2018/05/01 13:42:27 by tmaslyan         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

SRCNAME	=	ft_lstdel.c\
			ft_putchar.c\
			ft_strdel.c\
			ft_strnew.c\
			ft_lstdelone.c\
			ft_putchar_fd.c\
			ft_strdup.c\
			ft_strnstr.c\
			ft_atoi.c\
			ft_lstiter.c\
			ft_putendl.c\
			ft_strequ.c\
			ft_strrchr.c\
			ft_bzero.c\
			ft_lstmap.c\
			ft_putendl_fd.c	\
			ft_striter.c\
			ft_strrev.c\
			ft_factorial.c\
			ft_lstnew.c\
			ft_putnbr.c\
			ft_striteri.c\
			ft_strsplit.c\
			ft_intsqrt.c\
			ft_memalloc.c\
			ft_putnbr_fd.c\
			ft_strjoin.c\
			ft_strstr.c\
			ft_isalnum.c\
			ft_memccpy.c\
			ft_putstr.c\
			ft_strlcat.c\
			ft_strsub.c\
			ft_isalpha.c\
			ft_memchr.c\
			ft_putstr_fd.c\
			ft_strlen.c\
			ft_strtrim.c\
			ft_isascii.c\
			ft_memcmp.c\
			ft_simple_pow.c\
			ft_strmap.c\
			ft_tolower.c\
			ft_isdigit.c\
			ft_memcpy.c\
			ft_strcat.c\
			ft_strmapi.c\
			ft_toupper.c\
			ft_isprime.c\
			ft_memdel.c\
			ft_strchr.c\
			ft_strncat.c\
			ft_isprint.c\
			ft_memmove.c\
			ft_strclr.c\
			ft_strncmp.c\
			ft_itoa.c\
			ft_memset.c\
			ft_strcmp.c\
			ft_strncpy.c\
			ft_lstadd.c\
			ft_nextprime.c\
			ft_strcpy.c\
			ft_strnequ.c\
			ft_sort_list.c\
			itoa_base.c\
			len_int.c\
			ft_printf.c\
			print_d.c\
			start_x_o_u.c\
			print_smth.c\
			pass_spaces.c\
			parse_flags.c\
			print_o.c\
			print_u.c\
			print_x.c\
			print_percent.c\
			print_c.c\
			print_s.c\
			print_p.c\
			get_dnbr.c\
			undefined_parse.c\
			get_next_line.c\

SRC    = $(addprefix src/, $(SRCNAME))
OBJECT = $(SRC:.c=.o)
FLAGS  = -Wall -Wextra -Werror
HDIR   = include

all: $(NAME)

$(NAME): $(OBJECT)
	ar rc $(NAME) $(OBJECT)
	ranlib $(NAME)
%.o: %.c
	gcc $(FLAGS) -o $@ -c $< -I $(HDIR)

clean:
	rm -f $(OBJECT)
	rm -f "*.swp"

fclean: clean
	rm -f $(NAME)

re: fclean all
