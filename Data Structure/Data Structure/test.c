#define _CRT_SECURE_NO_WARNINGS 1
#include"structure.h"

//������˳���ļ�ʵ��
//��ʵ����һ��ؤ��ͨѶ¼
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
//��������˳���

//������
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
//���������Ͽ�����




