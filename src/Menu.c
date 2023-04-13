#include "Menu.h"
#include "PutDataIn.h"

void MainMenu(struct CNode* Headr,struct SNode*headr)
{
	int Choice;

	StoList(headr);

	while (1)
	{
		printf("\n\n");
		printf("\t\t      欢迎使用学生选课系统\n");
		printf("\t-----------------------------------------------\n");
		printf("\t***********************************************\n");
		printf("\t**********0.退出系统                     ******\n");
		printf("\t**********1.我是学生                     ******\n");
		printf("\t**********2.我是管理员                   ******\n");
		printf("\t***********************************************\n");
		printf("\t-----------------------------------------------\n");

		scanf("%d", &Choice);
		switch (Choice)
		{
		case 1:
			system("cls");
			StMenu(Headr,headr);
			break;
		case 2:
			system("cls");
			CouseMenu(Headr,headr);
			break;
		case 0:
			return;
		default:
			printf("输入错误\n");
			system("pause");
			system("cls");
			break;
		}
	}

}

void CouseMenu(struct CNode* Headr,struct SNode*headr)
{
	int Choice;
	while (1)
	{
		printf("\n\n");
		printf("\t-----------------------------------------------\n");
		printf("\t***********************************************\n");
		printf("\t*********1.录入课程信息                 *******\n");
		printf("\t*********2.管理课程信息                 *******\n");
		printf("\t*********3.返回上一级                   *******\n");	
		printf("\t***********************************************\n");
		printf("\t-----------------------------------------------\n");

		scanf("%d", &Choice);
		switch (Choice)
		{
		case 1:
			system("cls");
			DataMenu(Headr,headr);
			break;
		case 2:
			system("cls");
			ManageMenu(Headr,headr);
			return;
		case 3:
			system("cls");
			return;
		default:
			printf("输入错误\n");
			system("pause");
			break;
		}
		system("cls");
	}
}

void DataMenu(struct CNode* Headr,struct SNode*headr)
{
	int Choice;
	
	while (1)
	{
		printf("\n\n");
		printf("\t-----------------------------------------------\n");
		printf("\t***********************************************\n");
		printf("\t******1.通过键盘输入                     ******\n");
		printf("\t******2.通过文件输入                     ******\n");
		printf("\t******3.返回上一级                       ******\n");
		printf("\t***********************************************\n");
		printf("\t-----------------------------------------------\n");
		scanf("%d", &Choice);
		switch (Choice)
		{
		case 1:
			Data_Key(Headr);
			break;
		case 2:
			Data_File(Headr,headr);
			break;
		case 3:
			return;
			break;
		default:
			printf("输入错误\n");
			system("pause");
			break;
		}
		system("cls");
	}

}

void ManageMenu(struct CNode* Headr,struct SNode*headr)
{
	int Choice;
	char CoName[20] = { 0 };
	struct CNode* node = NULL;


	while (1)
	{
		printf("\n\n");
		printf("\t-----------------------------------------------\n");
		printf("\t***********************************************\n");
		printf("\t******1.查看课程表                       ******\n");
		printf("\t******2.删除课程信息                     ******\n");
		printf("\t******3.查找课程信息                     ******\n");
		printf("\t******4.修改课程信息                     ******\n");
		printf("\t******5.返回上一级                       ******\n");
		printf("\t***********************************************\n");
		printf("\t-----------------------------------------------\n");
		scanf("%d", &Choice);
		switch (Choice)
		{
		case 1:
			PrintColist(Headr);
			system("pause");
			break;
		case 2:
			DeleteCoNode(Headr,headr);
			system("pause");
			break;
		case 3:
			system("cls");
			printf("请输入想要查找的课程\n");
			scanf("%s", CoName);
			if (node = FindNamNode(Headr, CoName))
			{
				printf("查到此课程如下表\n");
				PrintNode(node);
			}
			else
			{
				printf("未查到该课程\n");
				system("pause");
			}
			break;

		case 4:
			ChangeCo(Headr, headr);
			system("pause");
			break;
		case 5:
			system("cls");
			CouseMenu(Headr,headr);
			return;
		default:
			printf("输入错误\n");
			system("pause");
			break;
		}
		system("cls");
	}
}

void StMenu(struct CNode* Headr,struct SNode* headr)
{
	int Choice;

	while (1)
	{
		printf("\n\n");
		printf("\t-----------------------------------------------\n");
		printf("\t***********************************************\n");
		printf("\t******1.开始选课                         ******\n");
		printf("\t******2.查看课程表                       ******\n");
		printf("\t******3.搜索学生                         ******\n");
		printf("\t******4.录入个人信息                     ******\n");
		printf("\t******5.修改选课                         ******\n");
		printf("\t******6.返回上一级                       ******\n");
		printf("\t***********************************************\n");
		printf("\t-----------------------------------------------\n");
		

		scanf("%d", &Choice);
		switch (Choice)
		{
		case 1:
			ChooseCo(Headr, headr);
			system("pause");
			break;
		case 2:
			PrintColist(Headr);
			system("pause");
			break;
		case 3:
			PrintStNode(headr);
			system("pause");
			break;
		case 4:
			Data_Key_St(headr);
			system("pause");
			break;
		case 5:
			ChangeChooseCo(Headr, headr);
			system("pause");
			break;
		case 6:
			system("cls");
			return;
			break;
		default:
			printf("输入错误");
			system("pause");
			break;
		}
		system("cls");
	}
}



