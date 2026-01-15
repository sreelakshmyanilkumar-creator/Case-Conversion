# compiler
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Target executable
TARGET = main

# Source files
SRCS = main.c read_user_input.c change_case.c
OBJS = $(SRCS:.c=.o)

# Default rule
all: $(TARGET)

#Link object files into final executable
$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

#compile each .c into .o
%.o: %.c read_user_input.h change_case.h
	$(CC) $(CFLAGS) -c $< -o $@

#clean up
clean:
	rm -f $(OBJS) $(TARGET)