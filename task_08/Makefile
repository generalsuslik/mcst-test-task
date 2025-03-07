CC = gcc
CC_FLAGS = -g -W -Werror -Wall -Wpedantic -std=c11

TARGET = main

SRC_DIR = src
BIN_DIR = bin

SOURCES = $(SRC_DIR)/*.c

DEL_FILE = rm -f
MKDIR_P  = mkdir -p
INC_DIRS = -Iinc
LIBS     = $(INC_DIRS) -lc

FUNC ?= sig

.PHONY:
	clean build

all: clean build

build: $(SOURCE)
	$(CC) $(CC_FLAGS) $(LIBS) $(SOURCES) -o $(BIN_DIR)/$(TARGET)

run:
	./$(BIN_DIR)/$(TARGET) -f $(FUNC)

clean:
	$(MKDIR_P) $(BIN_DIR)
	$(DEL_FILE) $(BIN_DIR)/*

