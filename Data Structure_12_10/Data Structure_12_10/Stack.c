#include"Stack.h"
// 初始化栈
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
// 入栈
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
// 出栈
void StackPop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	ps->top--;
}
// 获取栈顶元素
STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->a[ps->top-1];
}
// 获取栈中有效元素个数
int StackSize(Stack* ps)
{
	return ps->top;
}
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
bool StackEmpty(Stack* ps)
{
	return ps->top == 0;
}
// 销毁栈
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