# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsabik <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/27 23:47:47 by lsabik            #+#    #+#              #
#    Updated: 2022/10/29 16:54:54 by lsabik           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
NAME := libftprintf.a
FLAGS := -Wall -Wextra -Werror
SRC := ft_printf.c  ft_putnbr_hexa.c \
		ft_putchar.c ft_putstr.c ft_putaddr.c ft_putnbr_u.c ft_flags.c 

OBJCTS := ${SRC:.c=.o}
BONUS_SRC := ft_flags_bonus.c ft_putchar_bonus.c \
				ft_printf_bonus.c ft_putnbr_hexa_bonus.c \
					ft_putaddr_bonus.c ft_putstr_bonus.c ft_putnbr_u_bonus.c

BONUS_OBJCTS := ${BONUS_SRC:.c=.o}
AR := ar rc
HEADER := ft_printf.h
HEADER_BONUS := ft_printf_bonus.h

all: ${NAME}

${NAME}: ${OBJCTS}
	${AR} ${NAME} ${OBJCTS}

%.o: %.c ${HEADER}
	${CC} ${FLAGS} -c $<

bonus: ${BONUS_OBJCTS} ${HEADER_BONUS }
	${AR} ${NAME} ${BONUS_OBJCTS}

clean:
	rm -f ${OBJCTS} ${BONUS_OBJCTS}

fclean: clean
	rm -f ${NAME}

re: fclean all bonus
