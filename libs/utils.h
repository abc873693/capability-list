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
bool checkPermissionFormat(string);
int findUserGroupIndex(vector<Group> , string );