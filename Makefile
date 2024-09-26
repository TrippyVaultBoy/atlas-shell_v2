CC = gcc
CFlags = -Wall -Werror -Wextra -pedantic
TARGET = hsh
SRC = main.c read_command.c tokenize.c handle_cd.c
HEADER = main.h

all: $(TARGET)
hsh: $(SRC) $(HEADER)
	$(CC) $(CFlags) -o $(TARGET) $(SRC)

clean:
	rm -f shell

.PHONY: all clean
