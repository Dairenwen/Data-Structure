#include"Stack.h"
#include"Queue.h"
#include"Heap.h"
//int main()
//{
//	Queue q;
//	QueueInit(&q);
//	QueuePush(&q, 1);
//	QueuePush(&q, 2);
//	QueuePush(&q, 3);
//	QueuePush(&q, 4);
//	QueuePush(&q, 5);
//	while (!QueueEmpty(&q))
//	{
//		printf("%d ",QueueFront(&q));
//		QueuePop(&q);
//	}
//	QueueDestroy(&q);
//	HP con;
//	HeapInit(&con);
//	HeapPush(&con,1);
//	HeapPush(&con, 2);
//	HeapPush(&con, 6);
//	HeapPush(&con, 9);
//	HeapPush(&con, 345);
//	HeapPush(&con, 456);
//	HeapPush(&con, 765);
//	return 0;
//}

void heapsort(int* arr, int sz)
{
	int i = 0;
	//向上建堆(O(NlogN))
	for (i = 1; i < sz; i++)
	{
		AdjustUp(arr, i);
	}
	//or向下建堆(O(N))
	for (i = (sz - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(arr, sz, 0);
	}
	int end = sz - 1;
	while (end > 0)//时间复杂度(NlogN)
	{
		swap(&arr[0], &arr[end]);
		AdjustDown(arr, end, 0);
		end--;
	}
}
int main()
{
	int arr[10] = {10,9,8,7,6,5,4,3,2,1};
	int sz = sizeof(arr) / sizeof(arr[0]);
	heapsort(arr, sz);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}

