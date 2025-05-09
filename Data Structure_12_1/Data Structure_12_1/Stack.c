#include"Stack.h"
// ��ʼ��ջ
void StackInit(Stack* ps)
{
	assert(ps);
	STDataType* tmp = (STDataType*)malloc(sizeof(STDataType) * start);
	if (tmp == NULL)
	{
		perror("malloc failed");
		return;
	}
	ps->a = tmp;
	ps->capacity = start;
	ps->top = 0;
}
// ��ջ
void StackPush(Stack* ps, STDataType data)
{
	if (ps->capacity == ps->top )
	{
		STDataType* tmp = (STDataType*)realloc(ps->a,sizeof(STDataType) * (ps->capacity + inc));
		if (tmp == NULL)
		{
			perror("realloc failed");
			return;
		}
		printf("expand successfully\n");
		ps->a = tmp;
		ps->capacity += inc;
	}
	ps->a[ps->top] = data;
	ps->top++;
}
// ��ջ
void StackPop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	ps->top--;
}
// ��ȡջ��Ԫ��
STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->a[ps->top-1];
}
// ��ȡջ����ЧԪ�ظ���
int StackSize(Stack* ps)
{
	return ps->top;
}
// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
bool StackEmpty(Stack* ps)
{
	return ps->top == 0;
}
// ����ջ
void StackDestroy(Stack* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
}

void print(Stack* ps)
{
	int i = 0;
	for (i = 0; i <= ps->top; i++)
	{
		printf("%d ", ps->a[i]);
	}
}