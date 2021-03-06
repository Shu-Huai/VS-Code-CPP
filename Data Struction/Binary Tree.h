#pragma once
#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__
#include "Binary Tree Node.h"
#include <queue>
using namespace std;
template <class ElemType>
class BinaryTree
{
protected:
    BinaryTreeNode<ElemType> *root_;
    void CreateByPreOrder(BinaryTreeNode<ElemType> *&elem, ElemType *elems, int &index, int length, ElemType referenceValue);
    void Clear(BinaryTreeNode<ElemType> *&elem);
    void PreOrderTraverse(BinaryTreeNode<ElemType> *elem) const;
    void InOrderTraverse(BinaryTreeNode<ElemType> *elem) const;
    void PostOrderTraverse(BinaryTreeNode<ElemType> *elem) const;
    BinaryTreeNode<ElemType> *GetNode(BinaryTreeNode<ElemType> *node, const ElemType &elem) const;
    int GetHeight(const BinaryTreeNode<ElemType> *root) const;
    int GetNodeNumber(const BinaryTreeNode<ElemType> *node) const;
    BinaryTreeNode<ElemType> *GetParent(BinaryTreeNode<ElemType> *root, const BinaryTreeNode<ElemType> *node) const;
    BinaryTreeNode<ElemType> *Copy(BinaryTreeNode<ElemType> *node);
    void GetMirror(BinaryTreeNode<ElemType> *node);

public:
    BinaryTree();
    BinaryTree(const ElemType &elem);
    BinaryTree(BinaryTreeNode<ElemType> *node);
    BinaryTree(const BinaryTree<ElemType> &tree);
    virtual ~BinaryTree();
    void CreateByPreOrder(ElemType *elems, int length, ElemType &referenceValue);
    void Clear();
    bool IsEmpty() const;
    void PreOrderTraverse() const;
    void InOrderTraverse() const;
    void PostOrderTraverse() const;
    void LevelOrderTraverse() const;
    void InsertLeftChild(BinaryTreeNode<ElemType> *node, const ElemType &elem);
    void InsertRightChild(BinaryTreeNode<ElemType> *node, const ElemType &elem);
    void DeleteLeftChild(BinaryTreeNode<ElemType> *node);
    void DeleteRightChild(BinaryTreeNode<ElemType> *node);
    void SetElem(BinaryTreeNode<ElemType> *node, const ElemType &elem);
    BinaryTreeNode<ElemType> *GetRoot() const;
    BinaryTreeNode<ElemType> *GetNode(const ElemType &elem) const;
    ElemType GetElem(BinaryTreeNode<ElemType> *node) const;
    BinaryTreeNode<ElemType> *GetParent(const BinaryTreeNode<ElemType> *node) const;
    BinaryTreeNode<ElemType> *GetLeftChild(const BinaryTreeNode<ElemType> *node) const;
    BinaryTreeNode<ElemType> *GetRightChild(const BinaryTreeNode<ElemType> *node) const;
    BinaryTreeNode<ElemType> *GetLeftSibling(const BinaryTreeNode<ElemType> *node) const;
    BinaryTreeNode<ElemType> *GetRightSibling(const BinaryTreeNode<ElemType> *node) const;
    int GetHeight() const;
    int GetWidth() const;
    int GetNodeNumber() const;
    void GetMirror();
    BinaryTree<ElemType> &operator=(const BinaryTree<ElemType> &tree);
};
template <class ElemType>
void BinaryTree<ElemType>::CreateByPreOrder(BinaryTreeNode<ElemType> *&elem, ElemType *elems, int &index, int length, ElemType referenceValue)
{
    if (elems[index] != referenceValue && index < length)
    {
        elem = new BinaryTreeNode<ElemType>(elems[index]);
        CreateByPreOrder(elem->leftChild_, elems, ++index, length, referenceValue);
        CreateByPreOrder(elem->rightChild_, elems, ++index, length, referenceValue);
    }
    else
    {
        elem = NULL;
    }
}
template <class ElemType>
void BinaryTree<ElemType>::Clear(BinaryTreeNode<ElemType> *&elem)
{
    if (elem)
    {
        Clear(elem->leftChild_);
        Clear(elem->rightChild_);
        delete elem;
        elem = NULL;
    }
}
template <class ElemType>
void BinaryTree<ElemType>::PreOrderTraverse(BinaryTreeNode<ElemType> *elem) const
{
    if (elem)
    {
        cout << elem->elem_ << " ";
        PreOrderTraverse(elem->leftChild_);
        PreOrderTraverse(elem->rightChild_);
    }
}
template <class ElemType>
void BinaryTree<ElemType>::InOrderTraverse(BinaryTreeNode<ElemType> *elem) const
{
    if (elem)
    {
        InOrderTraverse(elem->leftChild_);
        cout << elem->elem_ << " ";
        InOrderTraverse(elem->rightChild_);
    }
}
template <class ElemType>
void BinaryTree<ElemType>::PostOrderTraverse(BinaryTreeNode<ElemType> *elem) const
{
    if (elem)
    {
        PostOrderTraverse(elem->leftChild_);
        PostOrderTraverse(elem->rightChild_);
        cout << elem->elem_ << " ";
    }
}
template <class ElemType>
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::GetNode(BinaryTreeNode<ElemType> *node, const ElemType &elem) const
{
    if (!node)
    {
        return NULL;
    }
    if (node->elem_ == elem)
    {
        return node;
    }
    BinaryTreeNode<ElemType> *p = GetNode(node->leftChild_, elem);
    if (p)
    {
        return p;
    }
    p = GetNode(node->rightChild_, elem);
    if (p)
    {
        return p;
    }
    return NULL;
}
template <class ElemType>
int BinaryTree<ElemType>::GetHeight(const BinaryTreeNode<ElemType> *root) const
{
    if (!root)
    {
        return 0;
    }
    int leftheight = GetHeight(root->leftChild_);
    int rightheight = GetHeight(root->rightChild_);
    return 1 + (leftheight > rightheight ? leftheight : rightheight);
}
template <class ElemType>
int BinaryTree<ElemType>::GetNodeNumber(const BinaryTreeNode<ElemType> *node) const
{
    if (!node)
    {
        return 0;
    }
    return 1 + GetNodeNumber(node->leftChild_) + GetNodeNumber(node->rightChild_);
}
template <class ElemType>
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::GetParent(BinaryTreeNode<ElemType> *root, const BinaryTreeNode<ElemType> *node) const
{
    if (!root)
    {
        return NULL;
    }
    if (root->leftChild_ == node || root->rightChild_ == node)
    {
        return root;
    }
    BinaryTreeNode<ElemType> *temp;
    temp = GetParent(root->leftChild_, node);
    if (temp)
    {
        return temp;
    }
    temp = GetParent(root->rightChild_, node);
    if (temp)
    {
        return temp;
    }
    return NULL;
}
template <class ElemType>
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::Copy(BinaryTreeNode<ElemType> *node)
{
    if (!node)
    {
        return NULL;
    }
    BinaryTreeNode<ElemType> *copy = new BinaryTreeNode<ElemType>(node->elem_);
    copy->leftChild_ = Copy(node->leftChild_);
    copy->rightChild_ = Copy(node->rightChild_);
    return copy;
}
template <class ElemType>
void BinaryTree<ElemType>::GetMirror(BinaryTreeNode<ElemType> *node)
{
    if (!node || (!node->leftChild_ && !node->rightChild_))
    {
        return;
    }
    BinaryTreeNode<ElemType> *temp = node->leftChild_;
    node->leftChild_ = node->rightChild_;
    node->rightChild_ = temp;
    if (node->leftChild_)
    {
        GetMirror(node->leftChild_);
    }
    if (node->rightChild_)
    {
        GetMirror(node->rightChild_);
    }
}
template <class ElemType>
BinaryTree<ElemType>::BinaryTree() : root_(NULL)
{
}
template <class ElemType>
BinaryTree<ElemType>::BinaryTree(const ElemType &elem)
{
    root_ = new BinaryTreeNode<ElemType>;
    root_->elem_ = elem;
}
template <class ElemType>
BinaryTree<ElemType>::BinaryTree(BinaryTreeNode<ElemType> *node)
{
    root_ = Copy(node);
}
template <class ElemType>
BinaryTree<ElemType>::BinaryTree(const BinaryTree<ElemType> &tree)
{
    root_ = new BinaryTreeNode<ElemType>;
    *this = tree;
}
template <class ElemType>
BinaryTree<ElemType>::~BinaryTree()
{
    Clear(root_);
}
template <class ElemType>
void BinaryTree<ElemType>::CreateByPreOrder(ElemType *elems, int length, ElemType &referenceValue)
{
    int index = 0;
    CreateByPreOrder(root_, elems, index, length, referenceValue);
}
template <class ElemType>
void BinaryTree<ElemType>::Clear()
{
    Clear(root_);
}
template <class ElemType>
bool BinaryTree<ElemType>::IsEmpty() const
{
    return root_ == NULL;
}
template <class ElemType>
void BinaryTree<ElemType>::PreOrderTraverse() const
{
    PreOrderTraverse(root_);
    cout << endl;
}
template <class ElemType>
void BinaryTree<ElemType>::InOrderTraverse() const
{
    InOrderTraverse(root_);
    cout << endl;
}
template <class ElemType>
void BinaryTree<ElemType>::PostOrderTraverse() const
{
    PostOrderTraverse(root_);
    cout << endl;
}
template <class ElemType>
void BinaryTree<ElemType>::LevelOrderTraverse() const
{
    queue<BinaryTreeNode<ElemType> *> queue;
    BinaryTreeNode<ElemType> *p;
    if (root_)
    {
        queue.push(root_);
    }
    while (!queue.empty())
    {
        p = queue.front();
        queue.pop();
        cout << p->elem_ << " ";
        if (p->leftChild_)
        {
            queue.push(p->leftChild_);
        }
        if (p->rightChild_)
        {
            queue.push(p->rightChild_);
        }
    }
    cout << endl;
}
template <class ElemType>
void BinaryTree<ElemType>::InsertLeftChild(BinaryTreeNode<ElemType> *node, const ElemType &elem)
{
    if (!node)
    {
        return;
    }
    BinaryTreeNode<ElemType> *q = new BinaryTreeNode<ElemType>(elem);
    if (node->leftChild_)
    {
        q->leftChild_ = node->leftChild_;
    }
    node->leftChild_ = q;
}
template <class ElemType>
void BinaryTree<ElemType>::InsertRightChild(BinaryTreeNode<ElemType> *node, const ElemType &elem)
{
    if (!node)
    {
        return;
    }
    BinaryTreeNode<ElemType> *q = new BinaryTreeNode<ElemType>(elem);
    if (node->rightChild_)
    {
        q->rightChild_ = node->rightChild_;
    }
    node->rightChild_ = q;
}
template <class ElemType>
void BinaryTree<ElemType>::DeleteLeftChild(BinaryTreeNode<ElemType> *node)
{
    Clear(node->leftChild_);
}
template <class ElemType>
void BinaryTree<ElemType>::DeleteRightChild(BinaryTreeNode<ElemType> *node)
{
    Clear(node->rightChild_);
}
template <class ElemType>
void BinaryTree<ElemType>::SetElem(BinaryTreeNode<ElemType> *node, const ElemType &elem)
{
    if (!node)
    {
        throw(string) "元素不存在。";
    }
    node->elem_ = elem;
}
template <class ElemType>
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::GetRoot() const
{
    return root_;
}
template <class ElemType>
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::GetNode(const ElemType &elem) const
{
    return GetNode(root_, elem);
}
template <class ElemType>
ElemType BinaryTree<ElemType>::GetElem(BinaryTreeNode<ElemType> *node) const
{
    if (!node)
    {
        throw(string) "元素不存在。";
    }
    return node->elem_;
}
template <class ElemType>
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::GetParent(const BinaryTreeNode<ElemType> *node) const
{
    return GetParent(root_, node);
}
template <class ElemType>
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::GetLeftChild(const BinaryTreeNode<ElemType> *node) const
{
    if (!node)
    {
        return NULL;
    }
    return node->leftChild_;
}
template <class ElemType>
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::GetRightChild(const BinaryTreeNode<ElemType> *node) const
{
    if (!node)
    {
        return NULL;
    }
    return node->rightChild_;
}
template <class ElemType>
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::GetLeftSibling(const BinaryTreeNode<ElemType> *node) const
{
    BinaryTreeNode<ElemType> *r = GetParent(root_, node);
    if (!r)
    {
        return NULL;
    }
    if (r->rightChild_ == node)
    {
        return r->leftChild_;
    }
    return NULL;
}
template <class ElemType>
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::GetRightSibling(const BinaryTreeNode<ElemType> *node) const
{
    BinaryTreeNode<ElemType> *r = GetParent(root_, node);
    if (!r)
    {
        return NULL;
    }
    if (r->leftChild_ == node)
    {
        return r->rightChild_;
    }
    return NULL;
}
template <class ElemType>
int BinaryTree<ElemType>::GetHeight() const
{
    return GetHeight(root_);
}
template <class ElemType>
int BinaryTree<ElemType>::GetWidth() const
{
    queue<BinaryTreeNode<ElemType> *> queue;
    BinaryTreeNode<ElemType> *temp;
    int maxWidth = 0;
    int number = 0;
    int nextNumber = 0;
    if (root_)
    {
        queue.push(root_);
        maxWidth = 1;
        number = 1;
    }
    while (!queue.empty())
    {
        nextNumber = 0;
        for (int i = 0; i < number; i++)
        {
            temp = queue.front();
            queue.pop();
            if (temp->leftChild_)
            {
                queue.push(temp->leftChild_);
                nextNumber++;
            }
            if (temp->rightChild_)
            {
                queue.push(temp->rightChild_);
                nextNumber++;
            }
        }
        number = nextNumber;
        if (nextNumber > maxWidth)
        {
            maxWidth = nextNumber;
        }
    }
    return maxWidth;
}
template <class ElemType>
int BinaryTree<ElemType>::GetNodeNumber() const
{
    return GetNodeNumber(root_);
}
template <class ElemType>
void BinaryTree<ElemType>::GetMirror()
{
    GetMirror(root_);
}
template <class ElemType>
BinaryTree<ElemType> &BinaryTree<ElemType>::operator=(const BinaryTree<ElemType> &tree)
{
    if (&tree != this)
    {
        Clear(root_);
        root_ = Copy(tree.root_);
    }
    return *this;
}
#endif