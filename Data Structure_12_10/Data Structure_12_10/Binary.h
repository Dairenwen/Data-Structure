#include<stdio.h>
#include<errno.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
typedef int BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

BTNode* BuyBTNode(BTDataType x);
void PreOrder(BTNode* root);
void PostOrder(BTNode* root);
void InOrder(BTNode* root);
void LevelOrder(BTNode* root);
int TreeSize(BTNode* root);
int TreeHeight(BTNode* root);
int TreekNode(BTNode* root, int k);
int TreeLeafNum(BTNode* root);
BTNode* TreeFind(BTNode* root, int x);
void TreeDestroy(BTNode* root);
bool judgetree(BTNode* root);
