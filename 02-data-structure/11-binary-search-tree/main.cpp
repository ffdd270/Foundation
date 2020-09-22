#include <iostream>
#include "BinarySearchTree.h"
using namespace bstree;

int main()
{
    BSTree<int> bstree;
    BtreeNode<int>* searchNode;

    bstree.Insert(5);   bstree.Insert(8);
    bstree.Insert(1);   bstree.Insert(6);
    bstree.Insert(4);   bstree.Insert(9);
    bstree.Insert(3);   bstree.Insert(2);
    bstree.Insert(7);

    bstree.ShowAll(); std::cout << std::endl;
    searchNode = bstree.Remove(3);
    free(searchNode);

    bstree.ShowAll(); std::cout << std::endl;
    searchNode = bstree.Remove(8);
    delete searchNode;

    bstree.ShowAll(); std::cout << std::endl;
    searchNode = bstree.Remove(1);
    delete searchNode;

    bstree.ShowAll(); std::cout << std::endl;
    searchNode = bstree.Remove(6);
    delete searchNode;

    bstree.ShowAll(); std::cout << std::endl;
    return 0;
}