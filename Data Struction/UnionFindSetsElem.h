#pragma once
#ifndef __UNION_FIND_SETS_ELEM_H__
#define __UNION_FIND_SETS_ELEM_H__
#include "Assistance.h"
template <class ElemType>
class UnionFindSetsElem
{
public:
    ElemType data_;
    int parent_;
    UnionFindSetsElem();
    Status SetData(ElemType data);
    Status SetParent(int parent);
    ElemType GetData() const;
    int GetParent() const;
};
template <class ElemType>
UnionFindSetsElem<ElemType>::UnionFindSetsElem()
{
}
template <class ElemType>
Status UnionFindSetsElem<ElemType>::SetData(ElemType data)
{
    data_ = data;
    return SUCCESS;
}
template <class ElemType>
Status UnionFindSetsElem<ElemType>::SetParent(int parent)
{
    parent_ = parent;
    return SUCCESS;
}
template <class ElemType>
ElemType UnionFindSetsElem<ElemType>::GetData() const
{
    return data_;
}
template <class ElemType>
int UnionFindSetsElem<ElemType>::GetParent() const
{
    return parent_;
}
#endif