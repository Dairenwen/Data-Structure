#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<assert.h>
#include<ctype.h>
#include<errno.h>
#include<stdbool.h>
#define INIT_CAPACITY 4
#define INC_CAPACITY 3
#pragma once

//��������˳���
typedef int SLDataType;
//
////��̬�ڴ��
typedef struct SeqList
{
	SLDataType* a;
	int size;
	int capacity;
}SL;
//
void SLInit(SL* s);
void SLDestory(SL* s);
void SLPushBack(SL* s, SLDataType x);//β��
void SLPopBack(SL* s, SLDataType x);//βɾ
void SLPushFront(SL* s);
void SLPopFront(SL* s, SLDataType x);
//��������˳���

//������
typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

void SLTPrint(SLTNode* phead);

void SLTPushBack(SLTNode** pphead, SLTDataType x);

SLTNode* BuySLTNode(SLTDataType x);

void SLTPushFrout(SLTNode** pphead, SLTDataType x);

void SLTPopBack(SLTNode** pphead);

void SLTPopFrout(SLTNode** pphead);
//���������
SLTNode* SListFind(SLTNode* phead, SLTDataType x);
//pos֮ǰ����
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);
//posλ��ɾ��
void SListErase(SLTNode** pphead, SLTNode* pos);
//pos�������
void SListInsertAfter(SLTNode* pos, SLTDataType x);
//posλ�ú���ɾ��
void SListEraseAfter(SLTNode* pos);

void SLTDestroy(SLTNode* phead);

//��������˫������
typedef int LTDataType;

typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType data;
}LTNode;

LTNode* LTInit();

void LTPrint(LTNode* phead);

void LTDestroy();

void LTPushBack(LTNode* phead, LTDataType x);

void LTPopBack(LTNode* phead);

bool LTEmpty(LTNode* phead);

void LTPushFrout(LTNode* phead,LTDataType x);

void LTPopFrout(LTNode* phead);
//��posλ�ò���һ��ֵ
void LTInsert(LTNode* pos, LTDataType x);

void LTErase(LTNode* pos);

LTNode* BuyListNode(LTDataType x);

