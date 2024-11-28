CC = g++
CFLAGS = -Wall -Wextra -Werror -Wpedantic -std=c++98

SRC_DIR = .
OBJ_DIR = obj
INC_DIR = .

SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
INC = $(wildcard $(INC_DIR)/*.hpp) $(wildcard $(INC_DIR)/*.h)
EXE = ex01

all: $(EXE)

$(EXE): $(OBJ) $(INC)
	$(CC) $(CFLAGS) -I$(INC_DIR) $(OBJ) -o $(EXE)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INC)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

valgrind: $(EXE)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(EXE)

fsan: $(EXE)
	$(CC) $(CFLAGS) -fsanitize=address -I$(INC_DIR) $(OBJ) -o $(EXE)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(EXE)

re: fclean all

.PHONY: all valgrind fsan clean fclean re
