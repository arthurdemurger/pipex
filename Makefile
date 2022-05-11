# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 22:21:01 by ademurge          #+#    #+#              #
#    Updated: 2022/05/11 18:58:59 by ademurge         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= 	srcs/error.c \
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

clean:
				@rm -f ${OBJS}

fclean:			clean
				@rm -f $(NAME)
				@echo "...Everything removed!"

re:				fclean all
				@echo "...Completed!"

.PHONY:		all clean fclean re