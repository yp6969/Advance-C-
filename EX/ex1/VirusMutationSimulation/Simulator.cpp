//
// Created by ypinhas on 4/5/2022.
//

#include <sstream>
#include "Simulator.h"
#include "Alpha.h"
#include "Delta.h"
#include "Omicron.h"

Simulator::Simulator(const vector<string>& viruses, const int dimension, const string& target, const int max_generations)
: dimension(dimension), target(target), max_generations(max_generations)
{
    init(viruses);
}

void Simulator::init(const vector<string>& viruses) {
    /**
     * init the simulator
     */
    init_ancestors(viruses);
    init_virus_list();

    sort();
    delete virus_list[0];
    virus_list.erase(virus_list.begin());


    auto p = pair<string, int>("sdf", 3);
    vector<SarsCov2*> v{};
    v.push_back(new Delta(&p));
    cout << *v[0] << endl;
    delete v[0];
//    delete virus_list[1];
//    virus_list[0]->getAncestor()->second--;
//    SarsCov2* a =  virus_list[2];
//    delete a;


    for(auto v: virus_list){
        cout << *v << " taget: " << v->strength(target) <<endl;
    }

    for(auto p: ancestors){
        cout << p.first << " " << p.second << endl;
    }
}

void Simulator::init_ancestors(const vector<string> &viruses) {
    /**
     * initialize the nacestors list
     */
    for(string virus: viruses) {
        ancestors.push_back(make_pair(virus, 1));
    }
}

void Simulator::init_virus_list() {
    char type;
    for(auto& virus: ancestors){
        type = virus.first[0];
        build_virus(type, virus);
    }
}
void Simulator::build_virus(char type, pair<string, int>& virus){

    switch (type) {
        case 'a':
            virus_list.push_back(new Alpha(&virus));
            break;
        case 'd':
            virus_list.push_back(new Delta(&virus));
            break;
        case 'o':
            virus_list.push_back(new Omicron(&virus));
            break;
        default:
            return;
    }
}

void Simulator::sort() {
    /**
     * sort the virus list by its strength
     */
//    std::sort(virus_list.begin(), virus_list.end());
    std::sort(virus_list.begin(), virus_list.end(),
              [this](const SarsCov2* a, const SarsCov2* b)
              { return a->strength(this->target) < b->strength(this->target); } );

}



Simulator::~Simulator()=default;
