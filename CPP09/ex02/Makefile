NAME = PmergeMe
CC = c++
CFLAGS = -Wall -Werror -Wextra -MMD -MP -std=c++98 -g

SRCS_DIR = srcs
OBJS_DIR = objs
INCS_DIR = incs

SRCS = $(SRCS_DIR)/main.cpp \
       

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

run:	all
	./PmergeMe $$(shuf -i 1-1000000 -n 21 | tr "\n" " ")

runbig:	all
	./PmergeMe $$(shuf -i 1-1000000 -n 3000 | tr "\n" " ") | grep -e "SORTED" -e "Time"

leaks:	all
	@bash -c 'valgrind --leak-check=full ./PmergeMe $$(shuf -i 1-1000000 -n 21 | tr "\n" " ")'

bigleaks:	all
	@bash -c 'valgrind --leak-check=full ./PmergeMe $$(shuf -i 1-1000000 -n 3000 | tr "\n" " ") | grep -e "SORTED" -e "Time"'

	

-include $(DEPS)

.PHONY: all cleam fclean re big run




