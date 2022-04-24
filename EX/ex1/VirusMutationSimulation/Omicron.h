
//
// Created by ypinhas on 4/5/2022.
//

#ifndef VIRUSMUTATIONSIMULATION_OMICRON_H
#define VIRUSMUTATIONSIMULATION_OMICRON_H


#include "SarsCov2.h"

class Omicron : public SarsCov2{
    double p = 2.0 / gen.length();
public:
    explicit Omicron(pair<string,int>* ancestor);
    virtual ~Omicron();

    void switch_letters(int i) override;


};


#endif //VIRUSMUTATIONSIMULATION_OMICRON_H
