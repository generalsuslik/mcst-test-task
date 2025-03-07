CC = gcc
CC_FLAGS = -g -Wall -Werror -Wpedantic -std=c11

TARGET = main

SOURCES  = ./*.c
INCLUDES = ./*.h

DEL_FILE = rm -f
LIBS     = $(INCLUDES) -lc

FILE ?= main.c

.PHONY:
	clean build

all: clean build

build: $(SOURCE)
	$(CC) $(CC_FLAGS) $(LIBS) $(SOURCES) -o $(TARGET)

run:
	./$(TARGET) $(FILE)

clean:
	$(DEL_FILE) $(TARGET)

