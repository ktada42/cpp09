NAME = btc

SRCS = BtcDataBase.cpp BtcParser.cpp debug.cpp GregorianDate.cpp main.cpp BitcoinExchange.cpp
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