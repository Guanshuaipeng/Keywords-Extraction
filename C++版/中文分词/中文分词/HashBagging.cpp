#include "HashBagging.h"
#include "iostream"
#include <fstream>//test��
#include <cctype>
#include <algorithm>

HASHBAGGING::HASHBAGGING()
{
}


//HASHBAGGING::HASHBAGGING(int num)
//{
//	This_Threshold=0;
//	m_reader= new MailReader;
//
//	m_Bagging_Gram.resize(num);
//
//	//%%�����ǹ�������������
//	for(int i=0;i<m_Bagging_Gram.size();i++)
//		m_Bagging_Gram[i]=new HASHGRAMBASED(2);
//
//	//%%����ÿһ��������
//	for(int i=0;i<m_Bagging_Gram.size();i++)
//	{
//		vector<string> Temp_Path;
//		Temp_Path.clear();
//
//		//%%Temp_Path����ÿ��Ԫ�ؾ���string��Ϊʲô��Ҫ��c_str()��ת��char*
//		//%%ʲô����������ȡ��ַ
//		Temp_Path.push_back(Feature_Path[2*i].c_str());
//		Temp_Path.push_back(Feature_Path[2*i+1].c_str());
//
//		m_Bagging_Gram[i]->Clear();
//		
//		//ÿ��������Ҫ����������ϣ��
//		m_Bagging_Gram[i]->Initialize(2);
//		//���ļ���Ϊÿ�������������ϣ��
//		m_Bagging_Gram[i]->LoadData(Temp_Path);
//
//	}
//
//}
//

/*
Initial������
���ܣ���ʼ��������
������num�������ĸ�����ÿ����������2����ϣ��
*/
void HASHBAGGING::Initial(int num)
{
	//%%��������������Ѿ���ʼ����
	This_Threshold=0;

	//%%����һ���ʼ��Ķ���
	m_reader= new MailReader;

	//%%m_Bagging_Gram��һ��������ÿ��Ԫ����HASHGRAMBASED
	//%%���ú��������ֵΪ1
	m_Bagging_Gram.resize(num);

	//%%ʵ����ÿ������Ԫ��
	for(int i=0;i<m_Bagging_Gram.size();i++)
		m_Bagging_Gram[i]=new HASHGRAMBASED(2);

}



/*
Release���������������Ĺ�����ͬ
*/
HASHBAGGING::~HASHBAGGING()
{
	SaveFea ();	

	for(unsigned n = 0; n < m_Bagging_Gram.size(); n ++)
		delete m_Bagging_Gram[n];

	delete m_reader;

}

void HASHBAGGING::Release()
{
	SaveFea ();	

	for(unsigned n = 0; n < m_Bagging_Gram.size(); n ++)
		delete m_Bagging_Gram[n];

	delete m_reader;

}

/*
LoadFea������
���ܣ�ָ�������ļ�������HashGramBase��ʼ����ϣ��ķ��������������õĹ�ϣ��
������
*/
void HASHBAGGING::LoadFea()
{
   //%%�˴�size()Ϊ1��
	for(int i=0;i<m_Bagging_Gram.size();i++)
	{
		vector<string> Temp_Path;
		Temp_Path.clear();

		//%%�ڵ��ú������Ѿ���ɳ�ʼ��
		//%%Feature_Path[0]=".\\kidult\\src\\spamOriginal.dat"
		//%%Feature_Path[0]=".\\kidult\\src\\hamOriginal.dat"
		Temp_Path.push_back(Feature_Path[2*i].c_str());
		Temp_Path.push_back(Feature_Path[2*i+1].c_str());

		//%%HASHGRAMBASED��Initial���Ѿ�����clear()�������ڴ���HASHGRAMBASED��ʱ��
		//%%�Ѿ�������Initialize�������˴�Ӧ��û�б�Ҫ
		m_Bagging_Gram[i]->Clear();
		m_Bagging_Gram[i]->Initialize(2);

		//%%���ļ��ж�ȡ��������ϣ����
		//%%�������������ļ���������ϣ��
		m_Bagging_Gram[i]->LoadData(Temp_Path);
	}
}


/*
SaveFea������
���ܣ�ָ�������ļ�������HashGramBaseд��ϣ��ķ������������õĹ�ϣ��д���ļ�
������
*/
void HASHBAGGING::SaveFea()
{
	//%%��ѵ���õ�����д���ļ�
	//%%ʵ�ʾ��ǽ���ϣ��д���ļ�
	for(int i=0;i<m_Bagging_Gram.size();i++)
	{
		vector<string> Temp_Path;
		Temp_Path.clear();
		Temp_Path.push_back(Feature_Path[2*i].c_str());
		Temp_Path.push_back(Feature_Path[2*i+1].c_str());
		m_Bagging_Gram[i]->ExportData(Temp_Path);
	}
}

