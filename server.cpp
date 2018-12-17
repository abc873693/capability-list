// Server side C/C++ program to demonstrate Socket programming
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include "models/group.h"
#include "models/user.h"
#include "libs/utils.h"
#define PORT 9090

string excuteCommand(string, char *);
string newFile(string, string, string);
string readFile(string, string);
string writeFile(string, string, string);
string changeFile(string, string, string);
string informationFile(string, string);

int main(int argc, char const *argv[])
{
	int server_fd, new_socket, valread;
	struct sockaddr_in address;
	int opt = 1;
	int addrlen = sizeof(address);
	char buffer[1024] = {0};
	const char *hello = "Hello from server";

	// Creating socket file descriptor
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	{
		printf("socket failed");
		exit(EXIT_FAILURE);
	}

	// Forcefully attaching socket to the port 8080
	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
				   &opt, sizeof(opt)))
	{
		printf("setsockopt");
		exit(EXIT_FAILURE);
	}
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);

	// Forcefully attaching socket to the port 8080
	if (bind(server_fd, (struct sockaddr *)&address,
			 sizeof(address)) < 0)
	{
		printf("bind failed");
		exit(EXIT_FAILURE);
	}
	if (listen(server_fd, 3) < 0)
	{
		printf("listen");
		exit(EXIT_FAILURE);
	}
	if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
							 (socklen_t *)&addrlen)) < 0)
	{
		printf("accept");
		exit(EXIT_FAILURE);
	}

	printf("Please Enter username:");
	valread = recv(new_socket, buffer, sizeof(buffer), 0);
	while (1)
	{
		string username = string(buffer);
		//send(new_socket, hello, strlen(hello), 0);
		printf("Please Enter username:");
		valread = recv(new_socket, buffer, sizeof(buffer), 0);
		printf("buffer : %s\n", buffer);
		string result = excuteCommand(username, buffer);
		cout << result << endl;
		//printf("Hello message sent\n");
	}
	return 0;
}

vector<User> capabilityList;
vector<Group> groupList;
vector<FileData> filelist;

string excuteCommand(string username, char *cmd)
{
	vector<string> list = split(cmd, " ");
	if (list.size() > 1)
	{
		if (list[0] == "new")
		{
			if (list.size() > 2)
				return newFile(username, list[1], list[2]);
			else
				return "Command error";
		}
		if (list[0] == "read")
		{
			return readFile(username, list[1]);
		}
		if (list[0] == "write")
		{
			if (list.size() > 2)
				return writeFile(username, list[1], list[2]);
			else
				return "Command error";
		}
		if (list[0] == "change")
		{
			if (list.size() > 2)
				return changeFile(username, list[1], list[2]);
			else
				return "Command error";
		}
		if (list[0] == "information")
		{
			return informationFile(username, list[1]);
		}
		else
		{
			return "unkown command";
		}
	}
	else
		return "unkown command";
}

string newFile(string username, string fileName, string permission)
{
	if (checkPermissionFormat(permission))
	{
		int userGroupIndex = findUserGroupIndex(groupList, username);
		if (userGroupIndex != -1)
		{
			for (int i = 0; i < capabilityList.size(); i++)
			{
				if (i == userGroupIndex)
				{
					if (permission.substr(0, 2) != "--")
						capabilityList[i].fileRights.push_back(
							FileRight(
								fileName,
								permission.substr(0, 2)));
				}
				else
				{
					int otherGroupIndex = findUserGroupIndex(groupList, capabilityList[i].name);
					if (otherGroupIndex == userGroupIndex)
					{
						if (permission.substr(2, 2) != "--")
							capabilityList[i].fileRights.push_back(
								FileRight(
									fileName,
									permission.substr(2, 2)));
					}
					else
					{
						if (permission.substr(4, 2) != "--")
							capabilityList[i].fileRights.push_back(
								FileRight(
									fileName,
									permission.substr(4, 2)));
					}
				}
			}
		}
		else
			return "User error";
	}
	else
		return "Command error";
}

string readFile(string username, string fileName)
{
	string content = "content";
	return content;
}

string writeFile(string username, string fileName, string permission)
{
	if (permission.size() == 1 && (permission[0] == 'o' || permission[0] == 'a'))
	{
		return "Success";
	}
	else
		return "Command error";
}

string changeFile(string username, string fileName, string permission)
{
	if (checkPermissionFormat(permission))
	{
		return "Success";
	}
	else
		return "Command error";
}

string informationFile(string username, string fileName)
{
	string information = "information";
	return information;
}