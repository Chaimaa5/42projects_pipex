NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRCS = functions.c pipex.c
	
OBJS = $(SRCS:.c=.o)


$(NAME) : $(OBJS)

all : $(NAME)

clean :
	rm -f ${OBJS}
fclean : clean
	rm -f pipex

re : fclean all

