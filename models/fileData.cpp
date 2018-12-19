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
                   long int createTime,
                   long int updateTime,
                   long size,
                   string name,
                   short readLock,
                   short writelock)
{
        this->permission = permission;
        this->owner = owner;
        this->group = group;
        this->createTime = createTime;
        this->updateTime = updateTime;
        this->size = size;
        this->name = name;
        this->readLock = readLock;
        this->writeLock = writelock;
}
FileData::FileData(string permission,
                   string owner,
                   string group,
                   string name)
{
        this->permission = permission;
        this->owner = owner;
        this->group = group;
        time_t t = std::time(0);
        long int now = static_cast<long int>(t);
        this->createTime = now;
        this->updateTime = now;
        this->size = 1;
        this->name = name;
        this->readLock = 0;
        this->writeLock = 0;
}
string FileData::info()
{
        time_t ct = createTime;
        time_t ut = updateTime;
        char buffA[20];
        char buffB[20];
        strftime(buffA, 20, "%Y-%m-%d %H:%M:%S", localtime(&ct));
        strftime(buffB, 20, "%Y-%m-%d %H:%M:%S", localtime(&ut));
        return permission +
               " " + owner +
               " " + group +
               " " + to_string(size) +
               " " + string(buffA) +
               " " + string(buffB) +
               " " + name;
}