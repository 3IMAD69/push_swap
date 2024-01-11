


SRCM	= main.c parsing.c list_utils.c stack_utils.c sort_algo.c
OBJM	= ${SRCM:.c=.o}

NAME = push_swap

CFLAGS	= -Wall -Werror -Wextra -g -fsanitize=address 
CC		= cc
LIBFTA 	= ./includes/libft/libft.a

all : ${NAME}

${LIBFTA} : 
	make -C includes/libft

${NAME} : ${SRCM} ${LIBFTA}
	${CC} ${CFLAGS} ${SRCM} ${LIBFTA} -o ${NAME}

clean :
	rm -f {OBJM}

fclean : clean
	rm -f ${NAME}

re : fclean all
	

run : 
	./push_swap 7 4 2 3