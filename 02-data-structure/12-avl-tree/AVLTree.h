#pragma once
#include "../11-binary-search-tree/BinarySearchTree.h"
using namespace bstree;

namespace avltree
{
    template <typename T>
    class AVLTree : public BSTree<T>
    {
    public:
        using BSTree<T>::BSTree;

        void          Insert(T data) override;
        BtreeNode<T>* Remove(T target) override;
        void          ReBalance();
    private:
    };

    template<typename T>
    void AVLTree<T>::ReBalance()
    {
        int heightDifference = GetHeightDifference(this->root);

        if(heightDifference > 1)
        {
            if(GetHeightDifference(GetLeftSubTree(this->root)) > 0)
                this->root = RotateLL(this->root);
            else
                this->root = RotateLR(this->root);
        }
        else if(heightDifference < -1)
        {
            if(GetHeightDifference(GetRightSubTree(this->root)) < 0)
                this->root = RotateRR(this->root);
            else
                this->root = RotateRL(this->root);
        }
    }

    template <typename T>
    int GetHeight(BtreeNode<T>* bstree)
    {
        int leftHeight;
        int rightHeight;

        if(bstree == nullptr)
            return 0;

        leftHeight = GetHeight(GetLeftSubTree(bstree));
        rightHeight = GetHeight(GetRightSubTree(bstree));

        if(leftHeight > rightHeight)
            return leftHeight + 1;
        else
            return rightHeight + 1;
    }

    template <typename T>
    int GetHeightDifference(BtreeNode<T>* bstree)
    {
        int leftSubTreeHeight;
        int rightSubTreeHeight;

        if(bstree == nullptr)
            return 0;

        leftSubTreeHeight = GetHeight(GetLeftSubTree(bstree));
        rightSubTreeHeight = GetHeight(GetRightSubTree(bstree));
        return leftSubTreeHeight - rightSubTreeHeight;
    }

    template <typename T>
    BtreeNode<T>* RotateLL(BtreeNode<T>* bstree)
    {
        BtreeNode<T>* parentNode;
        BtreeNode<T>* childNode;

        parentNode = bstree;
        childNode = GetLeftSubTree(parentNode);

        ChangeLeftSubTree(parentNode, GetRightSubTree(childNode));
        ChangeRightSubTree(childNode, parentNode);

        return childNode;
    }

    template <typename T>
    BtreeNode<T>* RotateRR(BtreeNode<T>* bstree)
    {
        BtreeNode<T>* parentNode;
        BtreeNode<T>* childNode;

        parentNode = bstree;
        childNode = GetRightSubTree(parentNode);

        ChangeRightSubTree(parentNode, GetLeftSubTree(childNode));
        ChangeLeftSubTree(childNode, parentNode);

        return childNode;
    }

    template <typename T>
    BtreeNode<T>* RotateLR(BtreeNode<T>* bstree)
    {
        BtreeNode<T>* parentNode;
        BtreeNode<T>* childNode;

        parentNode = bstree;
        childNode = GetLeftSubTree(parentNode);

        ChangeLeftSubTree(parentNode, RotateRR(childNode));
        return RotateLL(parentNode);
    }

    template <typename T>
    BtreeNode<T>* RotateRL(BtreeNode<T>* bstree)
    {
        BtreeNode<T>* parentNode;
        BtreeNode<T>* childNode;

        parentNode = bstree;
        childNode = GetRightSubTree(parentNode);

        ChangeRightSubTree(parentNode, RotateLL(childNode));
        return RotateRR(parentNode);
    }
}