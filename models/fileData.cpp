#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <ctime>
#include "fileData.h"
#include "libs/utils.h"
using namespace std;
FileData::FileData(string permission,
                   string owner,
                   long createTime,
                   long updateTime,
                   long size,
                   string name)
{
        this->permission = permission;
        this->owner = owner;
        this->createTime = createTime;
        this->updateTime = updateTime;
        this->size = size;
        this->name = name;
}
FileData::FileData(string permission,
                   string owner,
                   string name)
{
        this->permission = permission;
        this->owner = owner;
        long int now = unixTimestamp();
        this->createTime = now;
        this->updateTime = now;
        this->size = 1;
        this->name = name;
}