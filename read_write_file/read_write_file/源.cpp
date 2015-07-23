#include<iostream>
#include<fstream>
#include<map>
#include<string>
#include<vector>
using namespace std;
int main(){
	//打开文件，他记录的是某些单词要转化成另一些单词
	ifstream infile("D:\\c++_project\\trans.txt");
	if(!infile){//检查打开文件是否成功
		cerr<<"error:can't open the file"<<endl;
		return -1;
	}
	string s1,s2;
	map<string ,string> trans;
	//用map容器存储要转化的一对单词
	//map的key值是要转换的单词，键所关联的单词就是转换的目标单词
	while(infile>>s1){
		infile>>s2;
		trans.insert(make_pair(s1,s2));
	}
	infile.close();
	//打开一个文件，该文件中若含map容器中的key所对应的单词就要转换成该key值所关联的单词
	infile.open("D:\\c++_project\\need.txt");
	if(!infile){
		cerr<<"error:can't open the file"<<endl;
		return -1;
	}
	vector<string> tranf;
	//读入的文件要保持文件中的格式，即空格要读进去，换行符也要存着
	//但是在这若文件中两行之间有两个换行符，读入到容器中也只有一个换行符
	while(getline(infile,s1)){
		string::iterator beg=s1.begin();
		string word;
		while (beg!=s1.end()){
			if(*beg==' '){
				if(!word.empty()){
					tranf.push_back(word);
					word="\0";
				}
				tranf.push_back(" ");
			}
			else
				word+=*beg;
			beg++;
		}
		if(!word.empty())
			tranf.push_back(word);
		tranf.push_back("\n");
		
	}
//-----------------------------------------------------------------------------------
	vector<string>::iterator beg=tranf.begin();
	map<string,string>::iterator it;
	while(beg!=tranf.end()){
		it=trans.find(*beg);
		if(it!=trans.end())
			*beg=it->second;
		++beg;
	}
	beg=tranf.begin();
	while(beg!=tranf.end())
		cout<<*beg++;
//--------------------------------------------------------------------------------------
	//把上面转换好的文件写到没有转换前的文件中
	infile.close();
	ofstream outfile("D:\\c++_project\\need.txt",ofstream::app);
	if(!outfile){
		cerr<<"error:can't open the file"<<endl;
		return -1;
	}
	outfile<<"\n";
	beg=tranf.begin();
	while(beg!=tranf.end())
		outfile<<*beg++;
	outfile.close();
	return 0;
}
