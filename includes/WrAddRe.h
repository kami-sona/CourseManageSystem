#ifndef WriteToFile
#define WriteToFile
#include "Common.h"
#include "CList.h"
#include "SList.h"
#include "PepoleandCouse.h"

//�γ̱��д���ļ�
void Wtofile(struct CNode* Headr);

void WtofileA(struct CNode* Headr);

//�γ̱��������
void Rtolist(struct CNode* Headr);

//ѧ����Ϣ��д��
void SWtoFile(struct SNode* Headr);

//ѧ����Ϣ�Ķ�ȡ
void StoList(struct SNode* Headr);



#endif // !WriteToFile
