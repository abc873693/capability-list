#include <iostream>
#include <string.h>
#include <vector>
#include "fileData.h"
using namespace std;
class User
{
  public:
	User(string, vector<FileRight> &);
	string name;
	vector<FileRight> fileRights;
};

class FileRight
{
  public:
	FileRight(string, string);
	string name;
	string right;
}