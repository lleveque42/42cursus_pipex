# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 09:52:26 by lleveque          #+#    #+#              #
#    Updated: 2022/01/27 16:28:44 by lleveque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ${SRCS_MAIN} ${SRCS_PARSING} ${SRCS_UTILS} ${SRCS_ERROR}

SRCS_MAIN = $(addprefix srcs/, pipex.c)

SRCS_PARSING = $(addprefix srcs/parsing/, parse_path.c)

SRCS_UTILS = $(addprefix srcs/utils/,  pipex_utils.c pipex_split.c)

SRCS_ERROR = ${addprefix srcs/error/, check_args.c error_utils.c messages.c}

OBJS = ${SRCS:.c=.o}

NAME = pipex

CC = clang

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

all:	${NAME}

${NAME}:	${OBJS}
			@echo "making ${NAME}..."
			@${CC} ${OBJS} ${CFLAG} -o ${NAME} ${LIBFT}
			@echo "${NAME} is ready !"

.c.o:
	@echo "compiling ${<:.c=.c}..."
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
		@echo "removing files..."
		@${RM} ${OBJS}

fclean:		clean
			@echo "removing executable..."
			@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
