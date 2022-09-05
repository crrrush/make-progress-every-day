#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

#include<stdlib.h>

#include<assert.h>

//int main()
//{
//    int N = 0;
//    int count = 0;
//    int n = 1;
//    scanf("%d", &N);
//    for (int i = 1; i <= N; i++)
//    {
//        n *= i;
//        count += n;
//    }
//    printf("%d\n", count);
//
//    return 0;
//}



//int main()
//{
//    int i = 0, j = 0;
//    int n = 0;
//    scanf("%d", &n);
//    for (i = 1; i <= n; ++i)
//    {
//        for (j = 1; j <= i; ++j)
//        {
//            printf("%d*%d=%-2d   ", j, i, i * j);
//        }
//        printf("\n");
//    }
//    return 0;
//}


//typedef struct Stu
//{
//    char num[6];
//    char name[11];
//    int n1;
//    int n2;
//    int n3;
//    int sum;
//}Stu;
//
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    Stu* s = (Stu*)malloc(sizeof(Stu) * n);
//    assert(s);
//    int maxi = 0;
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%s %s %d %d %d", s[i].num, s[i].name, &(s[i].n1), &(s[i].n2), &(s[i].n3));
//        s[i].sum = s[i].n1 + s[i].n2 + s[i].n3;
//        if (s[maxi].sum <= s[i].sum)
//            maxi = i;
//    }
//
//    printf("%s %s %d", s[maxi].name, s[maxi].num, s[maxi].sum);
//
//    free(s);
//    return 0;
//}


#include<string.h>

//int main()
//{
//    char moves[12] = "0";
//    int k = 0;
//    scanf("%d", &k);
//    int i = k;
//    getchar();
//    while (gets(moves))
//    {
//        if (!strcmp(moves, "End"))
//            break;
//        if (k)
//        {
//            if (!strcmp(moves, "JianDao"))
//                printf("ChuiZi\n");
//            else if (!strcmp(moves, "ChuiZi"))
//                printf("Bu\n");
//            else
//                printf("JianDao\n");
//        }
//        else
//        {
//            if (!strcmp(moves, "JianDao"))
//                printf("JianDao\n");
//            else if (!strcmp(moves, "ChuiZi"))
//                printf("ChuiZi\n");
//            else
//                printf("Bu\n");
//        }
//        if (k == 0)
//            k = i;
//        k--;
//    }
//    return 0;
//}

//int main()
//{
//    int a[11][11] = { 0 };
//    int i = 0, j = 0;
//    int N = 0;
//    scanf("%d", &N);
//    a[0][1] = 1;
//    for (i = 1; i <= N; i++)
//    {
//        for (int k = 0; k < 3 + N - i; k++)
//            printf(" ");
//
//        for (j = 1; j <= i; j++)
//        {
//            a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
//            printf("%4d", a[i][j]);
//        }
//        printf("\n");
//    }
//
//
//    return 0;
//}


//int main()
//{
//    int N = 0;
//    scanf("%d", &N);
//    int* a = (int*)malloc(sizeof(int) * (N + 1));
//    //初始化数组
//    int i = 0;
//    for (i = 0; i <= N; i++)
//    {
//        a[i] = i;
//    }
//    //除去猴子
//    while (N != 3)
//    {
//        int j = 1;
//        for (i = 1; i <= N; i++)
//        {
//            if (i % 3)
//            {
//                a[j] = a[i];
//                j++;
//            }
//        }
//        N = j - 1;
//    }
//    printf("%d\n", a[3]);
//
//
//    free(a);
//    a = NULL;
//    return 0;
//}


// 带头+双向+循环链表增删查改实现

typedef int LTDataType;

typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;



// 创建返回链表的头结点.
ListNode* ListCreate();

// 双向链表销毁
void ListDestory(ListNode* pHead);

// 双向链表打印
void ListPrint(const ListNode* pHead);

// 双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x);

// 双向链表尾删
void ListPopBack(ListNode* pHead);

// 双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x);

// 双向链表头删
void ListPopFront(ListNode* pHead);

// 双向链表查找
ListNode* ListFind(ListNode* pHead, LTDataType x);

// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x);

// 双向链表删除pos位置的节点
void ListErase(ListNode* pos);



