#ifndef PUTDATAIN
#define PUTDATAIN
#include "Common.h"
#include "PepoleandCouse.h"
#include "CList.h"
#include "SList.h"
#include "WrAddRe.h"
#include "Choose.h"

//通过键盘输入数据
void Data_Key(struct CNode* Headr);
//通过文件读入数据
void Data_File(struct CNode*Headr, struct SNode* headr);
//通过键盘输入学生信息
void Data_Key_St(struct SNode* Headr);



#endif // !PUTDATAIN
