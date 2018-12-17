#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include "user.h"
using namespace std;
User::User(string name, vector<FileData> &fileDatas)
{
        this->name = name;
        this->fileDatas = fileDatas;
}