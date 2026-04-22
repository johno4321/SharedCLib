CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS =

SRCS = main.c common.c string.c stack.c queue.c list.c dictionary.c tests.c
OBJS = $(SRCS:.c=.o)
TARGET = sharedclib.exe

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean