NAME = prog
SRCS = main.cpp \
       Animal.cpp \
       Dog.cpp \
       Cat.cpp \

OBJS = $(SRCS:.cpp=.o)

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -g

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

run: all
	@./$(NAME)

.PHONY: all clean fclean re
