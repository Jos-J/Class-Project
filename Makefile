# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++17

# Target executable
TARGET = main.exe

# Source files
SRCS = main.cpp roster.cpp student.cpp

# Object files (replace .cpp with .o)
OBJS = $(SRCS:.cpp=.o)

# Default rule: build the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to build object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean compiled files
.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)

# === Test Section ===
TEST_SRCS = tests/test_student.cpp
TEST_OBJS = $(TEST_SRCS:.cpp=.o)
TEST_TARGET = test_student.exe

test: $(TEST_TARGET)
	./$(TEST_TARGET)

$(TEST_TARGET): $(TEST_SRCS) student.cpp roster.cpp
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST_SRCS) student.cpp roster.cpp
