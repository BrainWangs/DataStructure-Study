#include <stdio.h>
#include <stdlib.h>

/*这个是GPT写的*/

// 定义树节点
typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// 创建新节点
TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 插入节点到二叉搜索树
TreeNode* insertIntoBST(TreeNode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->val) {
        root->left = insertIntoBST(root->left, value);
    } else {
        root->right = insertIntoBST(root->right, value);
    }
    return root;
}

// 镜像转换二叉树
void mirrorTree(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    // 交换左右子树
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // 递归镜像左右子树
    mirrorTree(root->left);
    mirrorTree(root->right);
}

// 打印二叉树的层次遍历
void levelOrderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    // 定义队列
    TreeNode** queue = (TreeNode**)malloc(1000 * sizeof(TreeNode*));
    int front = 0, rear = 0;

    // 入队根节点
    queue[rear++] = root;

    // 遍历队列
    while (front < rear) {
        TreeNode* current = queue[front++]; // 出队
        printf("%d ", current->val);

        // 左子树入队
        if (current->left != NULL) {
            queue[rear++] = current->left;
        }
        // 右子树入队
        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }

    free(queue);
}

int main() {
    TreeNode* root = NULL;
    // 输入
    char input[100];
    fgets(input, sizeof(input), stdin);
    // 解析输入
    int value;

    char* ptr = input;
    while (sscanf(ptr, "%d", &value) == 1) {
        root = insertIntoBST(root, value);
        while (*ptr != ' ' && *ptr != '\0') ptr++;
        if (*ptr == ' ') ptr++;
    }

    // 镜像转换
    mirrorTree(root);

    // 输出层次遍历
    levelOrderTraversal(root);
    // printf("\n");

    return 0;
}
