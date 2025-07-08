NAME = push_swap

SRC = utils.c ft_split.c  input_verification.c ft_atoi.c stack_creation.c \
      moves.c moves_2.c copy_stack.c free_stack.c  optimising.c radix_sort.c radix_sort_2.c \
	  selection_sort.c selection_sort_2.c get_index.c print_moves.c sort_three.c  sort_five.c  push_swap.c

HDR = push_swap.h

OBJ = $(SRC:.c=.o)

RM = rm -f

%.o: %.c
	gcc -Wall -Wextra -Werror -c $< -o $@

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME)

all: $(NAME)
	make clean

clean:
	${RM} $(OBJ)

clear: clean

fclean: clean
	${RM} $(NAME) ${OBJ}

re:	fclean
	make all
	make clean

rebonus: fclean
	make bonus
	make clean

.PHONY: all bonus clean fclean re clear rebonus
