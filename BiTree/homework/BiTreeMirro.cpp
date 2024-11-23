//Ë¼Â· ºóÐò±éÀú
#include <iostream>
#include <vector>
#include <stdio.h>
#include<stdlib.h>
using namespace std;

typedef struct BSTreeNode // a node in the binary search tree (BST)
{
int m_nValue; // value of node
BSTreeNode *m_pLeft; // left child of node
BSTreeNode *m_pRight; // right child of node
}BSTreeNode;

int addBSTreeNode(BSTreeNode * &T, int data)  //°Ñdata¼ÓÈëµÄÒÔTÎª¸ùµÄÊ÷ÖÐ
{
    if(T == NULL) //¸ù½Úµãµ¥¶À´¦Àí
    {
        T = (BSTreeNode *)malloc(sizeof(BSTreeNode));
        T->m_nValue = data;
        T->m_pLeft = NULL;
        T->m_pRight = NULL;
    }
    else
    {
        BSTreeNode * x = T;
        BSTreeNode * px = NULL;
        while(x != NULL)
        {
            if(data >= x->m_nValue)
            {
                px = x;
                x = x->m_pRight;
            }
            else
            {
                px = x;
                x = x->m_pLeft;
            }
        }

        if(data >= px->m_nValue)
        {
            px->m_pRight = (BSTreeNode *)malloc(sizeof(BSTreeNode));
            px->m_pRight->m_nValue = data;
            px->m_pRight->m_pLeft = NULL;
            px->m_pRight->m_pRight = NULL;
        }
        else
        {
            px->m_pLeft = (BSTreeNode *)malloc(sizeof(BSTreeNode));
            px->m_pLeft->m_nValue = data;
            px->m_pLeft->m_pLeft = NULL;
            px->m_pLeft->m_pRight = NULL;
        }
    }
    return 1;
}

int RecursiveMirror(BSTreeNode * T)
{
    if(T == NULL)
    {
        return 0;
    }
    else
    {
        RecursiveMirror(T->m_pLeft);
        RecursiveMirror(T->m_pRight);
        BSTreeNode * x = T->m_pLeft;
        T->m_pLeft = T->m_pRight;
        T->m_pRight = x;
    }
}

int NonRecursiveMirror(BSTreeNode * T)
{
    vector<BSTreeNode *> stack;
    int tag[50] = {0};
    int tagnum = 0;
    BSTreeNode * x = T;
    stack.push_back(T);
    while(!stack.empty())
    {
        while((x = stack.back()) != NULL)
        {
            x = x->m_pLeft;
            stack.push_back(x);
            tag[tagnum++] = 0;
        }
        while(tag[tagnum - 1] == 1) //×¢ÒâÏÈÅÐ¶ÏÊÇ·ñ´¦ÀíÊý¾Ý ÔÙµ¯³ö
        {
            stack.pop_back();
            tagnum--;
            BSTreeNode * cur = stack.back();
            BSTreeNode * tmp = cur->m_pLeft;
            cur->m_pLeft = cur->m_pRight;
            cur->m_pRight = tmp;

        }
        stack.pop_back();
        tagnum--;
        if(!stack.empty()) //×¢ÒâÕâÀïµÄÌõ¼þ
        {
            stack.push_back(stack.back()->m_pRight);
            tag[tagnum++] = 1;
        }

    }
    return 1;
}
int main()
{
    BSTreeNode * T = NULL;
    addBSTreeNode(T, 8);
    addBSTreeNode(T, 6);
    addBSTreeNode(T, 10);
    addBSTreeNode(T, 5);
    addBSTreeNode(T, 7);
    addBSTreeNode(T, 9);
    addBSTreeNode(T, 11);

    NonRecursiveMirror(T);
    RecursiveMirror(T);
    return 0;
}