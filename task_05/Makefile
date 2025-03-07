CC = gcc
CC_FLAGS = -g -Wall -Werror -Wpedantic -std=c11

TARGET = main

SOURCES = main.c

DEL_FILE = rm -f
LIBS     = -lc

.PHONY:
	clean build

all: clean build

build: $(SOURCE)
	$(CC) $(CC_FLAGS) $(LIBS) $(SOURCES) -o $(TARGET)

run:
	./$(TARGET)

clean:
	$(DEL_FILE) $(TARGET)

