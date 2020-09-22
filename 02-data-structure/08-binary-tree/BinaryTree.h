#pragma once
#include <iostream>

namespace btreenode
{
    template <typename T>
    struct BtreeNode
    {
        T data;
        BtreeNode* left;
        BtreeNode* right;
    };

    template <typename T>
    BtreeNode<T>* MakeBTreeNode()
    {
        BtreeNode<T>* newNode = new BtreeNode<T>;
        newNode->left = nullptr;
        newNode->right = nullptr;

        return newNode;
    }

    template <typename T>
    T GetData(BtreeNode<T>* bt)
    {
        return bt->data;
    }

    template <typename T>
    void SetData(BtreeNode<T>* bt, T data)
    {
        bt->data = data;
    }

    template <typename T>
    BtreeNode<T>* GetLeftSubTree(BtreeNode<T>* bt)
    {
        return bt->left;
    }

    template <typename T>
    BtreeNode<T>* GetRightSubTree(BtreeNode<T>* bt)
    {
        return bt->right;
    }

    template <typename T>
    void DeleteTree(BtreeNode<T>* bt)
    {
        if(bt == nullptr)
            return;

        DeleteTree(bt->left);
        DeleteTree(bt->right);
        delete bt;
        bt = nullptr;
    }

    template <typename T>
    void MakeLeftSubTree(BtreeNode<T>* main, BtreeNode<T>* sub)
    {
        if(main->left != nullptr)
            DeleteTree(main->left);

        main->left = sub;
    }

    template <typename T>
    void MakeRightSubTree(BtreeNode<T>* main, BtreeNode<T>* sub)
    {
        if(main->right != nullptr)
            DeleteTree(main->right);

        main->right = sub;
    }

    template <typename T>
    void InorderTraverse(BtreeNode<T>* bt, void (*action)(T))
    {
        if(bt == nullptr)
            return;

        InorderTraverse(bt->left, action);
        action(bt->data);
        InorderTraverse(bt->right, action);
    }

    template <typename T>
    void PreorderTraverse(BtreeNode<T>* bt, void (*action)(T))
    {
        if(bt == nullptr)
            return;

        action(bt->data);
        PreorderTraverse(bt->left, action);
        PreorderTraverse(bt->right, action);
    }

    template <typename T>
    void PostorderTraverse(BtreeNode<T>* bt, void (*action)(T))
    {
        if(bt == nullptr)
            return;

        PostorderTraverse(bt->left, action);
        PostorderTraverse(bt->right, action);
        action(bt->data);
    }



    template <typename T>
    BtreeNode<T>* RemoveLeftSubTree(BtreeNode<T>* bt)
    {
        BtreeNode<T>* delNode;

        if(bt != nullptr)
        {
            delNode = bt->left;
            bt->left = nullptr;
        }
        return delNode;
    }

    template<typename T>
    BtreeNode<T>* RemoveRightSubTree(BtreeNode<T> *bt)
    {
        BtreeNode<T>* delNode;

        if(bt != nullptr)
        {
            delNode = bt->right;
            bt->right = nullptr;
        }
        return delNode;
    }

    template<typename T>
    void ChangeLeftSubTree(BtreeNode<T> *main, BtreeNode<T> *sub)
    {
        main->left = sub;
    }

    template<typename T>
    void ChangeRightSubTree(BtreeNode<T> *main, BtreeNode<T> *sub)
    {
        main->right = sub;
    }
}