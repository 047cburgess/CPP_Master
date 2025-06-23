NAME = prog
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -g

SRCS = main.cpp \
       Bureaucrat.cpp \
       AForm.cpp \
       ShrubberyCreationForm.cpp \
       RobotomyRequestForm.cpp \
	PresidentialPardonForm.cpp \
	Intern.cpp \

OBJS = $(SRCS:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o:	%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

run:	$(NAME)
	./$(NAME)

leaks:	all
	valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes ./$(NAME)

.PHONY: all cleam fclean re run leaks




