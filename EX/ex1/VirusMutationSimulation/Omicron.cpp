//
// Created by ypinhas on 4/5/2022.
//

#include "Omicron.h"

Omicron::Omicron(pair<string,int>* ancestor) : SarsCov2(ancestor) {}

void Omicron::switch_letters(int i) {
    bool is_change = SarsCov2::randomWithProb(p);
    if(is_change) {
        switch (gen[i]) {
            case 'C':
                gen[i] = 'G';
                break;
            case 'G':
                gen[i] = 'C';
                break;
            case 'T':
                gen[i] = 'A';
                break;
            default:
                return;
        }
    }
}

Omicron::~Omicron() = default;