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