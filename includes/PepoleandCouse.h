#ifndef PEPOLE
#define PEPOLE
struct Couse
{
	int CoNum;//课程编号
	char CoName[20];//课程名字
	int score;//课程学分
	int Co_slct_num;//课程已选人数
	int Co_Max;//课程最大人数	
};

struct Student
{
	int StNum;//学生编号
	char StName[20];//学生名字
	int St_co_slct_num[100];//学生已选课程编号
	int St_co_most_num;//学生已选课程数	
};

struct CNode
{
	struct Couse couse;
	struct CNode* Cnext;
	
};

struct SNode
{
	struct Student student;
	struct SNode* Snext;
};
#endif // !PEPOLE
