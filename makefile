all: server.out

CC = g++
INCLUDE = .

server.out: server.o library.o
	${CC} -I${INCLUDE} -o server.o library.o
server.o: server.cpp
	${CC} -I${INCLUDE} -c server.cpp
library.o: library.cpp library.h
	${CC} -I${INCLUDE} -c library.cpp

clean:
	rm -f server.o library.o
