#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{

	//socket的建立
	int sockfd = 0;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if (sockfd == -1)
	{
		printf("Fail to create a socket.");
	}

	//socket的連線

	struct sockaddr_in info;
	bzero(&info, sizeof(info));
	info.sin_family = PF_INET;

	//localhost test
	info.sin_addr.s_addr = inet_addr("127.0.0.1");
	info.sin_port = htons(9090);

	int err = connect(sockfd, (struct sockaddr *)&info, sizeof(info));
	if (err == -1)
	{
		printf("Connection error");
	}
	else
		printf("Connection Success\n");

	//Send a message to server
	char message[1000];
	char receiveMessage[100] = {};
	while (cin.getline(message, 1000))
	{
		send(sockfd, message, sizeof(message), 0);
		//recv(sockfd, receiveMessage, sizeof(receiveMessage), 0);
	}
	printf("close Socket\n");
	close(sockfd);
	return 0;
}