CC = gcc
CFlags = -Wall -Werror -Wextra -pedantic
TARGET = hsh
SRC = main.c read_command.c tokenize.c handlers.c parse_command.c helpers.c executables.c
HEADER = main.h

all: $(TARGET)
hsh: $(SRC) $(HEADER)
	$(CC) $(CFlags) -o $(TARGET) $(SRC)

clean:
	rm -f shell

.PHONY: all clean
