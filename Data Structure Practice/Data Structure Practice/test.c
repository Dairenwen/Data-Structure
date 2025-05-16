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

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    
};
//合并两个有序链表
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    struct ListNode* cur1 = list1;
    struct ListNode* cur2 = list2;
    struct ListNode* newhead = NULL;
    struct ListNode* cur = NULL;
    if (list1 == NULL && list2 == NULL)
    {
        return newhead;
    }
    if (list1 == NULL)
    {
        return list2;
    }
    else if (list2 == NULL)
    {
        return list1;
    }
    else
    {
        if (cur1->val < cur2->val)
        {
            newhead = cur1;
            cur1 = cur1->next;
        }
        else
        {
            newhead = cur2;
            cur2 = cur2->next;
        }
        cur = newhead;
        while (cur1 && cur2)
        {
            if (cur1->val < cur2->val)
            {
                cur->next = cur1;
                cur = cur->next;
                cur1 = cur1->next;
            }
            else if (cur1->val > cur2->val)
            {
                cur->next = cur2;
                cur = cur->next;
                cur2 = cur2->next;
            }
            else
            {
                cur->next = cur2;
                cur = cur->next;
                cur2 = cur2->next;
                cur->next = cur1;
                cur = cur->next;
                cur1 = cur1->next;
            }
        }
        if (cur1 == NULL)
        {
            while (cur2)
            {
                cur->next = cur2;
                cur = cur->next;
                cur2 = cur2->next;
            }
        }
        else
        {
            while (cur1)
            {
                cur->next = cur1;
                cur = cur->next;
                cur1 = cur1->next;
            }
        }
        return newhead;
    }
}

//链表反转
struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode* newhead = NULL, * cur = head, * tmp = NULL, * tmp1 = NULL;
    int num = 0;
    if (head == NULL)
    {
        return NULL;
    }
    else
    {
        while (cur)
        {
            tmp = cur;
            newhead = tmp;
            cur = cur->next;
            num++;
            if (num == 1)
            {
                tmp->next = NULL;
                tmp1 = tmp;
            }
            else
            {
                tmp->next = tmp1;
                tmp1 = tmp;
            }
        }
        return newhead;
    }
}

//三个指针来反转链表
struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode* n1 = NULL, * n2 = NULL, * n3 = NULL;
    n1 = NULL;
    n2 = head;
    if (head == NULL)
    {
        return NULL;
    }
    n3 = n2->next;
    while (n2)
    {
        n2->next = n1;
        n1 = n2;
        n2 = n3;
        if (n3)
            n3 = n3->next;
    }
    return n1;
}

//用哨兵位点来对链表实现排序
struct ListNode* partition(struct ListNode* pHead, int x)
{
    struct ListNode* gguard, * gtail, * lguard, * ltail, * cur = pHead;
    gguard = (struct ListNode*)malloc(sizeof(struct ListNode));
    gtail = gguard;
    lguard = (struct ListNode*)malloc(sizeof(struct ListNode));
    ltail = lguard;
    gtail->next = NULL;
    ltail->next = NULL;
    while (cur)
    {
        if (cur->val < x)
        {
            gtail->next = cur;
            gtail = gtail->next;
        }
        else
        {
            ltail->next = cur;
            ltail = ltail->next;
        }
        cur = cur->next;
    }
    gtail->next = lguard->next;
    ltail->next = NULL;
    struct ListNode* head = gguard->next;
    free(gguard);
    free(lguard);
    return head;
}



//测试程序
struct ListNode
{
    int val;
    struct ListNode* next;
};
int main()
{
    struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = NULL;
    struct ListNode* partition(struct ListNode* pHead, int x);
    return 0;
}

#define offsetof(StructType, MemberName) (size_t)&((StructType*)0->MemberName)
#define  Swap(n) ((n&0x55555555)<<1|(n&0xaaaaaaaa)>>1)

