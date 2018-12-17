#include <iostream>
#include <string.h>
#include <vector>
#include "fileData.h"
using namespace std;
class User
{
public:
	User(string, vector<FileData> &);
	string name;
	vector<FileData> fileDatas;
};
