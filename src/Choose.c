#include "Choose.h"

void ChooseCo(struct CNode* Headr,struct SNode*headr)
{
	struct CNode* pMpve = Headr->Cnext;
	struct CNode* Co = NULL;
	struct SNode* St = NULL;
	char Name[20];

	//判断此时课程表中有无课程
	if (pMpve == NULL)
	{
		printf("此时课程表中无课程，请联系管理员添加课程\n");
	}
	else
	{
		PrintColist(Headr);
		printf("请输入你要选择的课程的名字\n");
		scanf("%s", Name);

		Co = FindNamNode(Headr, Name);//判断是否有该课程

		if (Co != NULL)
		{

			if (Co->couse.Co_slct_num == Co->couse.Co_Max)//判断该课程人数是否满员
			{
				printf("该课程人数已经满了\n");
				
				return;
			}
			else
			{
				printf("请输入你的姓名\n");//需要知道放到哪一个学生的信息上，如果，还未有该学生信息，则提示登记
				scanf("%s",&Name);
				St = SFindNameNode(headr, Name);

				if (St != NULL)
				{
					//选课之前需要判断一下这个学生是否已经选了这个课

					if (IfbeenChoose(Co, St, St->student.St_co_most_num) == 1)
					{
						printf("你已经选择了该课程无需重复选择\n");
						
						return;
					}
					else
					{
						printf("选课成功\n");
						Co->couse.Co_slct_num++;
						St->student.St_co_most_num++;

						St->student.St_co_slct_num[St->student.St_co_most_num] = Co->couse.CoNum;//将该课程的编号放入这个课程表中

						SWtoFile(headr);//更新磁盘中学生表的数据
						Wtofile(Headr);//更新磁盘中课程表的数据
						
						return;
					}
				}
				else
				{
					printf("你可能还未登入信息，请尝试登入个人信息\n");
				
					return;
				}
				
			}

		}
		else//未找到课程
		{
			printf("未查到由此课程,请重新输入\n");
			
			return;
		}

	}
}

int IfbeenChoose(struct CNode* Node1, struct SNode* Node2, int ChosenCo)
{
	if (Node1->couse.CoNum == Node2->student.St_co_slct_num[ChosenCo])
	{
		return 1;
	}

	return 0;
}


int CoWStNumber(struct CNode* Node, struct SNode* Headr)
{
	struct SNode* SpMove = Headr->Snext;
	int number = 0;//学生表中选择的该课程的人数总和

	for (; SpMove != NULL; SpMove = SpMove->Snext)
	{
		if (SFindCoNumNode(SpMove, Node->couse.CoNum, SpMove->student.St_co_most_num)==1 )
		{
			number++;
		}
	}

	return number;
}

void ChangeChooseCo(struct CNode* Headr, struct SNode* headr)
{
	char Name[20] = { 0 };
	struct SNode* SpMove = NULL;
	struct CNode* CpMove = NULL;
	struct CNode* CpAfterpMove = NULL;

	char CoName[20] = {0};//更改之前的姓名
	char CoAfterName[20] = {0};//更改后的姓名

	int CoNum = 0;
	int CoAfterNum = 0;
	int S_CoNum = 0;

	printf("请输入想要修改学生的姓名\n");
	scanf("%s", Name);
	if (SpMove = SFindNameNode(headr, Name))
	{
		printf("请输入想要修改课程的姓名\n");
		scanf("%s", &CoName);
		CpMove = FindNamNode(Headr, CoName);
		//如果没找到则跳过
		if (CpMove == NULL)
		{
			printf("无该课程无法修改");
			return;
		}
		CoNum = CpMove->couse.CoNum;
		S_CoNum = SFindCo_NumNode(SpMove, CoNum, SpMove->student.St_co_most_num);

		if ( CpMove && S_CoNum)//要学生中已经课程中存在想要修改的课程才能修改
		{

			printf("请输入想要修改成哪门课程\n");
			scanf("%s", CoAfterName);
			CpAfterpMove = FindNamNode(Headr, CoAfterName);
			CoAfterNum = CpAfterpMove->couse.CoNum;
			S_CoNum = SFindCo_NumNode(SpMove, CoAfterNum, SpMove->student.St_co_most_num);//判断是否已经选择了想修改的课程

			if (CpAfterpMove && S_CoNum == 0)
			{
				//直接修改不用判断
				S_CoNum = SFindCo_NumNode(SpMove, CoNum, SpMove->student.St_co_most_num);//把原来课程的编号赋值
				SpMove->student.St_co_slct_num[S_CoNum] = CpAfterpMove->couse.CoNum;//学生选择的课程编号改变
				CpMove->couse.Co_slct_num--;//选择之前的课程减少
				CpAfterpMove->couse.Co_slct_num++;//选择之后的课程增加

				Wtofile(Headr);
				SWtoFile(headr);

			}
			else
			{
				printf("所修改的课程不存在,或已经选择\n");
			}
		
		}
		else
		{
			printf("无该课程无法修改\n");
		}
	}
	else
	{
		printf("无该学生不能修改");
	}

}
