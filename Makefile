# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cel-mhan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/23 21:51:14 by cel-mhan          #+#    #+#              #
#    Updated: 2021/12/23 21:51:16 by cel-mhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRCS = pipex.c 02_utils.c 01_utils.c path_utils.c
	
OBJS = $(SRCS:.c=.o)

%.o : %.c
	   $(CC) $(CFLAGS) $< -c
$(NAME) : $(SRCS)
		$(CC) $(CFLAGS) $(SRCS) -o ${NAME}

all : $(NAME)

clean :
	rm -f ${OBJS}
fclean : clean
	rm -f pipex

re : fclean all