/*
	StrToVecChineseWord������
	���ܣ���һ����Ӣ�Ļ�ϵĴʴ���������ĺ�Ӣ��
	������str��Ӣ�Ļ�ϵĴʴ��� StrEngӢ�Ĵʴ���StrCh���Ĵʴ�
*/
void HASHBAGGING::StrToVecChineseWord(string str, string & StrEng,string & StrCh)
{
	StrCh.clear(); 
	StrEng.clear();

	for(unsigned n = 0; n < str.length(); n ++)
	{
		//���Ĵ�
		if(str[n] < 0)
		{
			//vecStrCh.push_back(str.substr(n, 2));
			//%%%�������ֽڱ�ʾһ�������֣��������еĴʶ�������һ��
			StrCh+=str.substr(n, 2);
			n++;
		}
		else
			//vecItem.push_back(strLine.substr(n, 1));
			//vecStrEng.push_back(str.substr(n,1));
			
			//%%ֻ���һ��Ӣ���ַ�������Ҫ�ӵ�StrEngβ
			StrEng+=str.substr(n,1);
	}
}

/*
WordParserMail������
���ܣ�1�����ʼ� 2��������������Ӣ�ķ��� 3���ֱ����Ӣ�ķִ�
*/
//void HASHBAGGING::WordParserMail()
void HASHBAGGING::WordParserMail( )
{
	//ÿ�ο�ʼ�µ��ִ���������Ӧ�ó�ʼ��
	vecWordsEng.clear();
	vecWordsCh.clear();
	StrEng.clear();
	StrCh.clear();

	//%%���ú����Ѿ�������ʼ����Ƶĳ�ʼ��
	//%%��������ʼ��Ķ���Ķ��ʼ��ķ���
	m_reader->ReadMail(m_mailname);

	//++++++++++++++++++++++++++++++++++++++++++
	/*if(mode)
	{
		cout<<"***************body******************"<<endl;
		cout<<m_reader->GetBody()<<endl;
		cout<<"***************subject******************"<<endl;
		cout<<m_reader->GetSubject()<<endl;
		cout<<"**************************************"<<endl;
	}*/
	
	//++++++++++++++++++++++++++++++++++++++++++

	//%%���ʼ��������Լ�ȫ�Ľ��н�����������ֱ����strEng��Ӣ�ģ�strch�����ģ�
	StrToVecChineseWord(m_reader->GetBody()+m_reader->GetSubject(),StrEng, StrCh);

	//++++++++++++++++++++++++++++++++++++++++++
	/*if(mode)
	{
		ofstream outfile("body.txt");
		if(!outfile.is_open() )
			cout<<"failed open"<<endl;

		outfile.write(StrEng.c_str(), StrEng.size() );
		outfile.write(StrCh.c_str(), StrCh.size() );

		outfile.close();
	}*/

	//++++++++++++++++++++++++++++++++++++++++++

	//cout<<StrEng.c_str()<<endl;
	//cout<<StrCh.c_str()<<endl;
    
	/*if(StrCh.length()>2){
	//LoadSegRes();
	void* pSegger = CreateSegger();	
	WordSegment(pSegger, StrCh, vecWordsCh);
	ReleaseSegger(pSegger);
	//ReleaseSegRes();
	}*/
	//else{
	//	vecWordsCh.push_back(StrCh);
	//}

	//%%�����������һ�����Ĵ�
	if(StrCh.length()>2)
	{
		//�ִʣ��������Ķ�������һ��ģ�ͨ���ִʣ������һ��������
		PRISCLAS *pClas = new PRISCLAS;
		pClas->InitSegment(1, false, true);		
		pClas->Segment(StrCh, vecWordsCh);
		pClas->ReleaseMem();
	}

//for(int i=0;i<vecWordsCh.size();i++)
 // cout<<vecWordsCh[i].c_str()<<endl;

	//%%�����������һ��Ӣ���ַ�
   if(StrEng.length()>2)
   {
	   /*
		//m_mailterm.clear();

		//%%��Ϊ��ReadMail�У����ļ��л��з��ÿո������
		string tmpline,tmpword;
		basic_string <char>::size_type npos1,npos2,npos3,npos4;
		npos2 = npos1 =0;

		//%%��npos1 + 1λ�ÿ�ʼ������ֱ������"\n"��
		//%%��ʵ�����ļ��е�һ��
		while((npos2 = StrEng.find("\n",npos1 + 1)) != -1)
		{
			//��strEng�д�npos1��ʼ����ȡ����Ϊnpos2-npos1���ַ���
			//ʵ�ʾ����ó�һ�з���
			tmpline = StrEng.substr(npos1,npos2 - npos1);

			//��һ������һ���ַ���������һ��
			if(tmpline.length() < 2)
			{
				npos1 = npos2 + 1;
				continue;
			}

			//��һ��ĩβ���һ���ո�
			tmpline += " ";

			npos4 = npos3 = 0;
			//long wordhash;
			//%%�Կո�Ϊ��ֵ㣬��һ���ַ�����ֳ�һ������
			while((npos4 = tmpline.find(" ",npos3 + 1))!= -1)
			{
				tmpword = tmpline.substr(npos3,npos4 - npos3);
				vecWordsEng.push_back(tmpword);
				//wordhash = hash((char *)tmpword.c_str(),tmpword.length());
				//if(m_mailterm.find(wordhash) != m_mailterm.end())
					//m_mailterm[wordhash] ++;
				//else
					//m_mailterm[wordhash] = 1;
				npos3 = npos4 + 1;
			}

			npos1 = npos2 + 1;
		}
		*/

	   string::iterator h_iter = StrEng.begin();
	   string::iterator t_iter;
	   while(h_iter != StrEng.end() )
	   {
		   h_iter = find_if(h_iter,StrEng.end(), charactor_number );
		   t_iter = find_if(h_iter, StrEng.end(), not_charactor_number );

		   if(h_iter != StrEng.end() )
				vecWordsEng.push_back(string(h_iter, t_iter) );

		   h_iter = t_iter;
		   
	   }

   }

   else
   {
		vecWordsEng.push_back(StrEng);
   }
	StrEng.clear();
	StrCh.clear();
}

