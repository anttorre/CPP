BOLD	:= \033[1m
BLACK	:= \033[30;1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
MAGENTA	:= \033[35;1m
CYAN	:= \033[36;1m
WHITE	:= \033[37;1m
RESET	:= \033[0m

CC = clang++
CFLAGS = -g -fsanitize=address,undefined -Wall -Werror -Wextra 
#-fsanitize=address,undefined
NAME = btc

STD = -std=c++98

SRCS =	main.cpp \
		BitcoinExchange.cpp
		

OBJS = $(SRCS:.cpp=.o)

$(NAME) :	$(OBJS)
			@echo "$(MAGENTA)$(BOLD)Compiling...$(RESET)"
			@$(CC) $(CFLAGS) $(STD) $(OBJS) -o $(NAME)
			@echo "$(CYAN)$(BOLD)Done$(RESET)"

$(OBJS):	%.o : %.cpp
			@$(CC) $(CFLAGS) $(STD) -c $< -o $@

all : $(NAME)

clean:
			@echo "$(RED)$(BOLD)Cleaning objects...$(RESET)"
			@rm -f $(OBJS)
			@echo "$(GREEN)$(BOLD)Done.$(RESET)"

fclean:
			@echo "$(RED)$(BOLD)Cleaning all files...$(RESET)"
			@rm -f $(NAME) $(OBJS) $(LIB_NAME)
			@echo "$(GREEN)$(BOLD)Done.$(RESET)"

re : fclean all

cub : all clean

.PHONY : all re fclean clean