//
// Created by ypinhas on 4/5/2022.
//

#ifndef VIRUSMUTATIONSIMULATION_ALPHA_H
#define VIRUSMUTATIONSIMULATION_ALPHA_H


#include "SarsCov2.h"

class Alpha : public SarsCov2{
    double p = 0.37;

public:
    explicit Alpha(pair<string,int>* ancestor);
    virtual ~Alpha();

    void switch_letters(int i) override;

};


#endif //VIRUSMUTATIONSIMULATION_ALPHA_H

