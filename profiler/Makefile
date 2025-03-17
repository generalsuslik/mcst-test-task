CXX = clang++
CXX_FLAGS = -g -std=c++20 -Wall -Werror -Wpedantic

TARGET_SINGLE  = main
TARGET_FORK    = main_fork
TARGET_ETALONE = etalone

SRC_DIR = src
BIN_DIR = bin

SOURCES = $(SRC_DIR)/*.cpp

DEL_FILE = rm -f
MKDIR_P  = mkdir -p
INC_DIRS = -Iinc
LIBS     = $(INC_DIRS)

.PHONY:
	clean build_single build_fork build_etalone

all: clean build_single build_fork build_etalone

build_single: $(SOURCE)
	@echo "Building one-process target"
	$(CXX) $(CXX_FLAGS) $(LIBS) main.cpp $(SOURCES) -o $(BIN_DIR)/$(TARGET_SINGLE)

build_fork: $(SOURCE)
	@echo "Building multiprocessing target"
	$(CXX) $(CXX_FLAGS) $(LIBS) main_fork.cpp $(SOURCES) -o $(BIN_DIR)/$(TARGET_FORK)

build_etalone: $(SOURCE)
	@echo "Building etalone target"
	$(CXX) $(CXX_FLAGS) $(LIBS) etalone.cpp src/process.cpp -o $(BIN_DIR)/$(TARGET_ETALONE)

run_single:
	./$(BIN_DIR)/$(TARGET_SINGLE)

run_fork:
	./$(BIN_DIR)/$(TARGET_FORK)

run_etalone:
	./$(BIN_DIR)/$(TARGET_ETALONE)

clean:
	$(MKDIR_P) $(BIN_DIR)
	$(DEL_FILE) $(BIN_DIR)/*