// 创建返回链表的头结点.
ListNode* ListCreate()
{
	ListNode* Head = (ListNode*)malloc(sizeof(ListNode));
	if (Head == NULL)
	{
		perror("Failed to apply for head node space");
		exit(-1);
	}
	Head->_next = Head;
	Head->_prev = Head;

	return Head;
}

// 双向链表销毁
void ListDestory(ListNode* pHead)//外部使用时自行置空
{
	assert(pHead);

	ListNode* cur = pHead->_next;
	while (cur != pHead)
	{
		ListNode* tmp = cur->_next;
		free(cur);
		cur = tmp;
	}
	free(pHead);
}

// 双向链表打印
void ListPrint(const ListNode* pHead)
{
	assert(pHead);
	ListNode* cur = pHead->_next;
	while (cur != pHead)
	{
		printf("%d<=>", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}

ListNode* CreateListNode(LTDataType x)
{
	ListNode* NewNode = (ListNode*)malloc(sizeof(ListNode));
	if (NewNode == NULL)
	{
		perror("malloc newnode failed");
		exit(-1);
	}
	NewNode->_prev = NULL;
	NewNode->_next = NULL;
	NewNode->_data = x;
	return NewNode;
}

// 双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);

	//ListNode* newnode = CreateListNode(x);
	//ListNode* Prev = pHead->_prev;

	//Prev->_next = newnode;
	//newnode->_prev = Prev;
	//newnode->_next = pHead;
	//pHead->_prev = newnode;
	ListInsert(pHead, x);
}


// 双向链表尾删
void ListPopBack(ListNode* pHead)
{
	//assert(pHead);
	//assert(pHead->_prev != pHead);
	//ListNode* Tail = pHead->_prev;
	//ListNode* Prev = Tail->_prev;
	//Prev->_next = pHead;
	//pHead->_prev = Prev;
	//free(Tail);
	ListErase(pHead->_prev);
}


// 双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x)
{
	//assert(pHead);
	//ListNode* newnode = CreateListNode(x);
	//ListNode* Next = pHead->_next;
	//pHead->_next = newnode;
	//newnode->_prev = pHead;
	//newnode->_next = Next;
	//Next->_prev = newnode;
	ListInsert(pHead->_next, x);
}


// 双向链表头删
void ListPopFront(ListNode* pHead)
{
	//assert(pHead);
	//assert(pHead->_next != pHead);
	//ListNode* head = pHead->_next;
	//ListNode* Next = head->_next;
	//pHead->_next = Next;
	//Next->_prev = pHead;
	//free(head);
	ListErase(pHead->_next);
}

// 双向链表查找
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* curHead = pHead->_next;
	ListNode* curTail = pHead->_prev;
	while (curHead != curTail)
	{
		if (curHead->_data == x)
		{
			return curHead;
		}
		else if (curTail->_data == x)
		{
			return curTail;
		}
		curHead = curHead->_next;
		curTail = curTail->_prev;
	}
	if (curHead->_data == x)
		return curHead;
	else
		return NULL;
}


// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* newnode = CreateListNode(x);
	ListNode* Prev = pos->_prev;

	Prev->_next = newnode;
	newnode->_prev = Prev;
	newnode->_next = pos;
	pos->_prev = newnode;
}


// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
	assert(pos);
	assert(pos->_next != pos);
	ListNode* Prev = pos->_prev;
	ListNode* Next = pos->_next;
	Prev->_next = Next;
	Next->_prev = Prev;
	free(pos);
}

int main()
{
	ListNode* head = ListCreate();
	int N = 0;
	scanf("%d", &N);

	int i = 0;
	for (i = 1; i <= N; i++)
	{
		ListPushBack(head, i);
	}
	i = 2;
	ListNode* p = head->_next;
	while (head->_next != head->_prev)
	{
		if (p == head)
			p = p->_next;
		if (i == 0)
		{
			ListNode* tmp = p;
			p = p->_next;
			ListErase(tmp);
			i = 2;
		}
		else
		{
			p = p->_next;
			i--;
		}
	}
	printf("%d\n", head->_next->_data);

	ListDestory(head);
	head = NULL;
	return 0;
}


