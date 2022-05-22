//
// Created by ypinhas on 5/14/2022.
//

#include <fstream>
#include <utility>
#include "Neverland.h"

const int MAX = 1000000;


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
        cout << type << " " << config[type] << endl;
    }
    my_file.close();

}

void Neverland::print_configuration(){
    for(const auto& k : config.c){
        cout <<  k.first << " " << k.second << endl;
    }
}

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
    map< string,bool> is_visited1;
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


void is_from_exist(const string& node){
//    for()
}


/**
 * calculate for each vehicle the shortest path
 */
void uniExpress(const string& from, const string& to){

}











void Neverland::BFS1(const string& type  , const string& station , const string& prev_station  , map<string , bool>& reachable,map < string ,int > & route){
    for(const auto& s : transport[type]->graph[station]){
        if(route[prev_station] + s.second < route[s.first] ){
            route[s.first] = route[prev_station] + s.second;
        }
        if(!reachable[s.first]){
            reachable[s.first] = true;
            BFS1(type , s.first , s.first , reachable , route);
        }
    }
}


void Neverland:: set_max_time_route(const string& type ,const string& station, map <string , int >& route){

    for (const auto& t: transport[type]->graph[station]){
        if(route.find(t.first) == route.end()){
            route[t.first] = MAX;
            set_max_time_route(type , t.first , route);
        }
    }
}

void Neverland::uniExpress_multiExpress(const string& func , const string& source , const string& destination){
    map<string , bool> reachable; // < station , is visited>
    map < string ,int > route;  // < station , route time from source  >
    for(const auto& t : transport){  // loop on vehicles
        route[source] = 0 ;
        set_max_time_route(t.first , source , route); // set distance to MAX int to all te reachable stations from source
        BFS1(t.first , source  , source , reachable , route);
        cout << t.first << ": " << endl;
        if(route.find(destination) != route.end()) {
            cout << source << "--> " << destination << " = " << route[destination]<< endl;
        } else{
            cout << "route not found" << endl;
        }
        reachable.clear();
        route.clear();
    }

}
