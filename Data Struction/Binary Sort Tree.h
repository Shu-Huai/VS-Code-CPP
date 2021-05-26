#pragma once
#ifndef __BINNARY_SORT_TREE_H__
#define __BINNARY_SORT_TREE_H__
#include "Binary Tree.h"
#include <stack>
#include <vector>
template <class ElemType>
class BinarySortTree : public BinaryTree<ElemType>
{
protected:
    BinaryTreeNode<ElemType> *Find(const ElemType &key, BinaryTreeNode<ElemType> *&parentNode) const;

public:
    bool IsBinarySortTree() const;
    void InsertElem(const ElemType &elem);
    void FindAndInsert(const ElemType &elem);
    void DeleteElem(const ElemType &key);
    BinaryTreeNode<ElemType> *Find(const ElemType &key) const;
    void GetElemsAbove(int key) const;
};
template <class ElemType>
BinaryTreeNode<ElemType> *BinarySortTree<ElemType>::Find(const ElemType &key, BinaryTreeNode<ElemType> *&parentNode) const
{
    BinaryTreeNode<ElemType> *p = this->root_;
    parentNode = NULL;
    while (p && p->data_ != key)
    {
        if (key < p->data_)
        {
            parentNode = p;
            p = p->leftChild_;
        }
        else
        {
            parentNode = p;
            p = p->rightChild_;
        }
    }
    return p;
}
template <class ElemType>
bool BinarySortTree<ElemType>::IsBinarySortTree() const
{
    if (!this->root_)
    {
        return true;
    }
    vector<ElemType> result;
    stack<BinaryTreeNode<ElemType> *> s;
    BinaryTreeNode<ElemType> *p = this->root_;
    while (p || !s.empty())
    {
        if (p)
        {
            s.push(p);
            p = p->leftChild_;
        }
        else
        {
            p = s.top();
            result.push_back(p->data_);
            s.pop();
            p = p->rightChild_;
        }
    }
    for (int i = 1; i < int(result.size()); i++)
    {
        if (result[i] < result[i - 1])
        {
            return false;
        }
    }
    return true;
}
template <class ElemType>
void BinarySortTree<ElemType>::InsertElem(const ElemType &elem)
{
    BinaryTreeNode<ElemType> *parentNode;
    if (Find(elem, parentNode))
    {
        throw(string) "Element exists.";
    }
    BinaryTreeNode<ElemType> *p = new BinaryTreeNode<ElemType>(elem);
    if (this->IsEmpty())
    {
        this->root_ = p;
    }
    else if (elem < parentNode->data_)
    {
        parentNode->leftChild_ = p;
    }
    else
    {
        parentNode->rightChild_ = p;
    }
}
template <class ElemType>
void BinarySortTree<ElemType>::FindAndInsert(const ElemType &elem)
{
    if (!this->root_)
    {
        this->root_ = new BinaryTreeNode<ElemType>(elem);
        return;
    }
    BinaryTreeNode<ElemType> *p = this->root_;
    BinaryTreeNode<ElemType> *parentNode = NULL;
    while (p)
    {
        if (elem == p->data_)
        {
            cout << "The element exsits." << endl;
            return;
        }
        parentNode = p;
        if (elem < p->data_)
        {
            p = p->leftChild_;
        }
        else
        {
            p = p->rightChild_;
        }
    }
    p = new BinaryTreeNode<ElemType>(elem);
    if (elem < parentNode->data_)
    {
        parentNode->leftChild_ = p;
    }
    else
    {
        parentNode->rightChild_ = p;
    }
}
template <class ElemType>
void BinarySortTree<ElemType>::DeleteElem(const ElemType &key)
{
    BinaryTreeNode<ElemType> *parentNode = NULL;
    BinaryTreeNode<ElemType> *p = Find(key, parentNode);
    if (!p)
    {
        throw(string) "The tree is empty.";
    }
    if (!parentNode)
    {
        DeleteElem(p->data_);
    }
    else if (key < parentNode->data_)
    {
        DeleteElem(parentNode->leftChild_->data_);
    }
    else
    {
        DeleteElem(parentNode->rightChild_->data_);
    }
}
template <class ElemType>
BinaryTreeNode<ElemType> *BinarySortTree<ElemType>::Find(const ElemType &key) const
{
    BinaryTreeNode<ElemType> *parentNode;
    return Find(key, parentNode);
}
template <class ElemType>
void BinarySortTree<ElemType>::GetElemsAbove(int key) const
{
    if (!this->root_)
    {
        return;
    }
    vector<ElemType> result;
    stack<BinaryTreeNode<ElemType> *> s;
    BinaryTreeNode<ElemType> *p = this->root_;
    while (p || !s.empty())
    {
        if (p)
        {
            s.push(p);
            p = p->leftChild_;
        }
        else
        {
            p = s.top();
            result.push_back(p->data_);
            s.pop();
            p = p->rightChild_;
        }
    }
    for (int i = int(result.size()) - 1; i >= 0; i--)
    {
        if (result[i] >= key)
        {
            cout << result[i] << " ";
        }
        else
        {
            break;
        }
    }
}
#endif