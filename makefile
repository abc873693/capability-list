all: server.out client.out

CC = g++
INCLUDE = .

client.out:client.o
	${CC} -o client.out client.o
client.o:
	${CC} -I${INCLUDE} -c client.cpp
server.out: server.o utils.o fileData.o group.o user.o
	${CC} -o server.out server.o utils.o fileData.o group.o user.o -lpthread
server.o: server.cpp models/fileData.h models/group.h models/user.h
	${CC} -I${INCLUDE} -c server.cpp -lpthread
utils.o: libs/utils.cpp models/fileData.h models/group.h models/user.h
	${CC} -I${INCLUDE} -c libs/utils.cpp
fileData.o: models/fileData.cpp
	${CC} -I${INCLUDE} -c models/fileData.cpp
group.o: models/group.cpp
	${CC} -I${INCLUDE} -c models/group.cpp
user.o: models/user.cpp models/fileData.h
	${CC} -I${INCLUDE} -c models/user.cpp

clean:
	rm -f client.o server.o utils.o fileData.o group.o user.o