//判断链表回文
struct ListNode* find(struct ListNode* phead)
{
    struct ListNode* p1 = phead;
    struct ListNode* p2 = phead;
    while (p2 && p2->next)
    {
        p2 = p2->next->next;
        p1 = p1->next;
    }
    return p1;
}
struct ListNode* reverse(struct ListNode* phead)
{
    struct ListNode* n1 = NULL;
    struct ListNode* n2 = phead;
    struct ListNode* n3 = n2->next;
    while (n2)
    {
        n2->next = n1;
        n1 = n2;
        n2 = n3;
        if (n3)
        {
            n3 = n3->next;
        }
    }
    return n1;
}
bool chkPalindrome(struct ListNode* phead)
{
    struct ListNode* head1 = find(phead);
    struct ListNode* head2 = reverse(head1);
    while (phead && head2)
    {
        if (phead->val != head2->val)
        {
            return false;
        }
        phead = phead->next;
        head2 = head2->next;
    }
    return true;
}

//判断链表的结点
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
    struct ListNode* tail1 = headA;
    int num1 = 0;
    int num2 = 0;
    int sub = 0;
    struct ListNode* tail2 = headB;
    while (tail1)
    {
        tail1 = tail1->next;
        num1++;
    }
    while (tail2)
    {
        tail2 = tail2->next;
        num2++;
    }
    if (num1 > num2)
    {
        sub = num1 - num2;
        while (sub)
        {
            headA = headA->next;
            sub--;
        }
    }
    else
    {
        sub = num2 - num1;
        while (sub)
        {
            headB = headB->next;
            sub--;
        }
    }
    while (headA && headB)
    {
        if (headA == headB)
        {
            return headA;
        }
        headA = headA->next;
        headB = headB->next;
    }
    return NULL;
}

//判断是否有环
bool hasCycle(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}

//环形链表返回环结点（重点！！！画图分析）
struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode* slow = head, * meet, * fast = head, * phead = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            meet = fast;
            while (meet != phead)
            {
                meet = meet->next;
                phead = phead->next;
            }
            return meet;
        }
    }
    return NULL;
}
//第二种思路：也可以把相遇点下一项断开，然后就是寻找两端链表的交点
//尝试实现：使用前面的函数，不然可能对空指针进行解引用，出错

//链表的深度拷贝
//1.拷贝节点链接在源节点的后面
//2.拷贝结点的random，源节点的random->next
//3.拷贝结点解下来，连接成一个新链表，原链表恢复

struct Node
{
    int val;
    struct Node* next;
    struct Node* random;
};

struct Node* copyRandomList(struct Node* head)
{
    struct Node* cur = head;
    while (cur)
    {
        struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
        copy->next = cur->next;
        cur->next = copy;
        copy->val = cur->val;
        cur = copy->next;
    }
    cur = head;
    while (cur)
    {
        struct Node* copy = cur->next;
        if (cur->random == NULL)
        {
            copy->random = NULL;
        }
        else
        {
            copy->random = cur->random->next;
        }
        cur = copy->next;
    }
    cur = head;
    struct Node* newhead = NULL;
    struct Node* tail = NULL;
    while (cur)
    {
        struct Node* copy = cur->next;
        struct Node* next = copy->next;
        if (newhead == NULL)
        {
            newhead = copy;
            tail = copy;
        }
        else
        {
            tail->next = copy;
            tail = copy;
        }
        cur->next = next;
        cur = next;
    }
    return newhead;
}

//栈的括号匹配判断
//这里的函数是Stack里面的，搭配看
bool isValid(char* s)
{
    Stack st;
    StackInit(&st);
    while (*s)
    {
        if (*s == '(' || *s == '[' || *s == '{')
        {
            StackPush(&st, *s);
        }
        else
        {
            if (StackEmpty(&st))//注意这里要用empty来判断，否则就越界访问了
                return false;
            char top = StackTop(&st);
            StackPop(&st);
            if ((*s == ')' && top != '(') ||
                (*s == ']' && top != '[') ||
                (*s == '}' && top != '{'))
            {
                return false;
            }
        }
        s++;
    }
    bool ret = StackEmpty(&st);//判断是否为空，而不是来看top的值，写了函数就要用上
    StackDestroy(&st);//这里注意要释放空间，但是内存泄漏是不报错的
    return ret;
}

//用两个队列来实现栈的功能以及用两个栈来实现队列的功能 记住参考栈与队列的实现，善于运用已有函数！

