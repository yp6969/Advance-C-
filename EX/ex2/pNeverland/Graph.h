//
// Created by ypinhas on 5/11/2022.
//

#ifndef PNEVERLAND_GRAPH_H
#define PNEVERLAND_GRAPH_H
#include "Matrix2D.h"
#include <vector>
#include <map>
#include "exceptions.h"

using namespace std;

template <typename V, typename E>
class Graph {
public:
    std::map<V, vector<pair<V, E>>> graph;
    Graph();
    ~Graph();

    /**
     * adding element to the graph
     * @param from
     * @param to
     * @param time
     */
    void add_node(V from, V to, E time){
        pair<V, E> p = make_pair(to, time);
        if(graph.contains(from)){
            update_node(from, p);
        }
        else{
            graph.insert({from, vector<pair<V, E>>{p}});
        }
    }

    /**
     * update node in the map
     * assume that map contains from
     * @param from
     * @param p
     */
    void update_node(V from, pair<V, E> p){
        for(auto e: graph[from]){
            if(e.first == p.first){
                e.secound = e.secound < p.second ? e.secound: p.secound; // the lower
                return;
            }
        }
        graph[from].emplace_back(p); // if dest not found
    }

    /**
     * search for the node by its name
     * @param station_name
     * @return the vector for the specific node
     */
    vector<pair<V, E>>& get_node(V station_name) const{
        if(!graph.contains(station_name)){
            throw NeverlandException(station_name +
            " dose not exist in the current network. \n");
        }
        return graph[station_name];
    }




};


#endif //PNEVERLAND_GRAPH_H
