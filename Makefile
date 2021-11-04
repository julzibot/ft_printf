# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jibot <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 19:19:15 by jibot             #+#    #+#              #
#    Updated: 2021/11/03 18:18:06 by jibot            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= printlibft.a

CC		= gcc

AR		= ar rc

RM		= rm -f

CFLAGS	= -Wall -Werror -Wextra

SRCS	= ft_printf.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putnbru_fd.c ft_puthex.c ft_puthexp.c

OBJS	= ${SRCS:.c=.o}

all:		${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} 
			${AR} ${NAME} ${OBJS}
			
clean: 
			${RM} ${SRCS:.c=.o} ${B_SRCS:.c=.o}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

bonus_re:	fclean bonus

.PHONY:		all clean fclean re
