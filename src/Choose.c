#include "Choose.h"

void ChooseCo(struct CNode* Headr,struct SNode*headr)
{
	struct CNode* pMpve = Headr->Cnext;
	struct CNode* Co = NULL;
	struct SNode* St = NULL;
	char Name[20];

	//�жϴ�ʱ�γ̱������޿γ�
	if (pMpve == NULL)
	{
		printf("��ʱ�γ̱����޿γ̣�����ϵ����Ա��ӿγ�\n");
	}
	else
	{
		PrintColist(Headr);
		printf("��������Ҫѡ��Ŀγ̵�����\n");
		scanf("%s", Name);

		Co = FindNamNode(Headr, Name);//�ж��Ƿ��иÿγ�

		if (Co != NULL)
		{

			if (Co->couse.Co_slct_num == Co->couse.Co_Max)//�жϸÿγ������Ƿ���Ա
			{
				printf("�ÿγ������Ѿ�����\n");
				
				return;
			}
			else
			{
				printf("�������������\n");//��Ҫ֪���ŵ���һ��ѧ������Ϣ�ϣ��������δ�и�ѧ����Ϣ������ʾ�Ǽ�
				scanf("%s",&Name);
				St = SFindNameNode(headr, Name);

				if (St != NULL)
				{
					//ѡ��֮ǰ��Ҫ�ж�һ�����ѧ���Ƿ��Ѿ�ѡ�������

					if (IfbeenChoose(Co, St, St->student.St_co_most_num) == 1)
					{
						printf("���Ѿ�ѡ���˸ÿγ������ظ�ѡ��\n");
						
						return;
					}
					else
					{
						printf("ѡ�γɹ�\n");
						Co->couse.Co_slct_num++;
						St->student.St_co_most_num++;

						St->student.St_co_slct_num[St->student.St_co_most_num] = Co->couse.CoNum;//���ÿγ̵ı�ŷ�������γ̱���

						SWtoFile(headr);//���´�����ѧ���������
						Wtofile(Headr);//���´����пγ̱������
						
						return;
					}
				}
				else
				{
					printf("����ܻ�δ������Ϣ���볢�Ե��������Ϣ\n");
				
					return;
				}
				
			}

		}
		else//δ�ҵ��γ�
		{
			printf("δ�鵽�ɴ˿γ�,����������\n");
			
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
	int number = 0;//ѧ������ѡ��ĸÿγ̵������ܺ�

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

	char CoName[20] = {0};//����֮ǰ������
	char CoAfterName[20] = {0};//���ĺ������

	int CoNum = 0;
	int CoAfterNum = 0;
	int S_CoNum = 0;

	printf("��������Ҫ�޸�ѧ��������\n");
	scanf("%s", Name);
	if (SpMove = SFindNameNode(headr, Name))
	{
		printf("��������Ҫ�޸Ŀγ̵�����\n");
		scanf("%s", &CoName);
		CpMove = FindNamNode(Headr, CoName);
		//���û�ҵ�������
		if (CpMove == NULL)
		{
			printf("�޸ÿγ��޷��޸�");
			return;
		}
		CoNum = CpMove->couse.CoNum;
		S_CoNum = SFindCo_NumNode(SpMove, CoNum, SpMove->student.St_co_most_num);

		if ( CpMove && S_CoNum)//Ҫѧ�����Ѿ��γ��д�����Ҫ�޸ĵĿγ̲����޸�
		{

			printf("��������Ҫ�޸ĳ����ſγ�\n");
			scanf("%s", CoAfterName);
			CpAfterpMove = FindNamNode(Headr, CoAfterName);
			CoAfterNum = CpAfterpMove->couse.CoNum;
			S_CoNum = SFindCo_NumNode(SpMove, CoAfterNum, SpMove->student.St_co_most_num);//�ж��Ƿ��Ѿ�ѡ�������޸ĵĿγ�

			if (CpAfterpMove && S_CoNum == 0)
			{
				//ֱ���޸Ĳ����ж�
				S_CoNum = SFindCo_NumNode(SpMove, CoNum, SpMove->student.St_co_most_num);//��ԭ���γ̵ı�Ÿ�ֵ
				SpMove->student.St_co_slct_num[S_CoNum] = CpAfterpMove->couse.CoNum;//ѧ��ѡ��Ŀγ̱�Ÿı�
				CpMove->couse.Co_slct_num--;//ѡ��֮ǰ�Ŀγ̼���
				CpAfterpMove->couse.Co_slct_num++;//ѡ��֮��Ŀγ�����

				Wtofile(Headr);
				SWtoFile(headr);

			}
			else
			{
				printf("���޸ĵĿγ̲�����,���Ѿ�ѡ��\n");
			}
		
		}
		else
		{
			printf("�޸ÿγ��޷��޸�\n");
		}
	}
	else
	{
		printf("�޸�ѧ�������޸�");
	}

}
