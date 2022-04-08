//
// Created by ypinhas on 4/5/2022.
//

#ifndef VIRUSMUTATIONSIMULATION_SIMULATOR_H
#define VIRUSMUTATIONSIMULATION_SIMULATOR_H
#include <vector>
#include "SarsCov2.h"

using namespace std;

class Simulator {
    int dimension;
    string& target;
    vector<SarsCov2> virus_list;
    int max_generations;

public:
    Simulator(const vector<string>& gen_list, const int dimension, const string& target, const int max_gen);
    ~Simulator();
    void init(const vector<string>& gen_list, const int dimension, const string& target, const int max_gen);



};


#endif //VIRUSMUTATIONSIMULATION_SIMULATOR_H
