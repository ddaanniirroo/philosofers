NAME = philosophers_bonus

SRC = main_bonus.c\
	ft_atoi.c\
	ft_check.c\
	ft_fork.c\

HDRS = main_bonus.h

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
