CC = g++
CFLAGS = -Wall -Wextra -Werror -Wpedantic -std=c++98

SRC_DIR = .
OBJ_DIR = obj
INC_DIR = -I.

SRC = $(wildcard *.cpp)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
INC = $(wildcard *.hpp) $(wildcard *.h)
EXE = ex00

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) $(INC_DIR) $(OBJ) -o $(EXE)

%.o: %.cpp $(INC)
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@

valgrind: $(EXE)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(EXE)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(EXE)

re: fclean all
