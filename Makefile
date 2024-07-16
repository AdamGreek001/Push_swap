FILE = tools.c 

NAME = push_swap

CC = cc

#FLAGS = -Wall -Wextra -Werror

SRCS =  Push_swap.c checking.c ft_split.c indexing.c instr_push.c instr_rev_rot.c instr_rotate.c \
			instrctions_swap.c linked_list/lists.c sorting.c tools.c tools2.c algo.c

OBJS = ${SRCS:.c=.o}

${NAME} : ${OBJS}
	${CC} $(FLAGS) $(OBJS) -o $(NAME)

%.o : %.c push_swap.h 
	@${CC} ${FLAGS} -c $< -o $@
	@echo "Compiled "$<" successfully!"
	
all : ${NAME}
	
clean :
	@rm -f ${OBJS} 

fclean : clean
	@rm -f ${NAME}

re : fclean all

.PHONY : clean 
