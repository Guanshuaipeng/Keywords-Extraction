#include "PRISCLAS.h"
#include "iostream"
#include <fstream>//test��
#include <cctype>
#include <algorithm>
#include <vector>
using namespace std;

string LoadDoc(string address);

void main()
{
	const char* s= "�Ұ������찲�ţ��찲����̫������ΰ������ë��ϯ��ָ��������ǰ����";
	string StrCh;
	//StrCh = s;
	StrCh= "�Ұ������찲�ţ��찲����̫������ΰ������ë��ϯ��ָ��������ǰ����";
	vector<string> vecWordsCh;
	PRISCLAS *pClas = new PRISCLAS;
	pClas->InitSegment(1, true, true);
	pClas->Segment(StrCh, vecWordsCh);
	pClas->ReleaseMem();

	for(int i=0;i<vecWordsCh.size();i++)
		if(vecWordsCh[i].empty())
			vecWordsCh[i].erase();

	string NewStr="";
	for(int i=0;i<vecWordsCh.size();i++)
	{
		if (i!=0)
		{
			NewStr+=" ";
		}
		NewStr+=vecWordsCh[i];
	}

	const char* r=NewStr.c_str();

	system("pause");
}


string LoadDoc(string address)
{
	filebuf *pbuf;  
	ifstream filestr;  
	long size;  
	char * buffer;  
	// Ҫ���������ļ���������ö����ƴ�   
	filestr.open (address,ios::binary);  //TheOriginofSpeciesv6_rvPun
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

	return text;
}