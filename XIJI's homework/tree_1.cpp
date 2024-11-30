#include <iostream>
#include <cstdio>
using namespace std;

struct Node
{
    char data;
    Node *lchild;
    Node *rchild;
};

void preorder(Node *tree) // 先序遍历
{
    if (!tree) return;
    cout << tree->data;
    preorder(tree->lchild);
    preorder(tree->rchild);
}

Node *create(string s1, string s2) // s1后序，s2中序
{
    Node *tree = NULL;

    if (s1.size() > 0)
    {
        tree = new Node;
        int len = s1.size();
        tree->data = s1[len - 1]; // 确定根节点
        tree->lchild = NULL;
        tree->rchild = NULL;
        string p1, p2;
        string in1, in2;

        int index = s2.find(s1[len - 1]);                  // 找到根结点在中序遍历中的位置
        in1 = s2.substr(0, index);                         // 取出左子树 （中序的）
        in2 = s2.substr(index + 1, s2.size() - index - 1); // 取出右子树 （中序的）
        p1 = s1.substr(0, index);                          // 取出左子树 （后序的）
        p2 = s1.substr(index, s1.size() - index - 1);      // 取出右子树 （后序的）

        tree->lchild = create(p1, in1);
        tree->rchild = create(p2, in2);
    }

    return tree;
}

int main()
{
    string s1, s2;
    cin >> s2;
    cin >> s1;

    Node *tree = create(s1, s2);
    preorder(tree);

    return 0;
}
