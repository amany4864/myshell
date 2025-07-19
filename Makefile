CC = gcc
CFLAGS = -Iinclude -Wall -g
SRCS = src/main.c src/executor.c src/parser.c
OBJS = $(SRCS:.c=.o)
TARGET = mysh

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
