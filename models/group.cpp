#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include "group.h"
using namespace std;
Group::Group(vector<string> &users)
{
        this->users = users;
}

bool Group::isMember(string user)
{
        int index = -1;
        for (int i = 0; i < users.size(); i++)
        {
                if (users[i] == user)
                        index = i;
        }
        return index != -1;
}