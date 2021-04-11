#pragma once
#ifndef __CHILD_SIBLING_TREE_H__
#define __CHILD_SIBLING_TREE_H__
#include "ChildSiblingTreeNode.h"
#include "LinkQueue.h"
template <class ElemType>
class ChildSiblingTree
{
protected:
    ChildSiblingTreeNode<ElemType> *root_;
    ChildSiblingTreeNode<ElemType> *Copy(ChildSiblingTreeNode<ElemType> *root);
    ChildSiblingTreeNode<ElemType> *Create(ElemType *datas, int *parents, int n, int rootIndex);
    void Destroy(ChildSiblingTreeNode<ElemType> *&root);
    void PreOrder(ChildSiblingTreeNode<ElemType> *root, void (*Visit)(const ElemType &)) const;
    void PostOrder(ChildSiblingTreeNode<ElemType> *root, void (*Visit)(const ElemType &)) const;
    ChildSiblingTreeNode<ElemType> *GetParent(ChildSiblingTreeNode<ElemType> *root, ChildSiblingTreeNode<ElemType> *CSTN) const;
    int GetDegree(ChildSiblingTreeNode<ElemType> *root) const;
    int GetHeight(ChildSiblingTreeNode<ElemType> *root) const;
    int GetNodeDegree(ChildSiblingTreeNode<ElemType> *root) const;
    int GetNodeNumber(ChildSiblingTreeNode<ElemType> *root) const;

public:
    ChildSiblingTree();
    ChildSiblingTree(const ElemType &e);
    ChildSiblingTree(ChildSiblingTreeNode<ElemType> *root);
    ChildSiblingTree(ElemType *datas, int *parents, int n);
    ChildSiblingTree(const ChildSiblingTree<ElemType> &CST);
    virtual ~ChildSiblingTree();
    bool IsEmpty() const;
    void PreOrder(void (*Visit)(const ElemType &)) const;
    void PostOrder(void (*Visit)(const ElemType &)) const;
    ChildSiblingTreeNode<ElemType> *GetFirstChild(ChildSiblingTreeNode<ElemType> *CSTN) const;
    ChildSiblingTreeNode<ElemType> *GetNextSibling(ChildSiblingTreeNode<ElemType> *CSTN) const;
    ChildSiblingTreeNode<ElemType> *GetParent(ChildSiblingTreeNode<ElemType> *CSTN) const;
    ChildSiblingTreeNode<ElemType> *GetRoot() const;
    int GetDegree() const;
    int GetHeight() const;
    int GetNodeNumber() const;
    Status InsertChild(ChildSiblingTreeNode<ElemType> *CSTN, int position, const ElemType &e);
    Status DeleteChild(ChildSiblingTreeNode<ElemType> *CSTN, int position, ElemType &e);
    Status SetElem(ChildSiblingTreeNode<ElemType> *CSTN, const ElemType &e);
    Status GetElem(ChildSiblingTreeNode<ElemType> *CSTN, ElemType &e) const;
    ChildSiblingTree<ElemType> &operator=(const ChildSiblingTree<ElemType> &CST);
};
template <class ElemType>
ChildSiblingTreeNode<ElemType> *ChildSiblingTree<ElemType>::Copy(ChildSiblingTreeNode<ElemType> *CSTN)
{
    if (!CSTN)
    {
        return NULL;
    }
    ChildSiblingTreeNode<ElemType> *root = new ChildSiblingTreeNode<ElemType>(CSTN->data_);
    ChildSiblingTreeNode<ElemType> *p = CSTN->firstChild_;
    ChildSiblingTreeNode<ElemType> *q = NULL;
    while (p)
    {
        ChildSiblingTreeNode<ElemType> *subTreeRoot = Copy(p);
        if (!root->firstChild_)
        {
            root->firstChild_ = subTreeRoot;
        }
        else
        {
            q->nextSibling_ = subTreeRoot;
        }
        q = subTreeRoot;
        p = p->nextSibling_;
    }
    return root;
}
template <class ElemType>
ChildSiblingTreeNode<ElemType> *ChildSiblingTree<ElemType>::Create(ElemType *datas, int *parents, int n, int rootIndex)
{
    if (rootIndex >= 0 && rootIndex < n)
    {
        ChildSiblingTreeNode<ElemType> *root = new ChildSiblingTreeNode<ElemType>(datas[rootIndex]);
        ChildSiblingTreeNode<ElemType> *subRoot;
        ChildSiblingTreeNode<ElemType> *p = NULL;
        for (int i = 0; i < n; i++)
        {
            if (parents[i] == rootIndex)
            {
                subRoot = Create(datas, parents, n, i);
                if (!root->firstChild_)
                {
                    root->firstChild_ = subRoot;
                }
                else
                {
                    p->nextSibling_ = subRoot;
                }
                p = subRoot;
            }
        }
        return root;
    }
    return NULL;
}
template <class ElemType>
void ChildSiblingTree<ElemType>::Destroy(ChildSiblingTreeNode<ElemType> *&root)
{
    if (root)
    {
        Destroy(root->firstChild_);
        Destroy(root->nextSibling_);
        delete root;
        root = NULL;
    }
}
template <class ElemType>
void ChildSiblingTree<ElemType>::PreOrder(ChildSiblingTreeNode<ElemType> *root, void (*Visit)(const ElemType &)) const
{
    if (root)
    {
        (*Visit)(root->data_);
        ChildSiblingTreeNode<ElemType> *p = root->firstChild_;
        while (p)
        {
            PreOrder(p, Visit);
            p = p->nextSibling_;
        }
    }
}
template <class ElemType>
void ChildSiblingTree<ElemType>::PostOrder(ChildSiblingTreeNode<ElemType> *root, void (*Visit)(const ElemType &)) const
{
    if (root)
    {
        ChildSiblingTreeNode<ElemType> *p = root->firstChild_;
        while (p)
        {
            PostOrder(p, Visit);
            p = p->nextSibling_;
        }
        (*Visit)(root->data);
    }
}
template <class ElemType>
ChildSiblingTreeNode<ElemType> *ChildSiblingTree<ElemType>::GetParent(ChildSiblingTreeNode<ElemType> *root, ChildSiblingTreeNode<ElemType> *CSTN) const
{
    if (!root)
    {
        return NULL;
    }
    ChildSiblingTreeNode<ElemType> *p = root->firstChild_;
    while (p)
    {
        if (p == CSTN)
        {
            return root;
        }
        p = p->nextSibling_;
    }
    p = root->firstChild_;
    while (p)
    {
        ChildSiblingTreeNode<ElemType> *q = GetParent(p, CSTN);
        if (q)
        {
            return q;
        }
        p = p->nextSibling_;
    }
    return NULL;
}
template <class ElemType>
int ChildSiblingTree<ElemType>::GetDegree(ChildSiblingTreeNode<ElemType> *root) const
{
    if (!root)
    {
        return 0;
    }
    ChildSiblingTreeNode<ElemType> *p = root->firstChild_;
    int maxDegree = GetNodeDegree(root);
    while (p)
    {
        int degree = GetDegree(p);
        maxDegree = maxDegree > degree ? maxDegree : degree;
        p = p->nextSibling_;
    }
    return maxDegree;
}
template <class ElemType>
int ChildSiblingTree<ElemType>::GetHeight(ChildSiblingTreeNode<ElemType> *root) const
{
    if (!root)
    {
        return 0;
    }
    ChildSiblingTreeNode<ElemType> *p = root->firstChild_;
    int maxHeight = 0;
    while (p)
    {
        int height = GetHeight(p);
        maxHeight = maxHeight > height ? maxHeight : height;
        p = p->nextSibling_;
    }
    return maxHeight + 1;
}
template <class ElemType>
int ChildSiblingTree<ElemType>::GetNodeDegree(ChildSiblingTreeNode<ElemType> *root) const
{
    if (!root)
    {
        return 0;
    }
    ChildSiblingTreeNode<ElemType> *p = root->firstChild_;
    int count = 0;
    while (p)
    {
        count++;
        p = p->nextSibling_;
    }
    return count;
}
template <class ElemType>
int ChildSiblingTree<ElemType>::GetNodeNumber(ChildSiblingTreeNode<ElemType> *root) const
{
    if (!root)
    {
        return 0;
    }
    return GetNodeNumber(root->firstChild_) + GetNodeNumber(root->nextSibling_) + 1;
}
template <class ElemType>
ChildSiblingTree<ElemType>::ChildSiblingTree() : root_(NULL)
{
}
template <class ElemType>
ChildSiblingTree<ElemType>::ChildSiblingTree(const ElemType &e)
{
    root_ = new ChildSiblingTreeNode<ElemType>(e);
}
template <class ElemType>
ChildSiblingTree<ElemType>::ChildSiblingTree(ChildSiblingTreeNode<ElemType> *root) : root_(root)
{
}
template <class ElemType>
ChildSiblingTree<ElemType>::ChildSiblingTree(ElemType *datas, int *parents, int n)
{
    root_ = Create(datas, parents, n, 0);
}
template <class ElemType>
ChildSiblingTree<ElemType>::ChildSiblingTree(const ChildSiblingTree<ElemType> &CST)
{
    root_ = Copy(CST.GetRoot());
}
template <class ElemType>
ChildSiblingTree<ElemType>::~ChildSiblingTree()
{
    Destroy(root_);
}
template <class ElemType>
bool ChildSiblingTree<ElemType>::IsEmpty() const
{
    return root_ == NULL;
}
template <class ElemType>
void ChildSiblingTree<ElemType>::PreOrder(void (*Visit)(const ElemType &)) const
{
    PreRootOrder(root_, Visit);
}
template <class ElemType>
void ChildSiblingTree<ElemType>::PostOrder(void (*Visit)(const ElemType &)) const
{
    PostOrder(root_, Visit);
}
template <class ElemType>
ChildSiblingTreeNode<ElemType> *ChildSiblingTree<ElemType>::GetFirstChild(ChildSiblingTreeNode<ElemType> *CSTN) const
{
    return CSTN ? CSTN->firstChild_ : NULL;
}
template <class ElemType>
ChildSiblingTreeNode<ElemType> *ChildSiblingTree<ElemType>::GetNextSibling(ChildSiblingTreeNode<ElemType> *CSTN) const
{
    return CSTN ? CSTN->nextSibling_ : NULL;
}
template <class ElemType>
ChildSiblingTreeNode<ElemType> *ChildSiblingTree<ElemType>::GetParent(ChildSiblingTreeNode<ElemType> *CSTN) const
{
    return GetParent(root_, CSTN);
}
template <class ElemType>
ChildSiblingTreeNode<ElemType> *ChildSiblingTree<ElemType>::GetRoot() const
{
    return root_;
}
template <class ElemType>
int ChildSiblingTree<ElemType>::GetDegree() const
{
    return GetDegree(root_);
}
template <class ElemType>
int ChildSiblingTree<ElemType>::GetHeight() const
{
    return GetHeight(root_);
}
template <class ElemType>
int ChildSiblingTree<ElemType>::GetNodeNumber() const
{
    return GetNodeNumber(root_);
}
template <class ElemType>
Status ChildSiblingTree<ElemType>::InsertChild(ChildSiblingTreeNode<ElemType> *CSTN, int position, const ElemType &e)
{
    if (!CSTN)
    {
        return UNDER_FLOW;
    }
    if (position < 1 || position > GetNodeDegree(CSTN) + 1)
    {
        return RANGE_ERROR;
    }
    ChildSiblingTreeNode<ElemType> *q = new ChildSiblingTreeNode<ElemType>(e);
    if (position == 1)
    {
        q->nextSibling_ = CSTN->firstChild_;
        CSTN->firstChild_ = q;
    }
    else
    {
        ChildSiblingTreeNode<ElemType> *p = CSTN->firstChild_;
        for (int i = 1; i < position - 1; i++)
        {
            p = p->nextSibling_;
        }
        q->nextSibling_ = p->nextSibling_;
        p->nextSibling_ = q;
    }
    return SUCCESS;
}
template <class ElemType>
Status ChildSiblingTree<ElemType>::DeleteChild(ChildSiblingTreeNode<ElemType> *CSTN, int position, ElemType &e)
{
    if (!CSTN)
    {
        return UNDER_FLOW;
    }
    ChildSiblingTreeNode<ElemType> *p, *q;
    if (position < 0 || position > GetNodeDegree(CSTN))
    {
        return UNDER_FLOW;
    }
    if (position == 1)
    {
        q = CSTN->firstChild_;
        CSTN->firstChild_ = q->nextSibling_;
    }
    else
    {
        p = CSTN->firstChild_;
        for (int i = 1; i < i - 1; i++)
        {
            p = p->nextSibling_;
        }
        q = p->nextSibling_;
        p->nextSibling_ = q->nextSibling_;
    }
    e = q->data_;
    Destroy(q);
    return SUCCESS;
}
template <class ElemType>
Status ChildSiblingTree<ElemType>::SetElem(ChildSiblingTreeNode<ElemType> *CSTN, const ElemType &e)
{
    if (!CSTN)
    {
        return UNDER_FLOW;
    }
    CSTN->data_ = e;
    return SUCCESS;
}
template <class ElemType>
Status ChildSiblingTree<ElemType>::GetElem(ChildSiblingTreeNode<ElemType> *CSTN, ElemType &e) const
{
    if (!CSTN)
    {
        return UNDER_FLOW;
    }
    e = CSTN->data_;
    return SUCCESS;
}
template <class ElemType>
ChildSiblingTree<ElemType> &ChildSiblingTree<ElemType>::operator=(const ChildSiblingTree<ElemType> &CST)
{
    if (&CST != this)
    {
        Destroy(root_);
        root_ = Copy(CST.GetRoot());
    }
    return *this;
}
#endif