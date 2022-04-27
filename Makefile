# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 22:21:01 by ademurge          #+#    #+#              #
#    Updated: 2022/04/27 17:39:29 by ademurge         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= 	pipex.c

OBJS			= $(addprefix srcs/, ${SRCS:.c=.o})

NAME			= pipex

CFLAGS			= -Wall -Wextra -Werror

%o:				%c
				@gcc ${CFLAGS} -I./includes -c $< -o ${<:.c=.o}

$(NAME):		${OBJS}
				@echo "...Everything compiled!"

all:			$(NAME)

clean:
				@rm -f ${OBJS} $(BONUS_OBJS)

fclean:			clean
				@rm -f $(NAME)
				@echo "...Everything removed!"

re:				fclean all
				@echo "...Completed!"

.PHONY:		all clean fclean re