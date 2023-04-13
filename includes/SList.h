#ifndef SList
#define SList
#include "Common.h"
#include "PepoleandCouse.h"

//����һ��ѧ������
struct SNode* CreateStlist();

//����һ��ѧ���ڵ�
struct SNode* CreatStNode(struct Student* StData);

//����һ��ѧ���ڵ�
void InsertStNode(struct SNode* Headr, struct Student* StudentData);

//����ѧ������
void PrintStList(struct SNode* Headr);

void PrintStNode(struct SNode* Headr);

//ɾ��һ��ѧ���ڵ�
void DeleteStNode(struct SNode* Headr);

//����һ���ڵ�ͨ����ţ����뺯���ķ�ʽ
int SFindNumNode(struct SNode* Headr, int Num);

//����һ��ѧ��������
struct SNode* SFindNameNode(struct SNode* Headr, char Name[]);

//ͨ��һ��ѧ���ڵ�������������ѡ��γ̱��е��и��γ��Ƿ���ڣ������򷵻�1
int SFindCoNumNode(struct SNode* Node, int num,int loop);

//������ѡ��γ̱�������е��±��1��ʼ
int SFindCo_NumNode(struct SNode* Headr, int num,int loop);

//�ͷŸ�����
void FreeStList(struct SNode* Headr);

#endif // !SList
