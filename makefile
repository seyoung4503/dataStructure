# DLL.out : DLL.o main.o
# 	gcc -o DLL.out DLL.o main.o

# DLL.o : DLL.c
# 	gcc -c -o DLL.o DLL.c

# main.o : main.c
# 	gcc -c -o main.o main.c

# clean:
# 	rm *.o DLL.out


# # stack
# stack.out : ArrayStack.o main.o
# 	gcc -o stack.out ArrayStack.o main.o

# DLL.o : ArrayStack.c
# 	gcc -c -o ArrayStack.o ArrayStack.c

# main.o : main.c
# 	gcc -c -o main.o main.c

# clean:
# 	rm *.o stack.out

# # queue
# queue.out : CircularQueue.o main.o
# 	gcc -o queue.out CircularQueue.o main.o

# DLL.o : CircularQueue.c
# 	gcc -c -o CircularQueue.o CircularQueue.c

# main.o : main.c
# 	gcc -c -o main.o main.c

# clean:
# 	rm *.o queue.out


# # LCRS
# lcrs.out : LCRS.o main.o
# 	gcc -o lcrs.out LCRS.o main.o

# DLL.o : LCRS.c
# 	gcc -c -o LCRS.o LCRS.c

# main.o : main.c
# 	gcc -c -o main.o main.c

# clean:
# 	rm *.o lcrs.out



# CC=gcc
# CFLAGS=-g -Wall

# LDFLAGS =

# SRC_DIR=./lib/src/

# OBJ_DIR=./object

# INC=-Ilib/inc/

# TARGET=main.out

# # OBJS = main.o DLL.o ArrayStack.o CircularQueue.o LCRS.o
# SRCS = $(notdir $(wildcard $(SRC_DIR)/*.c))

# OBJS = $(SRCS:.c=.o)
# DEPS = $(SRCS:.c=.d)

# OBJECTS = $(parsubst %.o, $(OBJ_DIR)%.o, $(OBJS))
# DEPS = $(OBJECTS:.o=.d)

# all : $(TARGET)

# $(OBJ_DIR)/%.o : $(SRC_DIR)/%.cc
# 	$(CC) $(CFLAGS) $(INC) -c $< -o $@ -MD $(LDFLAGS)

# $(TARGET) : $(OBJECTS)
# 	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

# .PHONY: clean all
# clean:
# 	rm -f $(OBJECTS) $(DEPS) $(TARGET)

# -include $(DEPS)


CC = gcc
CFLAGS = -g -Wall
LDFLAGS =

SRC_DIR = ./lib/src/
OBJ_DIR = ./object
INC = -Ilib/inc/
TARGET = main.out

# Collecting source files in lib/src directory
SRCS = $(notdir $(wildcard $(SRC_DIR)/*.c))

# Generating object file names
OBJS = $(SRCS:.c=.o)
OBJECTS = $(addprefix $(OBJ_DIR)/,$(OBJS))
DEPS = $(OBJECTS:.o=.d)

all: $(TARGET)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(TARGET): $(OBJECTS) main.o
	$(CC) $(CFLAGS) $(OBJECTS) main.o -o $(TARGET) $(LDFLAGS)

main.o: main.c
	$(CC) $(CFLAGS) $(INC) -c main.c -o main.o

clean:
	rm -f $(OBJECTS) $(DEPS) $(TARGET) main.o

-include $(DEPS)


