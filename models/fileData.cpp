#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include "fileData.h"
using namespace std;
FileData::FileData(string name, string permission)
{
        this->name = name;
        this->permission = permission;
}