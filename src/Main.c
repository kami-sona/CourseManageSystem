#include "Common.h"
#include "Menu.h"
#include "CList.h"
#include "SList.h"
#include "PepoleandCouse.h"
#include "WrAddRe.h"


int main()
{
	struct CNode* Headr = Createlist();
	struct SNode* headr = CreateStlist();

	MainMenu(Headr,headr);



	FreeCoList(Headr);
	FreeStList(headr);
	system("pause");
	return 0;
}