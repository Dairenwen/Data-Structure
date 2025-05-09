#pragma once
#include<stdio.h>
#include<stdbool.h>
#include<errno.h>
#include<stdlib.h>
#include<assert.h>

typedef int QDatatype;

typedef struct  QueueNode
{
	struct QueueNode* next;
	QDatatype data;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
	int size;
}Queue;

void QueueInit(Queue* pq);

void QueueDestroy(Queue* pq);

void QueuePush(Queue* pq, QDatatype x);

void QueuePop(Queue* pq);

int QueueSize(Queue* pq);

bool QueueEmpty(Queue* pq);

QDatatype QueueFront(Queue* pq);

QDatatype QueueBack(Queue* pq);



