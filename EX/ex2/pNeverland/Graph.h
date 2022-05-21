//
// Created by ypinhas on 5/11/2022.
//

#ifndef PNEVERLAND_GRAPH_H
#define PNEVERLAND_GRAPH_H
#include <vector>
#include <iostream>
#include <map>
#include "exceptions.h"

using namespace std;

template <typename V, typename E>
class Graph {
public:
    std::map<V, vector<pair<V, E>>> graph; // from: to, time
    Graph(): graph(){};
    ~Graph()= default;

    void add_node(V from, V to, E time);
    void update_node(V from, pair<V, E> p);
    bool is_node_exist(V node);
    vector<pair<V, E>>& get_node(V station_name) const;

    friend ostream& operator<<(ostream& os, const Graph<V, E>& graph)
    {
        for(auto const g: graph.graph){
            for(auto v: g.second){
                os << g.first << " --> " << v.first <<" " << v.second<< endl;
            }
            os << "\n";
        }
        return os;
    }

};

template <typename V, typename E>
void Graph<V,E>::add_node(V from, V to, E time){
    pair<V, E> p = make_pair(to, time);
    auto a = graph.find(from);
    if(a == graph.end()){
        graph.insert({from, vector<pair<V, E>>{p}});
    }
    else{
        update_node(from, p);
    }
}

template <typename V, typename E>
void Graph<V,E>::update_node(V from, pair<V, E> p){
    for(auto& e: graph[from]){
        if(e.first == p.first){
            e.second = e.second < p.second ? e.second: p.second; // the lower
            return;
        }
    }
    graph[from].emplace_back(p); // if dest not found
}

/**
     * checking if the node is exist in the graph
     * @param node
     * @return bool
     */
template <typename V, typename E>
bool Graph<V, E>::is_node_exist(V node){
    return graph.find(node) != graph.end();
}

/**
 * get the row of the wanted node
 * @tparam V
 * @tparam E
 * @param station_name
 * @return
 */
template <typename V, typename E>
vector<pair<V, E>>&  Graph<V,E>::get_node(V station_name) const{
    if(!graph.contains(station_name)){
        throw NeverlandException(station_name +
                                 " dose not exist in the current network. \n");
    }
    return graph[station_name];
}

#endif //PNEVERLAND_GRAPH_H
