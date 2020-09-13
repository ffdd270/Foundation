#include "BinaryTree.h"
#include <iostream>

template <typename T>
void CoutNodeData(T data)
{
    std::cout << data << " ";
}

int main()
{
    BtreeNode<int>* bt1 = MakeTreeNdoe<int>();
    BtreeNode<int>* bt2 = MakeTreeNdoe<int>();
    BtreeNode<int>* bt3 = MakeTreeNdoe<int>();
    BtreeNode<int>* bt4 = MakeTreeNdoe<int>();
    BtreeNode<int>* bt5 = MakeTreeNdoe<int>();
    BtreeNode<int>* bt6 = MakeTreeNdoe<int>();

    SetData(bt1, 1);
    SetData(bt2, 2);
    SetData(bt3, 3);
    SetData(bt4, 4);
    SetData(bt5, 5);
    SetData(bt6, 6);

    MakeLeftSubTree(bt1, bt2);
    MakeRightSubTree(bt1, bt3);
    MakeLeftSubTree(bt2, bt4);
    MakeRightSubTree(bt2, bt5);
    MakeLeftSubTree(bt3, bt6);

    InorderTraverse(bt1, CoutNodeData); std::cout << std::endl;
    PreorderTraverse(bt1, CoutNodeData); std::cout << std::endl;
    PostorderTraverse(bt1, CoutNodeData);

    return 0;
}