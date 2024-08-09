# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++17 -IC:/raylib/include -g

# Linker flags
LDFLAGS = -LC:/raylib/lib -lraylib -lopengl32 -lgdi32 -lwinmm -lpsapi -ldxguid

# Source files
SRCS = dasher.cpp

# Output executable
OUT = dasher.exe

# Build target
all: $(OUT)

$(OUT): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(OUT) $(SRCS) $(LDFLAGS)

# Clean target
clean:
	del /Q $(OUT)
	del /Q *.o

.PHONY: all clean
