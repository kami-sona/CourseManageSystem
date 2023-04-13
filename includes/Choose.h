#ifndef CHOOSE
#define CHOOSE
#include "Common.h"
#include "PepoleandCouse.h"
#include "CList.h"
#include "SList.h"
#include"WrAddRe.h"

//开始进行选课
void ChooseCo(struct CNode* Headr,struct SNode* headr);

//遍历学生的已选课程表看时候和选择的课程的编号一致
int IfbeenChoose(struct CNode* Node1, struct SNode* Node2, int ChosenCo);


//检查链表中的数据是否与课表中的数据相同，相同则不++,不相同要统计对应的课程数并且++,并且返回课程的数量
int CoWStNumber(struct CNode* Headr1, struct SNode* Headr2);

void ChangeChooseCo(struct CNode* Headr, struct SNode* headr);

#endif // !CHOOSE
