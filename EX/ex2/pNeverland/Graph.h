//
// Created by ypinhas on 5/11/2022.
//

#ifndef PNEVERLAND_GRAPH_H
#define PNEVERLAND_GRAPH_H
#include "Matrix2D.h"

template <typename V, typename E>
class Graph {
public:
    std::vector<V> vertices;
    SquareMatrix2D<E> edge;
    Graph();
    ~Graph();

    void add_node();
};


#endif //PNEVERLAND_GRAPH_H
