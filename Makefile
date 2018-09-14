# Makefile to compile several simple programs

### Variables for this project ###
# These should be the only ones that need to be modified
# The files that must be compiled, with a .o extension
OBJECTS = main.o vigenere_cipher.o
# The header files
DEPENDS = vigenere_cipher.h
# The executable programs to be created
MAIN = main

### Variables for the compilation rules ###
# These should work for most projects, but can be modified when necessary
# The compiler program to use
CC = gcc
# Options to use when compiling object files
CFLAGS = -Wall -g -std=c99
# Options to use for the final linking process
# This one links the math library
LDFLAGS = -lm

### The rules ###
# These should work for most projects without change

# Default rule
all: $(MAIN)

# Rule to make the executable
$(MAIN): $(OBJECTS)
	$(CC) $^ -o $@ $(LDFLAGS)

# Rule to make the object files
%.o: %.c $(DEPENDS)
	$(CC) $< -c -o $@ $(CFLAGS)

# Clear the compiled files
clean:
	rm -rf *.o $(MAIN)

# Indicate the rules that do not refer to a file
.PHONY: clean all
