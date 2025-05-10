#include<stdio.h>
#include<errno.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

typedef struct BinaryTreeNode* QueueDataType;

typedef struct QNode
{
	QueueDataType data;
	struct QNode* next;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
	int size;
}Queue;

void QueueInit(Queue* q);
void QueueDestroy(Queue* q);
void QueuePush(Queue* q, QueueDataType x);
void QueuePop(Queue* q);
int QueueSize(Queue* q);
bool QueueEmpty(Queue* q);
QueueDataType QueueFront(Queue* q);
QueueDataType QueueBack(Queue* q);
