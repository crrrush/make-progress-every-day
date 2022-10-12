#define _CRT_SECURE_NO_WARNINGS

//
//20. ��Ч������
//
//����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ��� s ���ж��ַ����Ƿ���Ч��
//
//��Ч�ַ��������㣺
//
//�����ű�������ͬ���͵������űպϡ�
//�����ű�������ȷ��˳��պϡ�
//ÿ�������Ŷ���һ����Ӧ����ͬ���͵������š�
//
//
//
//ʾ�� 1��
//
//���룺s = "()"
//�����true
//
//ʾ�� 2��
//
//���룺s = "()[]{}"
//�����true
//
//ʾ�� 3��
//
//���룺s = "(]"
//�����false
//
//
//
//��ʾ��
//
//1 <= s.length <= 104
//s �������� '()[]{}' ���
//
//ͨ������1, 272, 632
//�ύ����2, 857, 969
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode.cn/problems/valid-parentheses
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
// 
//
//

typedef char STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;		// ջ��
	int _capacity;  // ���� 
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
int StackEmpty(Stack* ps);

// ����ջ 
void StackDestroy(Stack* ps);


// ��ʼ��ջ 
void StackInit(Stack* ps)
{
	assert(ps);
	ps->_a = NULL;
	ps->_capacity = ps->_top = 0;
}

// ��ջ 
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		int newcapacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
		STDataType* tmp = (STDataType*)realloc(ps->_a, newcapacity * sizeof(STDataType));
		if (tmp == NULL)
		{
			perror("realloc failed");
			exit(-1);
		}
		ps->_a = tmp;
		ps->_capacity = newcapacity;
	}
	ps->_a[ps->_top] = data;
	ps->_top++;
}

// ��ջ 
void StackPop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	ps->_top--;
}

// ��ȡջ��Ԫ�� 
STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->_a[ps->_top - 1];
}

// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}

// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(Stack* ps)
{
	assert(ps);

	return ps->_top == 0;
}

// ����ջ 
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->_a);
	ps->_capacity = ps->_top = 0;
}



bool isValid(char* s) {
	Stack c;
	StackInit(&c);
	while (*s)
	{
		if (*s == '(' || *s == '{' || *s == '[')
		{
			StackPush(&c, *s);
		}
		else
		{
			if (StackEmpty(&c))
			{
				StackDestroy(&c);
				return false;
			}
			char tmp = StackTop(&c);
			StackPop(&c);
			if ((tmp == '(' && *s != ')') ||
				(tmp == '{' && *s != '}') ||
				(tmp == '[' && *s != ']'))
			{
				StackDestroy(&c);
				return false;
			}
		}
		++s;
	}
	int flag = 1;
	if (!StackEmpty(&c))
	{
		flag = 0;
	}
	StackDestroy(&c);
	return flag;
}
