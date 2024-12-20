#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点
typedef struct TreeNode {
    char val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// 创建新的二叉树节点
TreeNode* createNode(char val) {
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// 在中序遍历数组中查找给定值的索引
int findIndex(char *inorder, int start, int end, char value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value) {
            return i;
        }
    }
    return -1; 
}

// 递归构建二叉树
TreeNode* buildTree(char *inorder, char *postorder, int start, int end, int *postIndex) {
    if (start > end) {
        return NULL;
    }
    // 获取当前根节点
    char rootValue = postorder[*postIndex];
    (*postIndex)--;
    TreeNode *root = createNode(rootValue);
    
    // 在中序遍历中查找根节点位置，划分左右子树
    int inIndex = findIndex(inorder, start, end, rootValue);
    
    // 递归构建右子树和左子树（先右后左，因为对后序遍历数组是从后向前处理）
    root->right = buildTree(inorder, postorder, inIndex + 1, end, postIndex);
    root->left = buildTree(inorder, postorder, start, inIndex - 1, postIndex);
    
    return root;
}

// 先序遍历输出
void preorderTraversal(TreeNode *root) {
    if (root == NULL) {
        return;
    }
    printf("%c ", root->val);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// 释放二叉树内存
void freeTree(TreeNode *root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// 主函数
int main() {
    char inorder[5], postorder[5];

    // 输入中序遍历数组
    printf("请输入中序遍历数组: ");
    scanf("%5s", inorder);

    // 输入后序遍历数组
    printf("请输入后序遍历数组: ");
    scanf("%5s", postorder);

    int length = 5;
    int postIndex = length - 1; // 后序遍历的索引，初始化为最后一个元素

    // 构建二叉树
    TreeNode *root = buildTree(inorder, postorder, 0, length - 1, &postIndex);

    // 输出先序遍历
    printf("先序遍历结果: ");
    preorderTraversal(root);
    printf("\n");

    // 释放内存
    freeTree(root);

    return 0;
}
