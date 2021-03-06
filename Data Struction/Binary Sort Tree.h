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
    void DeleteNode(BinaryTreeNode<ElemType> *&node);
    void DeleteElem(const ElemType &key);
    BinaryTreeNode<ElemType> *Find(const ElemType &key) const;
    void GetElemsAbove(const ElemType &key) const;
};
template <class ElemType>
BinaryTreeNode<ElemType> *BinarySortTree<ElemType>::Find(const ElemType &key, BinaryTreeNode<ElemType> *&parentNode) const
{
    BinaryTreeNode<ElemType> *p = this->root_;
    parentNode = NULL;
    while (p && p->elem_ != key)
    {
        if (key < p->elem_)
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
            result.push_back(p->elem_);
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
    else if (elem < parentNode->elem_)
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
        if (elem == p->elem_)
        {
            cout << "The element exsits." << endl;
            return;
        }
        parentNode = p;
        if (elem < p->elem_)
        {
            p = p->leftChild_;
        }
        else
        {
            p = p->rightChild_;
        }
    }
    p = new BinaryTreeNode<ElemType>(elem);
    if (elem < parentNode->elem_)
    {
        parentNode->leftChild_ = p;
    }
    else
    {
        parentNode->rightChild_ = p;
    }
}
template <class ElemType>
void BinarySortTree<ElemType>::DeleteNode(BinaryTreeNode<ElemType> *&node)
{
    BinaryTreeNode<ElemType> *tempNode;
    BinaryTreeNode<ElemType> *tempParentNode;
    if (!node->leftChild_ && !node->rightChild_)
    {
        delete node;
        node = NULL;
    }
    else if (!node->leftChild_)
    {
        tempNode = node;
        node = node->rightChild_;
        delete tempNode;
    }
    else if (!node->rightChild_)
    {
        tempNode = node;
        node = node->leftChild_;
        delete tempNode;
    }
    else
    {
        tempParentNode = node;
        tempNode = node->leftChild_;
        while (tempNode->rightChild_)
        {
            tempParentNode = tempNode;
            tempNode = tempNode->rightChild_;
        }
        node->elem_ = tempNode->elem_;
        if (tempParentNode->rightChild_ == tempNode)
        {
            DeleteNode(tempParentNode->rightChild_);
        }
        else
        {
            DeleteNode(tempParentNode->leftChild_);
        }
    }
}
template <class ElemType>
void BinarySortTree<ElemType>::DeleteElem(const ElemType &key)
{
    BinaryTreeNode<ElemType> *tempNode = NULL;
    BinaryTreeNode<ElemType> *p = Find(key, tempNode);
    if (!p)
    {
        throw(string) "The element dose not exist.";
    }
    DeleteNode(p);
}
template <class ElemType>
BinaryTreeNode<ElemType> *BinarySortTree<ElemType>::Find(const ElemType &key) const
{
    BinaryTreeNode<ElemType> *parentNode;
    return Find(key, parentNode);
}
template <class ElemType>
void BinarySortTree<ElemType>::GetElemsAbove(const ElemType &key) const
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
            result.push_back(p->elem_);
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