//循环队列：
//MyCircularQueue(k) : 构造器，设置队列长度为 k 。
//Front : 从队首获取元素。如果队列为空，返回 - 1 。
//Rear : 获取队尾元素。如果队列为空，返回 - 1 。
//enQueue(value) : 向循环队列插入一个元素。如果成功插入则返回真。
//deQueue() : 从循环队列中删除一个元素。如果成功删除则返回真。
//isEmpty() : 检查循环队列是否为空。
//isFull() : 检查循环队列是否已满。

typedef struct {
    int* data;
    int front;
    int rear;
    int k;
} MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* create = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    create->front = 0;
    create->rear = 0;
    create->k = k;
    create->data = (int*)malloc(sizeof(int) * (k + 1));
    return create;
}
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->front == obj->rear;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (obj->rear + 1) % (obj->k + 1) == obj->front;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj))
    {
        return false;
    }
    obj->data[obj->rear++] = value;
    obj->rear %= (obj->k + 1);
    return true;
}
int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
    {
        return -1;
    }
    return obj->data[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
    {
        return -1;
    }
    if (obj->rear != 0)
    {
        return obj->data[obj->rear - 1];
    }
    else
    {
        return obj->data[obj->k];
    }
}
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
    {
        return false;
    }
    obj->front++;
    obj->front %= (obj->k + 1);
    return true;
}


void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->data);
    obj->data = NULL;
    free(obj);
    obj = NULL;
}

//单值二叉树
bool isUnivalTree(struct TreeNode* root) {
    if (root == NULL)
    {
        return true;
    }
    if (root->left && root->val != root->left->val)
    {
        return false;
    }
    if (root->right && root->val != root->right->val)
    {
        return false;
    }
    return isUnivalTree(root->left) && isUnivalTree(root->right);
}

//相同的树
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL)
    {
        return true;
    }
    else if ((p == NULL && q != NULL) || (p != NULL && q == NULL))
    {
        return false;
    }
    else
    {
        if (p->val == q->val)
        {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
        else
        {
            return false;
        }
    }
}

//申请空间的前序遍历
int treesize(struct TreeNode* root)
{
    return root == NULL ? 0 : treesize(root->left) + treesize(root->right) + 1;
}
void xu(int* tmp, struct TreeNode* root, int* i)
{
    if (root == NULL)
    {
        return;
    }
    tmp[(*i)++] = root->val;
    xu(tmp, root->left, i);
    xu(tmp, root->right, i);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = treesize(root);
    int* tmp = (int*)malloc(sizeof(int) * (*returnSize));
    int i = 0;
    xu(tmp, root, &i);
    return tmp;
}

//寻找子树
bool issametree(struct TreeNode* r1, struct TreeNode* r2)
{
    if (r1 == NULL && r2 == NULL)
    {
        return true;
    }
    if (r1 != NULL && r2 == NULL)
    {
        return false;
    }
    if (r1 == NULL && r2 != NULL)
    {
        return false;
    }
    if (r1->val != r2->val)
    {
        return false;
    }
    return  issametree(r1->left, r2->left) && issametree(r1->right, r2->right);
}
bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    if (root == NULL)
    {
        return false;
    }
    if (issametree(root, subRoot))
    {
        return true;
    }
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

//二叉树根据结果建堆 中序遍历输出
typedef struct tree
{
    struct tree* right;
    struct tree* left;
    char data;
}tree;
tree* createtree(char* a, int* i)
{
    if (a[*i] == '\0')
    {
        return NULL;
    }
    if (a[*i] == '#')
    {
        (*i)++;
        return NULL;
    }
    tree* newnode = (tree*)malloc(sizeof(tree));
    newnode->data = a[(*i)++];
    newnode->left = createtree(a, i);
    newnode->right = createtree(a, i);
    return newnode;
}
void InOrder(tree* root)
{
    if (root == NULL)
    {
        return;
    }
    InOrder(root->left);
    printf("%c ", root->data);
    InOrder(root->right);
}
int main() {
    char arr[101] = { 0 };
    gets(arr);
    int i = 0;
    tree* ret = createtree(arr, &i);
    InOrder(ret);
    return 0;
}
