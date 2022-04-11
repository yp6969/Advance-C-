//
// Created by ypinhas on 4/5/2022.
//

#include <sstream>
#include "Simulator.h"
#include "Alpha.h"
#include "Delta.h"
#include "Omicron.h"

Simulator::Simulator(const vector<string>& virus_list, const int dimension, const string& target, const int max_generations)
: dimension(dimension), target(target), max_generations(max_generations)
{
    init(virus_list);
}

void Simulator::init(const vector<string> &virus_str) {
    stringstream ss;
    char type;
    string gen;
    for(const string& s: virus_str){
        type = s[0];
        gen = s.substr(1);
        build_virus(type, gen);
        ss.str("");

//        cout << "type = " << type << " " << "gen " << gen << endl;
    }

//    Omicron q(gen);
//    cout << q << endl;
//    virus_list.push_back(new Omicron(gen));

    for(SarsCov2* v: virus_list){
        cout << *v << endl;
    }
}

void Simulator::build_virus(const char& type, const string& gen){
    switch (type) {
        case 'a':
            virus_list.push_back(new Alpha(gen));
            break;
        case 'd':
            virus_list.push_back(new Delta(gen));
            break;
        case 'o':
            virus_list.push_back(new Omicron(gen));
            break;
        default:
            return;
    }
}

Simulator::~Simulator()=default;
