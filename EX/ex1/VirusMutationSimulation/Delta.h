
//
// Created by ypinhas on 4/5/2022.
//

#ifndef VIRUSMUTATIONSIMULATION_DELTA_H
#define VIRUSMUTATIONSIMULATION_DELTA_H


#include "SarsCov2.h"

class Delta : public SarsCov2{
public:
    Delta(const string &gen);

    virtual ~Delta();
};




#endif //VIRUSMUTATIONSIMULATION_DELTA_H
