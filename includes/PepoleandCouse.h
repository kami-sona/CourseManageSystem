#ifndef PEPOLE
#define PEPOLE
struct Couse
{
	int CoNum;//�γ̱��
	char CoName[20];//�γ�����
	int score;//�γ�ѧ��
	int Co_slct_num;//�γ���ѡ����
	int Co_Max;//�γ��������	
};

struct Student
{
	int StNum;//ѧ�����
	char StName[20];//ѧ������
	int St_co_slct_num[100];//ѧ����ѡ�γ̱��
	int St_co_most_num;//ѧ����ѡ�γ���	
};

struct CNode
{
	struct Couse couse;
	struct CNode* Cnext;
	
};

struct SNode
{
	struct Student student;
	struct SNode* Snext;
};
#endif // !PEPOLE
