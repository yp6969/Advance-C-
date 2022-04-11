//
// Created by ypinhas on 4/5/2022.
//

#ifndef VIRUSMUTATIONSIMULATION_SIMULATOR_H
#define VIRUSMUTATIONSIMULATION_SIMULATOR_H
#include <iostream>
#include <vector>
#include "SarsCov2.h"

using namespace std;

class Simulator {
    const int dimension;
    const int max_generations;
    const string& target;
    vector<SarsCov2> virus_list;

public:
    Simulator(const vector<string>& virus_list, int dimension, const string& target, int max_generations);
    ~Simulator();
    void init(const vector<string>& virus_list);
    void build_virus(const char& type, const string& gen);

};


#endif //VIRUSMUTATIONSIMULATION_SIMULATOR_H
