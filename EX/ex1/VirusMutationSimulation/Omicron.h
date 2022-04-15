
//
// Created by ypinhas on 4/5/2022.
//

#ifndef VIRUSMUTATIONSIMULATION_OMICRON_H
#define VIRUSMUTATIONSIMULATION_OMICRON_H


#include "SarsCov2.h"

class Omicron : public SarsCov2{
    const char type = 'o';

public:
    Omicron(pair<string,int>* ancestor);

    virtual ~Omicron();

};


#endif //VIRUSMUTATIONSIMULATION_OMICRON_H
