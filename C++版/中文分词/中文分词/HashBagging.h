#include "../PRIS-CLAS-DEMO V0.6/PRISCLAS.h"
//#include <boost/tokenizer.hpp>
#include <vector>
#include <string>
#include <set>

using namespace std;
//using namespace boost;

typedef struct {
	int spamall,hamall,spamerror,hamerror;
} m_Error_Unit;

typedef struct {
	int spamall,hamall,spameq,hameq;
	float MI;
} Weight_Unit;

class HASHBAGGING{
public:
	
	string StrCh;  //�ֱ���ʼ�����Ӣ���ַ���
	vector<string> vecWordsCh;


public:
	HASHBAGGING();//Bagging��ʼ��,nΪ������
	//HASHBAGGING(int num);//Bagging��ʼ��,nΪ������
	~HASHBAGGING(void);
	void Initial(int num);//Bagging��ʼ��,nΪ������
	void Release();//Bagging��ʼ��,nΪ������

public:	
	void LoadFea(void);
	void SaveFea(void);
	void StrToVecChineseWord(string str, string & StrEng,string & StrCh);
	long StrHash(char *str, long len);
	void WordParserMail(void);//��wordΪbasic unit���ʼ����н���	

	void WordTrain(string mail_mode);
	float WordClassify();

private:
	//added by xuxin 2010.3.26
	//���ڷָ�Ӣ�ĵ���
	static bool charactor_number(char c);
	static bool not_charactor_number(char c);
};