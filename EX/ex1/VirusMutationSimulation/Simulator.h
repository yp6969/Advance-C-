//
// Created by ypinhas on 4/5/2022.
//

#ifndef VIRUSMUTATIONSIMULATION_SIMULATOR_H
#define VIRUSMUTATIONSIMULATION_SIMULATOR_H
#include <iostream>
#include <vector>
#include <algorithm>
#include "SarsCov2.h"


using namespace std;

class Simulator {
    const int dimension;
    const int max_generations;
    const string& target;
    vector<SarsCov2*> virus_list;
    vector<pair<string, int>> ancestors;


public:
    Simulator(const vector<string>& viruses, int dimension, const string& target, int max_generations);
    virtual ~Simulator();
    void init(const vector<string>& virus_list);
    void init_ancestors(const vector<string>& virus_list);
    void init_virus_list();
    void build_virus(char type, pair<string, int>& virus);
    void sort();


};

#endif //VIRUSMUTATIONSIMULATION_SIMULATOR_H
