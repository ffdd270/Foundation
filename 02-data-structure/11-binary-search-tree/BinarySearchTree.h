#pragma once
#include "../08-binary-tree/BinaryTree.h"
using namespace btreenode;

namespace bstree
{
    template <typename T>
    class BSTree
    {
    public:
        BSTree();

        virtual void          Insert(T data);
        BtreeNode<T>*         Search(T target);
        virtual BtreeNode<T>* Remove(T target);
        void                  ShowAll();

        BtreeNode<T>* GetRoot();
    protected:
        BtreeNode<T>* root;
        BtreeNode<T>* cur;
    };

    template<typename T>
    BSTree<T>::BSTree()
    {
        root = nullptr;
        cur = root;
    }

    template<typename T>
    void BSTree<T>::Insert(T data)
    {
        cur = root;
        BtreeNode<T>* parentNode = nullptr;
        BtreeNode<T>* newNode = nullptr;

        while (cur != nullptr)
        {
            if(data == GetData(cur))
                return;

            parentNode = cur;

            if(GetData(cur) > data)
                cur = GetLeftSubTree(cur);
            else
                cur = GetRightSubTree(cur);
        }

        newNode = MakeBTreeNode<T>();
        SetData(newNode, data);

        if(parentNode != nullptr)
        {
            if(data < GetData(parentNode))
                MakeLeftSubTree(parentNode, newNode);
            else
                MakeRightSubTree(parentNode, newNode);
        }
        else
        {
            root = newNode;
        }
    }

    template<typename T>
    BtreeNode<T> *BSTree<T>::Search(T target)
    {
        cur = root;
        T curData;

        while(cur != nullptr)
        {
            curData = GetData(cur);

            if(target == curData)
                return cur;
            else if(target < curData)
                cur = GetLeftSubTree(cur);
            else
                cur = GetRightSubTree(cur);
        }

        return nullptr;
    }

    template<typename T>
    BtreeNode<T> *BSTree<T>::Remove(T target)
    {
        BtreeNode<T>* parentVirtualRoot = MakeBTreeNode<T>();
        BtreeNode<T>* parentNode = parentVirtualRoot;

        BtreeNode<T>* currentNode = root;
        BtreeNode<T>* deleteNode;

        ChangeRightSubTree(parentVirtualRoot, root);

        while(currentNode != nullptr && GetData(currentNode) != target)
        {
            parentNode = currentNode;

            if(target < GetData(currentNode))
                currentNode = GetLeftSubTree(currentNode);
            else
                currentNode = GetRightSubTree(currentNode);
        }

        if(currentNode == nullptr)
            return nullptr;

        deleteNode = currentNode;

        if(GetLeftSubTree(deleteNode) == nullptr && GetRightSubTree(deleteNode) == nullptr)
        {
            if(GetLeftSubTree(parentNode) == deleteNode)
                RemoveLeftSubTree(parentNode);
            else
                RemoveRightSubTree(parentNode);
        }

        else if (GetLeftSubTree(deleteNode) == nullptr || GetRightSubTree(deleteNode) == nullptr)
        {
            BtreeNode<T>* deleteChildNode;

            if(GetLeftSubTree(deleteNode) != nullptr)
                deleteChildNode = GetLeftSubTree(deleteNode);
            else
                deleteChildNode = GetRightSubTree(deleteNode);

            if(GetLeftSubTree(parentNode) == deleteNode)
                ChangeLeftSubTree(parentNode, deleteChildNode);
            else
                ChangeRightSubTree(parentNode, deleteChildNode);
        }

        else
        {
            BtreeNode<T>* minimumNode = GetRightSubTree(deleteNode);
            BtreeNode<T>* minimumParentNode =deleteNode;
            T deleteData;

            while(GetLeftSubTree(minimumNode) != nullptr)
            {
                minimumParentNode = minimumNode;
                minimumNode = GetLeftSubTree(minimumNode);
            }

            deleteData = GetData(deleteNode);
            SetData(deleteNode, GetData(minimumNode));

            if(GetLeftSubTree(minimumParentNode) == minimumNode)
                ChangeLeftSubTree(minimumParentNode, GetRightSubTree(minimumNode));
            else
                ChangeRightSubTree(minimumParentNode, GetRightSubTree(minimumNode));

            deleteNode = minimumNode;
            SetData(deleteNode, deleteData);
        }

        if(GetRightSubTree(parentVirtualRoot) != root)
            root = GetRightSubTree(parentVirtualRoot);

        delete parentVirtualRoot; 
        return deleteNode;
    }

    template <typename T>
    void ShowData(T data)
    {
        std::cout << data << " ";
    }

    template<typename T>
    void BSTree<T>::ShowAll()
    {
        InorderTraverse(root, ShowData);
    }

    template<typename T>
    BtreeNode<T> *BSTree<T>::GetRoot()
    {
        return root;
    }
}