NAME = lem-in

SRCNAME	=   main.c opt_functions.c check_func.c algorithm.c simple_queue.c

SRC    = $(addprefix src/, $(SRCNAME))
OBJECT = $(SRC:.c=.o)
FLAGS  = -Wall -Wextra -Werror
HDIR   = include/lemin.h
LIBFT = libft/libft.a

all: lib $(NAME)

$(NAME):$(OBJECT) $(LIBFT) $(HDIR)
	gcc $(OBJECT) $(LIBFT) $(FLAGS) -o $(NAME)

lib:
	make -C libft

%.o: %.c
	gcc $(FLAGS) -o $@ -c $< -I $(HDIR)

clean:
	rm -f $(OBJECT)
	make clean -C libft

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all
