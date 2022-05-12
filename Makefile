# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 22:21:01 by ademurge          #+#    #+#              #
#    Updated: 2022/05/12 16:39:29 by ademurge         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLACK		= $(shell tput -Txterm setaf 0)
RED			= $(shell tput -Txterm setaf 1)
GREEN		= $(shell tput -Txterm setaf 2)
YELLOW		= $(shell tput -Txterm setaf 3)
LIGHTPURPLE	= $(shell tput -Txterm setaf 4)
PURPLE		= $(shell tput -Txterm setaf 5)
BLUE		= $(shell tput -Txterm setaf 6)
WHITE		= $(shell tput -Txterm setaf 7)
RESET		= $(shell tput -Txterm sgr0)

SRCS			= 	srcs/error.c \
					srcs/free.c \
					srcs/init.c \
					srcs/main.c \
					srcs/parse_path.c \
					srcs/pipex.c

LIBFT			=	libft/ft_split.c \
					libft/ft_strdup.c \
					libft/ft_strjoin.c \
					libft/ft_strlcat.c \
					libft/ft_strlcpy.c \
					libft/ft_strlen.c \
					libft/ft_strstr.c \
					libft/ft_substr.c

NAME			= pipex

CFLAGS			= -Wall -Wextra -Werror

all:			$(NAME)

$(NAME):
				@gcc ${CFLAGS} ${SRCS} ${LIBFT} -o ${NAME}
				@echo "$(GREEN)********** Compiled. $(RESET)"

clean:
				@rm -f ${OBJS}
				@echo "$(PURPLE)********** Objects removed. $(RESET)"

fclean:			clean
				@rm -f $(NAME)
				@echo "$(LIGHTPURPLE)********** Executable removed. $(RESET)"

re:				fclean all

.PHONY:		all clean fclean re