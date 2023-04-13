#include "PutDataIn.h"


void Data_Key(struct CNode* Headr)
{
	struct Couse couse = {0};
	struct CNode* TempList = Createlist();

	Rtolist(TempList);
	
	int CoNum;
	char CoName[20] = { 0 };
	int score;
	int Co_Max;
	int loop;
	printf("请输入想要添加课程的门数:\n");
	scanf("%d", &loop);
	system("cls");

	for (int i = 0; i < loop; i++)
	{
		printf("请输入该课程的名字\n");
		scanf("%s", CoName);

		printf("请输入课程编号\n");
		scanf("%d", &CoNum);

		printf("请输入课程学分\n");
		scanf("%d", &score);

		printf("请输入课程最大人数\n");
		scanf("%d", &Co_Max);

		couse.CoNum = CoNum;
		couse.score = score;
		couse.Co_Max = Co_Max;
		couse.Co_slct_num = 0;

		for (int i = 0; i < 20; i++)
		{
			couse.CoName[i] = CoName[i];
		}

		//写入链表前，必须先写到一个临时链表查看里面的数据是否与自己当前写的数据冲突，如果冲突则提示无法写入，请将该课程从文件中录入

		if (FindNumNode(Headr, couse.CoNum) == 0 &&  FindNamNode(Headr,couse.CoName) == NULL)
		{
			if (FindNumNode(TempList, couse.CoNum) == 0 && FindNamNode(TempList, couse.CoName) == NULL)
			{
				InsertCoNode(Headr, &couse);//循环插入节点
				WtofileA(Headr);
			}
			else
			{
				printf("课程已经在文件中存在,请先从文件录入该课程\n");
				system("pause");
			}
			
		}
		else
		{
			printf("该课程已经存在无需添加\n");
			system("pause");
		}
	}


	
	FreeCoList(TempList);
	system("cls");
	
}

void Data_File(struct CNode* Headr,struct SNode*headr)
{
	struct CNode* CpMove = Headr->Cnext;

	//1.文件不存在
	FILE* fstream = fopen(COUSE, "r");
	char Choice = 0;
	int CoNum = 0;
	char CoName[20] = { 0 };
	int score = 0;
	int Co_Max = 0;
	int number = 0;

	static int Chooseloop = 0;

	if (fstream == NULL)
	{
		printf("文件不存在,是否要创建一个文件<y/n>\n");
		Choice = getchar();//读取上一个scanf的回车符
		Choice = getchar();

		if (Choice == 'y' || Choice == 'Y')
		{
			fstream = fopen(COUSE, "w");
			fclose(fstream);
			printf("文件创建成功\n");
		}
		else if (Choice == 'n' || Choice == 'N')
		{
			printf("返回\n");
		}
		else
		{
			printf("输入错误\n");
		}

		system("pause");
		return;
	}
	else
	{
		//2.文件存在但不为空,需要把该数据读到链表中
		//3.文件存在但为空
		if (fgetc(fstream) == EOF)
		{
			printf("\t\t文件为空,请尝试输入将数据输入文本中，或者按照以下格式编辑\n");
			printf("\t\t----------------------------------------------------------------------------\n");
			printf("\t\t课程编号  课程名字  课程分数  课程已选人数  课程最大人数这样的格式\n");
		}
		else
		{
	
				printf("文件已经读入系统当中啦\n");
				Rtolist(Headr);

				CpMove = Headr->Cnext;
				//课程表的信息与学生表的信息必须统一
				for (; CpMove != NULL; CpMove = CpMove->Cnext)
				{
					number = CoWStNumber(CpMove, headr);
					if (number != CpMove->couse.Co_slct_num)
					{
						CpMove->couse.Co_slct_num = number;
					}
					
				}			
				Wtofile(Headr);

		}
	}

	fclose(fstream);

	system("pause");

}

void Data_Key_St(struct SNode* Headr)
{
	struct Student St = { 0 };
	int StNum = 0;
	char StName[20] = { 0 };

	printf("请输入你的名字\n");
	scanf("%s", StName);

	printf("请输入你的编号\n");
	scanf("%d", &StNum);


	if (SFindNumNode(Headr,StNum) == 0)
	{
		St.St_co_most_num = 0;//根据已选课程数为下标依次放入数组中
		St.StNum = StNum;
		for (int i = 0; i < 20; i++)
		{
			St.StName[i] = StName[i];

		}

		InsertStNode(Headr, &St);
		SWtoFile(Headr);
	}
	else
	{
		printf("你已经注册好信息了,不用重复注册\n");

		return;
	}
}
