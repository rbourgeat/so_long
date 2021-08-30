# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 16:06:39 by rbourgea          #+#    #+#              #
#    Updated: 2021/08/30 14:20:11 by rbourgea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =	ft_bzero.c \
		ft_strlen.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
        ft_strrchr.c \
		ft_strcmp.c \
		ft_strlcpy.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_itoa.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putstr.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		get_next_line.c

BONUS_SRCS =	ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c

OBJS= ${SRCS:.c=.o}

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: ${NAME}

.c.o:
	gcc -Wall -Wextra -Werror -c $< -o $(<:.c=.o)

${NAME}: ${OBJS}
	ar rc ${NAME} ${OBJS}

bonus:		${OBJS} ${BONUS_OBJS}
			ar -rc ${NAME} ${OBJS} ${BONUS_OBJS}

clean:
	/bin/rm -f ${OBJS} ${BONUS_OBJS}

fclean: clean
	/bin/rm -f ${NAME}

re: fclean all

.PHONY: re fclean clean bonus all .c.o
