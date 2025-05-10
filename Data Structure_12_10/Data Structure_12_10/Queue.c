#include"Queue.h"
void QueueInit(Queue* q)
{
	assert(q);
	q->size = 0;
	q->head = NULL;
	q->tail = NULL;
}
void QueueDestroy(Queue* q)
{
	assert(q);
	q->size = 0;
	QNode* prev = NULL;
	QNode* cur = q->head;
	while (cur)
	{
		prev = cur;
		cur = cur->next;
		free(prev);
	}
	q->head = NULL;
	q->tail = NULL;
}
void QueuePush(Queue* q, QueueDataType x)
{
	assert(q);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc failed");
		return;
	}
	newnode->next = NULL;
	newnode->data = x;
	if (q->head == NULL)
	{
		q->head = newnode;
		q->tail = newnode;
	}
	else
	{
		q->tail->next = newnode;
		q->tail = newnode;
	}
	q->size++;
}
void QueuePop(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	QNode* del = q->head;
	q->head = q->head->next;
	free(del);
	del = NULL;
	if (q->head == NULL)
	{
		q->tail = NULL;
	}
	q->size--;
}
int QueueSize(Queue* q)
{
	assert(q);
	return q->size == 0;
}
bool QueueEmpty(Queue* q)
{
	assert(q);
	return q->size == 0;
}
QueueDataType QueueFront(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->head->data;
}
QueueDataType QueueBack(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->tail->data;
}