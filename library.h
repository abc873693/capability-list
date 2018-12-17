using namespace std;
class User{
	public:
		Book(string ,vector<FileRight> &);
		string name;	
		vector<FileRight> fileRights;
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
		vector<string> users;
};
