CC = clang
CC_FLAGS = -g -std=c++20

TARGET = main

SOURCES = main.cpp

DEL_FILE = rm -f
LIBS     = -lstdc++

.PHONY:
	clean build

all: clean build

build: $(SOURCE) 
	$(CC) $(CC_FLAGS) $(LIBS) $(SOURCES) -o $(TARGET)

run:
	./$(TARGET)

clean:
	$(DEL_FILE) $(TARGET)

