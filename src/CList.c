#include "CList.h"

//����ͷ
struct CNode* Createlist()
{
	struct CNode* Headr = (struct CNode*)malloc(sizeof(struct CNode));
	Headr->Cnext = NULL;
	return Headr;
}
//�����ڵ�
struct CNode* CreateCoNode(struct Couse* CouseData)
{
	struct CNode* Node = (struct CNode*)malloc(sizeof(struct CNode));
	Node->Cnext = NULL;//�����ÿ�
	Node->couse.CoNum = CouseData->CoNum;
	Node->couse.Co_Max = CouseData->Co_Max;
	Node->couse.score = CouseData->score;
	Node->couse.Co_slct_num = CouseData->Co_slct_num;

	for (int i = 0; i < 20; i++)
	{
		Node->couse.CoName[i] = CouseData->CoName[i];
	}

	return Node;
}

//ͷ�巨����γ�
void InsertCoNode(struct CNode* Headr,struct Couse* CouseData)
{
	struct CNode* newNode = CreateCoNode(CouseData);
	newNode->Cnext = Headr->Cnext;
	Headr->Cnext = newNode;
}


//��������Ŀγ�
void PrintColist(struct CNode* Headr)
{
	struct CNode* pMove = Headr->Cnext;
	printf("\t�γ̱��\t�γ���\t\t�γ�ѧ��\t�γ���ѡ����\t�γ��������\n");

	while (pMove != NULL)
	{
		printf("\t%d", pMove->couse.CoNum);
		printf("\t\t%s", pMove->couse.CoName);
		printf("\t\t%d", pMove->couse.score);
		printf("\t\t%d", pMove->couse.Co_slct_num);
		printf("\t\t%d", pMove->couse.Co_Max);
		printf("\n");
		pMove = pMove->Cnext;
	}

}


//�����γ̵Ľڵ�
void PrintNode(struct CNode* CoNode)
{
	printf("\t�γ̱��\t�γ���\t\t�γ�ѧ��\t�γ���ѡ����\t�γ��������\n");
	printf("\t%d", CoNode->couse.CoNum);
	printf("\t\t%s", CoNode->couse.CoName);
	printf("\t\t%d", CoNode->couse.score);
	printf("\t\t%d", CoNode->couse.Co_slct_num);
	printf("\t\t%d", CoNode->couse.Co_Max);
	printf("\n");

	system("pause");
}

//�ͷŸ�����
void FreeCoList(struct CNode* Headr)
{
	struct CNode* pMove = Headr->Cnext;
	struct CNode* pFontMove;

	while (pMove != NULL)
	{
		pFontMove = pMove;
		pMove = pMove->Cnext;
		free(pFontMove);
	}

	free(Headr);
}

//ɾ��һ���ڵ�
void DeleteCoNode(struct CNode* Headr,struct SNode*headr)
{
	struct CNode* pMove = Headr->Cnext;
	struct CNode* pFontMove = Headr;
	struct SNode* SpMove = headr->Snext;
	int Num;//�γ̱��
	int Co_;//�γ̵��±�

	printf("��������Ҫɾ���Ŀγ̵ı��\n");
	scanf("%d", &Num);

	if (pMove == NULL)
	{
		printf("ɾ���γ�ʧ�ܣ������޿γ̱������һ��\n");
		
		return;
	}
	else
	{
		while (pMove->couse.CoNum != Num)
		{
			pFontMove = pMove;
			pMove = pMove->Cnext;

			if (pMove == NULL)
			{
				printf("�޴˿�ɾ��ʧ��\n");
				
				return;
			}
		}
		pFontMove->Cnext = pMove->Cnext;


		for (; SpMove != NULL; SpMove = SpMove->Snext)
		{
			if (Co_ = SFindCo_NumNode(headr, pMove->couse.CoNum, SpMove->student.St_co_most_num))
			{
				for (int i = Co_ ; i <= SpMove->student.St_co_most_num; i++)
				{
					SpMove->student.St_co_slct_num[i] = SpMove->student.St_co_slct_num[i+1];//��һλ����ǰһλ
				}
			}

			SpMove->student.St_co_most_num--;//��ѧ���ڵ���ѡ��γ�������
		}

		Wtofile(Headr);
		SWtoFile(headr);

		free(pMove);
	}

	printf("ɾ���ɹ�\n");
}



int FindNumNode(struct CNode* Headr,int Num)
{
	struct CNode* pMove = Headr->Cnext;

	while (pMove)
	{
		if (pMove->couse.CoNum == Num)
		{
			return 1;
		}
		pMove = pMove->Cnext;
	}

	return 0;
}

struct CNode * FindNamNode(struct CNode* Headr,char Name[])
{
	struct CNode* pMove = Headr->Cnext;

	while (pMove)
	{
		if (strcmp(Name, pMove->couse.CoName) == 0)
		{
			return pMove;
		}
		pMove = pMove->Cnext;
	}

	return NULL;
}

void ChangeCo(struct CNode* Headr,struct SNode*headr)
{
	int TempNum;
	int CoNum;
	int score;
	char CoName[20] = { 0 };
	int Co_Max;
	int Co_ = 0;

	printf("��������Ҫ���ҵĿγ�\n");
	scanf("%s", CoName);

	struct CNode* pMove = FindNamNode(Headr,CoName);
	struct SNode* SpMove = headr->Snext;

	if (pMove != NULL)
	{

		printf("������γ̱��\n");
		scanf("%d", &CoNum);

		printf("������γ�ѧ��\n");
		scanf("%d", &score);
	
		do
		{
			printf("������γ�������������ܽ����С\n");
			scanf("%d", &Co_Max);

		} while (Co_Max < pMove->couse.Co_Max);

		//��֮ǰ�ı�ű�������
		TempNum = pMove->couse.CoNum;
		pMove->couse.CoNum = CoNum;
		pMove->couse.score = score;
		pMove->couse.Co_Max = Co_Max;

		for (; SpMove != NULL; SpMove = SpMove->Snext)
		{
			if (Co_ = SFindCo_NumNode(SpMove, TempNum, SpMove->student.St_co_most_num))
			{
				SpMove->student.St_co_slct_num[Co_] = CoNum;
			}
		}

		Wtofile(Headr);
		SWtoFile(headr);
		printf("�޸ĳɹ�\n");
	}
	else
	{
		printf("δ�鵽�д˿γ�\n");
	}
}
