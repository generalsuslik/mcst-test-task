CC = gcc
CC_FLAGS = -g -W -Werror -Wall -Wpedantic -std=c11

TARGET_SERVER = server
TARGET_CLIENT = client

SRC_DIR = src
BIN_DIR = bin

SERVER_SOURCES = $(SRC_DIR)/server.c $(SRC_DIR)/erproc.c
CLIENT_SOURCES = $(SRC_DIR)/client.c $(SRC_DIR)/erproc.c

DEL_FILE = rm -f
MKDIR_P  = mkdir -p
INC_DIRS = -Iinc
LIBS     = $(INC_DIRS) -lc

.PHONY: clean build_server build_client
all: clean build_server build_client

build_server: $(SOURCE)
	$(CC) $(CC_FLAGS) $(LIBS) $(SERVER_SOURCES) -o $(BIN_DIR)/$(TARGET_SERVER)

build_client: $(SOURCE)
	$(CC) $(CC_FLAGS) $(LIBS) $(CLIENT_SOURCES) -o $(BIN_DIR)/$(TARGET_CLIENT)

run:
	./$(BIN_DIR)/$(TARGET)

clean:
	${MKDIR_P} ${BIN_DIR}
	$(DEL_FILE) $(BIN_DIR)/*

