#define _CRT_SECURE_NO_WARNINGS

//
//145. �������ĺ������
//����һ�ö������ĸ��ڵ� root ��������ڵ�ֵ�� �������
//
//ʾ�� 1��
//
//���룺root = [1, null, 2, 3]
//�����[3, 2, 1]
//
//ʾ�� 2��
//
//���룺root = []
//�����[]
//
//ʾ�� 3��
//
//���룺root = [1]
//�����[1]
//
//
//
//��ʾ��
//
//���нڵ����Ŀ�ڷ�Χ[0, 100] ��
//- 100 <= Node.val <= 100
//
//
//���ף��ݹ��㷨�ܼ򵥣������ͨ�������㷨�����
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode.cn/problems/binary-tree-postorder-traversal
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


 /**
  * Note: The returned array must be malloced, assume caller calls free().
  */

  // ֧�ֶ�̬������ջ
  /*typedef struct TreeNode* STDataType;
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
  */

  // �������ڵ����
int BinaryTreeSize(struct TreeNode* root)
{
	return root == NULL ? 0 : BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}

// ������ǰ����� 
void BinaryTreePostOrder(struct TreeNode* root, int* arr, int* n)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	BinaryTreePostOrder(root->left, arr, n);
	BinaryTreePostOrder(root->right, arr, n);
	arr[*n] = root->val;
	(*n)++;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
	int size = BinaryTreeSize(root);
	int* ret = (int*)malloc(size * sizeof(int));
	*returnSize = 0;
	BinaryTreePostOrder(root, ret, returnSize);
	return ret;
	/*Stack Root;
	StackInit(&Root);
	StackPush(&Root,root);
	int size = BinaryTreeSize(root);
	int* ret = (int*)malloc(size * sizeof(int));
	*returnSize = 0;

	//ͨ��ջ����
	while(!StackEmpty(&Root))
	{
		struct TreeNode* Node = StackTop(&Root);
		if(Node->left == NULL)
		{
			if(Node->right != NULL)
			{
				StackPush(&Root, Node->right);
			}
		}
		else if(Node->left !=NULL)
		{
			StackPush(&Root, Node->left);
		}


	}
	StackDestroy(&Root);
	//����
	return ret;
	*/
}