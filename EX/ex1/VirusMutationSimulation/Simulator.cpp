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
//        cout << "type = " << type << " " << "gen " << gen << endl;
        build_virus(type, gen);
        ss.str("");
    }
}

void Simulator::build_virus(const char& type, const string& gen){
    switch (type) {
        case 'a':
            virus_list.push_back(Alpha(gen));
        case 'd':
            virus_list.push_back(Delta(gen));
        case 'o':
            virus_list.push_back(Omicron(gen));


    }
}

Simulator::~Simulator()=default;
