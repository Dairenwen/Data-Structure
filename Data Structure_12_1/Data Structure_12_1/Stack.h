#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<windows.h>
#include<stdbool.h>
#include<assert.h>
#define start 3
#define inc 3
// ֧�ֶ�̬������ջ
typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top; // ջ��
	int capacity; // ����
}Stack;
// ��ʼ��ջ
void StackInit(Stack* ps);
// ��ջ
void StackPush(Stack* ps, STDataType data);
// ��ջ
void StackPop(Stack* ps);
// ��ȡջ��Ԫ��
STDataType StackTop(Stack* ps);
// ��ȡջ����ЧԪ�ظ���
int StackSize(Stack* ps);
// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
bool StackEmpty(Stack* ps);
// ����ջ
void StackDestroy(Stack* ps);

void print(Stack* ps);