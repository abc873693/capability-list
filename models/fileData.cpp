#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <ctime>
#include "fileData.h"
using namespace std;
FileData::FileData(string permission,
                   string owner,
                   string group,
                   long createTime,
                   long updateTime,
                   long size,
                   string name,
                   bool lock)
{
        this->permission = permission;
        this->owner = owner;
        this->group = group;
        this->createTime = createTime;
        this->updateTime = updateTime;
        this->size = size;
        this->name = name;
        this->lock = lock;
}
FileData::FileData(string permission,
                   string owner,
                   string group,
                   string name)
{
        this->permission = permission;
        this->owner = owner;
        this->group = group;
        long int now = 11111;
        this->createTime = now;
        this->updateTime = now;
        this->size = 1;
        this->name = name;
        this->lock = 0;
}
string FileData::info()
{
        return permission +
               " " + owner +
               " " + group +
               " " + to_string(size) +
               " " + to_string(createTime) +
               " " + to_string(updateTime) +
               " " + name;
}