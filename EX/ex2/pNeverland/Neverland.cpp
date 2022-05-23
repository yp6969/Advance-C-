//
// Created by ypinhas on 5/14/2022.
//

#include <fstream>
#include <utility>
#include "Neverland.h"

Neverland:: Neverland(): outputfile_name("output.dat"){
    transport.insert({"bus", nullptr});
    transport.insert({"rail", nullptr});
    transport.insert({"tram", nullptr});
    transport.insert({"sprinter", nullptr});
}

void Neverland:: add_route(const string& from, const string& to, unsigned int time, const string& type){
    if(transport[type] == nullptr){
        transport[type] = std::make_shared<Graph<string, int>>();
    }
    transport[type]->add_node(from, to, time);
}

ostream& operator<<(ostream& os, const Neverland& N){
    for(const auto& m : N.transport){
        os << endl;
        cout << m.first << "\n" << *(m.second.get())<< "\n";
    }
    return os;
}

void Neverland::update_config(string& file_name) {
    ifstream my_file(file_name);             /// OPEN FILE
    if(!my_file){
        cout << file_name;
        throw NeverlandException(" ERROR: file " + file_name +" 1cannot open\n");
    }

    string type;
    string time;
    while(my_file >> type){
        my_file >> time;
        config[type] = stoi(time);
    }
    my_file.close();

}

void Neverland::print_configuration(){
    for(const auto& k : config.c){
        cout <<  k.first << " " << k.second << endl;
    }
}

/**
 * finds the reachable nodes from station
 * @param type
 * @param station
 * @param reachables
 */
void Neverland:: BFS(const string& type ,const string& station  , map< string,bool>& reachables ){
  for(const auto& s :o_transport.empty()? transport[type]->graph[station]:o_transport[type].graph[station]){
      if(!reachables[s.first]){
          reachables[s.first] = true;
          BFS(type , s.first , reachables);
      }
  }
}

void Neverland::inbound_outbound(const string& station ,const string& func){
    if(func == "inbound"){ // MAKING OPPOSITE MAP OF TRANSPORTS
        for(auto &v: transport){ // loop on vehicles
            for(auto &s : v.second->graph){ // loop on each station
                for(auto &s1 : s.second){ // loop on each station that connect to s
                    o_transport[v.first].add_node(s1.first , s.first , 0  );
                }
            }
        }
    }
    map<string,bool> is_visited1;
    for(const auto &t : transport){ // loop on vehicles
        BFS(t.first , station , is_visited1  );
        cout << t.first  << ": " ;
        if(!is_visited1.empty()){
            for(const auto& s : is_visited1){
                if(s.first != station){
                    cout  << s.first << "   " ;}
            }}
        else{
            cout << "no outbound travel";
        }
        cout << endl;
        is_visited1.clear();
    }
    if(func == "inbound"){
        o_transport.clear();}
}

void Neverland::set_outputfile(string filename) {
    this->outputfile_name = move(filename);
}

/**
 * search if the from is exist in the graph as source node
 * @param from
 * @return
 */
bool Neverland::is_from_exist(const string& from){
    for(const auto& vehicle: transport)
        if(vehicle.second->is_from_exist(from) == true) return true;
    return false;
}

/**
 * search if the node exist in the graph as destination node
 * @param to
 * @return
 */
bool Neverland::is_to_exist(const string& node){
    for(const auto &vehicle: transport)
        if(vehicle.second->is_to_exist(node) == true) return true;
    return false;
}

/**
 * calculate for each vehicle the shortest path
 */
void Neverland::uniExpress(const string& from, const string& to){
//    if(!is_from_exist(from)) throw NodeNotExistException(from);
//    if(!is_to_exist(to)) throw NodeNotExistException(to);
//    TODO - make move operation to Graph
//    Graph<string, int> g = create_dijkstra_graph(*transport["bus"].get());
    dijkstra(*transport["bus"].get(), from, config["bus"]);
    cout << "success" << endl;
}

/**
 * get the lowest element in the map
 * @param vertices
 * @return
 */
string get_lowest(map<string, pair<int, bool>> &vertices){
    string s = vertices.begin()->first;
    int n = -1;
    for(const auto& v: vertices){
        if(v.second.first < 0 || v.second.second == true) continue;
        if(v.second.first <= n || n < 0){
            s = v.first;
            n = v.second.first;
        }
    }
    return s;
}

/**
 * implementing the dijkstra algorithm to the graph
 * @param G
 * @param source
 */
void Neverland::dijkstra(Graph<string, int>& G, const string& source, const int& halt_time){
    map<string, pair<int, bool>> vertices = create_dijkstra_map(G);
    vertices[source].first = 0;
    for(const auto& v: vertices){
        string lowest = get_lowest(vertices);
        try{
//            vector<pair<string, int>>& lowest_node = G[lowest];
            for(const auto& u: G[lowest]){
                if(vertices[u.first].second == true) continue;
                else if(vertices[u.first].first == -1){
                    vertices[u.first].first = vertices[lowest].first + u.second + halt_time;
                }
                else{
                    int distance = vertices[lowest].first + u.second + halt_time;
                    if(distance < vertices[u.first].first){
                        vertices[u.first].first = distance;
                    }
                }
            }
        }
        catch(DeadEndNodeException& e){
            cout << "dead end" << endl;
//            vertices[lowest].second = true;
//            continue;
        }
        vertices[lowest].second = true;
    }
    for(const auto& v: vertices)
        cout << v.first << " " << v.second.first << " " << v.second.second << endl;
}

/**
 * create a map for dijkstra algorithm <name, total_time, is_checked>
 * @param G
 * @return
 */
map<string, pair<int, bool>> Neverland::create_dijkstra_map(const Graph<string, int>& G){
    map<string, pair<int, bool>> short_graph;
    for(const auto& dest: G.graph){
        short_graph[dest.first] = make_pair(-1, false);
        for(const auto& v: dest.second){
            short_graph[v.first] = make_pair(-1, false);
        }
    }
    return short_graph;
}