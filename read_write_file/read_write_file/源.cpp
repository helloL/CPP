#include<iostream>
#include<fstream>
#include<map>
#include<string>
#include<vector>
using namespace std;
int main(){
	//���ļ�������¼����ĳЩ����Ҫת������һЩ����
	ifstream infile("D:\\c++_project\\trans.txt");
	if(!infile){//�����ļ��Ƿ�ɹ�
		cerr<<"error:can't open the file"<<endl;
		return -1;
	}
	string s1,s2;
	map<string ,string> trans;
	//��map�����洢Ҫת����һ�Ե���
	//map��keyֵ��Ҫת���ĵ��ʣ����������ĵ��ʾ���ת����Ŀ�굥��
	while(infile>>s1){
		infile>>s2;
		trans.insert(make_pair(s1,s2));
	}
	infile.close();
	//��һ���ļ������ļ�������map�����е�key����Ӧ�ĵ��ʾ�Ҫת���ɸ�keyֵ�������ĵ���
	infile.open("D:\\c++_project\\need.txt");
	if(!infile){
		cerr<<"error:can't open the file"<<endl;
		return -1;
	}
	vector<string> tranf;
	//������ļ�Ҫ�����ļ��еĸ�ʽ�����ո�Ҫ����ȥ�����з�ҲҪ����
	//�����������ļ�������֮�����������з������뵽������Ҳֻ��һ�����з�
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
	//������ת���õ��ļ�д��û��ת��ǰ���ļ���
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
