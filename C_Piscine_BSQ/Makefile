# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: naqua <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/07 14:19:51 by naqua             #+#    #+#              #
#    Updated: 2021/09/08 23:24:53 by zhizdahr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= srcs/main.c \
		  srcs/ft_atoi.c \
		  srcs/min.c \
		  srcs/glavn.c \
		srcs/txt_input.c \
		srcs/write_map.c \
		srcs/masiv_malloc.c
OBJS	= ${SRCS:.c=.o}
NAME	= bsq
HEADER	= ./includes/
CC		= gcc
FLAGS	= -Wall -Werror -Wextra
RM		= rm -f

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I ${HEADER}

${NAME}: ${OBJS}
	${CC} ${FLAGS} -o ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re .c.o
