#ifndef SList
#define SList
#include "Common.h"
#include "PepoleandCouse.h"

//创建一个学生链表
struct SNode* CreateStlist();

//创建一个学生节点
struct SNode* CreatStNode(struct Student* StData);

//插入一个学生节点
void InsertStNode(struct SNode* Headr, struct Student* StudentData);

//遍历学生链表
void PrintStList(struct SNode* Headr);

void PrintStNode(struct SNode* Headr);

//删除一个学生节点
void DeleteStNode(struct SNode* Headr);

//查找一个节点通过编号，传入函数的方式
int SFindNumNode(struct SNode* Headr, int Num);

//查找一个学生的名字
struct SNode* SFindNameNode(struct SNode* Headr, char Name[]);

//通过一个学生节点来查找它的已选择课程表中的有个课程是否存在，存在则返回1
int SFindCoNumNode(struct SNode* Node, int num,int loop);

//返回已选择课程编号数组中的下标从1开始
int SFindCo_NumNode(struct SNode* Headr, int num,int loop);

//释放该链表
void FreeStList(struct SNode* Headr);

#endif // !SList
