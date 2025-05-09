#include"Heap.h"
void HeapInit(HP* php)
{
	assert(php);
	php->a = (HPDataType*)malloc(sizeof(HPDataType) * 4);
	if (php->a == NULL)
	{
		perror("malloc failed");
		return;
	}
	php->size = 0;
	php->capacity = 4;
}
void swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child>0)
	{
		if (a[child] > a[parent])
		{
			swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
void HeapPush(HP* php, HPDataType x)
{
	if (php->capacity == php->size)
	{
		HPDataType* tmp = (HPDataType*)realloc(php->a, sizeof(HPDataType) * (php->capacity + 4));
		if (tmp == NULL)
		{
			perror("realloc failed");
			return;
		}
		php->a = tmp;
		php->capacity += 4;
	}
	php->a[php->size++] = x;
	AdjustUp(php->a, php->size - 1);
}
void AdjustDown(HPDataType* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		//选出最大的一个孩子
		if (child + 1 < n && a[child] < a[child + 1])
		{
			child = child + 1;
		}
		if (a[parent] < a[child])
		{
			swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapPop(HP* php)
{
	assert(php);
	assert(!HeapEmpty(php));
	swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;	
	AdjustDown(php->a, php->size, 0);
}
HPDataType HeapTop(HP* php)
{
	assert(php);
	assert(!HeapEmpty(php));
	return php->a[0];
}
bool HeapEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}
int HeapSize1(HP* php)
{
	assert(php);
	return php->size;
}
void HeapDestroy1(HP* php)
{
	free(php->a);
	php->a = NULL;
	free(php);	
	php = NULL;
}