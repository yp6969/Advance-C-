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

//    tick();
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
    for(auto& virus: ancestors){
        build_virus(virus);
    }
}
void Simulator::build_virus(pair<string, int>& virus){
    /**
     * build virus list
     */
    char type = virus.first[0];
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
    std::sort(virus_list.begin(), virus_list.end(),
              [this](const SarsCov2* a, const SarsCov2* b)
              { return a->strength(this->target) < b->strength(this->target); } );

}



Simulator::~Simulator(){
        for(auto v: virus_list){
            delete v;
        }
}

void Simulator::delete_to_lowest() {
    /**
     * delete the two lowest strength viruses
     */
    sort();
    delete virus_list[0];
    delete virus_list[1];
    virus_list.erase(virus_list.begin());
    virus_list.erase(virus_list.begin());
}

void Simulator::group_update() {
    /**
     * pick tow random ancestors build from them viruses and do gen
     * exchange between them.
     */
    auto len = ancestors.size();
    srand (time(nullptr));
    int virus1 = rand() % len;
    int virus2;
    srand (time(nullptr));
    do{
        virus2 = rand() % len;
    }while(virus1 == virus2);

    srand (time(nullptr));

    int index1 = rand() % (dimension - 2);
    int index2 = rand() % (dimension - (index1 + 1) -1) + index1 + 1;

//    cout << "index1 = " << index1 << " index2 = " << index2 << " " << endl;

    build_virus(ancestors[virus1]);
    build_virus(ancestors[virus2]);

    ancestors[virus1].second++;
    ancestors[virus2].second++;

    len = virus_list.size();
    gen_exchange(virus_list[len-1], virus_list[len-2], index1, index2);
}

void Simulator::private_viruses_update(){
    /**
     * preform private update on all the viruses
     */
    for(auto v: virus_list){
        v->private_update();
    }
}

void Simulator::gen_exchange(SarsCov2* virus1, SarsCov2* virus2, int index1, int index2){
    /**
     * exchange the gen between tow viruses
     */
    string sub1 = virus1->getGen().substr(index1+1, index2-index1);
    string sub2 = virus2->getGen().substr(index1+1, index2-index1);
    string s = virus1->getGen();
    string s2 = virus2->getGen();
    s.replace(index1+1, index2 - index1, sub2);
    s2.replace(index1+1, index2 - index1, sub1);
    virus1->setGen(s);
    virus2->setGen(s2);
}

void Simulator::tick() {
    int generations = 0;
    unsigned int len = virus_list.size();
    while((virus_list[len-1]->strength(target) != 1) && (generations < max_generations)){
        private_viruses_update();
        delete_to_lowest();
        group_update();
        generations++;
        sort();
        summery();
        sleep(2);
    }
}

void Simulator::print_viruses() const {
    for(auto v: virus_list){
        cout << *v << endl;
    }
}

ostream &operator<<(ostream &os, const pair<string, int> &ancestor) {
    for(char c: ancestor.first){
        os << c << " ";
    }
    os << ancestor.second << " ";
    return os;
}

void Simulator::print_ancestors() const {
    /**
     * print the ancestors
     */
    for(const auto& p: ancestors){
        cout << p << endl;
    }
}

void Simulator::print_strongest(){
    unsigned int len = virus_list.size();
    cout << *virus_list[len-1];
}

void Simulator::summery(){
    print_viruses();
    cout << endl;
    print_ancestors();
    cout << endl;
    print_strongest();
    cout << endl;
}