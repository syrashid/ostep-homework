CC = gcc
CFLAGS = -Wall

SRC := $(filter-out hw_template.c, $(wildcard *.c))
OBJ := $(SRC:.c=.o)

all: $(OBJ)

clean:
	rm -f $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
