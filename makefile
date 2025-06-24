# Compiler and flags
CC = clang
CFLAGS = -Wall -g -Iinclude

# Directories
SRC_DIR = src
OBJ_DIR = build
INCLUDE_DIR = include

# Target binary
TARGET = shell

# Source and object files
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Default target
build: $(TARGET)

# Link the final executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile .c to .o, ensuring build/ exists
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Run the program
run: build
	./$(TARGET)

# Clean up object files and executable
clean:
	rm -rf $(OBJ_DIR) $(TARGET)
