CXX=g++
CXX_FLAGS=-fsanitize=address,undefined -fno-omit-frame-pointer -g -Wall -Wshadow -std=c++17 -Wno-unused-result -Wno-sign-compare -Wno-char-subscripts
EXEC_NAME=TP1

all: build

build: instruction.o symbol_table.o symbol.o main.o
	${CXX} ${CXX_FLAGS} $^ -o ${EXEC_NAME}

main.o: main.cpp
	${CXX} ${CXX_FLAGS} -c $^ -o $@

instruction.o: instruction.cpp
	${CXX} ${CXX_FLAGS} -c $^ -o $@

symbol_table.o: symbol_table.cpp
	${CXX} ${CXX_FLAGS} -c $^ -o $@

symbol.o: symbol.cpp
	${CXX} ${CXX_FLAGS} -c $^ -o $@
        
clean:
	rm -f *.o prog

run:
	./${EXEC_NAME}
