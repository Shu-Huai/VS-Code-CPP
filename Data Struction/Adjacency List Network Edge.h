#pragma once
#ifndef __ADJACENCY_LIST_NETWORK_EDGE_H__
#define __ADJACENCY_LIST_NETWORK_EDGE_H__
#include <iostream>
template <class WeightType>
class AdjacencyListNetworkEdge
{
public:
    int vertex_;
    WeightType weight_;
    AdjacencyListNetworkEdge<WeightType> *nextEdge_;
    AdjacencyListNetworkEdge();
    AdjacencyListNetworkEdge(int vertex, WeightType weight, AdjacencyListNetworkEdge<WeightType> *nextEdge = NULL);
};
template <class WeightType>
AdjacencyListNetworkEdge<WeightType>::AdjacencyListNetworkEdge() : vertex_(-1)
{
}
template <class WeightType>
AdjacencyListNetworkEdge<WeightType>::AdjacencyListNetworkEdge(int vertex, WeightType weight, AdjacencyListNetworkEdge<WeightType> *nextEdge)
    : vertex_(vertex), weight_(weight), nextEdge_(nextEdge)
{
}
#endif