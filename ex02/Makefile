# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/26 15:04:37 by bguyot            #+#    #+#              #
#    Updated: 2023/04/26 15:04:38 by bguyot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	PmergeMe

SRCS 		=	srcs/main.cpp srcs/PmergeMe.cpp

INCS 		=	PmergeMe.hpp

OBJS 		=	${SRCS:.cpp=.o}

CC			=	@c++
RM			=	@rm -rf
CFLAGS		=	-Wall -Wextra -Werror -std=c++98

all:		${NAME}

${NAME}:	${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}
	@printf "\e[36m\tCompilation \t[ ✓ ]\n\e[39m"

.cpp.o: ${INCS}
	${CC} ${CFLAGS} -c $< -o ${<:.cpp=.o}

clean:
	${RM} ${OBJS}
	@printf "\e[31m\tClean \t\t[ ✓ ]\n\e[39m"

fclean:	clean
	${RM} ${NAME}
	@printf "\e[35;5;161m\tBinary Clean \t[ ✓ ]\n\e[39m"

re:		fclean all

.PHONY: all clean fclean re