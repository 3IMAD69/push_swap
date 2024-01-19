


SRCM	= main.c parsing.c list_utils.c sort_algo.c shark_sort.c shark_sort2.c list_utils2.c sort_algo_helper.c \
	 	   stack_utils/stack_utils.c stack_utils/stack_utils2.c stack_utils/stack_utils3.c stack_utils/stack_utils4.c

SRCB = bonus/bonus.c bonus/bonus_helper.c parsing.c list_utils.c  list_utils2.c  \
	   stack_utils/stack_utils.c stack_utils/stack_utils2.c stack_utils/stack_utils3.c stack_utils/stack_utils4.c

OBJM	= ${SRCM:.c=.o}
OBJB	= ${SRCB:.c=.o}

NAME = push_swap
NAME_BONUS = checker

CFLAGS	= -Wall -Werror -Wextra #-g -fsanitize=address 
CC		= cc
LIBFTA 	= ./includes/libft/libft.a

all : ${NAME}

bonus : ${NAME_BONUS}

${LIBFTA} : 
	@make -C includes/libft

${NAME} : ${OBJM} ${LIBFTA}
	${CC} ${CFLAGS} ${OBJM} ${LIBFTA} -o ${NAME}

${NAME_BONUS} : ${OBJB} ${LIBFTA}
	${CC} ${CFLAGS} ${OBJB} ${LIBFTA} -o ${NAME_BONUS} 

clean :
	make -C includes/libft clean
	rm -f ${OBJM} ${OBJB}

fclean : clean
	make -C includes/libft fclean
	rm -f ${NAME} $(NAME_BONUS)

re : fclean all
	

run :  
	./push_swap 42 140 61 52 104 45 71 55 9 

#make status arg="4 5 2"
status : 
	./push_swap $(arg) | ./checker_Mac $(arg)


#make count arg="34 2 1"
count : 
	./push_swap $(arg) | wc -l

test : 
	make
	bash push_swap_test.sh
