#include <vector>
using namespace std;
typedef struct  
{
	string word;  //����
	double EDnor; //�ز�ֵ��ֵԽ��˵������Խ�ؼ�
	int frequency; //������ֵ�Ƶ��
	vector<int> t_loc; //�������ı��г���λ��
	vector<int> d_list; //�������ı��м��
}Node;  //

#pragma comment (lib,"Keyword_Extraction.lib")

//���� string text Ϊ����Ԥ�������ı�
extern Node* keyword_extra_entropy(string text);  //һ����
extern Node* keyword_extra_entropy_MAX(string text);  //�����