#pragma once
#ifndef __LINK_LIST_NODE_H__
#define __LINK_LIST_NODE_H__
#include <iostream>
template <class ElemType>
class LinkListNode
{
public:
    ElemType elem_;
    LinkListNode<ElemType> *next_;
    LinkListNode();
    LinkListNode(ElemType data, LinkListNode<ElemType> *next = NULL);
};
template <class ElemType>
LinkListNode<ElemType>::LinkListNode() : next_(NULL)
{
}
template <class ElemType>
LinkListNode<ElemType>::LinkListNode(ElemType data, LinkListNode<ElemType> *next) : elem_(data), next_(next)
{
}
#endif
