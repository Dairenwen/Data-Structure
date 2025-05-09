#pragma once
#include<stdio.h>
#include<stdbool.h>
#include<errno.h>
#include<stdlib.h>
#include<assert.h>
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;
bool HeapEmpty(HP* php);
void swap(HPDataType* p1, HPDataType* p2);
void HeapInit(HP* php);
void AdjustUp(HPDataType* a, int child);
void HeapPush(HP* php,HPDataType x);
void AdjustDown(HPDataType* a, int n, int parent);
void HeapPop(HP* php);
HPDataType HeapTop(HP* php);
int HeapSize1(HP* php);
void HeapDestroy1(HP* php);