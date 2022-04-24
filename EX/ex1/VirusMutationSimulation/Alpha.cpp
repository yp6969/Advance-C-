//
// Created by ypinhas on 4/5/2022.
//

#include "Alpha.h"

Alpha::Alpha(pair<string,int>* ancestor) : SarsCov2(ancestor) {}

void Alpha::switch_letters(int i) {
    bool is_change = SarsCov2::randomWithProb(p);
    if(is_change) {
        switch (gen[i]) {
            case 'T':
                gen[i] = 'A';
                break;
            case 'A':
                gen[i] = 'T';
                break;
            default:
                return;
        }
    }
}



Alpha::~Alpha() = default;
