#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
class FileData
{
  public:
	FileData(string, string, long, long, long, string);
	FileData(string, string, string);
	string permission;
	string owner;
	long createTime;
	long updateTime;
	long size;
	string name;
};