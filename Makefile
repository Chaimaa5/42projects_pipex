NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRCS = 02_utils.c 01_utils.c pipex.c
	
OBJS = $(SRCS:.c=.o)


$(NAME) : $(SRCS)
		$(CC) $(CFLAGS) $(SRCS) -o ${NAME}

all : $(NAME)

clean :
	rm -f ${OBJS}
fclean : clean
	rm -f pipex

re : fclean all

