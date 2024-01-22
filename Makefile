# List of source files
SRCS = main.cpp player.cpp

# List of object files
OBJS = $(SRCS:.cpp=.o)

# Compiler
CC = g++

# Compiler flags
CFLAGS = -c -Wall

# Linker flags
LDFLAGS = -lraylib

# Output executable
OUTPUT = output

all: $(OUTPUT)

$(OUTPUT): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(OUTPUT)

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJS) $(OUTPUT)