# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmozella <wmozella@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/23 21:39:26 by wmozella          #+#    #+#              #
#    Updated: 2022/06/02 19:56:59 by wmozella         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers

SRC = ft_philo.c\
	ft_atoi.c\
	ft_check.c\
	main.c\

HDRS = main.h

OBJ = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(HDRS)
		$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re