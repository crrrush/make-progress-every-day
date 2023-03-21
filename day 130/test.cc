
// 二叉树遍历
// 链接：https://www.nowcoder.com/questionTerminal/4b91205483694f449f94c179883c1fef
// 来源：牛客网

// 编一个程序，读入用户输入的一串先序遍历字符串，根据此字符串建立一个二叉树（以指针方式存储）。 例如如下的先序遍历字符串： ABC##DE#G##F### 其中“#”表示的是空格，空格字符代表空树。建立起此二叉树以后，再对二叉树进行中序遍历，输出遍历结果。

// 输入描述:

// 输入包括1行字符串，长度不超过100。



// 输出描述:

// 可能有多组测试数据，对于每组数据，
// 输出将输入字符串建立二叉树后中序遍历的序列，每个字符后面都有一个空格。
// 每个输出结果占一行。

// 示例1
// 输入

// abc##de#g##f###

// 输出

// c b e g d f a 

#include<stdio.h>
#include<stdlib.h>

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	if (a[*pi] == '#' || *pi >= n)
	{
		(*pi)++;
		return NULL;
	}

	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	if (root == NULL)
	{
		perror("malloc failed");
		exit(-1);
	}

	root->_data = a[*pi];
	(*pi)++;
	root->_left = BinaryTreeCreate(a, n, pi);
	root->_right = BinaryTreeCreate(a, n, pi);


	return root;
}

// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
	{
		//printf("NULL ");
		return;
	}

	BinaryTreeInOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreeInOrder(root->_right);
}

int main()
{
    char str[100];
    scanf("%s",str);
    int i = 0;
      
    BinaryTreeInOrder(BinaryTreeCreate(str,100,&i));
    
    return 0;
}