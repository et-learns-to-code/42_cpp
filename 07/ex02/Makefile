NAME = array

SRC = main.cpp

OBJ_DIR = obj

OBJ = $(addprefix $(OBJ_DIR)/, ${SRC:.cpp=.o})

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -Wpedantic

RM = rm -f

all: $(NAME)

# Create the obj directory if it doesn't exist
# -p (parents) flag will create parent directories if
# necessary and won't throw an error even if the directory
# already exists
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

# | $(OBJ_DIR) part ensures that the directory is created before
# the compilation happens.
$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
