#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
class FileData
{
public:
	FileData(string, string, string, long, long, long, string, short, short);
	FileData(string, string, string, string);
	string permission;
	string owner;
	string group;
	long int createTime;
	long int updateTime;
	long size;
	string name;
	short readLock = 0;
	short writeLock = 0;
	string info();
};