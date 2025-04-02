NAME = philo

CC = gcc

FLAGS = -Wall -Wextra -Werror -g -gdwarf-4

SOURCES = 	./src/*.c \
			./src/chk/*.c \
			./src/utils/*.c \
		

all:
	$(CC) $(FLAGS) $(SOURCES) -o $(NAME)

fclean: 
	@rm -rf $(NAME)

re: fclean all