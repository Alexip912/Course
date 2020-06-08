EXE = bin/course
TEST = bin/test

DIR_SRC = build/src
DIR_TEST = build/test

DIR_GTEST = thirdparty/googletest
GFLAGS += -isystem $(DIR_GTEST)/include
LDFLAGS += -g -Wall -Wextra -pthread --std=c++17

FLAGS = -Wall -Werror --std=c++17
TEST_FLAGS = g++ $(GFLAGS) $(LDFLAGS) -L$(DIR_GTEST)/lib -l gtest_main -l gtest -lpthread

OBJ = g++ $(FLAGS) -c $^ -o $@
OBJ_TEST = g++ $(GFLAGS) $(LDFLAGS) -I src -c $^ -o $@

.PHONY: clean all

all: $(DIR_SRC)/main.o $(DIR_SRC)/menu.o $(DIR_SRC)/wordsTranslate.o
	g++ $(FLAGS) $^ -o $@
	
$(DIR_SRC)/main.o: src/main.cpp
	$(OBJ)
$(DIR_SRC)/menu.o: src/menu.cpp
	$(OBJ)
$(DIR_SRC)/wordsTranslate.o: src/wordsTranslate.cpp
	$(OBJ)
	
clean:
	rm -rf $(DIR_SRC)/*.o
	rm -rf $(DIR_TEST)/*.o
	rm bin/*.exe