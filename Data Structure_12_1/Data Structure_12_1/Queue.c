#include"Queue.h"
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
	pq->size = 0;
}

void QueueDestroy(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	QNode* prev = NULL;
	while (cur)
	{
		prev = cur;
		cur = cur->next;
		free(prev);
	}
	pq->head = NULL;
	pq->tail = NULL;
	pq->size = 0;
}

void QueuePush(Queue* pq, QDatatype x)
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc failed");
		return;
	}
	newnode->next = NULL;
	newnode->data = x;
	if (pq->tail == NULL)
	{
		pq->head = newnode;
		pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
	pq->size++;
}

void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	QNode* del = pq->head;
	pq->head = pq->head->next;
	free(del);
	del = NULL;
	if (pq->head == NULL)
	{
		pq->tail = NULL;
	}
	pq->size--;
}

int QueueSize(Queue* pq)
{
	assert(pq);
	return pq->size;
}

bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->size == 0;
}

QDatatype QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->head->data;
}

QDatatype QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->tail->data;
}