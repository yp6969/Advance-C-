//
// Created by ypinhas on 4/5/2022.
//

#ifndef VIRUSMUTATIONSIMULATION_REFCOUNTER_H
#define VIRUSMUTATIONSIMULATION_REFCOUNTER_H

#include <vector>
#include <string>

using namespace std;

typedef struct {
    int counter;
    string data;

}Ancestor;

class RefCounter {
    vector<string> ancestor_list;

public:
    RefCounter();

};


#endif //VIRUSMUTATIONSIMULATION_REFCOUNTER_H
