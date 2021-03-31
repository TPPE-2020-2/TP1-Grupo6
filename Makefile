PROJECT_NAME=tp1

CPP_SRC=$(filter-out src/tests.cpp, $(wildcard src/*.cpp))

HPP_SRC=$(wildcard inc/*.hpp)

OBJ=$(subst .cpp,.o,$(subst src,obj,$(CPP_SRC)))

CC=g++

CC_FLAGS = -Wall -c -I inc -L lib

all: objFolder $(PROJECT_NAME)

test: objFolder tests

tests: $(OBJ)
	$(CC) -o test.bin teste/main.cpp $(filter-out obj/main.o, $^) -I inc -L lib -lgtest -pthread

clean:
	rm -rf obj/*.o *.bin

objFolder:
	mkdir -p obj

$(PROJECT_NAME): $(OBJ)
	$(CC) -o $@.bin $^

obj/%.o: src/%.cpp inc/%.hpp
	$(CC) -o $@ $< $(CC_FLAGS)

obj/main.o: src/main.cpp $(HPP_SRC)
	$(CC) -o $@ $< $(CC_FLAGS)