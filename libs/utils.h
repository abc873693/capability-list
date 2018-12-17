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

long int unixTimestamp();
vector<string> split(char *, string);
bool checkPermissionFormat(string);
int findUserGroupIndex(vector<Group>, string);
int findUserIndex(vector<User>, string);
int findFileIndex(vector<FileData>, string);
int findFileRightIndex(vector<FileRight>, string);