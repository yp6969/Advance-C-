//
// Created by ypinhas on 4/5/2022.
//

#include "SarsCov2.h"


SarsCov2::SarsCov2(const string& gen): gen(gen) {}

SarsCov2::SarsCov2(SarsCov2 &o): gen(o.gen) {}

SarsCov2::~SarsCov2() {

}

ostream& operator<<(ostream &os, const SarsCov2 &cov2) {
    os << "gen: " << cov2.gen;
    return os;
}

//SarsCov2 &SarsCov2::operator=(const SarsCov2 &other) {
//    return ;
//}
