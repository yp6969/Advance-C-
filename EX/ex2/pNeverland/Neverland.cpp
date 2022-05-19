//
// Created by ypinhas on 5/14/2022.
//

#include <fstream>
#include "Neverland.h"

Neverland:: Neverland(){
    transport.insert({"bus", nullptr});
    transport.insert({"rail", nullptr});
    transport.insert({"tram", nullptr});
    transport.insert({"sprinter", nullptr});
}

void Neverland:: add_route(std::string from, std::string to, unsigned int time, string type){
    if(transport[type] == nullptr){
        transport[type] = std::make_shared<Graph<string, int>>();
    }
    transport[type]->add_node(from, to, time);
}

ostream& operator<<(ostream& os, const Neverland& N){
    for(auto m : N.transport){
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
    for(auto k : config.c){
        cout <<endl <<  k.first << " " << k.second << endl;
    }

}

void Neverland:: BFS(string type , string station  , map< string,bool>& reachables){
  for(auto s : transport[type]->graph[station]){
      if(!reachables[s.first]){
          reachables[s.first] = true;
          BFS(type , s.first , reachables);
      }

  }


}


void Neverland:: get_all_reachable_Stations(string source){
    map< string,bool> is_visited;
    for(auto t : transport){
        BFS(t.first , source , is_visited);
        cout << t.first  << ": " ;
        for(auto s : is_visited){
            if(s.first != source){
                cout  << s.first << "   " ;}
        }
        cout << endl;
        is_visited.clear();
    }
}


