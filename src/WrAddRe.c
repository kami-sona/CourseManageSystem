#include "WrAddRe.h"

void Wtofile(struct CNode* Headr)//接着写
{
	FILE* Filestream = fopen(COUSE, "w");
	struct CNode* pMove = Headr->Cnext;
	char H = '\n';
	for (; pMove != NULL; pMove = pMove->Cnext)
	{
		fprintf(Filestream, "%d  %s  %d  %d  %d", pMove->couse.CoNum, pMove->couse.CoName, pMove->couse.score, pMove->couse.Co_slct_num, pMove->couse.Co_Max);
		fprintf(Filestream, "%c", H);
	}
	fclose(Filestream);
}

void WtofileA(struct CNode* Headr)
{
	FILE* Filestream = fopen(COUSE, "a");
	struct CNode* pMove = Headr->Cnext;
	char H = '\n';

	for (; pMove != NULL; pMove = pMove->Cnext)
	{
		fprintf(Filestream, "%d  %s  %d  %d  %d", pMove->couse.CoNum, pMove->couse.CoName, pMove->couse.score, pMove->couse.Co_slct_num, pMove->couse.Co_Max);
		fprintf(Filestream, "%c", H);
	}
	fclose(Filestream);
}



void Rtolist(struct CNode* Headr)//读入链表中
{
	FILE* Filestream = fopen(COUSE, "r");
	struct Couse couse = { 0 };
	int re;

	while (re = fscanf(Filestream, "%d  %s  %d  %d  %d\n", &couse.CoNum, &couse.CoName, &couse.score, &couse.Co_slct_num, &couse.Co_Max) > 0)
	{
		if (FindNumNode(Headr, couse.CoNum) == 0 && FindNamNode(Headr,couse.CoName) == NULL)
		{
			InsertCoNode(Headr, &couse);
		}
	}
	fclose(Filestream);
}


void SWtoFile(struct SNode* Headr)//写到文件中
{
	FILE* FileStream = fopen(STUDENT, "w");
	struct SNode* SpMpve = Headr->Snext;
	char H = '\n';
	int C = 0;


	for (; SpMpve != NULL; SpMpve = SpMpve->Snext)
	{
		fprintf(FileStream, "%d  %s  %d  ", SpMpve->student.StNum, SpMpve->student.StName, SpMpve->student.St_co_most_num);

		for (int i = 1; i <= SpMpve->student.St_co_most_num; i++)//从1号元素开始的原因是因为写入文件时，它的已选课数已经加了1
		{
			C = SpMpve->student.St_co_slct_num[i];
			fprintf(FileStream, "%d,", C);
		}
		fprintf(FileStream, "%c", H);
	}

	fclose(FileStream);
}

void StoList(struct SNode* Headr)//读到学生的链表中
{
	FILE* FileStream = fopen(STUDENT, "r");

	if (FileStream == NULL)
		FileStream = fopen(STUDENT, "w");
	struct Student student = { 0 };

	int re, ee;
	char H = '\n';

	while (re = fscanf(FileStream, "%d  %s  %d  ", &student.StNum, &student.StName, &student.St_co_most_num) > 0)
	{
		for (int i = 1; i <= student.St_co_most_num; i++)
		{
			ee = fscanf(FileStream, "%d,", &student.St_co_slct_num[i]);
		}

		ee = fscanf(FileStream, "%c", &H);
		InsertStNode(Headr, &student);
	}
}
