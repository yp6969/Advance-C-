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
    SquareMatrix2D<E> edges;
    Graph();
    ~Graph();

    void add_node();


    V& get_vertice(unsigned int i) const{
        return vertices[i];
    }

    E& get_edge(unsigned int x, unsigned int y) const {
        return edges(x, y);
    }


};


#endif //PNEVERLAND_GRAPH_H
