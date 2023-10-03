NAME = DiamondTrap

CC = c++

CPPFLAGS = -std=c++98 -Wall -Werror -Wextra

BUILD_DIR = .build/

SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp DiamondTrap.cpp

OBJS = $(SRCS:%.cpp=$(BUILD_DIR)/%.o)

$(BUILD_DIR)/%.o : %.cpp
	mkdir -p $(@D)
	$(CC) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
		rm -rf $(BUILD_DIR)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean