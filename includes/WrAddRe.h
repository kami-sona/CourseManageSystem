#ifndef WriteToFile
#define WriteToFile
#include "Common.h"
#include "CList.h"
#include "SList.h"
#include "PepoleandCouse.h"

//课程表的写入文件
void Wtofile(struct CNode* Headr);

void WtofileA(struct CNode* Headr);

//课程表读入链表
void Rtolist(struct CNode* Headr);

//学生信息的写入
void SWtoFile(struct SNode* Headr);

//学生信息的读取
void StoList(struct SNode* Headr);



#endif // !WriteToFile
