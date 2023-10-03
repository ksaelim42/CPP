NAME = a.out

CXX = c++

CXX_FLAGS = -std=c++98 -Wall -Werror -Wextra

BUILD_DIR = .build

SRCS = main.cpp Fixed.cpp

OBJS = $(SRCS:%.cpp=$(BUILD_DIR)/%.o)

$(BUILD_DIR)/%.o : %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXX_FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CXX_FLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
		rm -rf $(BUILD_DIR)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean
