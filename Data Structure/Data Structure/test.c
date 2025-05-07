#define _CRT_SECURE_NO_WARNINGS 1
#include"structure.h"

//这里是顺序表的简单实现
//其实就是一个丐版通讯录
//int main()
//{
//	SL s;
//	SLInit(&s);
//	SLPushBack(&s, 1);
//	SLPushBack(&s, 2);
//	SLPushBack(&s, 3);
//	SLPushBack(&s, 4);
//	SLPushBack(&s, 5);
//	SLPushBack(&s, 6);
//	print(&s);
//	return 0;
//}
//————顺序表

//单链表
int main()
{
	SLTNode* plist = NULL;
	SLTPushFrout(&plist, 1);
	SLTPushFrout(&plist, 2);
	SLTPushFrout(&plist, 3);
	SLTPushFrout(&plist, 4);
	SLTPushFrout(&plist, 5);
	SLTPrint(plist);
	return 0;
}
//————上课链表




