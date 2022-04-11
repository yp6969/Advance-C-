//
// Created by ypinhas on 4/10/2022.
//

#include <iostream>
#include <vector>
#include <algorithm>
template<class IterIn, class IterOut>
void keep_it_real(IterIn first, IterIn last, IterOut out) {
    std::vector< std::pair<IterIn,int> > s(last-first);
    for(int i=0; i < s.size(); ++i)
        s[i] = std::make_pair(first+i, i );

    /* TODO 1: std::sort s according to the value of the first element within the pair */
    /* TODO 2: copy s into the IterOut instance */
}



int main(){

    return 0;
}