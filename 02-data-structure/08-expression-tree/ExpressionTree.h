#pragma once
#include <iostream>
#include "../08-binary-tree/BinaryTree.h"
#include "../06-list-base-stack/ListBaseStack.h"

BtreeNode<int>* MakeExpTree(const std::string& exp)
{
    ListStack<BtreeNode<int>*> stack;

    for(char c : exp)
    {
        BtreeNode<int>* pnode = MakeTreeNdoe<int>();

        if('0' <= c && c <= '9')
        {
            SetData(pnode, c - '0');
        }
        else
        {
            MakeRightSubTree(pnode, stack.pop());
            MakeLeftSubTree(pnode, stack.pop());
            SetData(pnode, static_cast<int>(c));
        }

        stack.push(pnode);
    }

    return stack.pop();
}

void ShowNodeData(int data)
{
    if(0 <= data && data <= 9)
        std::cout << data << " ";

    else
        std::cout << static_cast<char>(data) << " ";
}

void ShowPrefixTypeExp(BtreeNode<int>* bt)
{
    PreorderTraverse(bt, ShowNodeData);
}

void ShowInfixTypeExp(BtreeNode<int>* bt)
{
    if(bt == nullptr)
        return;

    if(bt->left != nullptr || bt->right != nullptr)
        std::cout << "( ";

    ShowInfixTypeExp(bt->left);
    ShowNodeData(bt->data);
    ShowInfixTypeExp(bt->right);

    if(bt->left != nullptr || bt->right != nullptr)
        std::cout << ") ";
}

void ShowPostfixTypeExp(BtreeNode<int>* bt)
{
    PostorderTraverse(bt, ShowNodeData);
}

int EvaluateExpTree(BtreeNode<int>* bt)
{
    if(GetLeftSubTree(bt) == nullptr && GetRightSubTree(bt) == nullptr)
        return GetData(bt);

    int op1 = EvaluateExpTree(bt->left);
    int op2 = EvaluateExpTree(bt->right);

    switch (bt->data)
    {
        case '+':
            return op1 + op2;

        case '-':
            return op1 - op2;

        case '*':
            return op1 * op2;

        case '/':
            return op1 / op2;
    }

    return 0;
}
