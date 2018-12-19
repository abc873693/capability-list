#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <vector>
#include <ctime>
#include "../models/group.h"
#include "../models/user.h"
#include "../models/fileData.h"
using namespace std;

long int unixTimestamp()
{
    time_t t = std::time(0);
    long int now = static_cast<long int>(t);
    return now;
}

string converTime(long int time)
{
    time_t t = time;
    return string(ctime(&t));
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

void readGroupData(vector<Group> &groupList, string FILENAME)
{
    ifstream fin(FILENAME);
    while (!fin.eof())
    {
        string groupName;
        int size;
        fin >> groupName >> size;
        vector<string> users;
        while (size--)
        {
            string userNmae;
            fin >> userNmae;
            users.push_back(userNmae);
        }
        Group tmp(groupName, users);
        groupList.push_back(tmp);
    }
    fin.close();
}

void readFileData(vector<FileData> &filelist, string FILENAME)
{
    ifstream fin(FILENAME);
    while (!fin.eof())
    {
        string permission;
        string owner;
        string group;
        long createTime;
        long updateTime;
        long size;
        string name;
        bool readLock = false;
        bool writeLock = false;
        fin >> permission >> owner >> group >> size >> createTime >> updateTime >> name >> readLock >> writeLock;
        FileData tmp(permission, owner, group, createTime, updateTime, size, name, readLock, writeLock);
        filelist.push_back(tmp);
    }
    fin.close();
}

void readCapabilityListData(vector<User> &capabilityList, string FILENAME)
{
    ifstream fin(FILENAME);
    while (!fin.eof())
    {
        string name;
        int size;
        fin >> name >> size;
        vector<FileRight> files;
        while (size--)
        {
            string fileName;
            string right;
            fin >> fileName >> right;
            files.push_back(FileRight(fileName, right));
        }
        User tmp(name, files);
        capabilityList.push_back(tmp);
    }
    fin.close();
}

void writeGroupData(vector<Group> &groupList, string FILENAME)
{
    ofstream fout(FILENAME);
    for (unsigned int i = 0; i < groupList.size(); i++)
    {
        fout << groupList[i].name << " " << groupList[i].users.size() << " ";
        for (int j = 0; j < groupList[i].users.size(); j++)
        {
            fout << groupList[i].users[j];
            if (j < groupList[i].users.size() - 1)
                fout << " ";
        }
        if (i < groupList.size() - 1)
            fout << endl;
    }
    fout.close();
}

void writeFileData(vector<FileData> &filelist, string FILENAME)
{
    ofstream fout(FILENAME);
    for (unsigned int i = 0; i < filelist.size(); i++)
    {
        FileData file = filelist[i];
        fout << file.permission << " "
             << file.owner << " "
             << file.group << " "
             << file.size << " "
             << file.createTime << " "
             << file.updateTime << " "
             << file.name << " "
             << file.readLock << " "
             << file.writeLock;
        if (i < filelist.size() - 1)
            fout << endl;
    }
    fout.close();
}
void writeCapabilityListData(vector<User> &capabilityList, string FILENAME)
{
    ofstream fout(FILENAME);
    for (unsigned int i = 0; i < capabilityList.size(); i++)
    {
        User user = capabilityList[i];
        fout << user.name << " " << user.fileRights.size();
        if (user.fileRights.size() != 0)
            fout << " ";
        for (unsigned int j = 0; j < user.fileRights.size(); j++)
        {
            FileRight right = user.fileRights[j];
            fout << right.name << " "
                 << right.right;
            if (j < user.fileRights.size() - 1)
                fout << " ";
        }
        if (i < capabilityList.size() - 1)
            fout << endl;
    }
    fout.close();
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