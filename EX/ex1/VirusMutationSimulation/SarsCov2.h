//
// Created by ypinhas on 4/5/2022.
//

#ifndef VIRUSMUTATIONSIMULATION_SARSCOV2_H
#define VIRUSMUTATIONSIMULATION_SARSCOV2_H
#include <string>
#include <ostream>
#include <iostream>
#include "utils.h"

using namespace std;


class SarsCov2 {
protected:
    string gen;
    const char type;
    pair<string, int>* ancestor;

public:
    explicit SarsCov2(pair<string,int>* ancestor);
    SarsCov2(SarsCov2& o);
    virtual ~SarsCov2();
//    SarsCov2& operator=(const SarsCov2& other);
    bool operator==(const SarsCov2& other) const;

    bool operator!=(const SarsCov2& other) const;
    const string &getGen() const;
    double strength(const string& tar) const;
    friend ostream &operator<<(ostream &os, const SarsCov2 &cov2);
    void private_update();
    virtual void switch_letters(int i)=0;
    bool randomWithProb(double p);

    /* getters and setters */
    pair<string, int> *getAncestor() const;
    void setGen(const string &gen);
    void setAncestor(pair<string, int> *ancestor);
    const char &getType() const;
};


#endif //VIRUSMUTATIONSIMULATION_SARSCOV2_H
