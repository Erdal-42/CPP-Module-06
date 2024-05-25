NAME = ex01

CC = g++

CFLAGS =   -Wall -Werror -Wextra -g  -std=c++98

SRCS =  Serializer.cpp \
		main.cpp 



OBJS = $(SRCS:.cpp=.o)

#all rule
all:	$(NAME)

ex01: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

#clean rule
clean:
	rm -f $(OBJS)

#fclean rule
fclean: clean
	rm -f $(NAME)

#re rule
re: fclean all

.PHONY: all clean fclean re