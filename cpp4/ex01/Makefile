# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/23 22:38:28 by mmaidel-          #+#    #+#              #
#    Updated: 2024/09/23 22:38:29 by mmaidel-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=	animals

SRCS=	Animal.cpp Cat.cpp Dog.cpp Brain.cpp main.cpp
OBJS=	$(SRCS:.cpp=.o)

RM=		rm -rf

CC=	c++
FLAGS =		-Wall -Werror -Wextra -std=c++98 -pedantic-errors -g

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re