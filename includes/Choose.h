#ifndef CHOOSE
#define CHOOSE
#include "Common.h"
#include "PepoleandCouse.h"
#include "CList.h"
#include "SList.h"
#include"WrAddRe.h"

//��ʼ����ѡ��
void ChooseCo(struct CNode* Headr,struct SNode* headr);

//����ѧ������ѡ�γ̱�ʱ���ѡ��Ŀγ̵ı��һ��
int IfbeenChoose(struct CNode* Node1, struct SNode* Node2, int ChosenCo);


//��������е������Ƿ���α��е�������ͬ����ͬ��++,����ͬҪͳ�ƶ�Ӧ�Ŀγ�������++,���ҷ��ؿγ̵�����
int CoWStNumber(struct CNode* Headr1, struct SNode* Headr2);

void ChangeChooseCo(struct CNode* Headr, struct SNode* headr);

#endif // !CHOOSE
