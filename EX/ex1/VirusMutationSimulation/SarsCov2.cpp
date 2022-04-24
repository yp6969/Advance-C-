//
// Created by ypinhas on 4/5/2022.
//

#include "SarsCov2.h"

#include <utility>


SarsCov2::SarsCov2(pair<string,int>* ancestor)
: ancestor(ancestor), gen(ancestor->first), type(ancestor->first[0]){
    gen.erase(gen.begin());
}

SarsCov2::SarsCov2(SarsCov2 &o): ancestor(o.ancestor), type(o.type) {}

SarsCov2::~SarsCov2() {
    ancestor->second-- ;
    ancestor = nullptr;
}

bool SarsCov2::operator==(const SarsCov2 &other) const {
    return gen == other.gen;
}

bool SarsCov2::operator!=(const SarsCov2 &other) const {
    return !operator==(other);
}

ostream& operator<<(ostream &os, const SarsCov2 &cov2) {
    os << cov2.type;
    for(char c: cov2.gen){
        os << " " << c;
    }
    return os;
}

double SarsCov2::strength(const string& tar) const {
    /**
     * rterun the strength of the gen
     */
    float cnt = 0.0;
    for(int i=0; i < gen.length(); i++){
        if(gen[i] == tar[i]){
            cnt++;
        }
    }
    return cnt / (float) gen.length();
}

void SarsCov2::private_update() {
    /**
     * update the gen letters
     */
    for(int i=0; i<gen.length(); i++){
        switch_letters(i);
    }
}

bool SarsCov2::randomWithProb(double p) {
    /**
     * get true or false with probability p
     */
    double rndDouble = (double)rand() / RAND_MAX;
    return rndDouble > p;
}


const string &SarsCov2::getGen() const {
    return gen;
}

void SarsCov2::setGen(const string &gen) {
    SarsCov2::gen = gen;
}

pair<string, int> *SarsCov2::getAncestor() const {
    return ancestor;
}

const char &SarsCov2::getType() const {
    return type;
}

void SarsCov2::setAncestor(pair<string, int> *ancestor) {
    SarsCov2::ancestor = ancestor;
}


