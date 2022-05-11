# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 22:21:01 by ademurge          #+#    #+#              #
#    Updated: 2022/05/11 16:37:27 by ademurge         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= 	init.c \
					main.c \
					pipex.c

OBJS			= $(addprefix srcs/, ${SRCS})

NAME			= pipex

CFLAGS			= -Wall -Wextra -Werror

all:
				@gcc ${CFLAGS} ${OBJS} -o ${NAME}
clean:
				@rm -f ${OBJS}

fclean:			clean
				@rm -f $(NAME)
				@echo "...Everything removed!"

re:				fclean all
				@echo "...Completed!"

.PHONY:		all clean fclean re