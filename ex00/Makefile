SRC = $(wildcard *.cpp)

OBJ = $(SRC:.cpp=.o)

NAME = bureaucrat

CC = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

%.o: %.cpp
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $@

all: $(NAME)

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re