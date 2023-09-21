NAME = phonebook

CC = g++

CPPFLAGS = -std=c++98 -Wall -Werror -Wextra

BUILD_DIR = .build/

SRCS = phonebook.cpp contact.cpp main.cpp utils.cpp

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

re: fclean re

.PHONY: all clean fclean