bool HASHBAGGING::charactor_number(char c)
{
	return isalnum(c);
}

bool HASHBAGGING::not_charactor_number(char c)
{
	return !isalnum(c);
}



/*
WordTrain������
���ܣ�����mail_mode�����÷����������Ӣ�Ĵʱ�ѵ����Ӧ�Ĺ�ϣ��

*/
void HASHBAGGING::WordTrain(string mail_mode)
{
	////%%body�е�0~14��ʲô��
	//std::string temst=m_reader->GetFrom()+m_reader->GetTo()+m_reader->GetSubject()+(m_reader->GetBody()).substr(0,14);

	////%%ΪʲôҪ�������ַ�����������������������������
	//long tempname=StrHash((char *)temst.c_str(),temst.length());

	//%%ֻ������һ����������ʱ��
	if(m_Bagging_Gram.size()==1)
	{
		//%%����ʲô���ͣ�������
		//%%mail_modeֻ��ѵ��ʱ����
		if(!mail_mode.compare("spam"))
		{
			//%%ͨ��train�ĵڶ�������ȷ��ѵ���Ĺ�ϣ��
			//%%ѵ��spam���ϣ��
			m_Bagging_Gram[0]->Train(vecWordsEng,0);
			m_Bagging_Gram[0]->Train(vecWordsCh,0);
		}		
		else if(!mail_mode.compare("ham"))
		{
			m_Bagging_Gram[0]->Train(vecWordsEng,1);
			m_Bagging_Gram[0]->Train(vecWordsCh,1);
		}
	}
}

/*
WordClassify������
���ܣ�����Ӣ�Ĵʱ������������������ֵ

*/
float HASHBAGGING::WordClassify()
{
	float sumeng=0,sumch=0;

	for(unsigned i=0;i<m_Bagging_Gram.size();i++)
	{
		//Ӣ��ķ���
		sumeng+=m_Bagging_Gram[i]->Classify(vecWordsEng);
		//���ĵ�����
		sumch+=m_Bagging_Gram[i]->Classify(vecWordsCh);
	}

	return sumch+sumeng;
}

long HASHBAGGING::StrHash (char *str, long len)
{
	long i;
	long hval;
	char *hstr;
	char chtmp;

	hval= len;

	hstr = (char *) &hval;

	for ( i = 0; i < len; i++)
	{

		hstr[0] ^= str[i];
		hstr[1] ^= str[i];
		hstr[2] ^= str[i];
		hstr[3] ^= str[i];

		hval = hval + (( hval >> 12) & 0x0000ffff) ;

		chtmp = hstr [0];
		hstr[0] = hstr[3];
		hstr [3] = chtmp;

		hval = (hval << 3 ) + (hval >> 29);
	}
	return (hval);
}
