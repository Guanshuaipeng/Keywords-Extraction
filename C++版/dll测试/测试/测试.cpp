#include <iostream>
 #include <string>
 //#include <regex>
 #include <fstream>  
 //#include <sstream>
 //#include <utility>
 //#include <algorithm>
 //#include <string>
 //#include <cctype>
 //#include <set>
 //#include <queue>
 //
 //#include <hash_map>

#include "Node.h"



void main(){
	
	
	
	/////////////////////////////          C++ TXT �����ļ��Ķ�ȡ //////////////////////////
	filebuf *pbuf;  
	ifstream filestr;  
	long size;  
	char * buffer;  
	// Ҫ���������ļ���������ö����ƴ�   
	filestr.open ("D:\\test.txt", ios::binary);  //TheOriginofSpeciesv6_rvPun
	// ��ȡfilestr��Ӧbuffer�����ָ��   
	pbuf=filestr.rdbuf();  

	// ����buffer���󷽷���ȡ�ļ���С  
	size=pbuf->pubseekoff (0,ios::end,ios::in);  
	pbuf->pubseekpos (0,ios::in);  

	// �����ڴ�ռ�  
	buffer=new char[size];  

	// ��ȡ�ļ�����  
	pbuf->sgetn (buffer,size);  

	filestr.close();  
	// �������׼���  

	string text=buffer;
	//string test;
	
	

	/*
	char *p;
	p=new char[text.size()]; 
	text.copy(p,text.size());
	*(p+text.size())='\0';
	ofstream fout;
	fout.open("D:\\1.txt", ios::binary);
	fout.write(p,text.size());
	fout.close(); 
	*/

	int i;
	Node *result;
	result=keyword_extra_entropy_MAX(text);
	for(i=0;i<30;i++)
		cout<<endl<<result[i].word<<"==="<<result[i].EDnor<<"==="<<result[i].frequency;


	vector<int> p=result[0].t_loc;
	for(i=0;i<p.size();i++)
		cout<<endl<<p[i];
	//cout<<word_loc.size();
//	cout<<Term_list.size();
//	cout<<word_frequency.size();
	system("pause");
}