
//
// Created by ypinhas on 4/5/2022.
//

#ifndef VIRUSMUTATIONSIMULATION_DELTA_H
#define VIRUSMUTATIONSIMULATION_DELTA_H


#include "SarsCov2.h"

class Delta : public SarsCov2{
    double p = 1.0 / gen.length();
public:
    explicit Delta(pair<string,int>* ancestor);
    virtual ~Delta();

    void switch_letters(int i) override;

};




#endif //VIRUSMUTATIONSIMULATION_DELTA_H
