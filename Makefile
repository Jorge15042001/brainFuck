CC:=gcc
OUTPUT := brainfuck

SRC_DIR := src
OBJ_DIR := build/obj
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))
OBJ_FILES_NO_MAIN := $(filter-out $(OBJ_DIR)/main.o, $(OBJ_FILES))

TEST_SRC_DIR := test
TEST_BIN_DIR := test_build
TEST_SRC_FILES := $(wildcard $(TEST_SRC_DIR)/*.c)
TEST_BIN_FILES := $(patsubst $(TEST_SRC_DIR)/%.c,$(TEST_BIN_DIR)/%,$(TEST_SRC_FILES))


CXXFLAGS := -O3 -Wall -Wextra 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p build
	mkdir -p build/obj
	$(CC)   $(CXXFLAGS)   -c -o $@ $^  

$(OUTPUT): $(OBJ_FILES)
	$(CC)  -o $@ $^   $(CXXFLAGS) 

$(TEST_BIN_DIR)/%: $(TEST_SRC_DIR)/%.c
	mkdir -p test_build
	$(CC)   $(CXXFLAGS)  $(OBJ_FILES_NO_MAIN)  -o $@ $^ -lcriterion 

test: $(TEST_BIN_FILES)
	for test in $(TEST_BIN_FILES) ; do ./$$test ; done



clean :
	rm -rf build
	rm -rf test_build
	rm $(OUTPUT)

