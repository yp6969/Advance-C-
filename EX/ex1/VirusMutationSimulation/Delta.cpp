//
// Created by ypinhas on 4/5/2022.
//

#include "Delta.h"

Delta::Delta(pair<string,int>* ancestor) : SarsCov2(ancestor){}
Delta::~Delta() = default;

void Delta::switch_letters(int i) {
    bool is_change = SarsCov2::randomWithProb(p);
    if(is_change) {
        switch (gen[i]) {
            case 'C':
                gen[i] = 'G';
                break;
            case 'G':
                gen[i] = 'C';
                break;
            case 'A':
                gen[i] = 'T';
                break;
            default:
                return;
        }
    }
}