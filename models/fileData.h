#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
class FileData
{
public:
	FileData(string, string, string, long, long, long, string, bool);
	FileData(string, string, string, string);
	string permission;
	string owner;
	string group;
	long createTime;
	long updateTime;
	long size;
	string name;
	bool lock = false;
	string info();
};