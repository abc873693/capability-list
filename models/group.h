#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
class Group
{
public:
	Group(string,vector<string> &);
	string name;
	vector<string> users;
	bool isMember(string);
};
