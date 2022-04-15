//
// Created by ypinhas on 4/5/2022.
//

#include "SarsCov2.h"

#include <utility>


SarsCov2::SarsCov2(pair<string,int>* ancestor, const char type)
: ancestor(ancestor), gen(ancestor->first), type(type){}

SarsCov2::SarsCov2(SarsCov2 &o): ancestor(o.ancestor), type(o.type) {}

SarsCov2::~SarsCov2() {
    ancestor->second-- ;
}

bool SarsCov2::operator==(const SarsCov2 &other) const {
    return gen == other.gen;
}

bool SarsCov2::operator!=(const SarsCov2 &other) const {
    return !operator==(other);
}

ostream& operator<<(ostream &os, const SarsCov2 &cov2) {
    os << "gen: " << cov2.gen << " ancestor: " << cov2.ancestor->first;
    return os;
}

double SarsCov2::strength(const string& tar) const {
    float cnt = 0.0;
    for(int i=0; i < gen.length(); i++){
        if(gen[i] == tar[i]){
            cnt++;
        }
    }
    return cnt / (float) gen.length();
}

const string &SarsCov2::getGen() const {
    return gen;
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
