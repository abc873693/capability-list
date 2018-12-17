#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <vector>
#include <ctime>
#include "group.h"
#include "user.h"
using namespace std;

long int unixTimestamp()
{
    time_t t = std::time(0);
    long int now = static_cast<long int>(t);
    return now;
}

vector<string> split(char *phrase, string delimiter)
{
    vector<string> list;
    string s = string(phrase);
    size_t pos = 0;
    string token;
    while ((pos = s.find(delimiter)) != string::npos)
    {
        token = s.substr(0, pos);
        list.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    list.push_back(s);
    return list;
}

bool checkPermissionFormat(string permission)
{
    if (permission.size() == 6)
    {
        int error = 0;
        for (int i = 0; i < 6; i++)
        {
            if (i % 2 == 0)
            {
                if (!(permission[i] == 'r' || permission[i] == '-'))
                    error++;
            }
            else
            {
                if (!(permission[i] == 'w' || permission[i] == '-'))
                    error++;
            }
        }
        return error == 0;
    }
    else
        return false;
}

int findUserGroupIndex(vector<Group> groupList, string username)
{
    for (int i = 0; i < groupList.size(); i++)
    {
        if (groupList[i].isMember(username))
            return i;
    }
    return -1;
}

int findUserIndex(vector<User> capabilityList, string username)
{
    for (int i = 0; i < capabilityList.size(); i++)
    {
        if (capabilityList[i].name == username)
            return i;
    }
    return -1;
}

int findFileIndex(vector<FileData> filelist, string fileName)
{
    for (int i = 0; i < filelist.size(); i++)
    {
        if (filelist[i].name == fileName)
            return i;
    }
    return -1;
}

int findFileRightIndex(vector<FileRight> fileRightList, string fileName)
{
    for (int i = 0; i < fileRightList.size(); i++)
    {
        if (fileRightList[i].name == fileName)
            return i;
    }
    return -1;
}