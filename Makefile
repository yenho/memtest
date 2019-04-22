.PHONY: build clean run

CC = gcc
CFLAGS = -Wall -g
CFLAGS += -O2

OBJS = memtest.o main.o

all: test

%.o: %.c
	$(CC) -c -o $@ $<

test: $(OBJS)
	$(CC) -o test $(OBJS)

run: clean all
	./test

clean:
	rm -f *.o test
