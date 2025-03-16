CXX = clang
CXX_FLAGS = -g -std=c++20 -Wall -Werror -Wpedantic

TARGET = main

SRC_DIR = src
BIN_DIR = bin

SOURCES = main.cpp $(SRC_DIR)/*.cpp

DEL_FILE = rm -f
MKDIR_P  = mkdir -p
INC_DIRS = -Iinc
LIBS     = $(INC_DIRS) -lstdc++

.PHONY:
	clean build

all: clean build

build: $(SOURCE)
	$(CXX) $(CXX_FLAGS) $(LIBS) $(SOURCES) -o $(BIN_DIR)/$(TARGET)

run:
	./$(BIN_DIR)/$(TARGET)

clean:
	$(MKDIR_P) $(BIN_DIR)
	$(DEL_FILE) $(BIN_DIR)/*
