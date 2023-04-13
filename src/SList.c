#include "SList.h"

struct SNode* CreateStlist()
{
	struct SNode* Headr = (struct SNode*)malloc(sizeof(struct SNode));
	Headr->Snext = NULL;
	return Headr;
}

//����һ��ѧ���ڵ�
struct SNode* CreatStNode(struct Student* StData)
{
	struct SNode* Node = (struct SNode*)malloc(sizeof(struct SNode));
	Node->Snext = NULL;
	Node->student.StNum = StData->StNum;
	Node->student.St_co_most_num = StData->St_co_most_num;

	for (int i = 0; i < 20; i++)
	{
		Node->student.StName[i] = StData->StName[i];
	}

	for (int i = 1; i <= StData->St_co_most_num; i++)
	{
		Node->student.St_co_slct_num[i] = StData->St_co_slct_num[i];
	}

	return Node;
}


//ͷ�巨����ѧ��
void InsertStNode(struct SNode * Headr ,struct Student* StudentData)
{
	struct SNode* newNode = CreatStNode(StudentData);
	newNode->Snext = Headr->Snext;
	Headr->Snext = newNode;
}


void PrintStList(struct SNode* Headr)
{
	struct SNode* pMove = Headr->Snext;
	char c = 0;
	printf("\tѧ�����\tѧ����\t�γ�ѧ��\tѧ����ѡ�γ���\tѧ���γ���ѡ���\n");

	while (pMove != NULL)
	{
		printf("\t%d", pMove->student.StNum);
		printf("\t\t%s", pMove->student.StName);
		printf("\t\t%d", pMove->student.St_co_most_num);

		for (int i = 0; c != '\0'; i++)
		{
			printf("%c,", pMove->student.St_co_slct_num[i]);
			c = pMove->student.St_co_slct_num[i];
		}
		printf("\n");
		pMove = pMove->Snext;
	}

}

void PrintStNode(struct SNode* Headr)
{
	char Name[20] = { 0 };
	struct SNode* SpMove = NULL;
	printf("��������Ҫ����ѧ��������\n");
	scanf("%s", Name);

	if (SpMove = SFindNameNode(Headr, Name))
	{
		printf("\t���\t����\t��ѡ�γ���\t��ѡ�γ̱��\n");
		printf("\t%d", SpMove->student.StNum);
		printf("\t%s", SpMove->student.StName);
		printf("\t%d", SpMove->student.St_co_most_num);
		printf("\t\t");
		for (int i = 1; i <= SpMove->student.St_co_most_num; i++)
		{
			printf("%d,", SpMove->student.St_co_slct_num[i]);
		}
		printf("\n");
		
	}
	else
	{
		printf("δ���ҵ���ѧ��\n");
	}
	
}


void DeleteStNode(struct SNode* Headr)
{
	struct SNode* pMove = Headr->Snext;
	struct SNode* pFontMove = Headr;

	int Num;
	printf("��������Ҫɾ����ѧ���ı��\n");
	scanf("%d", &Num);

	if (pMove == NULL)
	{
		printf("�����޸�ѧ����ɾ��ʧ��\n");
		system("pause");
		return;
	}
	else
	{
		while (pMove->student.StNum != Num)
		{
			pFontMove = pMove;
			pMove = pMove->Snext;
			if (pMove == NULL)
			{
				printf("�޴���ɾ��ʧ��\n");
				system("pause");
				return;
			}

		}
		pFontMove->Snext = pMove->Snext;
		free(pMove);
	}

}

int SFindNumNode(struct SNode* Headr, int Num)
{
	struct SNode* pMove = Headr->Snext;

	while (pMove)
	{
		if (pMove->student.StNum == Num)
		{
			return 1;
		}
		pMove = pMove->Snext;
	}

	return 0;
}

struct SNode* SFindNameNode(struct SNode* Headr, char Name[])
{
	struct SNode* pMove = Headr->Snext;

	while (pMove)
	{
		if (strcmp(Name, pMove->student.StName) == 0)
		{
			return pMove;
		}
		pMove = pMove->Snext;
	}

	return NULL;
}

int SFindCoNumNode(struct SNode* Node, int num,int loop)
{
	struct SNode* SpMove = Node;

	for (int i = 1; i <= loop; i++)
	{
		if (SpMove->student.St_co_slct_num[i] == num)
		{
			return 1;
		}
	}
	return 0;
}

int SFindCo_NumNode(struct SNode* Node, int num , int loop)
{
	struct SNode* SpMove = Node;

	for (int i = 1; i <= loop; i++)
	{
		if (SpMove->student.St_co_slct_num[i] == num)
		{
			return i;
		}
	}
	
	return 0;
}

//�ͷŸ�����
void FreeStList(struct SNode* Headr)
{
	struct SNode* pMove = Headr->Snext;
	struct SNode* pFontMove;

	while (pMove != NULL)
	{
		pFontMove = pMove;
		pMove = pMove->Snext;
		free(pFontMove);
	}

	free(Headr);
}
