#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <ctime>
#include "fileData.h"
using namespace std;
FileData::FileData(string permission,
                   string owner,
                   long createTime,
                   long updateTime,
                   long size,
                   string name,
                   bool lock)
{
        this->permission = permission;
        this->owner = owner;
        this->createTime = createTime;
        this->updateTime = updateTime;
        this->size = size;
        this->name = name;
        this->lock = lock;
}
FileData::FileData(string permission,
                   string owner,
                   string name)
{
        this->permission = permission;
        this->owner = owner;
        long int now = 11111;
        this->createTime = now;
        this->updateTime = now;
        this->size = 1;
        this->name = name;
}