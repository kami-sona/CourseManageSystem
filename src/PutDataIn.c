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
	printf("��������Ҫ��ӿγ̵�����:\n");
	scanf("%d", &loop);
	system("cls");

	for (int i = 0; i < loop; i++)
	{
		printf("������ÿγ̵�����\n");
		scanf("%s", CoName);

		printf("������γ̱��\n");
		scanf("%d", &CoNum);

		printf("������γ�ѧ��\n");
		scanf("%d", &score);

		printf("������γ��������\n");
		scanf("%d", &Co_Max);

		couse.CoNum = CoNum;
		couse.score = score;
		couse.Co_Max = Co_Max;
		couse.Co_slct_num = 0;

		for (int i = 0; i < 20; i++)
		{
			couse.CoName[i] = CoName[i];
		}

		//д������ǰ��������д��һ����ʱ����鿴����������Ƿ����Լ���ǰд�����ݳ�ͻ�������ͻ����ʾ�޷�д�룬�뽫�ÿγ̴��ļ���¼��

		if (FindNumNode(Headr, couse.CoNum) == 0 &&  FindNamNode(Headr,couse.CoName) == NULL)
		{
			if (FindNumNode(TempList, couse.CoNum) == 0 && FindNamNode(TempList, couse.CoName) == NULL)
			{
				InsertCoNode(Headr, &couse);//ѭ������ڵ�
				WtofileA(Headr);
			}
			else
			{
				printf("�γ��Ѿ����ļ��д���,���ȴ��ļ�¼��ÿγ�\n");
				system("pause");
			}
			
		}
		else
		{
			printf("�ÿγ��Ѿ������������\n");
			system("pause");
		}
	}


	
	FreeCoList(TempList);
	system("cls");
	
}

void Data_File(struct CNode* Headr,struct SNode*headr)
{
	struct CNode* CpMove = Headr->Cnext;

	//1.�ļ�������
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
		printf("�ļ�������,�Ƿ�Ҫ����һ���ļ�<y/n>\n");
		Choice = getchar();//��ȡ��һ��scanf�Ļس���
		Choice = getchar();

		if (Choice == 'y' || Choice == 'Y')
		{
			fstream = fopen(COUSE, "w");
			fclose(fstream);
			printf("�ļ������ɹ�\n");
		}
		else if (Choice == 'n' || Choice == 'N')
		{
			printf("����\n");
		}
		else
		{
			printf("�������\n");
		}

		system("pause");
		return;
	}
	else
	{
		//2.�ļ����ڵ���Ϊ��,��Ҫ�Ѹ����ݶ���������
		//3.�ļ����ڵ�Ϊ��
		if (fgetc(fstream) == EOF)
		{
			printf("\t\t�ļ�Ϊ��,�볢�����뽫���������ı��У����߰������¸�ʽ�༭\n");
			printf("\t\t----------------------------------------------------------------------------\n");
			printf("\t\t�γ̱��  �γ�����  �γ̷���  �γ���ѡ����  �γ�������������ĸ�ʽ\n");
		}
		else
		{
	
				printf("�ļ��Ѿ�����ϵͳ������\n");
				Rtolist(Headr);

				CpMove = Headr->Cnext;
				//�γ̱����Ϣ��ѧ�������Ϣ����ͳһ
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

	printf("�������������\n");
	scanf("%s", StName);

	printf("��������ı��\n");
	scanf("%d", &StNum);


	if (SFindNumNode(Headr,StNum) == 0)
	{
		St.St_co_most_num = 0;//������ѡ�γ���Ϊ�±����η���������
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
		printf("���Ѿ�ע�����Ϣ��,�����ظ�ע��\n");

		return;
	}
}
