using namespace std;
class User{
	public:
		User(string ,vector<FileRight> &);
		string name;	
		vector<FileRight> &fileRights;
};
class FileRight{
	public:
		FileRight(string,string);
		string name;
		string permission;
};
class Group{
	public:
		Group(vector<string> &);
		vector<string> &users;
};
