#ifndef LIST
#define LIST

#include "PepoleandCouse.h"
#include "Common.h"
#include "SList.h"
#include "PutDataIn.h"
//创建一个链表
struct CNode* Createlist();

//创建一个课程节点
struct CNode* CreateCoNode(struct Couse* CosueData);

//插入一个课程节点
void InsertCoNode(struct CNode* Headr, struct Couse* CouseData);

//遍历课程链表
void PrintColist(struct CNode* Headr);

//遍历结点
void PrintNode(struct CNode* Node);

//释放链表
void FreeCoList(struct CNode* Headr);

//删除一个结点
void DeleteCoNode(struct CNode* Headr,struct SNode* headr);

//查找一个结点通过编号，传入函数的方式
int FindNumNode(struct CNode* Headr,int Num);

//查找一个结点通过输入字符串
struct CNode* FindNamNode(struct CNode* Headr,char Name[]);

//修改一个课程
void ChangeCo(struct CNode* Headr,struct SNode* headr);



#endif // !LIST
