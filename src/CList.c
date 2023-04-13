#include "CList.h"

//链表头
struct CNode* Createlist()
{
	struct CNode* Headr = (struct CNode*)malloc(sizeof(struct CNode));
	Headr->Cnext = NULL;
	return Headr;
}
//创建节点
struct CNode* CreateCoNode(struct Couse* CouseData)
{
	struct CNode* Node = (struct CNode*)malloc(sizeof(struct CNode));
	Node->Cnext = NULL;//必须置空
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

//头插法插入课程
void InsertCoNode(struct CNode* Headr,struct Couse* CouseData)
{
	struct CNode* newNode = CreateCoNode(CouseData);
	newNode->Cnext = Headr->Cnext;
	Headr->Cnext = newNode;
}


//遍历插入的课程
void PrintColist(struct CNode* Headr)
{
	struct CNode* pMove = Headr->Cnext;
	printf("\t课程编号\t课程名\t\t课程学分\t课程已选人数\t课程最大人数\n");

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


//遍历课程的节点
void PrintNode(struct CNode* CoNode)
{
	printf("\t课程编号\t课程名\t\t课程学分\t课程已选人数\t课程最大人数\n");
	printf("\t%d", CoNode->couse.CoNum);
	printf("\t\t%s", CoNode->couse.CoName);
	printf("\t\t%d", CoNode->couse.score);
	printf("\t\t%d", CoNode->couse.Co_slct_num);
	printf("\t\t%d", CoNode->couse.Co_Max);
	printf("\n");

	system("pause");
}

//释放该链表
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

//删除一个节点
void DeleteCoNode(struct CNode* Headr,struct SNode*headr)
{
	struct CNode* pMove = Headr->Cnext;
	struct CNode* pFontMove = Headr;
	struct SNode* SpMove = headr->Snext;
	int Num;//课程编号
	int Co_;//课程的下标

	printf("请输入想要删除的课程的编号\n");
	scanf("%d", &Num);

	if (pMove == NULL)
	{
		printf("删除课程失败，可能无课程表，情添加一个\n");
		
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
				printf("无此课删除失败\n");
				
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
					SpMove->student.St_co_slct_num[i] = SpMove->student.St_co_slct_num[i+1];//后一位覆盖前一位
				}
			}

			SpMove->student.St_co_most_num--;//该学生节点已选择课程数减减
		}

		Wtofile(Headr);
		SWtoFile(headr);

		free(pMove);
	}

	printf("删除成功\n");
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

	printf("请输入想要查找的课程\n");
	scanf("%s", CoName);

	struct CNode* pMove = FindNamNode(Headr,CoName);
	struct SNode* SpMove = headr->Snext;

	if (pMove != NULL)
	{

		printf("请输入课程编号\n");
		scanf("%d", &CoNum);

		printf("请输入课程学分\n");
		scanf("%d", &score);
	
		do
		{
			printf("请输入课程最大人数，不能将其减小\n");
			scanf("%d", &Co_Max);

		} while (Co_Max < pMove->couse.Co_Max);

		//将之前的编号保存下来
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
		printf("修改成功\n");
	}
	else
	{
		printf("未查到有此课程\n");
	}
}
