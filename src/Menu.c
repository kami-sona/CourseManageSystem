#include "Menu.h"
#include "PutDataIn.h"

void MainMenu(struct CNode* Headr,struct SNode*headr)
{
	int Choice;

	StoList(headr);

	while (1)
	{
		printf("\n\n");
		printf("\t\t      ��ӭʹ��ѧ��ѡ��ϵͳ\n");
		printf("\t-----------------------------------------------\n");
		printf("\t***********************************************\n");
		printf("\t**********0.�˳�ϵͳ                     ******\n");
		printf("\t**********1.����ѧ��                     ******\n");
		printf("\t**********2.���ǹ���Ա                   ******\n");
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
			printf("�������\n");
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
		printf("\t*********1.¼��γ���Ϣ                 *******\n");
		printf("\t*********2.����γ���Ϣ                 *******\n");
		printf("\t*********3.������һ��                   *******\n");	
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
			printf("�������\n");
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
		printf("\t******1.ͨ����������                     ******\n");
		printf("\t******2.ͨ���ļ�����                     ******\n");
		printf("\t******3.������һ��                       ******\n");
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
			printf("�������\n");
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
		printf("\t******1.�鿴�γ̱�                       ******\n");
		printf("\t******2.ɾ���γ���Ϣ                     ******\n");
		printf("\t******3.���ҿγ���Ϣ                     ******\n");
		printf("\t******4.�޸Ŀγ���Ϣ                     ******\n");
		printf("\t******5.������һ��                       ******\n");
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
			printf("��������Ҫ���ҵĿγ�\n");
			scanf("%s", CoName);
			if (node = FindNamNode(Headr, CoName))
			{
				printf("�鵽�˿γ����±�\n");
				PrintNode(node);
			}
			else
			{
				printf("δ�鵽�ÿγ�\n");
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
			printf("�������\n");
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
		printf("\t******1.��ʼѡ��                         ******\n");
		printf("\t******2.�鿴�γ̱�                       ******\n");
		printf("\t******3.����ѧ��                         ******\n");
		printf("\t******4.¼�������Ϣ                     ******\n");
		printf("\t******5.�޸�ѡ��                         ******\n");
		printf("\t******6.������һ��                       ******\n");
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
			printf("�������");
			system("pause");
			break;
		}
		system("cls");
	}
}



