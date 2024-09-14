# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Directories
SRC_DIR = src
OBJ_DIR = build/obj
BIN_DIR = build/bin

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Object files (replace .c with .o and move to OBJ_DIR)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Executable name
EXEC = $(BIN_DIR)/treee

# Default target: build the executable
all: $(EXEC)

# Rule for building the executable
$(EXEC): $(OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Rule for building object files from source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create bin and obj directories if they don't exist
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean up the build (remove the executable and object files)
clean:
	rm -rf $(OBJ_DIR)/*.o $(EXEC)

# Run the interpreter
run: $(EXEC)
	./$(EXEC) .

.PHONY: all clean run
