# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/26 10:22:32 by user42            #+#    #+#              #
#    Updated: 2020/11/03 10:54:23 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
CFLAGS	= -f elf64   #macho64 for MacOS, elf64 for linux
CC		= nasm
OBJS	= ${SRCS:.s=.o}
NAME	= libasm.a
RM		= rm -f
TEST	= test

all:	${NAME}

$(NAME):		${OBJS}
				ar rcs ${NAME} ${OBJS}

${TEST}.out: 	${NAME} main.c
				gcc -Wall -Wextra -Werror main.c -L. -lasm -o ${TEST}.out

test:			${TEST}.out
				./${TEST}.out

%.o:			%.s
				${CC} ${CFLAGS} $<

clean:
				${RM} ${OBJS}

fclean:			clean
				${RM} ${NAME} ${TEST}.out

re:				fclean all

.PHONY : all clean fclean re test
