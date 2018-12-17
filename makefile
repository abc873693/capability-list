all: server.out

CC = g++
INCLUDE = .

server.out: server.o utils.o fileData.o group.o user.o
	${CC} -o server.out server.o utils.o fileData.o group.o user.o
server.o: server.cpp models/fileData.h models/group.h models/user.h
	${CC} -I${INCLUDE} -c server.cpp
utils.o: libs/utils.cpp
	${CC} -I${INCLUDE} -c libs/utils.cpp
fileData.o: models/fileData.cpp
	${CC} -I${INCLUDE} -c models/fileData.cpp
group.o: models/group.cpp
	${CC} -I${INCLUDE} -c models/group.cpp
user.o: models/user.cpp models/fileData.h
	${CC} -I${INCLUDE} -c models/user.cpp

clean:
	rm -f server.o utils.o fileData.o group.o user.o
