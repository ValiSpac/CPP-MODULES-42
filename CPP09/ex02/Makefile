CC = c++
CFLAGS = -Werror -Wextra -Wall -std=c++98 -I./inc
RM = rm -rf
NAME = PmergeMe
SRCS = main.cpp src/PmergeMe.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp Makefile ./inc/*.hpp
	${CC} ${CFLAGS} -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(RM) *.d

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: all clean
	./$(NAME)

.PHONY: all clean fclean re run
