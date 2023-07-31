#DISCLAIMER! Around 99% of this file is AI generated, as I do not have the adequate understanding on have to make Makefiles


# Compiler to use
CC = gcc

# Flags to pass to the compiler
CFLAGS = -Wall -Werror

# Source files directory
SRC_DIR = ./src

# Output directory for object files and the final executable
BUILD_DIR = ./build

# List all the C source files using a wildcard
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)

# Generate object file names from source file names
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC_FILES))

# Final executable name
TARGET = CMath

# Default target (the target to build when you run 'make' without arguments)
all: $(TARGET)

# Rule to build the final executable
$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ_FILES)

# Rule to build object files from C source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up the build directory
clean:
	rm -f $(BUILD_DIR)/*.o $(TARGET)

.PHONY: all clean
