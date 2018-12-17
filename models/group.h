#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
class Group
{
public:
	Group(vector<string> &);
	vector<string> users;
	bool isMember(string);
};
