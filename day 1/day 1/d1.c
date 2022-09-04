#define _CRT_SECURE_NO_WARNINGS


//����һ�����������ж����Ƿ��Ǹ߶�ƽ��Ķ�������
//
//�����У�һ�ø߶�ƽ�����������Ϊ��
//
//һ��������ÿ���ڵ� ���������������ĸ߶Ȳ�ľ���ֵ������ 1 ��
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode.cn/problems/balanced-binary-tree
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


 //�߶�
int BinaryTreeHeight(struct TreeNode* root)
{
    if (root == NULL)
    {
        return 0;
    }
    int HeightL = BinaryTreeHeight(root->left);
    int HeightR = BinaryTreeHeight(root->right);


    return 1 + (HeightL > HeightR ? HeightL : HeightR);
}


bool isBalanced(struct TreeNode* root) {
    if (root == NULL)
        return true;

    if (abs(BinaryTreeHeight(root->left) - BinaryTreeHeight(root->right)) > 1)
        return false;

    return isBalanced(root->left) && isBalanced(root->right);
}
