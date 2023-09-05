NAME = convert

CC = g++

CFLAGS =   -Wall -Werror -Wextra -g  #-std=c++98

SRCS =  ScalarConverter.cpp \
		Utility.cpp \
		main.cpp \
		tester.cpp



OBJS = $(SRCS:.cpp=.o)

#all rule
all:	$(NAME)

convert: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp						#produce object files from the c files.
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