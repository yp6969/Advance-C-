
//
// Created by ypinhas on 4/5/2022.
//

#ifndef VIRUSMUTATIONSIMULATION_OMICRON_H
#define VIRUSMUTATIONSIMULATION_OMICRON_H


#include "SarsCov2.h"

class Omicron : public SarsCov2{
public:
    Omicron(const string &gen);

    virtual ~Omicron();

};


#endif //VIRUSMUTATIONSIMULATION_OMICRON_H
