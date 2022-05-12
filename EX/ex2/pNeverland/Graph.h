//
// Created by ypinhas on 5/11/2022.
//

#ifndef PNEVERLAND_GRAPH_H
#define PNEVERLAND_GRAPH_H
#include "Matrix2D.h"

template <typename E, typename V>
class Graph {
private:
    std::vector<E> vertice;
    SquareMatrix2D<V> edge;
public:
    Graph();
    ~Graph();

    void add_node();
};


#endif //PNEVERLAND_GRAPH_H
