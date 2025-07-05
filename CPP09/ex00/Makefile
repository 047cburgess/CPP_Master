NAME = btc
CC = c++
CFLAGS = -Wall -Werror -Wextra -MMD -MP -std=c++98 -g

SRCS_DIR = srcs
OBJS_DIR = objs
INCS_DIR = incs

SRCS = $(SRCS_DIR)/main.cpp \
       $(SRCS_DIR)/BitcoinExchange.cpp \

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))
DEPS = $(OBJS:.o=.d)


all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJS_DIR)/%.o:	%.cpp
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INCS_DIR) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

leaks:	all
	valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes ./$(NAME) infile.txt
run: all
	./$(NAME) infile.txt

-include $(DEPS)

.PHONY: all cleam fclean re leaks run




