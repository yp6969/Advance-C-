//
// Created by ypinhas on 5/14/2022.
//

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
    {
        for(auto m : N.transport){
            os << endl;
            cout << m.first << "\n" << *(m.second.get())<< "\n";
        }
        return os;
    }
}