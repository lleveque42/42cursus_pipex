# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 09:52:26 by lleveque          #+#    #+#              #
#    Updated: 2022/01/28 18:42:44 by lleveque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ${SRCS_MAIN} ${SRCS_PARSING} ${SRCS_UTILS} ${SRCS_ERROR} ${SRCS_PIPEX}

SRCS_MAIN = $(addprefix srcs/, pipex.c)

SRCS_PARSING = $(addprefix srcs/parsing/, parse_data.c parse_cmd.c parse_utils.c)

SRCS_UTILS = $(addprefix srcs/utils/,  pipex_utils.c pipex_split.c)

SRCS_ERROR = ${addprefix srcs/error/, check_args.c error_utils.c messages.c}

SRCS_PIPEX = ${addprefix srcs/pipex/, exec.c}

OBJS = ${SRCS:.c=.o}

NAME = pipex

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

all:	${NAME}

BRED="\033[1;31m"
RED='\033[0;31m'
BGREEN='\033[1;32m'
BYELLOW='\033[1;33m'
YELLOW='\033[0;33m'
BLUE='\033[1;36m'
BROSE='\033[1;35m'
ROSE='\033[0;35m'

${NAME}:	${OBJS}
			@echo ${BYELLOW}"making" ${YELLOW}"${NAME}..."
			@${CC} ${OBJS} ${CFLAG} -o ${NAME} ${LIBFT}
			@echo ${BGREEN}"${NAME} is ready !"${NONE}

.c.o:
	@echo ${BROSE}"compiling" ${BLUE}"[${CFLAGS}]"${ROSE}" ${<:.c=.c}..."
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
		@echo ${BRED}"removing" ${RED}"objects..."
		@${RM} ${OBJS}

fclean:		clean
			@echo ${BRED}"removing" ${RED}"executable..."
			@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
