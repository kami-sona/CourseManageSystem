#ifndef LIST
#define LIST

#include "PepoleandCouse.h"
#include "Common.h"
#include "SList.h"
#include "PutDataIn.h"
//����һ������
struct CNode* Createlist();

//����һ���γ̽ڵ�
struct CNode* CreateCoNode(struct Couse* CosueData);

//����һ���γ̽ڵ�
void InsertCoNode(struct CNode* Headr, struct Couse* CouseData);

//�����γ�����
void PrintColist(struct CNode* Headr);

//�������
void PrintNode(struct CNode* Node);

//�ͷ�����
void FreeCoList(struct CNode* Headr);

//ɾ��һ�����
void DeleteCoNode(struct CNode* Headr,struct SNode* headr);

//����һ�����ͨ����ţ����뺯���ķ�ʽ
int FindNumNode(struct CNode* Headr,int Num);

//����һ�����ͨ�������ַ���
struct CNode* FindNamNode(struct CNode* Headr,char Name[]);

//�޸�һ���γ�
void ChangeCo(struct CNode* Headr,struct SNode* headr);



#endif // !LIST
