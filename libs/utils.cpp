#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <vector>
#include <ctime>
using namespace std;

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
            if (!(permission[i] == 'r' || permission[i] == 'w' || permission[i] == '-'))
                error++;
        }
        if (error == 0)
            return true;
        else
            return false;
    }
    else
        return false;
}