#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
class FileRight
{
  public:
	FileRight(string, string);
	string name;
	string right;
};
class User
{
  public:
	User(string, vector<FileRight> &);
	string name;
	vector<FileRight> fileRights;
};