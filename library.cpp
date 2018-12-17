#include <fstream> 
#include <string>
#include <iomanip>
#include <vector>
#include "library.h"
using namespace std;
User::User(string name,vector<FileRight> &fileRights){
	this.name = name;
	this.fileRights = fileRights;
}
FileRight::FileRight(string name,string permission){
        this.name = name;
        this.permission = permission;
}
Group::Group(vector<FileRight> &users){
        this.users = users;
}
