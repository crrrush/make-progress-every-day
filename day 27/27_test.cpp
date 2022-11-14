#define _CRT_SECURE_NO_WARNINGS

//
//145. 二叉树的后序遍历
//给你一棵二叉树的根节点 root ，返回其节点值的 后序遍历
//
//示例 1：
//
//输入：root = [1, null, 2, 3]
//输出：[3, 2, 1]
//
//示例 2：
//
//输入：root = []
//输出：[]
//
//示例 3：
//
//输入：root = [1]
//输出：[1]
//
//
//
//提示：
//
//树中节点的数目在范围[0, 100] 内
//- 100 <= Node.val <= 100
//
//
//进阶：递归算法很简单，你可以通过迭代算法完成吗？
//
//来源：力扣（LeetCode）
//链接：https ://leetcode.cn/problems/binary-tree-postorder-traversal
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


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

  // 支持动态增长的栈
  /*typedef struct TreeNode* STDataType;
  typedef struct Stack
  {
	  STDataType* _a;
	  int _top;		// 栈顶
	  int _capacity;  // 容量
  }Stack;

  // 初始化栈
  void StackInit(Stack* ps);

  // 入栈
  void StackPush(Stack* ps, STDataType data);

  // 出栈
  void StackPop(Stack* ps);

  // 获取栈顶元素
  STDataType StackTop(Stack* ps);

  // 获取栈中有效元素个数
  int StackSize(Stack* ps);

  // 检测栈是否为空，如果为空返回非零结果，如果不为空返回0
  int StackEmpty(Stack* ps);

  // 销毁栈
  void StackDestroy(Stack* ps);

  // 初始化栈
  void StackInit(Stack* ps)
  {
	  assert(ps);
	  ps->_a = NULL;
	  ps->_capacity = ps->_top = 0;
  }

  // 入栈
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

  // 出栈
  void StackPop(Stack* ps)
  {
	  assert(ps);
	  assert(!StackEmpty(ps));
	  ps->_top--;
  }

  // 获取栈顶元素
  STDataType StackTop(Stack* ps)
  {
	  assert(ps);
	  assert(!StackEmpty(ps));
	  return ps->_a[ps->_top - 1];
  }

  // 获取栈中有效元素个数
  int StackSize(Stack* ps)
  {
	  assert(ps);
	  return ps->_top;
  }

  // 检测栈是否为空，如果为空返回非零结果，如果不为空返回0
  int StackEmpty(Stack* ps)
  {
	  assert(ps);

	  return ps->_top == 0;
  }

  // 销毁栈
  void StackDestroy(Stack* ps)
  {
	  assert(ps);
	  free(ps->_a);
	  ps->_capacity = ps->_top = 0;
  }
  */

  // 二叉树节点个数
int BinaryTreeSize(struct TreeNode* root)
{
	return root == NULL ? 0 : BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}

// 二叉树前序遍历 
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

	//通过栈迭代
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
	//返回
	return ret;
	*/
}