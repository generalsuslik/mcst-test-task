CXX = clang
CXX_FLAGS = -g -std=c++20 -Wall -Werror -Wpedantic

TARGET_SINGLE = main
TARGET_FORK   = main_fork

SRC_DIR = src
BIN_DIR = bin

SOURCES = $(SRC_DIR)/*.cpp

DEL_FILE = rm -f
MKDIR_P  = mkdir -p
INC_DIRS = -Iinc
LIBS     = $(INC_DIRS) -lstdc++

.PHONY:
	clean build_single

all: clean build_single

build_single: $(SOURCE)
	@echo "Building a one-process target"
	$(CXX) $(CXX_FLAGS) $(LIBS) main.cpp $(SOURCES) -o $(BIN_DIR)/$(TARGET_SINGLE)

build_fork: $(SOURCE)
	@echo "Building a multiprocessing target"
	$(CXX) $(CXX_FLAGS) $(LIBS) main_fork.cpp $(SOURCES) -o $(BIN_DIR)/$(TARGET_FORK)

run_single:
	./$(BIN_DIR)/$(TARGET_SINGLE)

run_fork:
	./$(BIN_DIR)/$(TARGET_FORK)

clean:
	$(MKDIR_P) $(BIN_DIR)
	$(DEL_FILE) $(BIN_DIR)/*
