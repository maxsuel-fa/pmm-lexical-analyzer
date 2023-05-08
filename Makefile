# Compiler flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Wpedantic

# Directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Object files
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Executable
TARGET = $(BIN_DIR)/main

# Default target
all: $(TARGET)

# Compiling object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Linking object files
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Cleaning object files and executable
clean:
	$(RM) $(OBJS) $(TARGET)

# Running tests
test:
	./$(TARGET) < test/input_file > test/output_file
	diff test/output_file test/expected_output_file

# Running the lexical analyzer
run:
	./$(TARGET) $(IN) $(OUT)

