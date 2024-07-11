FILE = tools.c 

NAME = push_swap

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRCS =  Push_swap.c checking.c ft_split.c linked_list/lists.c sorting.c tools.c indexing.c

OBJS = ${SRCS:%.c=%.o}

${NAME} : ${OBJS}
	${CC} $(FLAGS) $(OBJS) -o $(NAME)

%.o : %.c push_swap.h 
	${CC} ${FLAGS} -c $< -o $@ 

all : ${NAME}
	
clean :
	@rm -f ${OBJS} 

fclean : clean
	@rm -f ${NAME}

re : fclean all