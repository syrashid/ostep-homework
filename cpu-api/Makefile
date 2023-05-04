CC = gcc
CFLAGS = -Wall

SRC := $(filter-out hw_template.c, $(wildcard *.c))
OBJ := $(patsubst %.c,%,$(SRC))

all: $(OBJ)

clean:
	rm -f $(OBJ)

%: %.c
	$(CC) $(CFLAGS) $< -o $@
