#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include "user.h"
using namespace std;
User::User(string name, vector<FileRight> &fileRights)
{
        this->name = name;
        this->fileRights = fileRights;
}
FileRight::FileRight(string name,
                     string right)
{
        this->name = name;
        this->right = right;
}