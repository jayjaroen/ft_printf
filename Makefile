# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjaroens <jjaroens@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 21:41:49 by jjaroens          #+#    #+#              #
#    Updated: 2024/01/31 22:41:55 by jjaroens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME = libftprintf.a

# LIBFT = ./libft/libft.a
SRCS = ft_printf.c ft_put_utils.c ft_put_format.c
OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a

CC	= gcc

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror

# HEAD = .

.c.o:
	${CC} ${CFLAGS} -c -I . $< -o ${<:.c=.o}

all:	${NAME}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:	fclean	all

.PHONY:		all	clean	fclean	re
