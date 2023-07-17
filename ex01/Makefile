NAME = RPN

SRCS = RPN.cpp main.cpp
OBJS = $(SRCS:%.cpp=%.o)
CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME)	: $(SRCS)
		$(CXX) $(CXXFLAGS) -o $@ $^

clean	:
	$(RM) $(OBJS)

fclean	: clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re