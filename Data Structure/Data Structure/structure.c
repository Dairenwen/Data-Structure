#define _CRT_SECURE_NO_WARNINGS 1
#include"structure.h"

//————顺序表
void SLInit(SL* s)
{
	s->a = (SLDataType*)calloc(INIT_CAPACITY, sizeof(SLDataType));
	if (s->a == NULL)
	{
		perror("calloc");
		return;
	}
	s->capacity = INIT_CAPACITY;
	s->size= 0;
}

void SLdestroy(SL* s)
{
	free(s->a);
	s->a = NULL;
	s->capacity = 0;
	s->size = 0;
}

void SLPushBack(SL* s, SLDataType x)
{
	if (s->size == s->capacity)
	{
		SLDataType* tmp = realloc(s->a, sizeof(SLDataType) * (s->capacity + INC_CAPACITY));
		if (tmp == NULL)
		{
			perror("realloc");
			return;
		}
		s->a = tmp;
		s->capacity += INC_CAPACITY;
	}
	s->a[s->size] = x;
	s->size++;
}

void print(SL* s)
{
	int i = 0;
	for (i = 0; i < s->size; i++)
	{
		printf("%d ", s->a[i]);
	}
}

void SLPopBack(SL* s)
{
	if(s->size!=0)
	s->size--;
}

void SLPushFrout(SL* s, SLDataType x)
{

}
//————顺序表

//单链表
void SLTPrint(SLTNode* phead)
{
	//这里不需要断言，如果phead为NULL的话，就不能打印出数据了
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL");
}

SLTNode* BuySLTNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("malloc failed");
		return;
	}
	else
	{
		newnode->data = x;
		newnode->next = NULL;
		return newnode;
	}
}

void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* newnode = BuySLTNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//找尾
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
	//错误写法：
	/*while (tail != NULL)
	{
		tail = tail->next;
	}
	tail = newnode;*///注意这样是在用局部变量给局部变量赋值,函数结束时会销毁,正确的做法是给结构体中的next赋值newnode的地址
}

void SLTPushFrout(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* newnode = BuySLTNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

void SLTPopBack(SLTNode** pphead)
{
	assert(pphead);
	assert(*pphead);
	if ((*pphead)->next = NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		//找尾
	    //第一种写法：
		SLTNode* prev = NULL;
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		prev->next = NULL;
	}
	//第二种写法：
	/*SLTNode* tail = *pphead;
	while (tail->next->next != NULL)//如果tail为空呢？如果tail->next为空呢？
	{
		tail = tail->next;
	}
	free(tail);
	tail = NULL;
	tail->next = NULL;*/
	
}

void SLTPopFrout(SLTNode** pphead)
{
	assert(pphead);
	assert(*pphead);
	SLTNode* frist = *pphead;
	*pphead = frist->next;
	free(frist);
	frist = NULL;
	
}

//单链表查找
SLTNode* SListFind(SLTNode* phead, SLTDataType x)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
//pos之前插入
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pos && pphead);
	SLTNode* node = *pphead;
	if (pos==*pphead)
	{
		SLTPushFrout(pphead, x);
	}
	else
	{
		while (node->next != pos)
		{
			node = node->next;
		}
		SLTNode* newnode = BuySLTNode(x);
		newnode->next = pos;
		node->next = newnode;
	}
}
//pos位置删除
void SListErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead&&pos); 
	assert(*pphead);
	SLTNode* node = *pphead;
	if (*pphead == pos)
	{
		SLTPopFrout(pphead);
	}
	else
	{
		while (node->next != pos)
		{
			node = node->next;
		}
		node->next = pos->next;
		free(pos);
		pos = NULL;
	}
}
//pos后面插入
void SListInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);
	SLTNode* newnode = BuySLTNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}
//pos位置后面删除
void SListEraseAfter(SLTNode* pos)
{
	assert(pos);
	assert(pos->next);
	SLTNode* del = pos->next;
	pos->next = pos->next->next;
	free(del);
	del = NULL;
}

void SLTDestroy(SLTNode* phead)
{
	SLTNode* cur = phead;
	SLTNode* prev = NULL;
	while (cur)
	{
		prev = cur->next;
		free(cur);
		cur = prev;
	}
}

//————双向链表
LTNode* LTInit()
{
	LTNode* phead = BuyListNode(-1);
	phead->next = phead;
	phead->prev = phead;
	return phead; 
}
void LTPrint(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d<=>", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void LTDestroy(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	LTNode* prev = NULL;
	while (cur != phead)
	{
		prev = cur;
		cur = cur->next;
		free(prev);
		//prev = NULL;
	}
	free(phead);
	//phead = NULL;
}

LTNode* BuyListNode(LTDataType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL)
	{
		perror("malloc failed");
		return;
	}
	newnode->next = NULL;
	newnode->prev = NULL;
	newnode->data = x;
	return newnode;
}

bool LTEmpty(LTNode* phead)
{
	assert(phead);
	/*if (phead->next == phead)
	{
		return true;
	}
	else
	{
		return false;
	}*/
	return phead->next == phead;
}

void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);
	/*LTNode* newnode = BuyListNode(x);
	LTNode* tail = phead->prev;
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;*/
	LTInsert(phead, x);
}

void LTPopBack(LTNode* phead)
{
	assert(phead);
	assert(!LTEmpty(phead));
	/*LTNode* tail = phead->prev;
	LTNode* tailPrev = tail->prev;
	tailPrev->next = phead;
	phead->prev = tailPrev;
	free(tail);
	tail = NULL;*/
	LTErase(phead->prev);
}

void LTPushFrout(LTNode* phead, LTDataType x)
{
	assert(phead);
	/*LTNode* newnode = BuyListNode(x);
	newnode->next = phead->next;
	phead->next->prev = newnode;
	phead->next = newnode;
	newnode->prev = phead;*/
	LTInsert(phead->next, x);
}

void LTPopFrout(LTNode* phead)
{
	assert(phead);
	assert(!LTEmpty(phead));
	LTErase(phead->next);
}

void LTInsert(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* newnode = BuyListNode(x);
	LTNode* prev = pos->prev;
	newnode->next = pos;
	pos->prev = newnode;
	prev->next = newnode;
	newnode->prev = prev;
}

void LTErase(LTNode* pos)
{
	assert(pos);
    LTNode* prev = pos->prev;
	prev->next = pos->next;
	pos->next->prev = prev;
	free(pos);
	pos = NULL;
}

LTNode* LTFind(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}