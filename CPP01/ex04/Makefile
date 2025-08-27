NAME = prog.out
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -g -MMD -MP

SRCS = main.cpp \

OBJS = $(SRCS:.cpp=.o)
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(DEPS)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

-include $(DEPS)

.PHONY: all clean fclean re
