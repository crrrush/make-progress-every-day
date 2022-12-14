<<<<<<< HEAD
#define _CRT_SECURE_NO_WARNINGS


//给定一个二叉树，判断它是否是高度平衡的二叉树。
//
//本题中，一棵高度平衡二叉树定义为：
//
//一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode.cn/problems/balanced-binary-tree
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


 //高度
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
=======
#define _CRT_SECURE_NO_WARNINGS


//给定一个二叉树，判断它是否是高度平衡的二叉树。
//
//本题中，一棵高度平衡二叉树定义为：
//
//一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode.cn/problems/balanced-binary-tree
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


 //高度
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
>>>>>>> 69a39be363279d67410a192d15835bcc43c6cde7
