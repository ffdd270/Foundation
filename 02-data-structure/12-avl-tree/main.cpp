#include <iostream>
#include "AVLTree.h"
using namespace avltree;

int main()
{
    AVLTree<int> avlTree;
    BtreeNode<int>* leftNode;
    BtreeNode<int>* rightNode;

    for(int i = 0; i < 10; ++i)
        avlTree.Insert(i);

    std::cout << "Root Node : " << GetData(avlTree.GetRoot()) << std::endl;
    return 0;
}