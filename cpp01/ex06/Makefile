NAME = HarlFilter

CC = c++

CPPFLAGS = -std=c++98 -Wall -Werror -Wextra

GREEN ="\033[0;32m"

RESET = "\033[0m"

BUILD_DIR = .build

SRCS = main.cpp Harl.cpp

OBJS = $(SRCS:%.cpp=$(BUILD_DIR)/%.o)

all: $(NAME)

$(BUILD_DIR)/%.o : %.cpp
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)
	@echo $(GREEN)$(NAME) has created ^^$(RESET)

clean:
		rm -rf $(BUILD_DIR)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all