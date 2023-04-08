# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: robegarc <robegarc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 15:22:58 by robegarc          #+#    #+#              #
#    Updated: 2023/04/08 12:18:30 by robegarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COLOR_GREEN = \033[0;32m
COLOR_BLUE = \033[0;34m
COLOR_RED = \033[0;31m
COLOR_VIOLET = \033[0;35m
COLOR_DEFAULT = \033[0m

SRC = main.c \
		srcs/reading.c
OBJ = ${SRC:.c=.o}

CC = cc 
FLAG = -Wall -Wextra -Werror

LIBFT = incl/libft
INCLUDE = -I$(LIBFT) -I/Users/robegarc/.brew/opt/readline/include
LIBS = -L$(LIBFT) -L/Users/robegarc/.brew/opt/readline/lib -lft -lreadline

NAME = minishell

%.o : %.c
	@${CC} ${FLAG} -c $< -o $@ -g

${NAME} : ${OBJ}
	@make -C ${LIBFT}
	@${CC} ${FLAG} ${OBJ} ${LIBRARY} ${INCLUDE} ${LIBS} -lreadline -o ${NAME} -g
	@echo "${COLOR_GREEN}COMPILATION${COLOR_DEFAULT}"

all : ${NAME}

clean :
	@make clean -C ${LIBFT}
	@rm -rf ${OBJ}
	@echo "${COLOR_RED}OBJs deleted${COLOR_DEFAULT}"

fclean : clean
	@make fclean -C ${LIBFT}
	@rm -rf ${NAME}
	@echo "${COLOR_RED}./${NAME} deleted${COLOR_DEFAULT}"

re : fclean all clean

.PHONY : clean fclean all re
