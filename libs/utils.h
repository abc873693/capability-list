#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <vector>
#include <ctime>
using namespace std;

long int unixTimestamp();
vector<string> split(char *, string);
void readGroupData(vector<Group> &, string);
void readFileData(vector<FileData> &, string);
void readCapabilityListData(vector<User> &, string);
bool checkPermissionFormat(string);
int findUserGroupIndex(vector<Group>, string);
int findUserIndex(vector<User>, string);
int findFileIndex(vector<FileData>, string);
int findFileRightIndex(vector<FileRight>, string);