CC = gcc
CFLAGS = -Wall -Werror -g
LIBS = -lm
SOURCES = $(wildcard *.c)
EXECUTABLES = $(SOURCES:.c=)

all: $(EXECUTABLES)

%: %.c
	$(CC) $(CFLAGS) $< -o $@ $(LIBS)

clean:
	rm -f $(EXECUTABLES)
