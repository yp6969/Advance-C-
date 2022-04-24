//
// Created by ypinhas on 4/5/2022.
//

#ifndef VIRUSMUTATIONSIMULATION_SIMULATOR_H
#define VIRUSMUTATIONSIMULATION_SIMULATOR_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <random>
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
    void build_virus(pair<string, int>& virus);
    void sort();

    void tick();
    void group_update();
    void delete_to_lowest();
    void gen_exchange(SarsCov2 *virus1, SarsCov2 *virus2, int index1, int index2);
    void private_viruses_update();

    void print_viruses() const;
    void print_ancestors() const;
    friend ostream &operator<<(ostream &os, const pair<string, int> &ancestor);
    void print_strongest();
    void summery();
};

#endif //VIRUSMUTATIONSIMULATION_SIMULATOR_H
