#include"Binary.h"
#include"Queue.h"
#include"Sort.h"
#include"Stack.h"
int main()
{
	BTNode* n1 = BuyBTNode(1);
	BTNode* n2 = BuyBTNode(2);
	BTNode* n3 = BuyBTNode(3);
	BTNode* n4 = BuyBTNode(4);
	BTNode* n5 = BuyBTNode(5);
	BTNode* n6 = BuyBTNode(6);
	n1->left = n2;
	n2->left = n3;
	n1->right = n4;
	n4->left = n5;
	n4->right = n6;
	LevelOrder(n1);
	return 0;
}

//int main()
//{
//    //RadixSort(arr, 13);
//	int arr[10] = { 6,1,6,7,6,6,4,5,6,8 };
//	QuickSort5(arr, 0, 9);
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	
//	return 0;
//}

